cmake_minimum_required(VERSION 3.12) # version can be different

project(sortbench) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES}) # add this executable
add_executable(quicksort ${SOURCES}) # add this executable

target_link_libraries(main PRIVATE gtest) # link google test to this executable