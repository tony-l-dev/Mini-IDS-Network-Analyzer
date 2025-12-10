#include "capture.h"

pcap_t * init_capture(const char * device) {
    char err[256];
    pcap_t * handle;

    handle = pcap_open_live(device, 8192, 1, 1, &err);

    if (handle == NULL) printf("%s\n", err);
    return handle;
}

int start_capture(pcap_t* handle) {
    pcap_loop(handle, -1, parser, NULL);
}