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
CMAKE_SOURCE_DIR = /home/christian/cplus/PokerHand

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/cplus/PokerHand

# Include any dependencies generated for this target.
include CMakeFiles/Poker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Poker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Poker.dir/flags.make

CMakeFiles/Poker.dir/Card.cpp.o: CMakeFiles/Poker.dir/flags.make
CMakeFiles/Poker.dir/Card.cpp.o: Card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/PokerHand/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Poker.dir/Card.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Poker.dir/Card.cpp.o -c /home/christian/cplus/PokerHand/Card.cpp

CMakeFiles/Poker.dir/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/Card.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/PokerHand/Card.cpp > CMakeFiles/Poker.dir/Card.cpp.i

CMakeFiles/Poker.dir/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/Card.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/PokerHand/Card.cpp -o CMakeFiles/Poker.dir/Card.cpp.s

CMakeFiles/Poker.dir/PokerHandTest.cpp.o: CMakeFiles/Poker.dir/flags.make
CMakeFiles/Poker.dir/PokerHandTest.cpp.o: PokerHandTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/PokerHand/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Poker.dir/PokerHandTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Poker.dir/PokerHandTest.cpp.o -c /home/christian/cplus/PokerHand/PokerHandTest.cpp

CMakeFiles/Poker.dir/PokerHandTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/PokerHandTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/PokerHand/PokerHandTest.cpp > CMakeFiles/Poker.dir/PokerHandTest.cpp.i

CMakeFiles/Poker.dir/PokerHandTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/PokerHandTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/PokerHand/PokerHandTest.cpp -o CMakeFiles/Poker.dir/PokerHandTest.cpp.s

CMakeFiles/Poker.dir/catch-main.cpp.o: CMakeFiles/Poker.dir/flags.make
CMakeFiles/Poker.dir/catch-main.cpp.o: catch-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/PokerHand/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Poker.dir/catch-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Poker.dir/catch-main.cpp.o -c /home/christian/cplus/PokerHand/catch-main.cpp

CMakeFiles/Poker.dir/catch-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poker.dir/catch-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/PokerHand/catch-main.cpp > CMakeFiles/Poker.dir/catch-main.cpp.i

CMakeFiles/Poker.dir/catch-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poker.dir/catch-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/PokerHand/catch-main.cpp -o CMakeFiles/Poker.dir/catch-main.cpp.s

# Object files for target Poker
Poker_OBJECTS = \
"CMakeFiles/Poker.dir/Card.cpp.o" \
"CMakeFiles/Poker.dir/PokerHandTest.cpp.o" \
"CMakeFiles/Poker.dir/catch-main.cpp.o"

# External object files for target Poker
Poker_EXTERNAL_OBJECTS =

Poker: CMakeFiles/Poker.dir/Card.cpp.o
Poker: CMakeFiles/Poker.dir/PokerHandTest.cpp.o
Poker: CMakeFiles/Poker.dir/catch-main.cpp.o
Poker: CMakeFiles/Poker.dir/build.make
Poker: CMakeFiles/Poker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/cplus/PokerHand/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Poker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Poker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Poker.dir/build: Poker

.PHONY : CMakeFiles/Poker.dir/build

CMakeFiles/Poker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Poker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Poker.dir/clean

CMakeFiles/Poker.dir/depend:
	cd /home/christian/cplus/PokerHand && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/cplus/PokerHand /home/christian/cplus/PokerHand /home/christian/cplus/PokerHand /home/christian/cplus/PokerHand /home/christian/cplus/PokerHand/CMakeFiles/Poker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Poker.dir/depend

