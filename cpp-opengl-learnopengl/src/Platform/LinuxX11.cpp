#include <Platform/LinuxX11.hpp>

OS::OS(int width, int height, const char* title) {
  m_windowWidth = width;
  m_windowHeight = height;
  m_windowTitle = title;
}

OS::~OS() {

}

int OS::Init() {
  m_display = XOpenDisplay(NULL);

  if (m_display == NULL) {
    LOG(LOG_TYPE::ERROR, "Cannot connect to the X Server\n");
    return 1;
  }

  m_screen   = DefaultScreen(m_display);
  m_root     = &RootWindow(m_display, m_screen);
  m_visual   = DefaultVisual(m_display, m_screen);
  m_colormap = XCreateColormap(m_display, *m_root, m_visual, AllocNone);
  
  XSetWindowAttributes attributes;
  attributes.event_mask = 
    ExposureMask | 
    KeyPressMask | 
    KeyReleaseMask | 
    ButtonPressMask | 
    ButtonReleaseMask |
    PointerMotionMask |
    PropertyChangeMask |
    FocusChangeMask;

  attributes.colormap = m_colormap;

  m_window = XCreateWindow(m_display, *m_root, 0, 0, m_windowWidth, m_windowHeight, 0,
    DefaultDepth(m_display, m_screen), InputOutput, m_visual,
    CWColormap | CWEventMask, &attributes);

  XMapWindow(m_display, m_window);
  XStoreName(m_display, m_window, m_windowTitle);

  if (!m_window) {
    LOG(ERROR, "Unable to create window\n");
    return 1;
  }

  return 0;
}

int OS::CreateContext() {
  int glx_version = gladLoaderLoadGLX(m_display, m_screen);
  if (!glx_version) {
    printf("Unable to load GLX.\n");
    return 1;
  }

  GLint visual_attributes[] = {
    GLX_RENDER_TYPE, GLX_RGBA_BIT,
    GLX_DOUBLEBUFFER, 1,
    None
  };

  int num_fbc = 0;
  m_fbc = glXChooseFBConfig(m_display, m_screen, visual_attributes, &num_fbc);
  GLint context_attributes[] = {
    GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
    GLX_CONTEXT_MINOR_VERSION_ARB, 3,
    GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
    None
  };

  m_context = glXCreateContextAttribsARB(m_display, m_fbc[0], NULL, 1, context_attributes);
  if (!m_context) {
    LOG(ERROR, "Unable to create OpenGL Context\n");
    return 1;
  }

  glXMakeCurrent(m_display, m_window, m_context);

  return 0;
}

int OS::LoadOpenGL() {
  int glx_version = gladLoaderLoadGLX(m_display, m_screen);
  int gl_version = gladLoaderLoadGL();

  if (!gl_version) {
    LOG(ERROR, "Unable to load OpenGL functions\n");
    return 1;
  }

  LOG(INFO, "Loaded GLX %d.%d and OpenGL %d.%d", 
    GLAD_VERSION_MAJOR(glx_version), 
    GLAD_VERSION_MINOR(glx_version), 
    GLAD_VERSION_MAJOR(gl_version), 
    GLAD_VERSION_MINOR(gl_version));

  XWindowAttributes gwa;
  XGetWindowAttributes(m_display, m_window, &gwa);
  glViewport(0, 0, gwa.width, gwa.height);
  glEnable(GL_DEPTH_TEST);

  return 0;
}

int OS::Close() {
  glXMakeCurrent(m_display, 0, 0);
  glXDestroyContext(m_display, m_context);

  XDestroyWindow(m_display, m_window);
  XFreeColormap(m_display, m_colormap);
  XCloseDisplay(m_display);

  gladLoaderUnloadGLX();

  return 0;
}

int OS::PollEvents() {
  return XPending(m_display);
}

Tridme::EventType OS::GetHandler() {
  XNextEvent(m_display, &m_xev);
  Tridme::EventType eventtype;

  switch (m_xev.type) {
    case ButtonPress:   eventtype = Tridme::EventType::EVENT_MOUSE_BUTTON_PRESSED; break;
    case ButtonRelease: eventtype = Tridme::EventType::EVENT_MOUSE_BUTTON_RELEASED; break;
    case KeyPress:      eventtype = Tridme::EventType::EVENT_KEYBOARD_PRESSED; break;
    case KeyRelease:    eventtype = Tridme::EventType::EVENT_KEYBOARD_RELEASED; break;
    case MotionNotify:  eventtype = Tridme::EventType::EVENT_MOUSE_MOTION; break;

    default: 
      eventtype = Tridme::EventType::UNHANDLED_INPUT;
  }

  return eventtype;
}

