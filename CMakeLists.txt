cmake_minimum_required(VERSION 3.8)
project(Wool
        VERSION 0.1
        DESCRIPTION "Wool is a wrapper for SHEEP that converts AST's into Circuits"
        LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

####################################################################################
## Dependencies
####################################################################################
find_package(Sheep REQUIRED)
find_package(ast_opt REQUIRED)

####################################################################################
## Build wool library
####################################################################################
set(SOURCE_FILES
        src/Wool.cpp
        src/CircuitCompositionVisitor.cpp
        src/BatchingVisitor.cpp
        src/CircuitHelpers.cpp
        src/OpCountVisitor.cpp
        src/MultCountVisitor.cpp
        src/ParameterVisitor.cpp)

set(PUBLIC_HEADERS
        include/Wool.hpp)

add_library(wool ${SOURCE_FILES})
add_library(Wool::wool ALIAS wool)
target_link_libraries(wool PUBLIC ast_opt::ast_opt)
target_link_libraries(wool PRIVATE Sheep::sheep)
target_include_directories(wool PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
set_target_properties(wool PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS})
target_compile_features(wool PUBLIC cxx_std_17)

####################################################################################
## Wool installation
##
## wool installed globally as a library
####################################################################################
# Create a Version File
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        WoolConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)

# Configure (i.e. generate) the WoolConfig.cmake file and copy both it and the version to install
configure_file(WoolConfig.cmake.in WoolConfig.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/WoolConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/WoolConfigVersion.cmake"
        DESTINATION lib/cmake/Wool)

install(TARGETS wool
        EXPORT  WoolTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
        INCLUDES DESTINATION include)

install(EXPORT WoolTargets
        FILE WoolTargets.cmake
        NAMESPACE Wool::
        DESTINATION lib/cmake/Wool)


####################################################################################
## Wool testing
####################################################################################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message("Enabling Wool Tests")
    enable_testing()
    add_subdirectory(tests EXCLUDE_FROM_ALL)
endif()
