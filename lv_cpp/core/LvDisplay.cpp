/*
 * LvDisplay.cpp
 *
 *  Created on: Sep 29, 2020
 *      Author: fstuffdev
 */

#include "LvDisplay.h"
#include "lvglpp.h"
#include <cstring>
#include <memory>

#if(USE_MONITOR + USE_FBDEV) > 1
#error "You cannot specify more than one display driver"
#endif

/* Input */
#if USE_MONITOR
#include <lv_drivers/display/monitor.h>
#include <SDL2/SDL.h>
#endif

#if USE_FBDEV
#include <lv_drivers/display/fbdev.h>
#endif

namespace lvglpp {

LvDisplay::LvDisplay(unsigned int hres, unsigned int vres)
{
#if LV_USE_EVDEV
    const char * input_device = getenv("LV_LINUX_EVDEV_POINTER_DEVICE");

    if(input_device == NULL) {
        fprintf(stderr, "please set the LV_LINUX_EVDEV_POINTER_DEVICE environment variable\n");
        exit(1);
    }

    lv_indev_t * touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, input_device);
    lv_indev_set_display(touch, disp);

    /* Set the cursor icon */
    LV_IMAGE_DECLARE(mouse_cursor_icon);
    lv_obj_t * cursor_obj = lv_image_create(lv_screen_active());
    lv_image_set_src(cursor_obj, &mouse_cursor_icon);
    lv_indev_set_cursor(touch, cursor_obj);
#endif
#if LV_USE_LINUX_FBDEV
    static void lv_linux_disp_init(void)
    {
        const char * device = getenv_default("LV_LINUX_FBDEV_DEVICE", "/dev/fb0");
        lv_display_t * disp = lv_linux_fbdev_create();

#if LV_USE_EVDEV
        lv_linux_init_input_pointer(disp);
#endif

        lv_linux_fbdev_set_file(disp, device);
    }
#elif LV_USE_LINUX_DRM
    static void lv_linux_disp_init(void)
    {
        const char * device = getenv_default("LV_LINUX_DRM_CARD", "/dev/dri/card0");
        lv_display_t * disp = lv_linux_drm_create();

#if LV_USE_EVDEV
        lv_linux_init_input_pointer(disp);
#endif

        lv_linux_drm_set_file(disp, device, -1);
    }
#elif LV_USE_SDL
    lv_display_t * dp = lv_sdl_window_create(hres, vres);
    disp              = std::unique_ptr<lv_display_t, CustomDeleter<lv_free>>(dp);

#elif LV_USE_WAYLAND
/* see backend/wayland.c */
#else
#error Unsupported configuration
#endif
}

LvDisplay::~LvDisplay()
{}

} // namespace lvglpp
