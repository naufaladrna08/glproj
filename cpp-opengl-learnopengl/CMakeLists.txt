cmake_minimum_required(VERSION 3.0.0)
project(OpenGL VERSION 0.1.0)

include(CTest)
include_directories(include)
enable_testing()

add_executable (
  OpenGL 
  main.cpp 
  src/glad.c 
  src/Shader.cpp 
  src/OpenGLBuffer.cpp 
  src/StbImage.cpp 
  src/Texture.cpp 
  src/Rectangle.cpp
  src/Window.cpp
  src/Camera.cpp
  src/Cube.cpp
  src/ShaderCollection.cpp
  src/LightObjects/PointLight.cpp
)

target_link_libraries(OpenGL -lglfw3 -lGL -ldl -lX11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
