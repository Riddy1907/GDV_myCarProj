# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/car_scene_code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/car_scene_code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/car_scene_code.dir/flags.make

CMakeFiles/car_scene_code.dir/car.cpp.o: CMakeFiles/car_scene_code.dir/flags.make
CMakeFiles/car_scene_code.dir/car.cpp.o: ../car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/car_scene_code.dir/car.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/car_scene_code.dir/car.cpp.o -c /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/car.cpp

CMakeFiles/car_scene_code.dir/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/car_scene_code.dir/car.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/car.cpp > CMakeFiles/car_scene_code.dir/car.cpp.i

CMakeFiles/car_scene_code.dir/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/car_scene_code.dir/car.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/car.cpp -o CMakeFiles/car_scene_code.dir/car.cpp.s

CMakeFiles/car_scene_code.dir/main.cpp.o: CMakeFiles/car_scene_code.dir/flags.make
CMakeFiles/car_scene_code.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/car_scene_code.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/car_scene_code.dir/main.cpp.o -c /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/main.cpp

CMakeFiles/car_scene_code.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/car_scene_code.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/main.cpp > CMakeFiles/car_scene_code.dir/main.cpp.i

CMakeFiles/car_scene_code.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/car_scene_code.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/main.cpp -o CMakeFiles/car_scene_code.dir/main.cpp.s

CMakeFiles/car_scene_code.dir/terrain.cpp.o: CMakeFiles/car_scene_code.dir/flags.make
CMakeFiles/car_scene_code.dir/terrain.cpp.o: ../terrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/car_scene_code.dir/terrain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/car_scene_code.dir/terrain.cpp.o -c /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/terrain.cpp

CMakeFiles/car_scene_code.dir/terrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/car_scene_code.dir/terrain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/terrain.cpp > CMakeFiles/car_scene_code.dir/terrain.cpp.i

CMakeFiles/car_scene_code.dir/terrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/car_scene_code.dir/terrain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/terrain.cpp -o CMakeFiles/car_scene_code.dir/terrain.cpp.s

# Object files for target car_scene_code
car_scene_code_OBJECTS = \
"CMakeFiles/car_scene_code.dir/car.cpp.o" \
"CMakeFiles/car_scene_code.dir/main.cpp.o" \
"CMakeFiles/car_scene_code.dir/terrain.cpp.o"

# External object files for target car_scene_code
car_scene_code_EXTERNAL_OBJECTS =

car_scene_code: CMakeFiles/car_scene_code.dir/car.cpp.o
car_scene_code: CMakeFiles/car_scene_code.dir/main.cpp.o
car_scene_code: CMakeFiles/car_scene_code.dir/terrain.cpp.o
car_scene_code: CMakeFiles/car_scene_code.dir/build.make
car_scene_code: CMakeFiles/car_scene_code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable car_scene_code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/car_scene_code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/car_scene_code.dir/build: car_scene_code

.PHONY : CMakeFiles/car_scene_code.dir/build

CMakeFiles/car_scene_code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/car_scene_code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/car_scene_code.dir/clean

CMakeFiles/car_scene_code.dir/depend:
	cd /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug /Users/ridvan/dev/CLionProjects/GDV_Projekte/car_scene_code/cmake-build-debug/CMakeFiles/car_scene_code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/car_scene_code.dir/depend
