#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* include for ssize_t in vlc headers */
#include <vlc/vlc.h>

/* might need to `sudo apt install vlc-plugin-access-extra` for screen streaming */
#define SCREEN_PATH "screen://"

static void set_media_screen_options(libvlc_media_t* media) {
    libvlc_media_add_option(media, "screen-fps=24");
    //libvlc_media_add_option(media, "screen-caching=0");
    //libvlc_media_add_option(media, "screen-top=0");
    //libvlc_media_add_option(media, "screen-left=0");
    //libvlc_media_add_option(media, "screen-width=1920");
    //libvlc_media_add_option(media, "screen-height=1080");
}

static void set_media_sout_options(libvlc_media_t* media) {

    libvlc_media_add_option(media, "sout=#transcode{vcodec=h264,vb=4096,acodec=mp4a,ab=256,fps=30,threads=4}:rtp{mux=ts,sdp=sap,dst=127.0.0.1}");
    libvlc_media_add_option(media, "sout-all");
    libvlc_media_add_option(media, "sout-keep");
}

static void set_media_other_options(libvlc_media_t* media) {
    libvlc_media_add_option(media, "avcodec-fast");
    libvlc_media_add_option(media, "network-caching=0");
}

libvlc_media_t* load_screen_as_media(libvlc_instance_t* libvlc_instance, int left, int top, int width, int height) {

    libvlc_media_t* media = libvlc_media_new_location(libvlc_instance, SCREEN_PATH);
    set_media_screen_options(media);
    set_media_sout_options(media);
    set_media_other_options(media);

    return media;
}

#endif
