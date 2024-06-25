// LVGL VERSION: 8.2.0

#include "ui.h"
#include "ui_helpers.h"
#include "./screens/Inc/ui_HomePage.h"
#include "./screens/Inc/ui_MenuPage.h"
#include "./screens/Inc/ui_GameSelectPage.h"
#include "./screens/Inc/ui_SetPage.h"
#include "./screens/Inc/ui_DateTimeSetPage.h"

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
    user_Stack_Pop(&ScrRenewStack);
    if(user_Stack_isEmpty(&ScrRenewStack))
    {
        ui_MenuPage_screen_init();
        lv_scr_load_anim(ui_MenuPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
        user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
        user_Stack_Push(&ScrRenewStack,(long long int)&ui_MenuPage);
    }
    else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
    {
        ui_HomePage_screen_init();
        lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
    }
    else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_MenuPage)
    {
        ui_MenuPage_screen_init();
        lv_scr_load_anim(ui_MenuPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
    }
    else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_GameSelectPage)
    {
        ui_GameSelectPage_screen_init();
        lv_scr_load_anim(ui_GameSelectPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
    }
    else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_SetPage)
    {
        ui_SetPage_screen_init();
        lv_scr_load_anim(ui_SetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
    }
    else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_DateTimeSetPage)
    {
        ui_DateTimeSetPage_screen_init();
        lv_scr_load_anim(ui_DateTimeSetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
    }
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
    user_Stack_Push(&ScrRenewStack,(long long int)&ui_HomePage);
    ui_HomePage_screen_init();
    lv_disp_load_scr(ui_HomePage);
}
