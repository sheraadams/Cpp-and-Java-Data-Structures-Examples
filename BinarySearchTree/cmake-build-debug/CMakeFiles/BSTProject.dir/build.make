# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/s.adams/BinarySearchTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/s.adams/BinarySearchTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BSTProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BSTProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BSTProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BSTProject.dir/flags.make

CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o: CMakeFiles/BSTProject.dir/flags.make
CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o: /Users/s.adams/BinarySearchTree/BinarySearchTree.cpp
CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o: CMakeFiles/BSTProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/s.adams/BinarySearchTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o -MF CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o.d -o CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o -c /Users/s.adams/BinarySearchTree/BinarySearchTree.cpp

CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/s.adams/BinarySearchTree/BinarySearchTree.cpp > CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.i

CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/s.adams/BinarySearchTree/BinarySearchTree.cpp -o CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.s

# Object files for target BSTProject
BSTProject_OBJECTS = \
"CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o"

# External object files for target BSTProject
BSTProject_EXTERNAL_OBJECTS =

BSTProject: CMakeFiles/BSTProject.dir/BinarySearchTree.cpp.o
BSTProject: CMakeFiles/BSTProject.dir/build.make
BSTProject: CMakeFiles/BSTProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/s.adams/BinarySearchTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BSTProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BSTProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BSTProject.dir/build: BSTProject
.PHONY : CMakeFiles/BSTProject.dir/build

CMakeFiles/BSTProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BSTProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BSTProject.dir/clean

CMakeFiles/BSTProject.dir/depend:
	cd /Users/s.adams/BinarySearchTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/s.adams/BinarySearchTree /Users/s.adams/BinarySearchTree /Users/s.adams/BinarySearchTree/cmake-build-debug /Users/s.adams/BinarySearchTree/cmake-build-debug /Users/s.adams/BinarySearchTree/cmake-build-debug/CMakeFiles/BSTProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BSTProject.dir/depend
