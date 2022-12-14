#include <Window.h>

Tridme::Window::Window(int width, int height, const char* title) 
: m_width(width),
  m_height(height),
  m_title(title) {
  /* Initialize Backend and Create Window */
  m_os = new OS(width, height, title);
  
  if (m_os->Init()) {
    LOG(INFO, "Initialize Tridme on %s", m_os->GetName());
  }

  /* Create Context */
  m_os->CreateContext();

  /* Load OpenGL */
  m_os->LoadOpenGL();
}

Tridme::Window::~Window() {
  this->m_os->Close();
}

bool Tridme::Window::IsOpen() {
  return this->m_running;
}

void Tridme::Window::Display() {
  this->m_os->SwapBuffers();
}

void Tridme::Window::Close() {
  this->m_running = false;
  LOG(INFO, "Tridme Engine Closed...");
}

int Tridme::Window::PollEvents() {
  return m_os->PollEvents();
}

Tridme::Event Tridme::Window::GetHandler() {
  Event event;

  event.type = m_os->GetHandler();
  event.keyCode = m_os->KeyCodeHandler();

  return event;
}
