# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/thomas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/thomas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/Documents/snake-plusplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/Documents/snake-plusplus/cmake-build-debug

# Include any dependencies generated for this target.
include SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/flags.make

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/flags.make
SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../SnakePlusPlusTests/lib/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/snake-plusplus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/thomas/Documents/snake-plusplus/SnakePlusPlusTests/lib/googletest/src/gtest_main.cc

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/snake-plusplus/SnakePlusPlusTests/lib/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/snake-plusplus/SnakePlusPlusTests/lib/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/build.make SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

SnakePlusPlusTests/lib/googletest/libgtest_main.a: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
SnakePlusPlusTests/lib/googletest/libgtest_main.a: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/build.make
SnakePlusPlusTests/lib/googletest/libgtest_main.a: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/Documents/snake-plusplus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/build: SnakePlusPlusTests/lib/googletest/libgtest_main.a

.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/build

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/requires: SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/requires

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/clean

SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/depend:
	cd /home/thomas/Documents/snake-plusplus/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/Documents/snake-plusplus /home/thomas/Documents/snake-plusplus/SnakePlusPlusTests/lib/googletest /home/thomas/Documents/snake-plusplus/cmake-build-debug /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest /home/thomas/Documents/snake-plusplus/cmake-build-debug/SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SnakePlusPlusTests/lib/googletest/CMakeFiles/gtest_main.dir/depend
