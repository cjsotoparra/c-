# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/christian/cplus/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/cplus/GameOfLife

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/GameOfLife.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/GameOfLife.cpp.o: GameOfLife.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/GameOfLife.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/GameOfLife.cpp.o -c /home/christian/cplus/GameOfLife/GameOfLife.cpp

CMakeFiles/demo.dir/GameOfLife.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/GameOfLife.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/GameOfLife/GameOfLife.cpp > CMakeFiles/demo.dir/GameOfLife.cpp.i

CMakeFiles/demo.dir/GameOfLife.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/GameOfLife.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/GameOfLife/GameOfLife.cpp -o CMakeFiles/demo.dir/GameOfLife.cpp.s

CMakeFiles/demo.dir/catch-main.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/catch-main.cpp.o: catch-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/catch-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/catch-main.cpp.o -c /home/christian/cplus/GameOfLife/catch-main.cpp

CMakeFiles/demo.dir/catch-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/catch-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/GameOfLife/catch-main.cpp > CMakeFiles/demo.dir/catch-main.cpp.i

CMakeFiles/demo.dir/catch-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/catch-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/GameOfLife/catch-main.cpp -o CMakeFiles/demo.dir/catch-main.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/GameOfLife.cpp.o" \
"CMakeFiles/demo.dir/catch-main.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/GameOfLife.cpp.o
demo: CMakeFiles/demo.dir/catch-main.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo

.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/christian/cplus/GameOfLife && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

