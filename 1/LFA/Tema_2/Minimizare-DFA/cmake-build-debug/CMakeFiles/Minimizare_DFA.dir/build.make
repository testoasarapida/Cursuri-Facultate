# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "D:\IDEs\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDEs\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Dadada\git\LFA\Tema_2\Minimizare-DFA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Minimizare_DFA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Minimizare_DFA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Minimizare_DFA.dir/flags.make

CMakeFiles/Minimizare_DFA.dir/main.cpp.obj: CMakeFiles/Minimizare_DFA.dir/flags.make
CMakeFiles/Minimizare_DFA.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Minimizare_DFA.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Minimizare_DFA.dir\main.cpp.obj -c E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\main.cpp

CMakeFiles/Minimizare_DFA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Minimizare_DFA.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\main.cpp > CMakeFiles\Minimizare_DFA.dir\main.cpp.i

CMakeFiles/Minimizare_DFA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Minimizare_DFA.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\main.cpp -o CMakeFiles\Minimizare_DFA.dir\main.cpp.s

CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.requires

CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.provides: CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Minimizare_DFA.dir\build.make CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.provides

CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.provides.build: CMakeFiles/Minimizare_DFA.dir/main.cpp.obj


# Object files for target Minimizare_DFA
Minimizare_DFA_OBJECTS = \
"CMakeFiles/Minimizare_DFA.dir/main.cpp.obj"

# External object files for target Minimizare_DFA
Minimizare_DFA_EXTERNAL_OBJECTS =

Minimizare_DFA.exe: CMakeFiles/Minimizare_DFA.dir/main.cpp.obj
Minimizare_DFA.exe: CMakeFiles/Minimizare_DFA.dir/build.make
Minimizare_DFA.exe: CMakeFiles/Minimizare_DFA.dir/linklibs.rsp
Minimizare_DFA.exe: CMakeFiles/Minimizare_DFA.dir/objects1.rsp
Minimizare_DFA.exe: CMakeFiles/Minimizare_DFA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Minimizare_DFA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Minimizare_DFA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Minimizare_DFA.dir/build: Minimizare_DFA.exe

.PHONY : CMakeFiles/Minimizare_DFA.dir/build

CMakeFiles/Minimizare_DFA.dir/requires: CMakeFiles/Minimizare_DFA.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Minimizare_DFA.dir/requires

CMakeFiles/Minimizare_DFA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Minimizare_DFA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Minimizare_DFA.dir/clean

CMakeFiles/Minimizare_DFA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Dadada\git\LFA\Tema_2\Minimizare-DFA E:\Dadada\git\LFA\Tema_2\Minimizare-DFA E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug E:\Dadada\git\LFA\Tema_2\Minimizare-DFA\cmake-build-debug\CMakeFiles\Minimizare_DFA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Minimizare_DFA.dir/depend

