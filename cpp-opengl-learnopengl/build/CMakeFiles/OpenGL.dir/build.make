# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/naufal/Documents/Projects/cpp-opengl-learnopengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/naufal/Documents/Projects/cpp-opengl-learnopengl/build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGL.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL.dir/flags.make

CMakeFiles/OpenGL.dir/main.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/main.cpp.o: ../main.cpp
CMakeFiles/OpenGL.dir/main.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/main.cpp.o -MF CMakeFiles/OpenGL.dir/main.cpp.o.d -o CMakeFiles/OpenGL.dir/main.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/main.cpp

CMakeFiles/OpenGL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/main.cpp > CMakeFiles/OpenGL.dir/main.cpp.i

CMakeFiles/OpenGL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/main.cpp -o CMakeFiles/OpenGL.dir/main.cpp.s

CMakeFiles/OpenGL.dir/src/glad.c.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/glad.c.o: ../src/glad.c
CMakeFiles/OpenGL.dir/src/glad.c.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGL.dir/src/glad.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/glad.c.o -MF CMakeFiles/OpenGL.dir/src/glad.c.o.d -o CMakeFiles/OpenGL.dir/src/glad.c.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/glad.c

CMakeFiles/OpenGL.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGL.dir/src/glad.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/glad.c > CMakeFiles/OpenGL.dir/src/glad.c.i

CMakeFiles/OpenGL.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGL.dir/src/glad.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/glad.c -o CMakeFiles/OpenGL.dir/src/glad.c.s

CMakeFiles/OpenGL.dir/src/Shader.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Shader.cpp.o: ../src/Shader.cpp
CMakeFiles/OpenGL.dir/src/Shader.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL.dir/src/Shader.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Shader.cpp.o -MF CMakeFiles/OpenGL.dir/src/Shader.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Shader.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Shader.cpp

CMakeFiles/OpenGL.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Shader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Shader.cpp > CMakeFiles/OpenGL.dir/src/Shader.cpp.i

CMakeFiles/OpenGL.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Shader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Shader.cpp -o CMakeFiles/OpenGL.dir/src/Shader.cpp.s

CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o: ../src/OpenGLBuffer.cpp
CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o -MF CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o.d -o CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/OpenGLBuffer.cpp

CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/OpenGLBuffer.cpp > CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.i

CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/OpenGLBuffer.cpp -o CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.s

CMakeFiles/OpenGL.dir/src/StbImage.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/StbImage.cpp.o: ../src/StbImage.cpp
CMakeFiles/OpenGL.dir/src/StbImage.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGL.dir/src/StbImage.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/StbImage.cpp.o -MF CMakeFiles/OpenGL.dir/src/StbImage.cpp.o.d -o CMakeFiles/OpenGL.dir/src/StbImage.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/StbImage.cpp

CMakeFiles/OpenGL.dir/src/StbImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/StbImage.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/StbImage.cpp > CMakeFiles/OpenGL.dir/src/StbImage.cpp.i

CMakeFiles/OpenGL.dir/src/StbImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/StbImage.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/StbImage.cpp -o CMakeFiles/OpenGL.dir/src/StbImage.cpp.s

CMakeFiles/OpenGL.dir/src/Texture.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Texture.cpp.o: ../src/Texture.cpp
CMakeFiles/OpenGL.dir/src/Texture.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGL.dir/src/Texture.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Texture.cpp.o -MF CMakeFiles/OpenGL.dir/src/Texture.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Texture.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Texture.cpp

CMakeFiles/OpenGL.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Texture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Texture.cpp > CMakeFiles/OpenGL.dir/src/Texture.cpp.i

CMakeFiles/OpenGL.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Texture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Texture.cpp -o CMakeFiles/OpenGL.dir/src/Texture.cpp.s

CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o: ../src/Rectangle.cpp
CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o -MF CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Rectangle.cpp

CMakeFiles/OpenGL.dir/src/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Rectangle.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Rectangle.cpp > CMakeFiles/OpenGL.dir/src/Rectangle.cpp.i

CMakeFiles/OpenGL.dir/src/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Rectangle.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Rectangle.cpp -o CMakeFiles/OpenGL.dir/src/Rectangle.cpp.s

