# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/otus_cpp_p_project/otus_cpp_p_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/otus_cpp_p_project/otus_cpp_p_project

# Include any dependencies generated for this target.
include CMakeFiles/halfSumFinder.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/halfSumFinder.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/halfSumFinder.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/halfSumFinder.exe.dir/flags.make

CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o: CMakeFiles/halfSumFinder.exe.dir/flags.make
CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o: halfSumFinder/main.cpp
CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o: CMakeFiles/halfSumFinder.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/otus_cpp_p_project/otus_cpp_p_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o -MF CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o.d -o CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o -c /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/halfSumFinder/main.cpp

CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/halfSumFinder/main.cpp > CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.i

CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/halfSumFinder/main.cpp -o CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.s

CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o: CMakeFiles/halfSumFinder.exe.dir/flags.make
CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o: src/halfsumfinder.cpp
CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o: CMakeFiles/halfSumFinder.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/otus_cpp_p_project/otus_cpp_p_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o -MF CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o.d -o CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o -c /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/halfsumfinder.cpp

CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/halfsumfinder.cpp > CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.i

CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/halfsumfinder.cpp -o CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.s

CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o: CMakeFiles/halfSumFinder.exe.dir/flags.make
CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o: src/set.cpp
CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o: CMakeFiles/halfSumFinder.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/otus_cpp_p_project/otus_cpp_p_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o -MF CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o.d -o CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o -c /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/set.cpp

CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/set.cpp > CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.i

CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/src/set.cpp -o CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.s

# Object files for target halfSumFinder.exe
halfSumFinder_exe_OBJECTS = \
"CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o" \
"CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o" \
"CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o"

# External object files for target halfSumFinder.exe
halfSumFinder_exe_EXTERNAL_OBJECTS =

halfSumFinder.exe: CMakeFiles/halfSumFinder.exe.dir/halfSumFinder/main.cpp.o
halfSumFinder.exe: CMakeFiles/halfSumFinder.exe.dir/src/halfsumfinder.cpp.o
halfSumFinder.exe: CMakeFiles/halfSumFinder.exe.dir/src/set.cpp.o
halfSumFinder.exe: CMakeFiles/halfSumFinder.exe.dir/build.make
halfSumFinder.exe: CMakeFiles/halfSumFinder.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/otus_cpp_p_project/otus_cpp_p_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable halfSumFinder.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/halfSumFinder.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/halfSumFinder.exe.dir/build: halfSumFinder.exe
.PHONY : CMakeFiles/halfSumFinder.exe.dir/build

CMakeFiles/halfSumFinder.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/halfSumFinder.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/halfSumFinder.exe.dir/clean

CMakeFiles/halfSumFinder.exe.dir/depend:
	cd /home/runner/work/otus_cpp_p_project/otus_cpp_p_project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/otus_cpp_p_project/otus_cpp_p_project /home/runner/work/otus_cpp_p_project/otus_cpp_p_project /home/runner/work/otus_cpp_p_project/otus_cpp_p_project /home/runner/work/otus_cpp_p_project/otus_cpp_p_project /home/runner/work/otus_cpp_p_project/otus_cpp_p_project/CMakeFiles/halfSumFinder.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/halfSumFinder.exe.dir/depend
