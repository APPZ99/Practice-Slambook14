# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/appz/Practice-Slambook14/Book14/ch4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/appz/Practice-Slambook14/Book14/ch4/build

# Include any dependencies generated for this target.
include CMakeFiles/UseSophus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UseSophus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UseSophus.dir/flags.make

CMakeFiles/UseSophus.dir/use_sophus.cpp.o: CMakeFiles/UseSophus.dir/flags.make
CMakeFiles/UseSophus.dir/use_sophus.cpp.o: ../use_sophus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/appz/Practice-Slambook14/Book14/ch4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UseSophus.dir/use_sophus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UseSophus.dir/use_sophus.cpp.o -c /home/appz/Practice-Slambook14/Book14/ch4/use_sophus.cpp

CMakeFiles/UseSophus.dir/use_sophus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UseSophus.dir/use_sophus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/appz/Practice-Slambook14/Book14/ch4/use_sophus.cpp > CMakeFiles/UseSophus.dir/use_sophus.cpp.i

CMakeFiles/UseSophus.dir/use_sophus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UseSophus.dir/use_sophus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/appz/Practice-Slambook14/Book14/ch4/use_sophus.cpp -o CMakeFiles/UseSophus.dir/use_sophus.cpp.s

CMakeFiles/UseSophus.dir/use_sophus.cpp.o.requires:

.PHONY : CMakeFiles/UseSophus.dir/use_sophus.cpp.o.requires

CMakeFiles/UseSophus.dir/use_sophus.cpp.o.provides: CMakeFiles/UseSophus.dir/use_sophus.cpp.o.requires
	$(MAKE) -f CMakeFiles/UseSophus.dir/build.make CMakeFiles/UseSophus.dir/use_sophus.cpp.o.provides.build
.PHONY : CMakeFiles/UseSophus.dir/use_sophus.cpp.o.provides

CMakeFiles/UseSophus.dir/use_sophus.cpp.o.provides.build: CMakeFiles/UseSophus.dir/use_sophus.cpp.o


# Object files for target UseSophus
UseSophus_OBJECTS = \
"CMakeFiles/UseSophus.dir/use_sophus.cpp.o"

# External object files for target UseSophus
UseSophus_EXTERNAL_OBJECTS =

UseSophus: CMakeFiles/UseSophus.dir/use_sophus.cpp.o
UseSophus: CMakeFiles/UseSophus.dir/build.make
UseSophus: CMakeFiles/UseSophus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/appz/Practice-Slambook14/Book14/ch4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UseSophus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UseSophus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UseSophus.dir/build: UseSophus

.PHONY : CMakeFiles/UseSophus.dir/build

CMakeFiles/UseSophus.dir/requires: CMakeFiles/UseSophus.dir/use_sophus.cpp.o.requires

.PHONY : CMakeFiles/UseSophus.dir/requires

CMakeFiles/UseSophus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UseSophus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UseSophus.dir/clean

CMakeFiles/UseSophus.dir/depend:
	cd /home/appz/Practice-Slambook14/Book14/ch4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/appz/Practice-Slambook14/Book14/ch4 /home/appz/Practice-Slambook14/Book14/ch4 /home/appz/Practice-Slambook14/Book14/ch4/build /home/appz/Practice-Slambook14/Book14/ch4/build /home/appz/Practice-Slambook14/Book14/ch4/build/CMakeFiles/UseSophus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UseSophus.dir/depend

