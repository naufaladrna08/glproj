#include <Window.hpp>

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

  /* Initialize core system */
  m_time = new Timer();
  m_time_offset = (double) m_time->GetCurrentTime();

  SetPointerMode(TRIDME_POINTER_MODE_SHOW);
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
  m_ev = new Event;
  m_ev->type  = m_os->GetHandler();
  m_ev->key   = m_os->GetKeyCode();
  m_ev->mouse = m_os->GetMouseEvent();
  m_ev->time  = (float) m_os->X11GetTIme();

  return *m_ev;
}

bool Tridme::Window::GetKey(int key) {
  #ifdef __linux__ 
    return m_os->X11GetKey(key);
  #endif

  return false;
}

float Tridme::Window::GetTime() {
  return (double) (m_time->GetCurrentTime() - m_time_offset);
}

void Tridme::Window::SetPointerMode(int mode) {
  #ifdef __linux__
    m_os->X11SetPointerMode(mode);
  #endif
}