bool OS::X11GetKey(int key) {
  KeySym keysym = 0;

  switch (key) {
    case Tridme::Keyboard::TRIDME_KEY_0: keysym = XK_0; break;
    case Tridme::Keyboard::TRIDME_KEY_1: keysym = XK_1; break;
    case Tridme::Keyboard::TRIDME_KEY_2: keysym = XK_2; break;
    case Tridme::Keyboard::TRIDME_KEY_3: keysym = XK_3; break;
    case Tridme::Keyboard::TRIDME_KEY_4: keysym = XK_4; break;
    case Tridme::Keyboard::TRIDME_KEY_5: keysym = XK_5; break;
    case Tridme::Keyboard::TRIDME_KEY_6: keysym = XK_6; break;
    case Tridme::Keyboard::TRIDME_KEY_7: keysym = XK_7; break;
    case Tridme::Keyboard::TRIDME_KEY_8: keysym = XK_8; break;
    case Tridme::Keyboard::TRIDME_KEY_9: keysym = XK_9; break;
    case Tridme::Keyboard::TRIDME_KEY_A: keysym = XK_a; break;
    case Tridme::Keyboard::TRIDME_KEY_B: keysym = XK_b; break;
    case Tridme::Keyboard::TRIDME_KEY_C: keysym = XK_c; break;
    case Tridme::Keyboard::TRIDME_KEY_D: keysym = XK_d; break;
    case Tridme::Keyboard::TRIDME_KEY_E: keysym = XK_e; break;
    case Tridme::Keyboard::TRIDME_KEY_F: keysym = XK_f; break;
    case Tridme::Keyboard::TRIDME_KEY_G: keysym = XK_g; break;
    case Tridme::Keyboard::TRIDME_KEY_H: keysym = XK_h; break;
    case Tridme::Keyboard::TRIDME_KEY_I: keysym = XK_i; break;
    case Tridme::Keyboard::TRIDME_KEY_J: keysym = XK_j; break;
    case Tridme::Keyboard::TRIDME_KEY_K: keysym = XK_k; break;
    case Tridme::Keyboard::TRIDME_KEY_L: keysym = XK_l; break;
    case Tridme::Keyboard::TRIDME_KEY_M: keysym = XK_m; break;
    case Tridme::Keyboard::TRIDME_KEY_N: keysym = XK_n; break;
    case Tridme::Keyboard::TRIDME_KEY_O: keysym = XK_o; break;
    case Tridme::Keyboard::TRIDME_KEY_P: keysym = XK_p; break;
    case Tridme::Keyboard::TRIDME_KEY_Q: keysym = XK_q; break;
    case Tridme::Keyboard::TRIDME_KEY_R: keysym = XK_r; break;
    case Tridme::Keyboard::TRIDME_KEY_S: keysym = XK_s; break;
    case Tridme::Keyboard::TRIDME_KEY_T: keysym = XK_t; break;
    case Tridme::Keyboard::TRIDME_KEY_U: keysym = XK_u; break;
    case Tridme::Keyboard::TRIDME_KEY_V: keysym = XK_v; break;
    case Tridme::Keyboard::TRIDME_KEY_W: keysym = XK_w; break;
    case Tridme::Keyboard::TRIDME_KEY_X: keysym = XK_x; break;
    case Tridme::Keyboard::TRIDME_KEY_Y: keysym = XK_y; break;
    case Tridme::Keyboard::TRIDME_KEY_Z: keysym = XK_z; break;
    case Tridme::Keyboard::TRIDME_KEY_UP: keysym = XK_Up; break;
    case Tridme::Keyboard::TRIDME_KEY_DOWN: keysym = XK_Down; break;
    case Tridme::Keyboard::TRIDME_KEY_LEFT: keysym = XK_Left; break;
    case Tridme::Keyboard::TRIDME_KEY_RIGHT: keysym = XK_Right; break;
    case Tridme::Keyboard::TRIDME_KEY_ESCAPE: keysym = XK_Escape; break;
    case Tridme::Keyboard::TRIDME_KEY_ENTER: keysym = XK_Return; break;
  }

  KeyCode keycode = XKeysymToKeycode(m_display, keysym);
  if (keycode != 0) {
    char keys[32];
    XQueryKeymap(m_display, keys);

    return (keys[keycode / 8] & (1 << (keycode % 8))) != 0;
  } else {
    return false;
  }
}

int OS::GetKeyCode() {
  return m_xev.xkey.keycode;
}

