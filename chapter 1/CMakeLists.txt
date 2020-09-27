cmake_minimum_required(VERSION 3.12) # version can be different

project(cracking_code_intreview) #name of your project

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(exercise1Test exercise1Test.cpp) # add this executable

target_link_libraries(exercise1Test PRIVATE gtest) # link google test to this executable