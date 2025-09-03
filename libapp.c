
#include "libheaders.h"
#include <stdio.h>

void app_init(void) {
    codec_set_callback(AppOnDecoded);
}

void AppOnDecoded(const uint8_t* data, size_t len) {
    printf("[PVOD_APP] received decoded frame, will crash intentionally\n");
    (void)data; (void)len;
    volatile int *p = (int*)0x1;
    *p = 123; // Intentional SIGSEGV
}
