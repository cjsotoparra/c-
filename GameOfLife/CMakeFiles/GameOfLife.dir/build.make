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
include CMakeFiles/GameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameOfLife.dir/flags.make

CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o: GameOfLife.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o -c /home/christian/cplus/GameOfLife/GameOfLife.cpp

CMakeFiles/GameOfLife.dir/GameOfLife.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/GameOfLife.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/GameOfLife/GameOfLife.cpp > CMakeFiles/GameOfLife.dir/GameOfLife.cpp.i

CMakeFiles/GameOfLife.dir/GameOfLife.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/GameOfLife.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/GameOfLife/GameOfLife.cpp -o CMakeFiles/GameOfLife.dir/GameOfLife.cpp.s

CMakeFiles/GameOfLife.dir/catch-main.cpp.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/catch-main.cpp.o: catch-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameOfLife.dir/catch-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameOfLife.dir/catch-main.cpp.o -c /home/christian/cplus/GameOfLife/catch-main.cpp

CMakeFiles/GameOfLife.dir/catch-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameOfLife.dir/catch-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/GameOfLife/catch-main.cpp > CMakeFiles/GameOfLife.dir/catch-main.cpp.i

CMakeFiles/GameOfLife.dir/catch-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameOfLife.dir/catch-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/GameOfLife/catch-main.cpp -o CMakeFiles/GameOfLife.dir/catch-main.cpp.s

# Object files for target GameOfLife
GameOfLife_OBJECTS = \
"CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o" \
"CMakeFiles/GameOfLife.dir/catch-main.cpp.o"

# External object files for target GameOfLife
GameOfLife_EXTERNAL_OBJECTS =

GameOfLife: CMakeFiles/GameOfLife.dir/GameOfLife.cpp.o
GameOfLife: CMakeFiles/GameOfLife.dir/catch-main.cpp.o
GameOfLife: CMakeFiles/GameOfLife.dir/build.make
GameOfLife: CMakeFiles/GameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/cplus/GameOfLife/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GameOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameOfLife.dir/build: GameOfLife

.PHONY : CMakeFiles/GameOfLife.dir/build

CMakeFiles/GameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameOfLife.dir/clean

CMakeFiles/GameOfLife.dir/depend:
	cd /home/christian/cplus/GameOfLife && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife /home/christian/cplus/GameOfLife/CMakeFiles/GameOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameOfLife.dir/depend
