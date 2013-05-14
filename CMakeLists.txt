cmake_minimum_required (VERSION 2.6)
project(libsqlitepp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")
set(CMAKE_COLOR_MAKEFILE ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
endif()

find_package(sqlite3 REQUIRED)
include_directories(${SQLITE_INCLUDE_DIR})

add_executable(libsqlitepp-tests tests.cpp)
target_link_libraries(libsqlitepp-tests ${SQLITE_LIBRARY})
