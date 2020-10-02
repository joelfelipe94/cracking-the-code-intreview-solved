cmake_minimum_required(VERSION 3.12) # version can be different

project(cracking_code_intreview) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_subdirectory(chapter\ 1) # add chapter 1 subdirectory
add_subdirectory(chapter\ 2) # add chapter 2 subdirectory