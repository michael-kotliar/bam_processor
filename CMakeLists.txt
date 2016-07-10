cmake_minimum_required(VERSION 3.5)
project(bam_processor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories (include)
link_directories (lib)

set(SOURCE_FILES main.cpp)
add_executable(bam_processor ${SOURCE_FILES})
target_link_libraries (bam_processor bamtools)