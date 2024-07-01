// LVGL VERSION: 8.2.0

#include "ui.h"
#include "ui_helpers.h"
#include "./screens/Inc/ui_HomePage.h"
#include "../Func/Inc/pubsub.h"

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// CallBack functions ////////////////////
void SDL_KeyBoard_Subscriber(PubSub_Message_t message)
{
    printf("change screen\r\n");
    Page_Back();
}

/////////////////////// Timer //////////////////////
static void main_timer(lv_timer_t * timer)
{
    printf("timer\r\n");
    printf("%d\r\n",&ui_HomePage);
    printf("%d\r\n",Page_Get_NowPage()->page_obj);
    printf("stacklen:%d\r\n",PageStack.top);
}

/////////////////////// ui_initialize //////////////////////
void ui_init(void)
{
    Publisher_init(&SDL_KeyBoard_Publisher);
    Publisher_subscribe(&SDL_KeyBoard_Publisher, SDL_KeyBoard_Subscriber);

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    Pages_init();
    //timer
    lv_timer_t * ui_MainTimer = lv_timer_create(main_timer, 1000,  NULL);
}
