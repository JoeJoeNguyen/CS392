# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "/Users/joenguyen/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/233.14475.31/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake"

# The command to remove a file.
RM = "/Users/joenguyen/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/233.14475.31/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joenguyen/CS392

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joenguyen/CS392/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS392.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CS392.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CS392.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS392.dir/flags.make

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o: /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/bubble.c
CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o -MF CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o.d -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o -c /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/bubble.c

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/bubble.c > CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.i

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/bubble.c -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.s

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o: /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/utils.c
CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o -MF CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o.d -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o -c /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/utils.c

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/utils.c > CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.i

CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw2/hw2_starter_code/submission/utils.c -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.s

CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o: /Users/joenguyen/CS392/hw2/hw2_starter_code/bubble.c
CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o -MF CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o.d -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o -c /Users/joenguyen/CS392/hw2/hw2_starter_code/bubble.c

CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw2/hw2_starter_code/bubble.c > CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.i

CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw2/hw2_starter_code/bubble.c -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.s

CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o: /Users/joenguyen/CS392/hw2/hw2_starter_code/main.c
CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o -MF CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o.d -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o -c /Users/joenguyen/CS392/hw2/hw2_starter_code/main.c

CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw2/hw2_starter_code/main.c > CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.i

CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw2/hw2_starter_code/main.c -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.s

CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o: /Users/joenguyen/CS392/hw2/hw2_starter_code/utils.c
CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o -MF CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o.d -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o -c /Users/joenguyen/CS392/hw2/hw2_starter_code/utils.c

CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw2/hw2_starter_code/utils.c > CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.i

CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw2/hw2_starter_code/utils.c -o CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.s

CMakeFiles/CS392.dir/hw3/submission/main.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/submission/main.c.o: /Users/joenguyen/CS392/hw3/submission/main.c
CMakeFiles/CS392.dir/hw3/submission/main.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/CS392.dir/hw3/submission/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/submission/main.c.o -MF CMakeFiles/CS392.dir/hw3/submission/main.c.o.d -o CMakeFiles/CS392.dir/hw3/submission/main.c.o -c /Users/joenguyen/CS392/hw3/submission/main.c

CMakeFiles/CS392.dir/hw3/submission/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/submission/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/submission/main.c > CMakeFiles/CS392.dir/hw3/submission/main.c.i

CMakeFiles/CS392.dir/hw3/submission/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/submission/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/submission/main.c -o CMakeFiles/CS392.dir/hw3/submission/main.c.s

CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o: /Users/joenguyen/CS392/hw3/submission/oocmerge.c
CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o -MF CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o.d -o CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o -c /Users/joenguyen/CS392/hw3/submission/oocmerge.c

CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/submission/oocmerge.c > CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.i

CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/submission/oocmerge.c -o CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.s

CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o: /Users/joenguyen/CS392/hw3/submission2.o/main.c
CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o -MF CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o.d -o CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o -c /Users/joenguyen/CS392/hw3/submission2.o/main.c

CMakeFiles/CS392.dir/hw3/submission2.o/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/submission2.o/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/submission2.o/main.c > CMakeFiles/CS392.dir/hw3/submission2.o/main.c.i

CMakeFiles/CS392.dir/hw3/submission2.o/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/submission2.o/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/submission2.o/main.c -o CMakeFiles/CS392.dir/hw3/submission2.o/main.c.s

CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o: /Users/joenguyen/CS392/hw3/submission2.o/oocmerge.c
CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o -MF CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o.d -o CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o -c /Users/joenguyen/CS392/hw3/submission2.o/oocmerge.c

CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/submission2.o/oocmerge.c > CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.i

CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/submission2.o/oocmerge.c -o CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.s

CMakeFiles/CS392.dir/hw3/main.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/main.c.o: /Users/joenguyen/CS392/hw3/main.c
CMakeFiles/CS392.dir/hw3/main.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/CS392.dir/hw3/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/main.c.o -MF CMakeFiles/CS392.dir/hw3/main.c.o.d -o CMakeFiles/CS392.dir/hw3/main.c.o -c /Users/joenguyen/CS392/hw3/main.c

CMakeFiles/CS392.dir/hw3/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/main.c > CMakeFiles/CS392.dir/hw3/main.c.i

