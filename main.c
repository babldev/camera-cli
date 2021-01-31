#include "libuvc/libuvc.h"

#include <stdio.h>

int main(int argc, char **argv) {
    uint16_t temperature;
    uvc_context_t *ctx;
    uvc_device_t *dev;
    uvc_device_handle_t *devh;
    uvc_error_t res;
    
    res = uvc_init(&ctx, NULL);
    if (res < 0) {
        uvc_perror(res, "uvc_init");
        return res;
    }
    puts("uvc initialized");

    res = uvc_find_device(
        ctx, &dev,
        0, 0, NULL); /* filter devices: vendor_id, product_id, "serial_num" */
    if (res < 0) {
        uvc_perror(res, "uvc_find_device");
        return res;
    }        
    puts("device found");

    res = uvc_open(dev, &devh);
    if (res < 0) {
        uvc_perror(res, "uvc_open");
    }
    puts("device opened");

    // uvc_print_diag(devh, NULL);

    // get auto focus state
    uint8_t focus_state;
    res = uvc_get_focus_auto(devh, &focus_state, UVC_GET_CUR);
    if (res < 0) { uvc_perror(res, "uvc_get_focus_auto"); }
    printf("prev auto focus state: %d\n", focus_state);

    // get auto focus current value
    uint16_t focus_abs;
    res = uvc_get_focus_abs(devh, &focus_abs, UVC_GET_CUR);
    if (res < 0) { uvc_perror(res, "uvc_get_focus_abs"); }
    printf("prev abs focus: %d\n", focus_abs);

    // disable auto focus
    focus_state = 0;
    res = uvc_set_focus_auto(devh, focus_state);
    if (res < 0) { uvc_perror(res, "uvc_set_focus_auto"); }
    puts("disabled auto focus");

    // set focus distance to minimum value
    res = uvc_get_focus_abs(devh, &focus_abs, UVC_GET_MIN);
    if (res < 0) { uvc_perror(res, "uvc_set_focus_abs get min"); }
    res = uvc_set_focus_abs(devh, focus_abs);
    if (res < 0) { uvc_perror(res, "uvc_set_focus_abs"); }
    puts("set abs focus to minimum value");
}
