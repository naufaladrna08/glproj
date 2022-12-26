#ifndef EVENT_H
#define EVENT_H
#include <glad/gl.h>
#include <glad/glx.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

namespace Tridme {
  enum EventType {
    EVENT_MOUSE_BUTTON_PRESSED,
    EVENT_MOUSE_BUTTON_RELEASED,
    EVENT_MOUSE_MOTION,
    EVENT_KEYBOARD_PRESSED,
    EVENT_KEYBOARD_RELEASED,
    UNHANDLED_INPUT
  };
  
  enum Keyboard {
    TRIDME_KEY_0,
    TRIDME_KEY_1,
    TRIDME_KEY_2,
    TRIDME_KEY_3,
    TRIDME_KEY_4,
    TRIDME_KEY_5,
    TRIDME_KEY_6,
    TRIDME_KEY_7,
    TRIDME_KEY_8,
    TRIDME_KEY_9,
    TRIDME_KEY_A,
    TRIDME_KEY_B,
    TRIDME_KEY_C,
    TRIDME_KEY_D,
    TRIDME_KEY_E,
    TRIDME_KEY_F,
    TRIDME_KEY_G,
    TRIDME_KEY_H,
    TRIDME_KEY_I,
    TRIDME_KEY_J,
    TRIDME_KEY_K,
    TRIDME_KEY_L,
    TRIDME_KEY_M,
    TRIDME_KEY_N,
    TRIDME_KEY_O,
    TRIDME_KEY_P,
    TRIDME_KEY_Q,
    TRIDME_KEY_R,
    TRIDME_KEY_S,
    TRIDME_KEY_T,
    TRIDME_KEY_U,
    TRIDME_KEY_V,
    TRIDME_KEY_W,
    TRIDME_KEY_X,
    TRIDME_KEY_Y,
    TRIDME_KEY_Z
  };

  enum MouseButton {
    MOUSE_BUTTON_LEFT = 1,
    MOUSE_BUTTON_MIDDLE = 2,
    MOUSE_BUTTON_RIGHT = 3
  };

  typedef struct {
    int button;
    int pos_x;
    int pos_y;
  } MouseEvent;

  typedef struct {
    EventType type;
    int key;
    MouseEvent mouse;
  } Event;
}

#endif