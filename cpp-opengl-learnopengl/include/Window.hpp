#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <Logger.hpp>
#include <String.hpp>
#include <Event.hpp>
#include <Core/Timer.hpp>

#ifdef __linux__
  #include <Platform/LinuxX11.hpp>
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
      float GetTime();

      bool GetKey(int key);

      void SetPointerMode(int mode);

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
      Event* m_ev;
      Timer* m_time;
      double m_time_offset;
  };
}

#endif 