# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/nipun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nipun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nipun/Documents/ece244/lab1/lab1_release/harmonic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/harmonic.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/harmonic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/harmonic.dir/flags.make

CMakeFiles/harmonic.dir/harmonic.cpp.o: CMakeFiles/harmonic.dir/flags.make
CMakeFiles/harmonic.dir/harmonic.cpp.o: ../harmonic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/harmonic.dir/harmonic.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/harmonic.dir/harmonic.cpp.o -c /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/harmonic.cpp

CMakeFiles/harmonic.dir/harmonic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/harmonic.dir/harmonic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/harmonic.cpp > CMakeFiles/harmonic.dir/harmonic.cpp.i

CMakeFiles/harmonic.dir/harmonic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/harmonic.dir/harmonic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/harmonic.cpp -o CMakeFiles/harmonic.dir/harmonic.cpp.s

# Object files for target harmonic
harmonic_OBJECTS = \
"CMakeFiles/harmonic.dir/harmonic.cpp.o"

# External object files for target harmonic
harmonic_EXTERNAL_OBJECTS =

harmonic: CMakeFiles/harmonic.dir/harmonic.cpp.o
harmonic: CMakeFiles/harmonic.dir/build.make
harmonic: CMakeFiles/harmonic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable harmonic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/harmonic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/harmonic.dir/build: harmonic
.PHONY : CMakeFiles/harmonic.dir/build

CMakeFiles/harmonic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/harmonic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/harmonic.dir/clean

CMakeFiles/harmonic.dir/depend:
	cd /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nipun/Documents/ece244/lab1/lab1_release/harmonic /home/nipun/Documents/ece244/lab1/lab1_release/harmonic /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug /home/nipun/Documents/ece244/lab1/lab1_release/harmonic/cmake-build-debug/CMakeFiles/harmonic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/harmonic.dir/depend

