#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_HomePage.h"
#include "../Inc/ui_SetPage.h"
#include "../Inc/ui_OffTimePage.h"

///////////////////// Page Manager //////////////////
Page_t Page_LOffTimeSet = {ui_LOffTimeSetPage_screen_init, ui_LOffTimeSetPage_screen_deinit, &ui_LOffTimeSetPage};
Page_t Page_TOffTimeSet = {ui_TOffTimeSetPage_screen_init, ui_TOffTimeSetPage_screen_deinit, &ui_TOffTimeSetPage};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_LOffTimeSetPage;
lv_obj_t * ui_LTimeSetRoller;
lv_obj_t * ui_LTimeSetUnitLabel;
lv_obj_t * ui_LTimeSetOKButton;
lv_obj_t * ui_LTimeSetOKLabel;
lv_obj_t * ui_LTimeSeticon;

lv_obj_t * ui_TOffTimeSetPage;
lv_obj_t * ui_TTimeSetRoller;
lv_obj_t * ui_TTimeSetUnitLabel;
lv_obj_t * ui_TTimeSetOKButton;
lv_obj_t * ui_TTimeSetOKLabel;
lv_obj_t * ui_TTimeSeticon;

const uint8_t ui_LTimeOptions[6] = {10,15,20,30,45,60};
const uint8_t ui_TTimeOptions[6] = {15,20,25,35,50,65};
uint8_t ui_LTimeValue = 10;
uint8_t ui_TTimeValue = 15;

uint8_t ui_LTimeSelected = 0;
uint8_t ui_TTimeSelected = 0;
///////////////////// FUNCTIONS ////////////////////
void ui_event_LTimeSetOKButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
      ui_LTimeSelected = lv_roller_get_selected(ui_LTimeSetRoller);
			ui_LTimeValue = ui_LTimeOptions[ui_LTimeSelected];
      Page_Back();
			// if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
			// {
			// 	ui_HomePage_screen_init();
			// 	lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
			// }
			// else
			// {
			// 	ui_SetPage_screen_init();
			// 	lv_scr_load_anim(ui_SetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
			// }
			// user_Stack_Pop(&ScrRenewStack);
    }
}

void ui_event_TTimeSetOKButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
			ui_TTimeSelected = lv_roller_get_selected(ui_TTimeSetRoller);
      ui_TTimeValue = ui_LTimeOptions[ui_TTimeSelected];
      Page_Back();
			// if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
			// {
			// 	ui_HomePage_screen_init();
			// 	lv_scr_load_anim(ui_HomePage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
			// }
			// else
			// {
			// 	ui_SetPage_screen_init();
			// 	lv_scr_load_anim(ui_SetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,0,0,true);
			// }
			// user_Stack_Pop(&ScrRenewStack);
    }
}

