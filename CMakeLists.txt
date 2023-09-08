cmake_minimum_required(VERSION 3.25)

project(TBI DESCRIPTION "Demonstrate whether TBI is available.")
add_executable(tbi main.c)

#set_property(TARGET tbi PROPERTY CXX_STANDARD 20)
