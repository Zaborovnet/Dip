# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denis/Documents/DIP7/Client/map/proj-9.2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug

# Include any dependencies generated for this target.
include test/benchmark/CMakeFiles/bench_proj_trans.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/benchmark/CMakeFiles/bench_proj_trans.dir/compiler_depend.make

# Include the progress variables for this target.
include test/benchmark/CMakeFiles/bench_proj_trans.dir/progress.make

# Include the compile flags for this target's objects.
include test/benchmark/CMakeFiles/bench_proj_trans.dir/flags.make

test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o: test/benchmark/CMakeFiles/bench_proj_trans.dir/flags.make
test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o: /home/denis/Documents/DIP7/Client/map/proj-9.2.0/test/benchmark/bench_proj_trans.cpp
test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o: test/benchmark/CMakeFiles/bench_proj_trans.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o"
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o -MF CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o.d -o CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o -c /home/denis/Documents/DIP7/Client/map/proj-9.2.0/test/benchmark/bench_proj_trans.cpp

test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.i"
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/Documents/DIP7/Client/map/proj-9.2.0/test/benchmark/bench_proj_trans.cpp > CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.i

test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.s"
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/Documents/DIP7/Client/map/proj-9.2.0/test/benchmark/bench_proj_trans.cpp -o CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.s

# Object files for target bench_proj_trans
bench_proj_trans_OBJECTS = \
"CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o"

# External object files for target bench_proj_trans
bench_proj_trans_EXTERNAL_OBJECTS =

bin/bench_proj_trans: test/benchmark/CMakeFiles/bench_proj_trans.dir/bench_proj_trans.cpp.o
bin/bench_proj_trans: test/benchmark/CMakeFiles/bench_proj_trans.dir/build.make
bin/bench_proj_trans: lib/libproj.so.25.9.2.0
bin/bench_proj_trans: test/benchmark/CMakeFiles/bench_proj_trans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/bench_proj_trans"
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bench_proj_trans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/benchmark/CMakeFiles/bench_proj_trans.dir/build: bin/bench_proj_trans
.PHONY : test/benchmark/CMakeFiles/bench_proj_trans.dir/build

test/benchmark/CMakeFiles/bench_proj_trans.dir/clean:
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark && $(CMAKE_COMMAND) -P CMakeFiles/bench_proj_trans.dir/cmake_clean.cmake
.PHONY : test/benchmark/CMakeFiles/bench_proj_trans.dir/clean

test/benchmark/CMakeFiles/bench_proj_trans.dir/depend:
	cd /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/Documents/DIP7/Client/map/proj-9.2.0 /home/denis/Documents/DIP7/Client/map/proj-9.2.0/test/benchmark /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark /home/denis/Documents/DIP7/Client/map/build-proj-9.2.0-Desktop_Qt_5_14_2_GCC_64bit-Debug/test/benchmark/CMakeFiles/bench_proj_trans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/benchmark/CMakeFiles/bench_proj_trans.dir/depend
