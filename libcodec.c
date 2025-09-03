
#include "libheaders.h"
#include <stdio.h>

static frame_cb_t g_cb = NULL;

void codec_set_callback(frame_cb_t cb) { g_cb = cb; }

void codec_mainloop(void) {
    printf("[codec] mainloop start\n");
    wl_process_events();
}

void codec_decode(const uint8_t* data, size_t len) {
    printf("[codec] decoding %zu bytes\n", len);
    codec_deliver(data, len);
}

void codec_deliver(const uint8_t* data, size_t len) {
    printf("[codec] delivering frame\n");
    if (g_cb) g_cb(data, len);
}
