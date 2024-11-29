#include <lvgl.h>
#include <TFT_eSPI.h>
#include "touchscreen/TouchScreen.h"
#include "events/Events.h"
#include "gui/GUI.h"
#include "wifi/WiFiConnection.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

void log_print(lv_log_level_t level, const char * buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}

void setup() {
  String LVGL_Arduino = String("LVGL Library Version: ") + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);

  connectToWiFi();
  
  lv_init();
  lv_log_register_print_cb(log_print);

  init_touchscreen();

  lv_display_t * disp;

  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
    
  lv_indev_t * indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchscreen_read);

  // Create the GUI
  create_gui(); 
}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);     
}