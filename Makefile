# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/drake/DSYS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drake/DSYS

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/drake/DSYS/CMakeFiles /home/drake/DSYS/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/drake/DSYS/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named exe

# Build rule for target.
exe: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 exe
.PHONY : exe

# fast build rule for target.
exe/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/build
.PHONY : exe/fast

DAPP/main.o: DAPP/main.cpp.o

.PHONY : DAPP/main.o

# target to build an object file
DAPP/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DAPP/main.cpp.o
.PHONY : DAPP/main.cpp.o

DAPP/main.i: DAPP/main.cpp.i

.PHONY : DAPP/main.i

# target to preprocess a source file
DAPP/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DAPP/main.cpp.i
.PHONY : DAPP/main.cpp.i

DAPP/main.s: DAPP/main.cpp.s

.PHONY : DAPP/main.s

# target to generate assembly for a file
DAPP/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DAPP/main.cpp.s
.PHONY : DAPP/main.cpp.s

DSRC/DCLIENTTCP/DCLIENTTCP.o: DSRC/DCLIENTTCP/DCLIENTTCP.cpp.o

.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.o

# target to build an object file
DSRC/DCLIENTTCP/DCLIENTTCP.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTTCP/DCLIENTTCP.cpp.o
.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.cpp.o

DSRC/DCLIENTTCP/DCLIENTTCP.i: DSRC/DCLIENTTCP/DCLIENTTCP.cpp.i

.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.i

# target to preprocess a source file
DSRC/DCLIENTTCP/DCLIENTTCP.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTTCP/DCLIENTTCP.cpp.i
.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.cpp.i

DSRC/DCLIENTTCP/DCLIENTTCP.s: DSRC/DCLIENTTCP/DCLIENTTCP.cpp.s

.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.s

# target to generate assembly for a file
DSRC/DCLIENTTCP/DCLIENTTCP.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTTCP/DCLIENTTCP.cpp.s
.PHONY : DSRC/DCLIENTTCP/DCLIENTTCP.cpp.s

DSRC/DCLIENTUDP/DCLIENTUDP.o: DSRC/DCLIENTUDP/DCLIENTUDP.cpp.o

.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.o

# target to build an object file
DSRC/DCLIENTUDP/DCLIENTUDP.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTUDP/DCLIENTUDP.cpp.o
.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.cpp.o

DSRC/DCLIENTUDP/DCLIENTUDP.i: DSRC/DCLIENTUDP/DCLIENTUDP.cpp.i

.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.i

# target to preprocess a source file
DSRC/DCLIENTUDP/DCLIENTUDP.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTUDP/DCLIENTUDP.cpp.i
.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.cpp.i

DSRC/DCLIENTUDP/DCLIENTUDP.s: DSRC/DCLIENTUDP/DCLIENTUDP.cpp.s

.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.s

# target to generate assembly for a file
DSRC/DCLIENTUDP/DCLIENTUDP.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DCLIENTUDP/DCLIENTUDP.cpp.s
.PHONY : DSRC/DCLIENTUDP/DCLIENTUDP.cpp.s

DSRC/DGLUTWINDOW/DGLUTWINDOW.o: DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.o

.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.o

# target to build an object file
DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.o
.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.o

DSRC/DGLUTWINDOW/DGLUTWINDOW.i: DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.i

.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.i

# target to preprocess a source file
DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.i
.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.i

DSRC/DGLUTWINDOW/DGLUTWINDOW.s: DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.s

.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.s

# target to generate assembly for a file
DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.s
.PHONY : DSRC/DGLUTWINDOW/DGLUTWINDOW.cpp.s

DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.o: DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.o

.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.o

# target to build an object file
DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.o
.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.o

DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.i: DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.i

.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.i

# target to preprocess a source file
DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.i
.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.i

DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.s: DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.s

.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.s

# target to generate assembly for a file
DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.s
.PHONY : DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.cpp.s

DSRC/DGTKWINDOW/DGTKWINDOW.o: DSRC/DGTKWINDOW/DGTKWINDOW.cpp.o

.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.o

# target to build an object file
DSRC/DGTKWINDOW/DGTKWINDOW.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGTKWINDOW/DGTKWINDOW.cpp.o
.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.cpp.o

DSRC/DGTKWINDOW/DGTKWINDOW.i: DSRC/DGTKWINDOW/DGTKWINDOW.cpp.i

.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.i

# target to preprocess a source file
DSRC/DGTKWINDOW/DGTKWINDOW.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGTKWINDOW/DGTKWINDOW.cpp.i
.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.cpp.i

DSRC/DGTKWINDOW/DGTKWINDOW.s: DSRC/DGTKWINDOW/DGTKWINDOW.cpp.s

.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.s

# target to generate assembly for a file
DSRC/DGTKWINDOW/DGTKWINDOW.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DGTKWINDOW/DGTKWINDOW.cpp.s
.PHONY : DSRC/DGTKWINDOW/DGTKWINDOW.cpp.s

DSRC/DKINECT/DKINECT.o: DSRC/DKINECT/DKINECT.cpp.o

.PHONY : DSRC/DKINECT/DKINECT.o

