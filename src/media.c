#include "media.h"

libvlc_media_t* load_screen_as_media(libvlc_instance_t* libvlc_instance, int left, int top, int width, int height) {

    libvlc_media_t* media = libvlc_media_new_location(libvlc_instance, SCREEN_PATH);
    set_media_screen_options(media);
    set_media_screen_options(media);

    return media;
}
