#include <lvgl.h>
#include "events/Events.h" // Include event handlers for button/slider callbacks

void create_gui() {
  lv_obj_t * btn_label;

  // Create a Button (btn1)
  lv_obj_t * btn1 = lv_button_create(lv_screen_active());
  lv_obj_add_event_cb(btn1, event_handler_btn1, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 0);
  lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);

  btn_label = lv_label_create(btn1);
  lv_label_set_text(btn_label, "Start");
  lv_obj_center(btn_label);


}
