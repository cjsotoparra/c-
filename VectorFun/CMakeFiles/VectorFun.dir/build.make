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
CMAKE_SOURCE_DIR = /home/christian/cplus/VectorFun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/cplus/VectorFun

# Include any dependencies generated for this target.
include CMakeFiles/VectorFun.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VectorFun.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VectorFun.dir/flags.make

CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o: CMakeFiles/VectorFun.dir/flags.make
CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o: VectorFunTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/VectorFun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o -c /home/christian/cplus/VectorFun/VectorFunTest.cpp

CMakeFiles/VectorFun.dir/VectorFunTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VectorFun.dir/VectorFunTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/VectorFun/VectorFunTest.cpp > CMakeFiles/VectorFun.dir/VectorFunTest.cpp.i

CMakeFiles/VectorFun.dir/VectorFunTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VectorFun.dir/VectorFunTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/VectorFun/VectorFunTest.cpp -o CMakeFiles/VectorFun.dir/VectorFunTest.cpp.s

CMakeFiles/VectorFun.dir/catch-main.cpp.o: CMakeFiles/VectorFun.dir/flags.make
CMakeFiles/VectorFun.dir/catch-main.cpp.o: catch-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/cplus/VectorFun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VectorFun.dir/catch-main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VectorFun.dir/catch-main.cpp.o -c /home/christian/cplus/VectorFun/catch-main.cpp

CMakeFiles/VectorFun.dir/catch-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VectorFun.dir/catch-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/cplus/VectorFun/catch-main.cpp > CMakeFiles/VectorFun.dir/catch-main.cpp.i

CMakeFiles/VectorFun.dir/catch-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VectorFun.dir/catch-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/cplus/VectorFun/catch-main.cpp -o CMakeFiles/VectorFun.dir/catch-main.cpp.s

# Object files for target VectorFun
VectorFun_OBJECTS = \
"CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o" \
"CMakeFiles/VectorFun.dir/catch-main.cpp.o"

# External object files for target VectorFun
VectorFun_EXTERNAL_OBJECTS =

VectorFun: CMakeFiles/VectorFun.dir/VectorFunTest.cpp.o
VectorFun: CMakeFiles/VectorFun.dir/catch-main.cpp.o
VectorFun: CMakeFiles/VectorFun.dir/build.make
VectorFun: CMakeFiles/VectorFun.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/cplus/VectorFun/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable VectorFun"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VectorFun.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VectorFun.dir/build: VectorFun

.PHONY : CMakeFiles/VectorFun.dir/build

CMakeFiles/VectorFun.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VectorFun.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VectorFun.dir/clean

CMakeFiles/VectorFun.dir/depend:
	cd /home/christian/cplus/VectorFun && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/cplus/VectorFun /home/christian/cplus/VectorFun /home/christian/cplus/VectorFun /home/christian/cplus/VectorFun /home/christian/cplus/VectorFun/CMakeFiles/VectorFun.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VectorFun.dir/depend

