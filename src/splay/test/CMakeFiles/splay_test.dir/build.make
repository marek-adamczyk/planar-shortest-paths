# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marro/mgr/planar/planar-shortest-paths

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marro/mgr/planar/planar-shortest-paths

# Include any dependencies generated for this target.
include src/splay/test/CMakeFiles/splay_test.dir/depend.make

# Include the progress variables for this target.
include src/splay/test/CMakeFiles/splay_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/splay/test/CMakeFiles/splay_test.dir/flags.make

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o: src/splay/test/CMakeFiles/splay_test.dir/flags.make
src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o: src/splay/test/splay_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marro/mgr/planar/planar-shortest-paths/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o"
	cd /home/marro/mgr/planar/planar-shortest-paths/src/splay/test && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/splay_test.dir/splay_test.c.o   -c /home/marro/mgr/planar/planar-shortest-paths/src/splay/test/splay_test.c

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splay_test.dir/splay_test.c.i"
	cd /home/marro/mgr/planar/planar-shortest-paths/src/splay/test && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/marro/mgr/planar/planar-shortest-paths/src/splay/test/splay_test.c > CMakeFiles/splay_test.dir/splay_test.c.i

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splay_test.dir/splay_test.c.s"
	cd /home/marro/mgr/planar/planar-shortest-paths/src/splay/test && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/marro/mgr/planar/planar-shortest-paths/src/splay/test/splay_test.c -o CMakeFiles/splay_test.dir/splay_test.c.s

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.requires:
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.requires

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.provides: src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.requires
	$(MAKE) -f src/splay/test/CMakeFiles/splay_test.dir/build.make src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.provides.build
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.provides

src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.provides.build: src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.provides.build

# Object files for target splay_test
splay_test_OBJECTS = \
"CMakeFiles/splay_test.dir/splay_test.c.o"

# External object files for target splay_test
splay_test_EXTERNAL_OBJECTS =

bin/test/splay_test: src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o
bin/test/splay_test: src/splay/libsplay.a
bin/test/splay_test: src/util/libutil.a
bin/test/splay_test: src/splay/test/CMakeFiles/splay_test.dir/build.make
bin/test/splay_test: src/splay/test/CMakeFiles/splay_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable ../../../bin/test/splay_test"
	cd /home/marro/mgr/planar/planar-shortest-paths/src/splay/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splay_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/splay/test/CMakeFiles/splay_test.dir/build: bin/test/splay_test
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/build

src/splay/test/CMakeFiles/splay_test.dir/requires: src/splay/test/CMakeFiles/splay_test.dir/splay_test.c.o.requires
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/requires

src/splay/test/CMakeFiles/splay_test.dir/clean:
	cd /home/marro/mgr/planar/planar-shortest-paths/src/splay/test && $(CMAKE_COMMAND) -P CMakeFiles/splay_test.dir/cmake_clean.cmake
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/clean

src/splay/test/CMakeFiles/splay_test.dir/depend:
	cd /home/marro/mgr/planar/planar-shortest-paths && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marro/mgr/planar/planar-shortest-paths /home/marro/mgr/planar/planar-shortest-paths/src/splay/test /home/marro/mgr/planar/planar-shortest-paths /home/marro/mgr/planar/planar-shortest-paths/src/splay/test /home/marro/mgr/planar/planar-shortest-paths/src/splay/test/CMakeFiles/splay_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/splay/test/CMakeFiles/splay_test.dir/depend

