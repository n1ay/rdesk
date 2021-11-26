#ifndef _INPUTSERVER_H_
#define _INPUTSERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "inputevent.h"

#define PORT 50006
#define BACKLOG 1
#define BUFSIZE 32

/*
 * keystroke buffer
 * +--------+------------------------+
 * | state  |         keycode        |
 * | 1 byte |         31 bytes       |
 * +--------+------------------------+
 */

int init_server(Display* display);

#endif
