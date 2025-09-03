
CC ?= gcc
CFLAGS := -fPIC -O0 -g -fno-omit-frame-pointer -Wall -Wextra
LDFLAGS_SO := -shared
LIBS := -ldl

all: libwayland.so libui.so libcodec.so libapp.so runner

libwayland.so: libwayland.c libheaders.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS_SO)

libui.so: libui.c libheaders.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS_SO)

libcodec.so: libcodec.c libheaders.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS_SO)

libapp.so: libapp.c libheaders.h
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS_SO)

runner: runner.c
	$(CC) $(CFLAGS) -Wl,-rpath,. -L. -o $@ $< -lcodec -lui -lwayland -lapp $(LIBS)

clean:
	rm -f *.o *.so runner
