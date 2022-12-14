#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Camera.hpp>

class Window {
  public:
    Window(int width, int height, const char* title);
    ~Window();

    void SetCamera(Camera& camera);
    bool IsOpen();
    void Display();
    inline GLFWwindow* GetWindow() { return this->m_window; };

  private:
    int m_x, m_y, m_width, m_height;
    const char* m_title;
    bool m_running;
    GLFWwindow* m_window;
    
    Camera* m_windowcamera;
};

#endif 