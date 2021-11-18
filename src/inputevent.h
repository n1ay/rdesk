#ifndef _INPUT_EVENT_H_
#define _INPUT_EVENT_H_

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#include "rdesk.h"

int mouse_press(Display* display, KeySym keysym);

int mouse_release(Display* display, KeySym keysym);

int keybd_press(Display* display, KeySym keysym);

int keybd_release(Display* display, KeySym keysym);

#endif
