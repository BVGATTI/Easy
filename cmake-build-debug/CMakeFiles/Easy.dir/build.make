# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\icon\File\GitHub\Easy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\icon\File\GitHub\Easy\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Easy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Easy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Easy.dir/flags.make

CMakeFiles/Easy.dir/main.cpp.obj: CMakeFiles/Easy.dir/flags.make
CMakeFiles/Easy.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\icon\File\GitHub\Easy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Easy.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Easy.dir\main.cpp.obj -c D:\icon\File\GitHub\Easy\main.cpp

CMakeFiles/Easy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Easy.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\icon\File\GitHub\Easy\main.cpp > CMakeFiles\Easy.dir\main.cpp.i

CMakeFiles/Easy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Easy.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\icon\File\GitHub\Easy\main.cpp -o CMakeFiles\Easy.dir\main.cpp.s

# Object files for target Easy
Easy_OBJECTS = \
"CMakeFiles/Easy.dir/main.cpp.obj"

# External object files for target Easy
Easy_EXTERNAL_OBJECTS =

Easy.exe: CMakeFiles/Easy.dir/main.cpp.obj
Easy.exe: CMakeFiles/Easy.dir/build.make
Easy.exe: CMakeFiles/Easy.dir/linklibs.rsp
Easy.exe: CMakeFiles/Easy.dir/objects1.rsp
Easy.exe: CMakeFiles/Easy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\icon\File\GitHub\Easy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Easy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Easy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Easy.dir/build: Easy.exe

.PHONY : CMakeFiles/Easy.dir/build

CMakeFiles/Easy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Easy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Easy.dir/clean

CMakeFiles/Easy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\icon\File\GitHub\Easy D:\icon\File\GitHub\Easy D:\icon\File\GitHub\Easy\cmake-build-debug D:\icon\File\GitHub\Easy\cmake-build-debug D:\icon\File\GitHub\Easy\cmake-build-debug\CMakeFiles\Easy.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Easy.dir/depend