# target to build an object file
DSRC/DKINECT/DKINECT.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DKINECT/DKINECT.cpp.o
.PHONY : DSRC/DKINECT/DKINECT.cpp.o

DSRC/DKINECT/DKINECT.i: DSRC/DKINECT/DKINECT.cpp.i

.PHONY : DSRC/DKINECT/DKINECT.i

# target to preprocess a source file
DSRC/DKINECT/DKINECT.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DKINECT/DKINECT.cpp.i
.PHONY : DSRC/DKINECT/DKINECT.cpp.i

DSRC/DKINECT/DKINECT.s: DSRC/DKINECT/DKINECT.cpp.s

.PHONY : DSRC/DKINECT/DKINECT.s

# target to generate assembly for a file
DSRC/DKINECT/DKINECT.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DKINECT/DKINECT.cpp.s
.PHONY : DSRC/DKINECT/DKINECT.cpp.s

DSRC/DML/DML.o: DSRC/DML/DML.cpp.o

.PHONY : DSRC/DML/DML.o

# target to build an object file
DSRC/DML/DML.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DML.cpp.o
.PHONY : DSRC/DML/DML.cpp.o

DSRC/DML/DML.i: DSRC/DML/DML.cpp.i

.PHONY : DSRC/DML/DML.i

# target to preprocess a source file
DSRC/DML/DML.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DML.cpp.i
.PHONY : DSRC/DML/DML.cpp.i

DSRC/DML/DML.s: DSRC/DML/DML.cpp.s

.PHONY : DSRC/DML/DML.s

# target to generate assembly for a file
DSRC/DML/DML.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DML.cpp.s
.PHONY : DSRC/DML/DML.cpp.s

DSRC/DML/DOP.o: DSRC/DML/DOP.cpp.o

.PHONY : DSRC/DML/DOP.o

# target to build an object file
DSRC/DML/DOP.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DOP.cpp.o
.PHONY : DSRC/DML/DOP.cpp.o

DSRC/DML/DOP.i: DSRC/DML/DOP.cpp.i

.PHONY : DSRC/DML/DOP.i

# target to preprocess a source file
DSRC/DML/DOP.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DOP.cpp.i
.PHONY : DSRC/DML/DOP.cpp.i

DSRC/DML/DOP.s: DSRC/DML/DOP.cpp.s

.PHONY : DSRC/DML/DOP.s

# target to generate assembly for a file
DSRC/DML/DOP.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DML/DOP.cpp.s
.PHONY : DSRC/DML/DOP.cpp.s

DSRC/DNETWORK/DNETWORK.o: DSRC/DNETWORK/DNETWORK.cpp.o

.PHONY : DSRC/DNETWORK/DNETWORK.o

# target to build an object file
DSRC/DNETWORK/DNETWORK.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DNETWORK/DNETWORK.cpp.o
.PHONY : DSRC/DNETWORK/DNETWORK.cpp.o

DSRC/DNETWORK/DNETWORK.i: DSRC/DNETWORK/DNETWORK.cpp.i

.PHONY : DSRC/DNETWORK/DNETWORK.i

# target to preprocess a source file
DSRC/DNETWORK/DNETWORK.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DNETWORK/DNETWORK.cpp.i
.PHONY : DSRC/DNETWORK/DNETWORK.cpp.i

DSRC/DNETWORK/DNETWORK.s: DSRC/DNETWORK/DNETWORK.cpp.s

.PHONY : DSRC/DNETWORK/DNETWORK.s

# target to generate assembly for a file
DSRC/DNETWORK/DNETWORK.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DNETWORK/DNETWORK.cpp.s
.PHONY : DSRC/DNETWORK/DNETWORK.cpp.s

DSRC/DOBJ/DOBJ.o: DSRC/DOBJ/DOBJ.cpp.o

.PHONY : DSRC/DOBJ/DOBJ.o

# target to build an object file
DSRC/DOBJ/DOBJ.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DOBJ/DOBJ.cpp.o
.PHONY : DSRC/DOBJ/DOBJ.cpp.o

DSRC/DOBJ/DOBJ.i: DSRC/DOBJ/DOBJ.cpp.i

.PHONY : DSRC/DOBJ/DOBJ.i

# target to preprocess a source file
DSRC/DOBJ/DOBJ.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DOBJ/DOBJ.cpp.i
.PHONY : DSRC/DOBJ/DOBJ.cpp.i

DSRC/DOBJ/DOBJ.s: DSRC/DOBJ/DOBJ.cpp.s

.PHONY : DSRC/DOBJ/DOBJ.s

# target to generate assembly for a file
DSRC/DOBJ/DOBJ.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DOBJ/DOBJ.cpp.s
.PHONY : DSRC/DOBJ/DOBJ.cpp.s

DSRC/DSERVERTCP/DSERVERTCP.o: DSRC/DSERVERTCP/DSERVERTCP.cpp.o

.PHONY : DSRC/DSERVERTCP/DSERVERTCP.o

# target to build an object file
DSRC/DSERVERTCP/DSERVERTCP.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERTCP/DSERVERTCP.cpp.o
.PHONY : DSRC/DSERVERTCP/DSERVERTCP.cpp.o

