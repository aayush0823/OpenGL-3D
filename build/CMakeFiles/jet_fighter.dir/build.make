# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build

# Include any dependencies generated for this target.
include CMakeFiles/jet_fighter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jet_fighter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jet_fighter.dir/flags.make

CMakeFiles/jet_fighter.dir/src/main.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jet_fighter.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/main.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/main.cpp

CMakeFiles/jet_fighter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/main.cpp > CMakeFiles/jet_fighter.dir/src/main.cpp.i

CMakeFiles/jet_fighter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/main.cpp -o CMakeFiles/jet_fighter.dir/src/main.cpp.s

CMakeFiles/jet_fighter.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/main.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/main.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/main.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/main.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/main.cpp.o


CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o: ../src/other_handlers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/other_handlers.cpp

CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/other_handlers.cpp > CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.i

CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/other_handlers.cpp -o CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.s

CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o


CMakeFiles/jet_fighter.dir/src/timer.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/timer.cpp.o: ../src/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/jet_fighter.dir/src/timer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/timer.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/timer.cpp

CMakeFiles/jet_fighter.dir/src/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/timer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/timer.cpp > CMakeFiles/jet_fighter.dir/src/timer.cpp.i

CMakeFiles/jet_fighter.dir/src/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/timer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/timer.cpp -o CMakeFiles/jet_fighter.dir/src/timer.cpp.s

CMakeFiles/jet_fighter.dir/src/timer.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/timer.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/timer.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/timer.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/timer.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/timer.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/timer.cpp.o


CMakeFiles/jet_fighter.dir/src/ball.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/ball.cpp.o: ../src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/jet_fighter.dir/src/ball.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/ball.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/ball.cpp

CMakeFiles/jet_fighter.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/ball.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/ball.cpp > CMakeFiles/jet_fighter.dir/src/ball.cpp.i

CMakeFiles/jet_fighter.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/ball.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/ball.cpp -o CMakeFiles/jet_fighter.dir/src/ball.cpp.s

CMakeFiles/jet_fighter.dir/src/ball.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/ball.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/ball.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/ball.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/ball.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/ball.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/ball.cpp.o


CMakeFiles/jet_fighter.dir/src/input.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/input.cpp.o: ../src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/jet_fighter.dir/src/input.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/input.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/input.cpp

CMakeFiles/jet_fighter.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/input.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/input.cpp > CMakeFiles/jet_fighter.dir/src/input.cpp.i

CMakeFiles/jet_fighter.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/input.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/input.cpp -o CMakeFiles/jet_fighter.dir/src/input.cpp.s

CMakeFiles/jet_fighter.dir/src/input.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/input.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/input.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/input.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/input.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/input.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/input.cpp.o


CMakeFiles/jet_fighter.dir/src/color.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/color.cpp.o: ../src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/jet_fighter.dir/src/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/color.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/color.cpp

CMakeFiles/jet_fighter.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/color.cpp > CMakeFiles/jet_fighter.dir/src/color.cpp.i

CMakeFiles/jet_fighter.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/color.cpp -o CMakeFiles/jet_fighter.dir/src/color.cpp.s

CMakeFiles/jet_fighter.dir/src/color.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/color.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/color.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/color.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/color.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/color.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/color.cpp.o


CMakeFiles/jet_fighter.dir/src/background.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/background.cpp.o: ../src/background.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/jet_fighter.dir/src/background.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/background.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/background.cpp

CMakeFiles/jet_fighter.dir/src/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/background.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/background.cpp > CMakeFiles/jet_fighter.dir/src/background.cpp.i

CMakeFiles/jet_fighter.dir/src/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/background.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/background.cpp -o CMakeFiles/jet_fighter.dir/src/background.cpp.s

CMakeFiles/jet_fighter.dir/src/background.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/background.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/background.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/background.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/background.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/background.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/background.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/background.cpp.o


CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o: ../src/nonedit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/nonedit.cpp

CMakeFiles/jet_fighter.dir/src/nonedit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/nonedit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/nonedit.cpp > CMakeFiles/jet_fighter.dir/src/nonedit.cpp.i

CMakeFiles/jet_fighter.dir/src/nonedit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/nonedit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/nonedit.cpp -o CMakeFiles/jet_fighter.dir/src/nonedit.cpp.s

CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o


CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o: ../src/dashboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/dashboard.cpp

CMakeFiles/jet_fighter.dir/src/dashboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/dashboard.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/dashboard.cpp > CMakeFiles/jet_fighter.dir/src/dashboard.cpp.i

CMakeFiles/jet_fighter.dir/src/dashboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/dashboard.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/dashboard.cpp -o CMakeFiles/jet_fighter.dir/src/dashboard.cpp.s

CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o


CMakeFiles/jet_fighter.dir/src/enemy.cpp.o: CMakeFiles/jet_fighter.dir/flags.make
CMakeFiles/jet_fighter.dir/src/enemy.cpp.o: ../src/enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/jet_fighter.dir/src/enemy.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jet_fighter.dir/src/enemy.cpp.o -c /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/enemy.cpp

CMakeFiles/jet_fighter.dir/src/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jet_fighter.dir/src/enemy.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/enemy.cpp > CMakeFiles/jet_fighter.dir/src/enemy.cpp.i

CMakeFiles/jet_fighter.dir/src/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jet_fighter.dir/src/enemy.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/src/enemy.cpp -o CMakeFiles/jet_fighter.dir/src/enemy.cpp.s

CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.requires:

.PHONY : CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.requires

CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.provides: CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.requires
	$(MAKE) -f CMakeFiles/jet_fighter.dir/build.make CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.provides.build
.PHONY : CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.provides

CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.provides.build: CMakeFiles/jet_fighter.dir/src/enemy.cpp.o


# Object files for target jet_fighter
jet_fighter_OBJECTS = \
"CMakeFiles/jet_fighter.dir/src/main.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/timer.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/ball.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/input.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/color.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/background.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o" \
"CMakeFiles/jet_fighter.dir/src/enemy.cpp.o"

# External object files for target jet_fighter
jet_fighter_EXTERNAL_OBJECTS =

jet_fighter: CMakeFiles/jet_fighter.dir/src/main.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/timer.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/ball.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/input.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/color.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/background.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/src/enemy.cpp.o
jet_fighter: CMakeFiles/jet_fighter.dir/build.make
jet_fighter: CMakeFiles/jet_fighter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable jet_fighter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jet_fighter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jet_fighter.dir/build: jet_fighter

.PHONY : CMakeFiles/jet_fighter.dir/build

CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/main.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/other_handlers.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/timer.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/ball.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/input.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/color.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/background.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/nonedit.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/dashboard.cpp.o.requires
CMakeFiles/jet_fighter.dir/requires: CMakeFiles/jet_fighter.dir/src/enemy.cpp.o.requires

.PHONY : CMakeFiles/jet_fighter.dir/requires

CMakeFiles/jet_fighter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jet_fighter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jet_fighter.dir/clean

CMakeFiles/jet_fighter.dir/depend:
	cd /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build /home/ayush/Downloads/Graphics/Assignments/OpenGL-3D/build/CMakeFiles/jet_fighter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jet_fighter.dir/depend
