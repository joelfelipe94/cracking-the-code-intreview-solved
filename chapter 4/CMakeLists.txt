cmake_minimum_required(VERSION 3.12) # version can be different

project(cracking_code_intreview)

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(chapter4Test chapter4Test.cpp) # add test executable

target_link_libraries(chapter4Test PRIVATE gtest) # link google test to this executable
