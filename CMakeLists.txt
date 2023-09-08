cmake_minimum_required(VERSION 3.25)

project(TBI DESCRIPTION "Test whether Tbi config system works as intended.")
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}")
find_package(Tbi REQUIRED CONFIG)

if(Tbi_FOUND)
message("TBI enabled.")
else()
message("TBI failed.")
endif()