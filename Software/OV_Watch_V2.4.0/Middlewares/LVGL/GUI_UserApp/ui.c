// LVGL VERSION: 8.2.0

#include "ui.h"
#include "ui_HomePage.h"
#include "ui_MenuPage.h"
#include "ui_helpers.h"

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

/////////////////////// ui_initialize //////////////////////
void ui_init(void)
{

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_HomePage_screen_init();
    lv_disp_load_scr(ui_HomePage);
}
