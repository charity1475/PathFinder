# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/charity/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/charity/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/charity/CLionProjects/Grids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/charity/CLionProjects/Grids/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/starter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/starter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/starter.dir/flags.make

CMakeFiles/starter.dir/main.cpp.o: CMakeFiles/starter.dir/flags.make
CMakeFiles/starter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/charity/CLionProjects/Grids/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/starter.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/starter.dir/main.cpp.o -c /home/charity/CLionProjects/Grids/main.cpp

CMakeFiles/starter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/starter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/charity/CLionProjects/Grids/main.cpp > CMakeFiles/starter.dir/main.cpp.i

CMakeFiles/starter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/starter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/charity/CLionProjects/Grids/main.cpp -o CMakeFiles/starter.dir/main.cpp.s

# Object files for target starter
starter_OBJECTS = \
"CMakeFiles/starter.dir/main.cpp.o"

# External object files for target starter
starter_EXTERNAL_OBJECTS =

starter: CMakeFiles/starter.dir/main.cpp.o
starter: CMakeFiles/starter.dir/build.make
starter: CMakeFiles/starter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/charity/CLionProjects/Grids/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable starter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/starter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/starter.dir/build: starter

.PHONY : CMakeFiles/starter.dir/build

CMakeFiles/starter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/starter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/starter.dir/clean

CMakeFiles/starter.dir/depend:
	cd /home/charity/CLionProjects/Grids/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/charity/CLionProjects/Grids /home/charity/CLionProjects/Grids /home/charity/CLionProjects/Grids/cmake-build-debug /home/charity/CLionProjects/Grids/cmake-build-debug /home/charity/CLionProjects/Grids/cmake-build-debug/CMakeFiles/starter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/starter.dir/depend
