# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anekin/Desktop/ItsLit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anekin/Desktop/ItsLit

# Include any dependencies generated for this target.
include CMakeFiles/its_lit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/its_lit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/its_lit.dir/flags.make

CMakeFiles/its_lit.dir/its_lit.cpp.o: CMakeFiles/its_lit.dir/flags.make
CMakeFiles/its_lit.dir/its_lit.cpp.o: its_lit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anekin/Desktop/ItsLit/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/its_lit.dir/its_lit.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/its_lit.dir/its_lit.cpp.o -c /Users/anekin/Desktop/ItsLit/its_lit.cpp

CMakeFiles/its_lit.dir/its_lit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/its_lit.dir/its_lit.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anekin/Desktop/ItsLit/its_lit.cpp > CMakeFiles/its_lit.dir/its_lit.cpp.i

CMakeFiles/its_lit.dir/its_lit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/its_lit.dir/its_lit.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anekin/Desktop/ItsLit/its_lit.cpp -o CMakeFiles/its_lit.dir/its_lit.cpp.s

CMakeFiles/its_lit.dir/its_lit.cpp.o.requires:

.PHONY : CMakeFiles/its_lit.dir/its_lit.cpp.o.requires

CMakeFiles/its_lit.dir/its_lit.cpp.o.provides: CMakeFiles/its_lit.dir/its_lit.cpp.o.requires
	$(MAKE) -f CMakeFiles/its_lit.dir/build.make CMakeFiles/its_lit.dir/its_lit.cpp.o.provides.build
.PHONY : CMakeFiles/its_lit.dir/its_lit.cpp.o.provides

CMakeFiles/its_lit.dir/its_lit.cpp.o.provides.build: CMakeFiles/its_lit.dir/its_lit.cpp.o


# Object files for target its_lit
its_lit_OBJECTS = \
"CMakeFiles/its_lit.dir/its_lit.cpp.o"

# External object files for target its_lit
its_lit_EXTERNAL_OBJECTS =

its_lit: CMakeFiles/its_lit.dir/its_lit.cpp.o
its_lit: CMakeFiles/its_lit.dir/build.make
its_lit: /usr/local/lib/libopencv_shape.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_stitching.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_superres.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_videostab.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_objdetect.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_calib3d.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_features2d.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_flann.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_highgui.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_ml.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_photo.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_video.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_videoio.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_imgcodecs.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_imgproc.3.2.0.dylib
its_lit: /usr/local/lib/libopencv_core.3.2.0.dylib
its_lit: CMakeFiles/its_lit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anekin/Desktop/ItsLit/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable its_lit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/its_lit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/its_lit.dir/build: its_lit

.PHONY : CMakeFiles/its_lit.dir/build

CMakeFiles/its_lit.dir/requires: CMakeFiles/its_lit.dir/its_lit.cpp.o.requires

.PHONY : CMakeFiles/its_lit.dir/requires

CMakeFiles/its_lit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/its_lit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/its_lit.dir/clean

CMakeFiles/its_lit.dir/depend:
	cd /Users/anekin/Desktop/ItsLit && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anekin/Desktop/ItsLit /Users/anekin/Desktop/ItsLit /Users/anekin/Desktop/ItsLit /Users/anekin/Desktop/ItsLit /Users/anekin/Desktop/ItsLit/CMakeFiles/its_lit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/its_lit.dir/depend

