#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include <lvgl.h>
#include <XPT2046_Touchscreen.h>

// Functions
void init_touchscreen();
void touchscreen_read(lv_indev_t * indev, lv_indev_data_t * data);

#endif
