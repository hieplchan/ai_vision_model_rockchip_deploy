# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build

# Include any dependencies generated for this target.
include CMakeFiles/gstrkfacevectorize.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gstrkfacevectorize.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gstrkfacevectorize.dir/flags.make

CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o: CMakeFiles/gstrkfacevectorize.dir/flags.make
CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o: ../src/InsightFace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o -c /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/InsightFace.cpp

CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/InsightFace.cpp > CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.i

CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/InsightFace.cpp -o CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.s

CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o: CMakeFiles/gstrkfacevectorize.dir/flags.make
CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o: ../src/gstrkfacevectorize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o -c /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/gstrkfacevectorize.cpp

CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/gstrkfacevectorize.cpp > CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.i

CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/src/gstrkfacevectorize.cpp -o CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.s

# Object files for target gstrkfacevectorize
gstrkfacevectorize_OBJECTS = \
"CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o" \
"CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o"

# External object files for target gstrkfacevectorize
gstrkfacevectorize_EXTERNAL_OBJECTS =

libgstrkfacevectorize.so: CMakeFiles/gstrkfacevectorize.dir/src/InsightFace.cpp.o
libgstrkfacevectorize.so: CMakeFiles/gstrkfacevectorize.dir/src/gstrkfacevectorize.cpp.o
libgstrkfacevectorize.so: CMakeFiles/gstrkfacevectorize.dir/build.make
libgstrkfacevectorize.so: /usr/local/lib/libopencv_gapi.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_stitching.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_aruco.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_barcode.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_bgsegm.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_bioinspired.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_ccalib.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_dnn_superres.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_dpm.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_face.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_freetype.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_fuzzy.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_hfs.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_img_hash.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_intensity_transform.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_line_descriptor.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_mcc.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_quality.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_rapid.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_reg.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_rgbd.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_saliency.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_stereo.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_structured_light.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_superres.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_surface_matching.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_tracking.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_videostab.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_wechat_qrcode.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_xfeatures2d.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_xobjdetect.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_xphoto.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_shape.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_highgui.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_datasets.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_plot.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_text.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_ml.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_optflow.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_ximgproc.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_video.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_videoio.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_imgcodecs.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_objdetect.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_calib3d.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_dnn.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_features2d.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_flann.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_photo.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_imgproc.so.4.5.4
libgstrkfacevectorize.so: /usr/local/lib/libopencv_core.so.4.5.4
libgstrkfacevectorize.so: CMakeFiles/gstrkfacevectorize.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libgstrkfacevectorize.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gstrkfacevectorize.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gstrkfacevectorize.dir/build: libgstrkfacevectorize.so

.PHONY : CMakeFiles/gstrkfacevectorize.dir/build

CMakeFiles/gstrkfacevectorize.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gstrkfacevectorize.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gstrkfacevectorize.dir/clean

CMakeFiles/gstrkfacevectorize.dir/depend:
	cd /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build /home/rock/ai_vision_model_rockchip_deploy/source/gst-rkfacevectorize/build/CMakeFiles/gstrkfacevectorize.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gstrkfacevectorize.dir/depend

