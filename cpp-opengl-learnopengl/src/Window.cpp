#include <Window.hpp>

Window::Window(int width, int height, const char* title) 
: m_width(width),
  m_height(height),
  m_title(title) {
  if (!glfwInit()) {
    std::cout << "GLFW INIT FAILED" << std::endl;
    exit(1);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
  
  if (m_window == NULL) {
    std::cout << "CANNNOT CREATE GLFW WINDOW" << std::endl;
    exit(1);
  }

  glfwMakeContextCurrent(m_window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "FAILED TO LOAD OPENGL FUNCTION" << std::endl;
    exit(1);
  }

  glViewport(0, 0, m_width, m_height);

  this->m_windowcamera = new Camera(PROJECTION::ORTHOGRAPHIC, m_width, m_height, 0.1f, 100.0f, glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f));
}

Window::~Window() {

}

bool Window::IsOpen() {
  return !glfwWindowShouldClose(m_window);
}

void Window::Display() {
  glfwSwapBuffers(m_window);
}

void Window::SetCamera(Camera& camera) {
  delete m_windowcamera;
  this->m_windowcamera = &camera;
}