///////////////////// SCREEN init ////////////////////
void ui_LOffTimeSetPage_screen_init(void)
{
    ui_LOffTimeSetPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_LOffTimeSetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LTimeSetRoller = lv_roller_create(ui_LOffTimeSetPage);

    lv_roller_set_options(ui_LTimeSetRoller, "10\n15\n20\n30\n45\n60", LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_LTimeSetRoller,ui_LTimeSelected,LV_ANIM_OFF);
    lv_obj_set_height(ui_LTimeSetRoller, 150);
    lv_obj_set_width(ui_LTimeSetRoller, LV_SIZE_CONTENT);   /// 0
    lv_obj_set_align(ui_LTimeSetRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_LTimeSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LTimeSetRoller, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LTimeSetRoller, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LTimeSetRoller, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LTimeSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LTimeSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_LTimeSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LTimeSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LTimeSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LTimeSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_LTimeSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_LTimeSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_LTimeSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_LTimeSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_LTimeSetUnitLabel = lv_label_create(ui_LOffTimeSetPage);
    lv_obj_set_width(ui_LTimeSetUnitLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LTimeSetUnitLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LTimeSetUnitLabel, 60);
    lv_obj_set_y(ui_LTimeSetUnitLabel, 0);
    lv_obj_set_align(ui_LTimeSetUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LTimeSetUnitLabel, "秒");
    lv_obj_set_style_text_font(ui_LTimeSetUnitLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LTimeSetOKButton = lv_btn_create(ui_LOffTimeSetPage);
    lv_obj_set_width(ui_LTimeSetOKButton, 240);
    lv_obj_set_height(ui_LTimeSetOKButton, 50);
    lv_obj_set_align(ui_LTimeSetOKButton, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_LTimeSetOKButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_LTimeSetOKButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_LTimeSetOKButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LTimeSetOKButton, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LTimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LTimeSetOKButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_LTimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LTimeSetOKLabel = lv_label_create(ui_LTimeSetOKButton);
    lv_obj_set_width(ui_LTimeSetOKLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LTimeSetOKLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LTimeSetOKLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LTimeSetOKLabel, "");
    lv_obj_set_style_text_font(ui_LTimeSetOKLabel, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LTimeSeticon = lv_label_create(ui_LOffTimeSetPage);
    lv_obj_set_width(ui_LTimeSeticon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LTimeSeticon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LTimeSeticon, 0);
    lv_obj_set_y(ui_LTimeSeticon, -105);
    lv_obj_set_align(ui_LTimeSeticon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LTimeSeticon, "");
    lv_obj_set_style_text_font(ui_LTimeSeticon, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_event_cb(ui_LTimeSetOKButton, ui_event_LTimeSetOKButton, LV_EVENT_ALL, NULL);

}


void ui_TOffTimeSetPage_screen_init(void)
{
    ui_TOffTimeSetPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TOffTimeSetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TTimeSetRoller = lv_roller_create(ui_TOffTimeSetPage);
    lv_roller_set_options(ui_TTimeSetRoller, "15\n20\n25\n35\n50\n65", LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_TTimeSetRoller,ui_TTimeSelected,LV_ANIM_OFF);
    lv_obj_set_height(ui_TTimeSetRoller, 150);
    lv_obj_set_width(ui_TTimeSetRoller, LV_SIZE_CONTENT);   /// 0
    lv_obj_set_align(ui_TTimeSetRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_TTimeSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TTimeSetRoller, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TTimeSetRoller, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TTimeSetRoller, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TTimeSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TTimeSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TTimeSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TTimeSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TTimeSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TTimeSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_TTimeSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_TTimeSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_TTimeSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_TTimeSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_TTimeSetUnitLabel = lv_label_create(ui_TOffTimeSetPage);
    lv_obj_set_width(ui_TTimeSetUnitLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TTimeSetUnitLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TTimeSetUnitLabel, 60);
    lv_obj_set_y(ui_TTimeSetUnitLabel, 0);
    lv_obj_set_align(ui_TTimeSetUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TTimeSetUnitLabel, "秒");
    lv_obj_set_style_text_font(ui_TTimeSetUnitLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TTimeSetOKButton = lv_btn_create(ui_TOffTimeSetPage);
    lv_obj_set_width(ui_TTimeSetOKButton, 240);
    lv_obj_set_height(ui_TTimeSetOKButton, 50);
    lv_obj_set_align(ui_TTimeSetOKButton, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_TTimeSetOKButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TTimeSetOKButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TTimeSetOKButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TTimeSetOKButton, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TTimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TTimeSetOKButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_TTimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_TTimeSetOKLabel = lv_label_create(ui_TTimeSetOKButton);
    lv_obj_set_width(ui_TTimeSetOKLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TTimeSetOKLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_TTimeSetOKLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TTimeSetOKLabel, "");
    lv_obj_set_style_text_font(ui_TTimeSetOKLabel, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TTimeSeticon = lv_label_create(ui_TOffTimeSetPage);
    lv_obj_set_width(ui_TTimeSeticon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TTimeSeticon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TTimeSeticon, 0);
    lv_obj_set_y(ui_TTimeSeticon, -105);
    lv_obj_set_align(ui_TTimeSeticon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TTimeSeticon, "");
    lv_obj_set_style_text_font(ui_TTimeSeticon, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_TTimeSetOKButton, ui_event_TTimeSetOKButton, LV_EVENT_ALL, NULL);

}

///////////////////// SCREEN deinit ////////////////////
void ui_LOffTimeSetPage_screen_deinit(void)
{}

void ui_TOffTimeSetPage_screen_deinit(void)
{}
