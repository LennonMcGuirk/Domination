# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lemon\Desktop\DominationProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lemon\Desktop\DominationProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DominationProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DominationProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DominationProject.dir/flags.make

CMakeFiles/DominationProject.dir/main.c.obj: CMakeFiles/DominationProject.dir/flags.make
CMakeFiles/DominationProject.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lemon\Desktop\DominationProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DominationProject.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DominationProject.dir\main.c.obj   -c C:\Users\lemon\Desktop\DominationProject\main.c

CMakeFiles/DominationProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DominationProject.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lemon\Desktop\DominationProject\main.c > CMakeFiles\DominationProject.dir\main.c.i

CMakeFiles/DominationProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DominationProject.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lemon\Desktop\DominationProject\main.c -o CMakeFiles\DominationProject.dir\main.c.s

CMakeFiles/DominationProject.dir/game_init.c.obj: CMakeFiles/DominationProject.dir/flags.make
CMakeFiles/DominationProject.dir/game_init.c.obj: ../game_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lemon\Desktop\DominationProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DominationProject.dir/game_init.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DominationProject.dir\game_init.c.obj   -c C:\Users\lemon\Desktop\DominationProject\game_init.c

CMakeFiles/DominationProject.dir/game_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DominationProject.dir/game_init.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lemon\Desktop\DominationProject\game_init.c > CMakeFiles\DominationProject.dir\game_init.c.i

CMakeFiles/DominationProject.dir/game_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DominationProject.dir/game_init.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lemon\Desktop\DominationProject\game_init.c -o CMakeFiles\DominationProject.dir\game_init.c.s

CMakeFiles/DominationProject.dir/input_output.c.obj: CMakeFiles/DominationProject.dir/flags.make
CMakeFiles/DominationProject.dir/input_output.c.obj: ../input_output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lemon\Desktop\DominationProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/DominationProject.dir/input_output.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DominationProject.dir\input_output.c.obj   -c C:\Users\lemon\Desktop\DominationProject\input_output.c

CMakeFiles/DominationProject.dir/input_output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DominationProject.dir/input_output.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lemon\Desktop\DominationProject\input_output.c > CMakeFiles\DominationProject.dir\input_output.c.i

CMakeFiles/DominationProject.dir/input_output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DominationProject.dir/input_output.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lemon\Desktop\DominationProject\input_output.c -o CMakeFiles\DominationProject.dir\input_output.c.s

# Object files for target DominationProject
DominationProject_OBJECTS = \
"CMakeFiles/DominationProject.dir/main.c.obj" \
"CMakeFiles/DominationProject.dir/game_init.c.obj" \
"CMakeFiles/DominationProject.dir/input_output.c.obj"

# External object files for target DominationProject
DominationProject_EXTERNAL_OBJECTS =

DominationProject.exe: CMakeFiles/DominationProject.dir/main.c.obj
DominationProject.exe: CMakeFiles/DominationProject.dir/game_init.c.obj
DominationProject.exe: CMakeFiles/DominationProject.dir/input_output.c.obj
DominationProject.exe: CMakeFiles/DominationProject.dir/build.make
DominationProject.exe: CMakeFiles/DominationProject.dir/linklibs.rsp
DominationProject.exe: CMakeFiles/DominationProject.dir/objects1.rsp
DominationProject.exe: CMakeFiles/DominationProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lemon\Desktop\DominationProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable DominationProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DominationProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DominationProject.dir/build: DominationProject.exe

.PHONY : CMakeFiles/DominationProject.dir/build

CMakeFiles/DominationProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DominationProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DominationProject.dir/clean

CMakeFiles/DominationProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lemon\Desktop\DominationProject C:\Users\lemon\Desktop\DominationProject C:\Users\lemon\Desktop\DominationProject\cmake-build-debug C:\Users\lemon\Desktop\DominationProject\cmake-build-debug C:\Users\lemon\Desktop\DominationProject\cmake-build-debug\CMakeFiles\DominationProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DominationProject.dir/depend

