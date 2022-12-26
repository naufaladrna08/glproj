#include <Platform/LinuxX11.h>

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
    PointerMotionMask;

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

  return 0;
}

int OS::CreateContext() {
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

  LOG(INFO, "Loaded GLX %d.%d and OpenGL %d.%d", GLAD_VERSION_MAJOR(glx_version), GLAD_VERSION_MINOR(glx_version), GLAD_VERSION_MAJOR(gl_version), GLAD_VERSION_MINOR(gl_version));

  XWindowAttributes gwa;
  XGetWindowAttributes(m_display, m_window, &gwa);
  glViewport(0, 0, gwa.width, gwa.height);

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
  ev.pos_x  = m_xev.xmotion.x;
  ev.pos_y  = m_xev.xmotion.y;

  return ev;
}

int OS::SwapBuffers() {
  glXSwapBuffers(m_display, m_window);

  return 0;
}