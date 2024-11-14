#include <lvgl.h>
#include <src/font/lv_font.h>

int main(int argc, const char** argv)
{
    lv_init();
    lv_sdl_window_create(480, 480);

    lv_obj_t* obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 480, 480);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);


    lv_obj_t* label = lv_label_create(obj);
    lv_obj_set_style_text_font(label, &lv_font_simsun_16_cjk, 0);
    lv_label_set_text(label, "毛志涛 你好");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    while (1) {
        uint32_t time = lv_timer_handler();
        lv_delay_ms(time * 1000);
    }

    return 0;
}