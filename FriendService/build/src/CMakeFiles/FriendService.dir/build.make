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
CMAKE_SOURCE_DIR = /home/ubuntu/ByteTalk/FriendService

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ByteTalk/FriendService/build

# Include any dependencies generated for this target.
include src/CMakeFiles/FriendService.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/FriendService.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/FriendService.dir/flags.make

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o: ../src/FriendServer.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/FriendServer.pb.cc.o -c /home/ubuntu/ByteTalk/FriendService/src/FriendServer.pb.cc

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/FriendServer.pb.cc.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/FriendServer.pb.cc > CMakeFiles/FriendService.dir/FriendServer.pb.cc.i

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/FriendServer.pb.cc.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/FriendServer.pb.cc -o CMakeFiles/FriendService.dir/FriendServer.pb.cc.s

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.requires

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.provides: src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.provides

src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.provides.build: src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o


src/CMakeFiles/FriendService.dir/FriendService.cpp.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/FriendService.cpp.o: ../src/FriendService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/FriendService.dir/FriendService.cpp.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/FriendService.cpp.o -c /home/ubuntu/ByteTalk/FriendService/src/FriendService.cpp

src/CMakeFiles/FriendService.dir/FriendService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/FriendService.cpp.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/FriendService.cpp > CMakeFiles/FriendService.dir/FriendService.cpp.i

src/CMakeFiles/FriendService.dir/FriendService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/FriendService.cpp.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/FriendService.cpp -o CMakeFiles/FriendService.dir/FriendService.cpp.s

src/CMakeFiles/FriendService.dir/FriendService.cpp.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/FriendService.cpp.o.requires

src/CMakeFiles/FriendService.dir/FriendService.cpp.o.provides: src/CMakeFiles/FriendService.dir/FriendService.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/FriendService.cpp.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/FriendService.cpp.o.provides

src/CMakeFiles/FriendService.dir/FriendService.cpp.o.provides.build: src/CMakeFiles/FriendService.dir/FriendService.cpp.o


src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o: ../src/FriendService.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/FriendService.pb.cc.o -c /home/ubuntu/ByteTalk/FriendService/src/FriendService.pb.cc

src/CMakeFiles/FriendService.dir/FriendService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/FriendService.pb.cc.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/FriendService.pb.cc > CMakeFiles/FriendService.dir/FriendService.pb.cc.i

src/CMakeFiles/FriendService.dir/FriendService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/FriendService.pb.cc.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/FriendService.pb.cc -o CMakeFiles/FriendService.dir/FriendService.pb.cc.s

src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.requires

src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.provides: src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.provides

src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.provides.build: src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o


src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o: ../src/LogServer.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/LogServer.pb.cc.o -c /home/ubuntu/ByteTalk/FriendService/src/LogServer.pb.cc

src/CMakeFiles/FriendService.dir/LogServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/LogServer.pb.cc.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/LogServer.pb.cc > CMakeFiles/FriendService.dir/LogServer.pb.cc.i

src/CMakeFiles/FriendService.dir/LogServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/LogServer.pb.cc.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/LogServer.pb.cc -o CMakeFiles/FriendService.dir/LogServer.pb.cc.s

src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.requires

src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.provides: src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.provides

src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.provides.build: src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o


src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o: ../src/ZooKeeperMatser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o -c /home/ubuntu/ByteTalk/FriendService/src/ZooKeeperMatser.cpp

src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/ZooKeeperMatser.cpp > CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.i

src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/ZooKeeperMatser.cpp -o CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.s

src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.requires

src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.provides: src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.provides

src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.provides.build: src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o


src/CMakeFiles/FriendService.dir/run.cpp.o: src/CMakeFiles/FriendService.dir/flags.make
src/CMakeFiles/FriendService.dir/run.cpp.o: ../src/run.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/FriendService.dir/run.cpp.o"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FriendService.dir/run.cpp.o -c /home/ubuntu/ByteTalk/FriendService/src/run.cpp

src/CMakeFiles/FriendService.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/run.cpp.i"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ByteTalk/FriendService/src/run.cpp > CMakeFiles/FriendService.dir/run.cpp.i

src/CMakeFiles/FriendService.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/run.cpp.s"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ByteTalk/FriendService/src/run.cpp -o CMakeFiles/FriendService.dir/run.cpp.s

src/CMakeFiles/FriendService.dir/run.cpp.o.requires:

.PHONY : src/CMakeFiles/FriendService.dir/run.cpp.o.requires

src/CMakeFiles/FriendService.dir/run.cpp.o.provides: src/CMakeFiles/FriendService.dir/run.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/FriendService.dir/build.make src/CMakeFiles/FriendService.dir/run.cpp.o.provides.build
.PHONY : src/CMakeFiles/FriendService.dir/run.cpp.o.provides

src/CMakeFiles/FriendService.dir/run.cpp.o.provides.build: src/CMakeFiles/FriendService.dir/run.cpp.o


# Object files for target FriendService
FriendService_OBJECTS = \
"CMakeFiles/FriendService.dir/FriendServer.pb.cc.o" \
"CMakeFiles/FriendService.dir/FriendService.cpp.o" \
"CMakeFiles/FriendService.dir/FriendService.pb.cc.o" \
"CMakeFiles/FriendService.dir/LogServer.pb.cc.o" \
"CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o" \
"CMakeFiles/FriendService.dir/run.cpp.o"

# External object files for target FriendService
FriendService_EXTERNAL_OBJECTS =

../bin/FriendService: src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/FriendService.cpp.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/run.cpp.o
../bin/FriendService: src/CMakeFiles/FriendService.dir/build.make
../bin/FriendService: src/CMakeFiles/FriendService.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ByteTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../bin/FriendService"
	cd /home/ubuntu/ByteTalk/FriendService/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FriendService.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/FriendService.dir/build: ../bin/FriendService

.PHONY : src/CMakeFiles/FriendService.dir/build

src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/FriendServer.pb.cc.o.requires
src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/FriendService.cpp.o.requires
src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/FriendService.pb.cc.o.requires
src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/LogServer.pb.cc.o.requires
src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/ZooKeeperMatser.cpp.o.requires
src/CMakeFiles/FriendService.dir/requires: src/CMakeFiles/FriendService.dir/run.cpp.o.requires

.PHONY : src/CMakeFiles/FriendService.dir/requires

src/CMakeFiles/FriendService.dir/clean:
	cd /home/ubuntu/ByteTalk/FriendService/build/src && $(CMAKE_COMMAND) -P CMakeFiles/FriendService.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/FriendService.dir/clean

src/CMakeFiles/FriendService.dir/depend:
	cd /home/ubuntu/ByteTalk/FriendService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ByteTalk/FriendService /home/ubuntu/ByteTalk/FriendService/src /home/ubuntu/ByteTalk/FriendService/build /home/ubuntu/ByteTalk/FriendService/build/src /home/ubuntu/ByteTalk/FriendService/build/src/CMakeFiles/FriendService.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/FriendService.dir/depend

