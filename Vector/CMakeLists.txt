cmake_minimum_required(VERSION 3.10)

# Set the project name
project(VectorSorting)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Include necessary headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Specify source files
set(SOURCE_FILES
        VectorSorting.cpp
)

# Add the executable target
add_executable(VectorSorting ${SOURCE_FILES})

# Copy bst.txt to the build directory
configure_file(bst.txt ${CMAKE_CURRENT_BINARY_DIR}/bst.txt COPYONLY)


