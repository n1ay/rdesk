#include "socketserver.h"

int init_server(Display* display) {

    int sockfd, new_fd;
    struct sockaddr_in addr;
    struct sockaddr_in new_addr;
    int sin_size;
    
    char* buf;
    char keystate;
    char* keystr;
    ssize_t recv_bytes;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(addr.sin_zero), 0, sizeof(addr.sin_zero));

    bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr));

    while(1) {
        listen(sockfd, BACKLOG);

        printf("Listening...\n");

        sin_size = sizeof(struct sockaddr_in);
        new_fd = accept(sockfd, (struct sockaddr*)&new_addr, (socklen_t*)&sin_size);

        printf("Client connected...\n");
        
        buf = (char*) malloc(BUFSIZE);
        memset(buf, 0, BUFSIZE);
        keystr = (char*) malloc(BUFSIZE - 1);
        memset(keystr, 0, BUFSIZE - 1);
        
        while((recv_bytes = recv(new_fd, buf, BUFSIZE, 0)) > 0) {

            //TODO: remove after testing with nc
            if (buf[recv_bytes - 1] == '\n') {
                buf[recv_bytes - 1] = 0;
            }
            //-

            keystate = buf[0];
            strncpy(keystr, buf + 1, recv_bytes - 1);

            printf("Received: %s, recv_bytes: %ld\n", buf, recv_bytes);

            KeySym keysym = None;
            keysym = XStringToKeysym(keystr);
            if (keysym != None) {
                if (keystate == 'p') {
                    keybd_press(display, keysym);
                } else if (keystate == 'r') {
                    keybd_release(display, keysym);
                }
            }

            memset(buf + 1, 0, recv_bytes - 1);
            memset(keystr, 0, recv_bytes - 1);
        }
    }
    
    return sockfd;
}
