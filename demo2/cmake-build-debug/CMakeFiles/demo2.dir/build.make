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
CMAKE_COMMAND = "D:\c_tools\clion\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\c_tools\clion\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\c_tools\c_projects\demo2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\c_tools\c_projects\demo2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/demo2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo2.dir/flags.make

CMakeFiles/demo2.dir/main.c.obj: CMakeFiles/demo2.dir/flags.make
CMakeFiles/demo2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\c_tools\c_projects\demo2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/demo2.dir/main.c.obj"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\demo2.dir\main.c.obj -c D:\c_tools\c_projects\demo2\main.c

CMakeFiles/demo2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo2.dir/main.c.i"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\c_tools\c_projects\demo2\main.c > CMakeFiles\demo2.dir\main.c.i

CMakeFiles/demo2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo2.dir/main.c.s"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\c_tools\c_projects\demo2\main.c -o CMakeFiles\demo2.dir\main.c.s

# Object files for target demo2
demo2_OBJECTS = \
"CMakeFiles/demo2.dir/main.c.obj"

# External object files for target demo2
demo2_EXTERNAL_OBJECTS =

demo2.exe: CMakeFiles/demo2.dir/main.c.obj
demo2.exe: CMakeFiles/demo2.dir/build.make
demo2.exe: CMakeFiles/demo2.dir/linklibs.rsp
demo2.exe: CMakeFiles/demo2.dir/objects1.rsp
demo2.exe: CMakeFiles/demo2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\c_tools\c_projects\demo2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable demo2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo2.dir/build: demo2.exe

.PHONY : CMakeFiles/demo2.dir/build

CMakeFiles/demo2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\demo2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/demo2.dir/clean

CMakeFiles/demo2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\c_tools\c_projects\demo2 D:\c_tools\c_projects\demo2 D:\c_tools\c_projects\demo2\cmake-build-debug D:\c_tools\c_projects\demo2\cmake-build-debug D:\c_tools\c_projects\demo2\cmake-build-debug\CMakeFiles\demo2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo2.dir/depend
