#include <unistd.h> /* include for sleep  */
#include <X11/extensions/XTest.h>

#include "media.h"
#include "socketserver.h"
#include "inputevent.h"

int main() {

    Display* display;
    display = NULL;
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        printf("Could not get display\n");
        exit(CODE_ERROR);
    }

    int sockfd = init_server(display);

    libvlc_instance_t* libvlc_instance;
    libvlc_media_player_t* media_player;
    libvlc_media_t* media;

    libvlc_instance = libvlc_new(0, NULL);
    libvlc_add_intf(libvlc_instance, "dummy");

    media = load_screen_as_media(libvlc_instance, 0, 0, 0, 0);

    media_player = libvlc_media_player_new_from_media(media);
    libvlc_media_release(media);

    libvlc_media_player_play(media_player);
    sleep(120);
    libvlc_media_player_stop(media_player);

    libvlc_release(libvlc_instance);

    return 0;
}
