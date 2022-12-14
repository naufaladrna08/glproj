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
  attributes.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask;
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

  if (m_xev.type == KeyPress) {
    return Tridme::EventType::EVENT_KEYBOARD_PRESSED;
  } else if (m_xev.type == KeyRelease) {
    return Tridme::EventType::EVENT_KEYBOARD_RELEASED;
  }

  return Tridme::EventType::UNHANDLED_INPUT;
}

int OS::KeyCodeHandler() {
  char buffer[32];
  KeySym keysym;
  XLookupString(&m_xev.xkey, buffer, 32, &keysym, NULL);

  return XKeysymToKeycode(m_display, keysym);
}

int OS::SwapBuffers() {
  glXSwapBuffers(m_display, m_window);

  return 0;
}