Tridme::MouseEvent OS::GetMouseEvent() {
  Tridme::MouseEvent ev;

  ev.button = m_xev.xbutton.button;
  int posX  = m_xev.xmotion.x;
  int posY  = m_xev.xmotion.y;
  int relX  = posX - m_lastMousePosX;
  int relY  = posY - m_lastMousePosY;

  if (this->m_mouseMode == TRIDME_POINTER_MODE_CAPTURED) {
    const int dx =  m_lastMousePosX;
    const int dy =  m_lastMousePosY;

    m_virtualMousePosX += relX;
    m_virtualMousePosY += relY;

    this->DoWarpPointer(relX, relY);
    
    LOG(INFO, "(%d, %d)", relX, relY);
  } else {
    m_virtualMousePosX = m_xev.xmotion.x;
    m_virtualMousePosY = m_xev.xmotion.y;
  }

  ev.pos_x = this->m_virtualMousePosX;
  ev.pos_y = this->m_virtualMousePosY;

  m_lastMousePosX = m_xev.xmotion.x;
  m_lastMousePosY = m_xev.xmotion.y;

  // LOG(INFO, "Position (%d, %d) > (%d, %d)", (int) m_xev.xbutton.x, (int) m_xev.xbutton.y, this->m_windowWidth, this->m_windowHeight);

  return ev;
}

int OS::SwapBuffers() {
  glXSwapBuffers(m_display, m_window);

  return 0;
}

void OS::X11SetPointerMode(int mode) {
  char data[1] = {0};
  XColor dummy;
  Pixmap blank = XCreateBitmapFromData(m_display, *m_root, data, 1, 1);
  Cursor cursor = XCreatePixmapCursor(m_display, blank, blank, &dummy, &dummy, 0, 0);
    
  if (mode == TRIDME_POINTER_MODE_HIDDEN) {
    XDefineCursor(m_display, *m_root, cursor);
  } else if (mode == TRIDME_POINTER_MODE_CAPTURED) {
    /*
     * Pada mode captured harusnya cursor pointer itu terhidden tetapi 
     * posisi pergerakan tetap ketrack. Kita bisa "lock" posisinya untuk
     * masih berada di window tetapi yg kita mau dalam mode ini adalah
     * posisinya tak terbatas (atau maksimumnya besar). Ini nggak bisa
     * kalau pakai pointer dari event Xlib karena m_xev.event.mouse hnya
     * nyimpen data posisi nggak lebih dari batas window. Oleh karena itu,
     * kita harus bikin virtual position yg dibuat untuk posisi baru si
     * pointer dengan maksimal yang lebih besar. 
     */

    /*
     * Ini dipakai pada game-game FPS dan TPS (atau genre lain) dimana 
     * kita butuh posisi mouse untuk pergerakan camera.
     */
    XGrabPointer(m_display, m_window, True,
                 ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
                 GrabModeAsync, GrabModeAsync,
                 m_window,
                 None,
                 CurrentTime);

    XDefineCursor(m_display, *m_root, cursor);

    this->m_virtualMousePosX = m_windowWidth / 2;
    this->m_virtualMousePosY = m_windowHeight / 2;
  }

  this->m_mouseMode = mode;

  // Flush the request buffer and wait for the cursor to be changed
  XFlush(m_display);
  XSync(m_display, False);

  // Clean up
  XFreeCursor(m_display, cursor);
  XFreePixmap(m_display, blank);
}

void OS::DoWarpPointer(double xpos, double ypos) {
  /*
   * Kembalikan kursor ke tengah jika kursor melebihi batas window
   * dan mode mouse adalah CAPTURED. 
   */
  if (m_xev.xmotion.x <= 0 || m_xev.xmotion.x >= m_windowWidth  - 1 || 
      m_xev.xmotion.y <= 0 || m_xev.xmotion.y >= m_windowHeight - 1) {
    
      LOG(WARNING, "W = %d, H = %d", m_windowWidth, m_windowHeight);
      this->SetCursorPointer(m_windowWidth / 2, m_windowHeight / 2);
    
    this->m_virtualMousePosX += xpos;
    this->m_virtualMousePosY += ypos;
    LOG(ERROR, "WARP ME");
  } 

  // LOG(WARNING, "RELATIVE POSITION (%d, %d)", xpos, ypos);
}

void OS::SetCursorPointer(double x, double y) {
  // Store the new position so it can be recognized later
  // double warpCursorPosX = (int) x;
  // double warpCursorPosY = (int) y;

  XWarpPointer(this->m_display, None, this->m_window,
                0,0,0,0, (int) x, (int) y);
  XFlush(this->m_display);
}