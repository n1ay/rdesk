#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* include for ssite_t in vlc headers */
#include <vlc/vlc.h>

int main() {

    libvlc_instance_t* vlc_inst;
    vlc_inst = libvlc_new(0, NULL);



    libvlc_release(vlc_inst);
    
    return 0;
}
