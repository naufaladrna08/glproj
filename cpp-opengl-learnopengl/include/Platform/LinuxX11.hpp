#ifndef LINUX_HPP
#define LINUX_HPP
#include <String.hpp>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <stdbool.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <glad/gl.h>
#include <glad/glx.h>
#include <Logger.hpp>
#include <Event.hpp>
#include <xcb/xcb.h>
#include <X11/keysymdef.h>

class OS {
  public: 
    OS(int width, int height, const char* title);
    ~OS();

    int Init();
    int CreateContext();
    int LoadOpenGL();
    int Close();
    int SwapBuffers();

    int PollEvents();
    Tridme::EventType GetHandler();
    
    /* Event Handlers */
    bool X11GetKey(int key);
    int GetKeyCode();
    Tridme::MouseEvent GetMouseEvent();
    void DoWarpPointer(double xpos, double ypos);
    void SetCursorPointer(double x, double y);

    inline String GetName() { return "GNU/Linux or Unix with X11"; }
    inline Display* GetDisplay() { return this->m_display; }
    inline Window GetWindow() { return m_window; }
    inline unsigned long X11GetTIme() { return m_xev.xproperty.time; }
    
    void X11SetPointerMode(int mode);

  private:
    Display*     m_display;
    Window       m_window;
    Window*      m_root;
    Visual*      m_visual;
    Colormap     m_colormap;
    GLXFBConfig* m_fbc;
    GLXContext   m_context;
    XEvent       m_xev;

    int m_screen;
    int m_windowWidth, m_windowHeight;
    int m_mouseMode;
    const char* m_windowTitle;
    int m_virtualMousePosX = 0;
    int m_virtualMousePosY = 0;
    int m_lastMousePosX = 0;
    int m_lastMousePosY = 0;
};

#endif