
#include "libheaders.h"
#include <stdio.h>

void ui_on_frame_event(void) {
    printf("[ui] frame event triggered\n");
    const uint8_t frame[4] = {0xde,0xad,0xbe,0xef};
    codec_decode(frame, sizeof(frame));
}
