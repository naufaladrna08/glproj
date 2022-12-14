#ifndef WINDOW_H
#define WINDOW_H
#include <Logger.h>
#include <String.h>
#include <Event.h>

#ifdef __linux__
  #include <Platform/LinuxX11.h>
#endif

namespace Tridme {
  class Window {
    public:
      Window(int width, int height, const char* title);
      ~Window();

      bool IsOpen();
      void Display();
      void Close();
      int  PollEvents();

      Event GetHandler();

      inline OS* GetOSImplementation() { return this->m_os; }

      #ifdef __linux__
      inline KeyCode KEY(int keycode) { return XKeysymToKeycode(this->m_os->GetDisplay(), keycode); }
      #endif

    private:
      int m_x, m_y, m_width, m_height;
      const char* m_title;
      bool m_running;

      /*
       * OS Implementation
       * Contains required elements in every supported OS like Display
       * for X11; HWND, HINSTANCE for WinAPI.
       */
      OS* m_os;
  };
}

#endif 