CMakeFiles/CS392.dir/hw3/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/main.c -o CMakeFiles/CS392.dir/hw3/main.c.s

CMakeFiles/CS392.dir/hw3/oocmerge.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3/oocmerge.c.o: /Users/joenguyen/CS392/hw3/oocmerge.c
CMakeFiles/CS392.dir/hw3/oocmerge.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/CS392.dir/hw3/oocmerge.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3/oocmerge.c.o -MF CMakeFiles/CS392.dir/hw3/oocmerge.c.o.d -o CMakeFiles/CS392.dir/hw3/oocmerge.c.o -c /Users/joenguyen/CS392/hw3/oocmerge.c

CMakeFiles/CS392.dir/hw3/oocmerge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3/oocmerge.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3/oocmerge.c > CMakeFiles/CS392.dir/hw3/oocmerge.c.i

CMakeFiles/CS392.dir/hw3/oocmerge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3/oocmerge.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3/oocmerge.c -o CMakeFiles/CS392.dir/hw3/oocmerge.c.s

CMakeFiles/CS392.dir/hw3.2/main.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw3.2/main.c.o: /Users/joenguyen/CS392/hw3.2/main.c
CMakeFiles/CS392.dir/hw3.2/main.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/CS392.dir/hw3.2/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw3.2/main.c.o -MF CMakeFiles/CS392.dir/hw3.2/main.c.o.d -o CMakeFiles/CS392.dir/hw3.2/main.c.o -c /Users/joenguyen/CS392/hw3.2/main.c

CMakeFiles/CS392.dir/hw3.2/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw3.2/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw3.2/main.c > CMakeFiles/CS392.dir/hw3.2/main.c.i

CMakeFiles/CS392.dir/hw3.2/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw3.2/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw3.2/main.c -o CMakeFiles/CS392.dir/hw3.2/main.c.s

CMakeFiles/CS392.dir/hw4/maxfile.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/hw4/maxfile.c.o: /Users/joenguyen/CS392/hw4/maxfile.c
CMakeFiles/CS392.dir/hw4/maxfile.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/CS392.dir/hw4/maxfile.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/hw4/maxfile.c.o -MF CMakeFiles/CS392.dir/hw4/maxfile.c.o.d -o CMakeFiles/CS392.dir/hw4/maxfile.c.o -c /Users/joenguyen/CS392/hw4/maxfile.c

CMakeFiles/CS392.dir/hw4/maxfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/hw4/maxfile.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/hw4/maxfile.c > CMakeFiles/CS392.dir/hw4/maxfile.c.i

CMakeFiles/CS392.dir/hw4/maxfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/hw4/maxfile.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/hw4/maxfile.c -o CMakeFiles/CS392.dir/hw4/maxfile.c.s

CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o: /Users/joenguyen/CS392/labs/lab5/fork_intro.c
CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o -MF CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o.d -o CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o -c /Users/joenguyen/CS392/labs/lab5/fork_intro.c

CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/labs/lab5/fork_intro.c > CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.i

CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/labs/lab5/fork_intro.c -o CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.s

CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o: /Users/joenguyen/CS392/labs/lab5/lab5_fork.c
CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o -MF CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o.d -o CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o -c /Users/joenguyen/CS392/labs/lab5/lab5_fork.c

CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/labs/lab5/lab5_fork.c > CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.i

CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/labs/lab5/lab5_fork.c -o CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.s

CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o: /Users/joenguyen/CS392/labs/lab2_fn_pointers\ (1).c
CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT "CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o" -MF "CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o.d" -o "CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o" -c "/Users/joenguyen/CS392/labs/lab2_fn_pointers (1).c"

CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/joenguyen/CS392/labs/lab2_fn_pointers (1).c" > "CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.i"

CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/joenguyen/CS392/labs/lab2_fn_pointers (1).c" -o "CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.s"

CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o: /Users/joenguyen/CS392/labs/lab2_fn_pointers.c
CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o -MF CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o.d -o CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o -c /Users/joenguyen/CS392/labs/lab2_fn_pointers.c

CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/labs/lab2_fn_pointers.c > CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.i

CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/labs/lab2_fn_pointers.c -o CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.s