CMakeFiles/OpenGL.dir/src/Window.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Window.cpp.o: ../src/Window.cpp
CMakeFiles/OpenGL.dir/src/Window.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OpenGL.dir/src/Window.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Window.cpp.o -MF CMakeFiles/OpenGL.dir/src/Window.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Window.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Window.cpp

CMakeFiles/OpenGL.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Window.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Window.cpp > CMakeFiles/OpenGL.dir/src/Window.cpp.i

CMakeFiles/OpenGL.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Window.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Window.cpp -o CMakeFiles/OpenGL.dir/src/Window.cpp.s

CMakeFiles/OpenGL.dir/src/Camera.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Camera.cpp.o: ../src/Camera.cpp
CMakeFiles/OpenGL.dir/src/Camera.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OpenGL.dir/src/Camera.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Camera.cpp.o -MF CMakeFiles/OpenGL.dir/src/Camera.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Camera.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Camera.cpp

CMakeFiles/OpenGL.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Camera.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Camera.cpp > CMakeFiles/OpenGL.dir/src/Camera.cpp.i

CMakeFiles/OpenGL.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Camera.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Camera.cpp -o CMakeFiles/OpenGL.dir/src/Camera.cpp.s

CMakeFiles/OpenGL.dir/src/Cube.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/Cube.cpp.o: ../src/Cube.cpp
CMakeFiles/OpenGL.dir/src/Cube.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/OpenGL.dir/src/Cube.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/Cube.cpp.o -MF CMakeFiles/OpenGL.dir/src/Cube.cpp.o.d -o CMakeFiles/OpenGL.dir/src/Cube.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Cube.cpp

CMakeFiles/OpenGL.dir/src/Cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/Cube.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Cube.cpp > CMakeFiles/OpenGL.dir/src/Cube.cpp.i

CMakeFiles/OpenGL.dir/src/Cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/Cube.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/Cube.cpp -o CMakeFiles/OpenGL.dir/src/Cube.cpp.s

CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o: ../src/ShaderCollection.cpp
CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o -MF CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o.d -o CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/ShaderCollection.cpp

CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/ShaderCollection.cpp > CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.i

CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/ShaderCollection.cpp -o CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.s

CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o: ../src/LightObjects/PointLight.cpp
CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o: CMakeFiles/OpenGL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o -MF CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o.d -o CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o -c /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/LightObjects/PointLight.cpp

CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/LightObjects/PointLight.cpp > CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.i

CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naufal/Documents/Projects/cpp-opengl-learnopengl/src/LightObjects/PointLight.cpp -o CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.s

# Object files for target OpenGL
OpenGL_OBJECTS = \
"CMakeFiles/OpenGL.dir/main.cpp.o" \
"CMakeFiles/OpenGL.dir/src/glad.c.o" \
"CMakeFiles/OpenGL.dir/src/Shader.cpp.o" \
"CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o" \
"CMakeFiles/OpenGL.dir/src/StbImage.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Texture.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Window.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Camera.cpp.o" \
"CMakeFiles/OpenGL.dir/src/Cube.cpp.o" \
"CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o" \
"CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o"

# External object files for target OpenGL
OpenGL_EXTERNAL_OBJECTS =

OpenGL: CMakeFiles/OpenGL.dir/main.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/glad.c.o
OpenGL: CMakeFiles/OpenGL.dir/src/Shader.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/OpenGLBuffer.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/StbImage.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Texture.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Rectangle.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Window.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Camera.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/Cube.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/ShaderCollection.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/src/LightObjects/PointLight.cpp.o
OpenGL: CMakeFiles/OpenGL.dir/build.make
OpenGL: CMakeFiles/OpenGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable OpenGL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL.dir/build: OpenGL
.PHONY : CMakeFiles/OpenGL.dir/build

CMakeFiles/OpenGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL.dir/clean

CMakeFiles/OpenGL.dir/depend:
	cd /home/naufal/Documents/Projects/cpp-opengl-learnopengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/naufal/Documents/Projects/cpp-opengl-learnopengl /home/naufal/Documents/Projects/cpp-opengl-learnopengl /home/naufal/Documents/Projects/cpp-opengl-learnopengl/build /home/naufal/Documents/Projects/cpp-opengl-learnopengl/build /home/naufal/Documents/Projects/cpp-opengl-learnopengl/build/CMakeFiles/OpenGL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL.dir/depend

