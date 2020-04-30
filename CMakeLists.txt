cmake_minimum_required(VERSION 3.8)
project(Wool VERSION 0.1)

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
        include/BatchingVisitor.hpp
        include/CircuitCompositionVisitor.hpp
        include/CircuitHelpers.hpp
        include/MultCountVisitor.hpp
        include/OpCountVisitor.hpp
        include/ParameterVisitor.hpp
        include/Wool.hpp)

add_library(wool ${SOURCE_FILES})
add_library(Wool::wool ALIAS wool)
target_link_libraries(wool PUBLIC Sheep::sheep ast_opt::ast_opt)
target_include_directories(wool PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
set_target_properties(wool PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS})
target_compile_features(wool PUBLIC cxx_std_17)

####################################################################################
## Wool testing
####################################################################################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    include(GoogleTest)
    add_subdirectory(tests EXCLUDE_FROM_ALL)
endif()