CMakeFiles/CS392.dir/labs/lab3_files.c.o: CMakeFiles/CS392.dir/flags.make
CMakeFiles/CS392.dir/labs/lab3_files.c.o: /Users/joenguyen/CS392/labs/lab3_files.c
CMakeFiles/CS392.dir/labs/lab3_files.c.o: CMakeFiles/CS392.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/CS392.dir/labs/lab3_files.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CS392.dir/labs/lab3_files.c.o -MF CMakeFiles/CS392.dir/labs/lab3_files.c.o.d -o CMakeFiles/CS392.dir/labs/lab3_files.c.o -c /Users/joenguyen/CS392/labs/lab3_files.c

CMakeFiles/CS392.dir/labs/lab3_files.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/CS392.dir/labs/lab3_files.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/joenguyen/CS392/labs/lab3_files.c > CMakeFiles/CS392.dir/labs/lab3_files.c.i

CMakeFiles/CS392.dir/labs/lab3_files.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/CS392.dir/labs/lab3_files.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/joenguyen/CS392/labs/lab3_files.c -o CMakeFiles/CS392.dir/labs/lab3_files.c.s

# Object files for target CS392
CS392_OBJECTS = \
"CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o" \
"CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o" \
"CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o" \
"CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o" \
"CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o" \
"CMakeFiles/CS392.dir/hw3/submission/main.c.o" \
"CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o" \
"CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o" \
"CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o" \
"CMakeFiles/CS392.dir/hw3/main.c.o" \
"CMakeFiles/CS392.dir/hw3/oocmerge.c.o" \
"CMakeFiles/CS392.dir/hw3.2/main.c.o" \
"CMakeFiles/CS392.dir/hw4/maxfile.c.o" \
"CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o" \
"CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o" \
"CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o" \
"CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o" \
"CMakeFiles/CS392.dir/labs/lab3_files.c.o"

# External object files for target CS392
CS392_EXTERNAL_OBJECTS =

CS392: CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/bubble.c.o
CS392: CMakeFiles/CS392.dir/hw2/hw2_starter_code/submission/utils.c.o
CS392: CMakeFiles/CS392.dir/hw2/hw2_starter_code/bubble.c.o
CS392: CMakeFiles/CS392.dir/hw2/hw2_starter_code/main.c.o
CS392: CMakeFiles/CS392.dir/hw2/hw2_starter_code/utils.c.o
CS392: CMakeFiles/CS392.dir/hw3/submission/main.c.o
CS392: CMakeFiles/CS392.dir/hw3/submission/oocmerge.c.o
CS392: CMakeFiles/CS392.dir/hw3/submission2.o/main.c.o
CS392: CMakeFiles/CS392.dir/hw3/submission2.o/oocmerge.c.o
CS392: CMakeFiles/CS392.dir/hw3/main.c.o
CS392: CMakeFiles/CS392.dir/hw3/oocmerge.c.o
CS392: CMakeFiles/CS392.dir/hw3.2/main.c.o
CS392: CMakeFiles/CS392.dir/hw4/maxfile.c.o
CS392: CMakeFiles/CS392.dir/labs/lab5/fork_intro.c.o
CS392: CMakeFiles/CS392.dir/labs/lab5/lab5_fork.c.o
CS392: CMakeFiles/CS392.dir/labs/lab2_fn_pointers_(1).c.o
CS392: CMakeFiles/CS392.dir/labs/lab2_fn_pointers.c.o
CS392: CMakeFiles/CS392.dir/labs/lab3_files.c.o
CS392: CMakeFiles/CS392.dir/build.make
CS392: CMakeFiles/CS392.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/joenguyen/CS392/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking C executable CS392"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CS392.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS392.dir/build: CS392
.PHONY : CMakeFiles/CS392.dir/build

CMakeFiles/CS392.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CS392.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CS392.dir/clean

CMakeFiles/CS392.dir/depend:
	cd /Users/joenguyen/CS392/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joenguyen/CS392 /Users/joenguyen/CS392 /Users/joenguyen/CS392/cmake-build-debug /Users/joenguyen/CS392/cmake-build-debug /Users/joenguyen/CS392/cmake-build-debug/CMakeFiles/CS392.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CS392.dir/depend
