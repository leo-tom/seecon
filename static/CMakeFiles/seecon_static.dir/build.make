# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/leo/src/seecon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/src/seecon

# Include any dependencies generated for this target.
include static/CMakeFiles/seecon_static.dir/depend.make

# Include the progress variables for this target.
include static/CMakeFiles/seecon_static.dir/progress.make

# Include the compile flags for this target's objects.
include static/CMakeFiles/seecon_static.dir/flags.make

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o: static/CMakeFiles/seecon_static.dir/flags.make
static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o: ArrayList.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/src/seecon/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/seecon_static.dir/__/ArrayList.c.o   -c /home/leo/src/seecon/ArrayList.c

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/seecon_static.dir/__/ArrayList.c.i"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/src/seecon/ArrayList.c > CMakeFiles/seecon_static.dir/__/ArrayList.c.i

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/seecon_static.dir/__/ArrayList.c.s"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/src/seecon/ArrayList.c -o CMakeFiles/seecon_static.dir/__/ArrayList.c.s

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.requires:
.PHONY : static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.requires

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.provides: static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.requires
	$(MAKE) -f static/CMakeFiles/seecon_static.dir/build.make static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.provides.build
.PHONY : static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.provides

static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.provides.build: static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o

static/CMakeFiles/seecon_static.dir/__/Map.c.o: static/CMakeFiles/seecon_static.dir/flags.make
static/CMakeFiles/seecon_static.dir/__/Map.c.o: Map.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/leo/src/seecon/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object static/CMakeFiles/seecon_static.dir/__/Map.c.o"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/seecon_static.dir/__/Map.c.o   -c /home/leo/src/seecon/Map.c

static/CMakeFiles/seecon_static.dir/__/Map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/seecon_static.dir/__/Map.c.i"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/leo/src/seecon/Map.c > CMakeFiles/seecon_static.dir/__/Map.c.i

static/CMakeFiles/seecon_static.dir/__/Map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/seecon_static.dir/__/Map.c.s"
	cd /home/leo/src/seecon/static && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/leo/src/seecon/Map.c -o CMakeFiles/seecon_static.dir/__/Map.c.s

static/CMakeFiles/seecon_static.dir/__/Map.c.o.requires:
.PHONY : static/CMakeFiles/seecon_static.dir/__/Map.c.o.requires

static/CMakeFiles/seecon_static.dir/__/Map.c.o.provides: static/CMakeFiles/seecon_static.dir/__/Map.c.o.requires
	$(MAKE) -f static/CMakeFiles/seecon_static.dir/build.make static/CMakeFiles/seecon_static.dir/__/Map.c.o.provides.build
.PHONY : static/CMakeFiles/seecon_static.dir/__/Map.c.o.provides

static/CMakeFiles/seecon_static.dir/__/Map.c.o.provides.build: static/CMakeFiles/seecon_static.dir/__/Map.c.o

# Object files for target seecon_static
seecon_static_OBJECTS = \
"CMakeFiles/seecon_static.dir/__/ArrayList.c.o" \
"CMakeFiles/seecon_static.dir/__/Map.c.o"

# External object files for target seecon_static
seecon_static_EXTERNAL_OBJECTS =

static/libseecon_static.a: static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o
static/libseecon_static.a: static/CMakeFiles/seecon_static.dir/__/Map.c.o
static/libseecon_static.a: static/CMakeFiles/seecon_static.dir/build.make
static/libseecon_static.a: static/CMakeFiles/seecon_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libseecon_static.a"
	cd /home/leo/src/seecon/static && $(CMAKE_COMMAND) -P CMakeFiles/seecon_static.dir/cmake_clean_target.cmake
	cd /home/leo/src/seecon/static && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seecon_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
static/CMakeFiles/seecon_static.dir/build: static/libseecon_static.a
.PHONY : static/CMakeFiles/seecon_static.dir/build

static/CMakeFiles/seecon_static.dir/requires: static/CMakeFiles/seecon_static.dir/__/ArrayList.c.o.requires
static/CMakeFiles/seecon_static.dir/requires: static/CMakeFiles/seecon_static.dir/__/Map.c.o.requires
.PHONY : static/CMakeFiles/seecon_static.dir/requires

static/CMakeFiles/seecon_static.dir/clean:
	cd /home/leo/src/seecon/static && $(CMAKE_COMMAND) -P CMakeFiles/seecon_static.dir/cmake_clean.cmake
.PHONY : static/CMakeFiles/seecon_static.dir/clean

static/CMakeFiles/seecon_static.dir/depend:
	cd /home/leo/src/seecon && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/src/seecon /home/leo/src/seecon/static /home/leo/src/seecon /home/leo/src/seecon/static /home/leo/src/seecon/static/CMakeFiles/seecon_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : static/CMakeFiles/seecon_static.dir/depend