DSRC/DSERVERTCP/DSERVERTCP.i: DSRC/DSERVERTCP/DSERVERTCP.cpp.i

.PHONY : DSRC/DSERVERTCP/DSERVERTCP.i

# target to preprocess a source file
DSRC/DSERVERTCP/DSERVERTCP.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERTCP/DSERVERTCP.cpp.i
.PHONY : DSRC/DSERVERTCP/DSERVERTCP.cpp.i

DSRC/DSERVERTCP/DSERVERTCP.s: DSRC/DSERVERTCP/DSERVERTCP.cpp.s

.PHONY : DSRC/DSERVERTCP/DSERVERTCP.s

# target to generate assembly for a file
DSRC/DSERVERTCP/DSERVERTCP.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERTCP/DSERVERTCP.cpp.s
.PHONY : DSRC/DSERVERTCP/DSERVERTCP.cpp.s

DSRC/DSERVERUDP/DSERVERUDP.o: DSRC/DSERVERUDP/DSERVERUDP.cpp.o

.PHONY : DSRC/DSERVERUDP/DSERVERUDP.o

# target to build an object file
DSRC/DSERVERUDP/DSERVERUDP.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERUDP/DSERVERUDP.cpp.o
.PHONY : DSRC/DSERVERUDP/DSERVERUDP.cpp.o

DSRC/DSERVERUDP/DSERVERUDP.i: DSRC/DSERVERUDP/DSERVERUDP.cpp.i

.PHONY : DSRC/DSERVERUDP/DSERVERUDP.i

# target to preprocess a source file
DSRC/DSERVERUDP/DSERVERUDP.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERUDP/DSERVERUDP.cpp.i
.PHONY : DSRC/DSERVERUDP/DSERVERUDP.cpp.i

DSRC/DSERVERUDP/DSERVERUDP.s: DSRC/DSERVERUDP/DSERVERUDP.cpp.s

.PHONY : DSRC/DSERVERUDP/DSERVERUDP.s

# target to generate assembly for a file
DSRC/DSERVERUDP/DSERVERUDP.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/exe.dir/build.make CMakeFiles/exe.dir/DSRC/DSERVERUDP/DSERVERUDP.cpp.s
.PHONY : DSRC/DSERVERUDP/DSERVERUDP.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... exe"
	@echo "... DAPP/main.o"
	@echo "... DAPP/main.i"
	@echo "... DAPP/main.s"
	@echo "... DSRC/DCLIENTTCP/DCLIENTTCP.o"
	@echo "... DSRC/DCLIENTTCP/DCLIENTTCP.i"
	@echo "... DSRC/DCLIENTTCP/DCLIENTTCP.s"
	@echo "... DSRC/DCLIENTUDP/DCLIENTUDP.o"
	@echo "... DSRC/DCLIENTUDP/DCLIENTUDP.i"
	@echo "... DSRC/DCLIENTUDP/DCLIENTUDP.s"
	@echo "... DSRC/DGLUTWINDOW/DGLUTWINDOW.o"
	@echo "... DSRC/DGLUTWINDOW/DGLUTWINDOW.i"
	@echo "... DSRC/DGLUTWINDOW/DGLUTWINDOW.s"
	@echo "... DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.o"
	@echo "... DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.i"
	@echo "... DSRC/DGLUTWINDOW/GLUTHELPERFUNCTIONS.s"
	@echo "... DSRC/DGTKWINDOW/DGTKWINDOW.o"
	@echo "... DSRC/DGTKWINDOW/DGTKWINDOW.i"
	@echo "... DSRC/DGTKWINDOW/DGTKWINDOW.s"
	@echo "... DSRC/DKINECT/DKINECT.o"
	@echo "... DSRC/DKINECT/DKINECT.i"
	@echo "... DSRC/DKINECT/DKINECT.s"
	@echo "... DSRC/DML/DML.o"
	@echo "... DSRC/DML/DML.i"
	@echo "... DSRC/DML/DML.s"
	@echo "... DSRC/DML/DOP.o"
	@echo "... DSRC/DML/DOP.i"
	@echo "... DSRC/DML/DOP.s"
	@echo "... DSRC/DNETWORK/DNETWORK.o"
	@echo "... DSRC/DNETWORK/DNETWORK.i"
	@echo "... DSRC/DNETWORK/DNETWORK.s"
	@echo "... DSRC/DOBJ/DOBJ.o"
	@echo "... DSRC/DOBJ/DOBJ.i"
	@echo "... DSRC/DOBJ/DOBJ.s"
	@echo "... DSRC/DSERVERTCP/DSERVERTCP.o"
	@echo "... DSRC/DSERVERTCP/DSERVERTCP.i"
	@echo "... DSRC/DSERVERTCP/DSERVERTCP.s"
	@echo "... DSRC/DSERVERUDP/DSERVERUDP.o"
	@echo "... DSRC/DSERVERUDP/DSERVERUDP.i"
	@echo "... DSRC/DSERVERUDP/DSERVERUDP.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

