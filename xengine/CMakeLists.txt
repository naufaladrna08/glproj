cmake_minimum_required(VERSION 3.0.0)
project(XEngine VERSION 0.1.0)

include(CTest)
include_directories(include)
enable_testing()

add_executable(XEngine 
  main.cpp 
  src/gl.c 
  src/glx.c 
  src/Platform/LinuxX11.cpp 
  src/Logger.cpp 
  src/String.cpp
  src/Window.cpp
  src/Event.cpp
)
target_link_libraries(XEngine -lX11 -lGLU -lGL -lXext )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
