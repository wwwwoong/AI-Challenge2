
#pragma once
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*frame_cb_t)(const uint8_t* data, size_t len);

// libcodec API
void codec_set_callback(frame_cb_t cb);
void codec_mainloop(void);
void codec_decode(const uint8_t* data, size_t len);
void codec_deliver(const uint8_t* data, size_t len);

// libui API
void ui_on_frame_event(void);

// libwayland API
void wl_process_events(void);

// libapp API
void app_init(void);
void AppOnDecoded(const uint8_t* data, size_t len);

#ifdef __cplusplus
}
#endif
