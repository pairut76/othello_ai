# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/ics46/projects/proj2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ics46/projects/proj2/out

# Include any dependencies generated for this target.
include CMakeFiles/othelloaistudent.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/othelloaistudent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/othelloaistudent.dir/flags.make

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o: CMakeFiles/othelloaistudent.dir/flags.make
CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o: ../core/AImove.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ics46/projects/proj2/out/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o -c /home/ics46/projects/proj2/core/AImove.cpp

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/othelloaistudent.dir/core/AImove.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ics46/projects/proj2/core/AImove.cpp > CMakeFiles/othelloaistudent.dir/core/AImove.cpp.i

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/othelloaistudent.dir/core/AImove.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ics46/projects/proj2/core/AImove.cpp -o CMakeFiles/othelloaistudent.dir/core/AImove.cpp.s

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.requires:
.PHONY : CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.requires

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.provides: CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.requires
	$(MAKE) -f CMakeFiles/othelloaistudent.dir/build.make CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.provides.build
.PHONY : CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.provides

CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.provides.build: CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o

# Object files for target othelloaistudent
othelloaistudent_OBJECTS = \
"CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o"

# External object files for target othelloaistudent
othelloaistudent_EXTERNAL_OBJECTS =

lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o
lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/build.make
lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library lib/libothelloaistudent.a"
	$(CMAKE_COMMAND) -P CMakeFiles/othelloaistudent.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/othelloaistudent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/othelloaistudent.dir/build: lib/libothelloaistudent.a
.PHONY : CMakeFiles/othelloaistudent.dir/build

CMakeFiles/othelloaistudent.dir/requires: CMakeFiles/othelloaistudent.dir/core/AImove.cpp.o.requires
.PHONY : CMakeFiles/othelloaistudent.dir/requires

CMakeFiles/othelloaistudent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/othelloaistudent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/othelloaistudent.dir/clean

CMakeFiles/othelloaistudent.dir/depend:
	cd /home/ics46/projects/proj2/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ics46/projects/proj2 /home/ics46/projects/proj2 /home/ics46/projects/proj2/out /home/ics46/projects/proj2/out /home/ics46/projects/proj2/out/CMakeFiles/othelloaistudent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/othelloaistudent.dir/depend

