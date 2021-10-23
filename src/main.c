#include <unistd.h> /* include for sleep  */

#include "media.h"

int main() {

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
