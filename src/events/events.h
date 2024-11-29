#ifndef EVENTS_H
#define EVENTS_H

#include <lvgl.h>

// Functions
void create_gui();
void event_handler_btn1(lv_event_t * e);
void event_handler_btn2(lv_event_t * e);
void slider_event_callback(lv_event_t * e);

#endif
