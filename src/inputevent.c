#include <string.h>
#include <stdio.h>

#include "inputevent.h"

int mouse_press(Display* display, KeySym keysym) {
    return 0;
}

int mouse_release(Display* display, KeySym keysym) {
    return 0;
}


int keybd_press(Display* display, KeySym keysym) {
    int ret = XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), True, 0);
    XFlush(display);
    return ret;
}

int keybd_release(Display* display, KeySym keysym) {
    int ret = XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), False, 0);
    XFlush(display);
    return ret;
}
