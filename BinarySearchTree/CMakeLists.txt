cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BSTProject)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the executable target
add_executable(BSTProject BinarySearchTree.cpp)

# Copy bst.txt to the build directory
configure_file(bst.txt ${CMAKE_CURRENT_BINARY_DIR}/bst.txt COPYONLY)

# Set additional include directories
target_include_directories(BSTProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

