cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HashTable)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Include necessary headers
include_directories(x64)

# Specify source files
set(SOURCE_FILES
        HashTable.cpp
)
# Copy bst.txt to the build directory
configure_file(bst.txt ${CMAKE_CURRENT_BINARY_DIR}/bst.txt COPYONLY)

# Add the executable target
add_executable(HashTable ${SOURCE_FILES})
