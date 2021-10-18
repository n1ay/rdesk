#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* include for ssite_t in vlc headers */
#include <vlc/vlc.h>

/* might need to `sudo apt install vlc-plugin-access-extra` for screen streaming */
#define SCREEN_PATH "screen://"

static void set_media_screen_options(libvlc_media_t* media) {
    libvlc_media_add_option(media, "screen-fps=24");
    libvlc_media_add_option(media, "screen-caching=10");
    libvlc_media_add_option(media, "screen-top=0");
    libvlc_media_add_option(media, "screen-left=0");
    libvlc_media_add_option(media, "screen-width=1920");
    libvlc_media_add_option(media, "screen-height=1080");
}

static void set_media_sout_options(libvlc_media_t* media) {
    libvlc_media_add_option(media, "sout-standard-access=http");
    libvlc_media_add_option(media, "sout-standard-mux=ts");
    libvlc_media_add_option(media, "sout-standard-dst=127.0.0.1:8080");
}

libvlc_media_t* load_screen_as_media(libvlc_instance_t* libvlc_instance, int left, int top, int width, int height);

#endif
