#ifndef LINUX_H
#define LINUX_H
#include <String.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <stdbool.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <glad/gl.h>
#include <glad/glx.h>
#include <Logger.h>
#include <Event.h>
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

    inline String GetName() { return "GNU/Linux or Unix with X11"; }
    inline Display* GetDisplay() { return m_display; }
    inline Window GetWindow() { return m_window; }

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
    const char* m_windowTitle;
};

#endif