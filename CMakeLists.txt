cmake_minimum_required(VERSION 3.8)
project(Wool VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

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




add_library(wool ${SOURCE_FILES})

target_include_directories(wool PUBLIC
        include
        ../Granite/lib/ast/include/ast
        ../Granite/lib/ast/include/visitor
        ../Granite/lib/ast/include/optimizer
        ../Granite/lib/ast/include/utilities )

find_package(Sheep REQUIRED)
target_link_libraries(wool
        Sheep::sheep
        ast_lib)

####################################################################################
## Wool testing
####################################################################################

# Disabled this guard until Granite & Wool are split into separate projects
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    include(GoogleTest)
    add_subdirectory(tests)
endif() #same as above - guard disabled until projects split
