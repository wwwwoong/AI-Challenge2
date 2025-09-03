
#include "libheaders.h"
#include <stdio.h>

void wl_process_events(void) {
    printf("[wayland] processing events...\n");
    ui_on_frame_event();
}
