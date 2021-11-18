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

int init_server(Display* display) {

    int sockfd, new_fd;
    struct sockaddr_in addr;
    struct sockaddr_in new_addr;
    int sin_size;
    
    char* buf;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(addr.sin_zero), 0, 8);

    bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

    while(1) {
        listen(sockfd, BACKLOG);

        printf("Listening...\n");

        sin_size = sizeof(struct sockaddr_in);
        new_fd = accept(sockfd, (struct sockaddr*)&new_addr, (socklen_t*)&sin_size);

        printf("Client connected...\n");
        
        buf = (char*) malloc(BUFSIZE);
        memset(buf, 0, BUFSIZE);
        
        while(recv(new_fd, buf, BUFSIZE - 1, 0) != 0) {
            printf("Received: %s", buf);

            KeySym keysym = (KeySym) strtol(buf, NULL, 16);
            keybd_press(display, keysym);
            keybd_release(display, keysym);

            memset(buf, 0, BUFSIZE);
        }
    }
    
    return sockfd;
}

#endif
