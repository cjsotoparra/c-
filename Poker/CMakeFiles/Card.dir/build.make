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
CMAKE_SOURCE_DIR = /home/christian/cplus/Poker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/cplus/Poker

# Include any dependencies generated for this target.
include CMakeFiles/Card.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Card.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Card.dir/flags.make

CMakeFiles/Card.dir/catch-main.cpp.o: CMakeFiles/Card.dir/flags.make
CMakeFiles/Card.dir/catch-main.cpp.o: catch-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/Poker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Card.dir/catch-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card.dir/catch-main.cpp.o -c /home/christian/cplus/Poker/catch-main.cpp

CMakeFiles/Card.dir/catch-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card.dir/catch-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/Poker/catch-main.cpp > CMakeFiles/Card.dir/catch-main.cpp.i

CMakeFiles/Card.dir/catch-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card.dir/catch-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/Poker/catch-main.cpp -o CMakeFiles/Card.dir/catch-main.cpp.s

CMakeFiles/Card.dir/CardTest.cpp.o: CMakeFiles/Card.dir/flags.make
CMakeFiles/Card.dir/CardTest.cpp.o: CardTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/Poker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Card.dir/CardTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Card.dir/CardTest.cpp.o -c /home/christian/cplus/Poker/CardTest.cpp

CMakeFiles/Card.dir/CardTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Card.dir/CardTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/Poker/CardTest.cpp > CMakeFiles/Card.dir/CardTest.cpp.i

CMakeFiles/Card.dir/CardTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Card.dir/CardTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/Poker/CardTest.cpp -o CMakeFiles/Card.dir/CardTest.cpp.s

# Object files for target Card
Card_OBJECTS = \
"CMakeFiles/Card.dir/catch-main.cpp.o" \
"CMakeFiles/Card.dir/CardTest.cpp.o"

# External object files for target Card
Card_EXTERNAL_OBJECTS =

Card: CMakeFiles/Card.dir/catch-main.cpp.o
Card: CMakeFiles/Card.dir/CardTest.cpp.o
Card: CMakeFiles/Card.dir/build.make
Card: CMakeFiles/Card.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/cplus/Poker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Card"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Card.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Card.dir/build: Card

.PHONY : CMakeFiles/Card.dir/build

CMakeFiles/Card.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Card.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Card.dir/clean

CMakeFiles/Card.dir/depend:
	cd /home/christian/cplus/Poker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/cplus/Poker /home/christian/cplus/Poker /home/christian/cplus/Poker /home/christian/cplus/Poker /home/christian/cplus/Poker/CMakeFiles/Card.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Card.dir/depend

