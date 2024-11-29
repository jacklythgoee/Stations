#include "Events.h"

static lv_obj_t * slider_label;
static int btn1_count = 0;
static int btn2_count = 0;

// Callback that is triggered when btn1 is clicked
void event_handler_btn1(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  if (code == LV_EVENT_CLICKED) {
    btn1_count++;
    LV_LOG_USER("Button clicked %d", (int)btn1_count);
  }
}