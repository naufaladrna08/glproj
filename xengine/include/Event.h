#ifndef EVENT_H
#define EVENT_H
#include <glad/gl.h>
#include <glad/glx.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#define TRIDME_KEY_0 0x30
#define TRIDME_KEY_1 0x31
#define TRIDME_KEY_2 0x32
#define TRIDME_KEY_3 0x33
#define TRIDME_KEY_4 0x34
#define TRIDME_KEY_5 0x35
#define TRIDME_KEY_6 0x36
#define TRIDME_KEY_7 0x37
#define TRIDME_KEY_8 0x38
#define TRIDME_KEY_9 0x39
#define TRIDME_KEY_A 0x41
#define TRIDME_KEY_B 0x42
#define TRIDME_KEY_C 0x43
#define TRIDME_KEY_D 0x44
#define TRIDME_KEY_E 0x45
#define TRIDME_KEY_F 0x46
#define TRIDME_KEY_G 0x47
#define TRIDME_KEY_H 0x48
#define TRIDME_KEY_I 0x49
#define TRIDME_KEY_J 0x4A
#define TRIDME_KEY_K 0x4B
#define TRIDME_KEY_L 0x4C
#define TRIDME_KEY_M 0x4D
#define TRIDME_KEY_N 0x4E
#define TRIDME_KEY_O 0x4F
#define TRIDME_KEY_P 0x50
#define TRIDME_KEY_Q 0x51
#define TRIDME_KEY_R 0x52
#define TRIDME_KEY_S 0x53
#define TRIDME_KEY_T 0x54
#define TRIDME_KEY_U 0x55
#define TRIDME_KEY_V 0x56
#define TRIDME_KEY_W 0x57
#define TRIDME_KEY_X 0x58
#define TRIDME_KEY_Y 0x59
#define TRIDME_KEY_Z 0x5A

#define TRIDME_KEY_ESCAPE 0x1B
#define TRIDME_KEY_SPACE  0x20

namespace Tridme {
  enum EventType {
    EVENT_MOUSE_BUTTON,
    EVENT_MOUSE_MOTION,
    EVENT_KEYBOARD_PRESSED,
    EVENT_KEYBOARD_RELEASED,
    UNHANDLED_INPUT
  };
  
  typedef struct {
    EventType type;
    int keyCode;
  } Event;

  int KEY(int code);
}

#endif