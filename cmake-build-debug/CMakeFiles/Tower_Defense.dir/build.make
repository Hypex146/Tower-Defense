# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/vlad_/cmake-3.20.6/bin/cmake

# The command to remove a file.
RM = /home/vlad_/cmake-3.20.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/f/programming/C++/labs_3_sem/Tower-Defense

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tower_Defense.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Tower_Defense.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tower_Defense.dir/flags.make

CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o: CMakeFiles/Tower_Defense.dir/flags.make
CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o: ../entities/allied/Tower.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o -c /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/Tower.cpp

CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/Tower.cpp > CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.i

CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/Tower.cpp -o CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.s

CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o: CMakeFiles/Tower_Defense.dir/flags.make
CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o: ../lib/my-lib/string/MyString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o -c /mnt/f/programming/C++/labs_3_sem/Tower-Defense/lib/my-lib/string/MyString.cpp

CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/programming/C++/labs_3_sem/Tower-Defense/lib/my-lib/string/MyString.cpp > CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.i

CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/programming/C++/labs_3_sem/Tower-Defense/lib/my-lib/string/MyString.cpp -o CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.s

CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o: CMakeFiles/Tower_Defense.dir/flags.make
CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o: ../entities/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o -c /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/Entity.cpp

CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/Entity.cpp > CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.i

CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/Entity.cpp -o CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.s

CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o: CMakeFiles/Tower_Defense.dir/flags.make
CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o: ../entities/allied/test_Tower.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o -c /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/test_Tower.cpp

CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/test_Tower.cpp > CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.i

CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/f/programming/C++/labs_3_sem/Tower-Defense/entities/allied/test_Tower.cpp -o CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.s

# Object files for target Tower_Defense
Tower_Defense_OBJECTS = \
"CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o" \
"CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o" \
"CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o" \
"CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o"

# External object files for target Tower_Defense
Tower_Defense_EXTERNAL_OBJECTS =

Tower_Defense: CMakeFiles/Tower_Defense.dir/entities/allied/Tower.cpp.o
Tower_Defense: CMakeFiles/Tower_Defense.dir/lib/my-lib/string/MyString.cpp.o
Tower_Defense: CMakeFiles/Tower_Defense.dir/entities/Entity.cpp.o
Tower_Defense: CMakeFiles/Tower_Defense.dir/entities/allied/test_Tower.cpp.o
Tower_Defense: CMakeFiles/Tower_Defense.dir/build.make
Tower_Defense: lib/libgtestd.a
Tower_Defense: lib/libgtest_maind.a
Tower_Defense: lib/libgtestd.a
Tower_Defense: CMakeFiles/Tower_Defense.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Tower_Defense"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tower_Defense.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tower_Defense.dir/build: Tower_Defense
.PHONY : CMakeFiles/Tower_Defense.dir/build

CMakeFiles/Tower_Defense.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tower_Defense.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tower_Defense.dir/clean

CMakeFiles/Tower_Defense.dir/depend:
	cd /mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/f/programming/C++/labs_3_sem/Tower-Defense /mnt/f/programming/C++/labs_3_sem/Tower-Defense /mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug /mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug /mnt/f/programming/C++/labs_3_sem/Tower-Defense/cmake-build-debug/CMakeFiles/Tower_Defense.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tower_Defense.dir/depend

