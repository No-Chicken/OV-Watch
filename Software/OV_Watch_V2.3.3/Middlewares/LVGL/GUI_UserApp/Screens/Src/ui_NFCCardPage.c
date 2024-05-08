#include "ui.h"
#include "ui_helpers.h"
#include "ui_Megboxes.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_NFCCardPage;
lv_obj_t * ui_Card1Panel;
lv_obj_t * ui_Card1Btn;
lv_obj_t * ui_Card1icon;
lv_obj_t * ui_Card1Label;
lv_obj_t * ui_WriteBtn1;
lv_obj_t * ui_WriteLabel1;
lv_obj_t * ui_ChooseBtn1;
lv_obj_t * ui_ChooseLabel1;

lv_obj_t * ui_Card2Panel;
lv_obj_t * ui_Card2Btn;
lv_obj_t * ui_Card2icon;
lv_obj_t * ui_Card2Label;
lv_obj_t * ui_WriteBtn2;
lv_obj_t * ui_WriteLabel2;
lv_obj_t * ui_ChooseBtn2;
lv_obj_t * ui_ChooseLabel2;

lv_obj_t * ui_Card3Panel;
lv_obj_t * ui_Card3Btn;
lv_obj_t * ui_Card3icon;
lv_obj_t * ui_Card3Label;
lv_obj_t * ui_WriteBtn3;
lv_obj_t * ui_WriteLabel3;
lv_obj_t * ui_ChooseBtn3;
lv_obj_t * ui_ChooseLabel3;

///////////////////// FUNCTIONS ////////////////////
void ui_event_WriteBtn1(lv_event_t * e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t * target = lv_event_get_target(e);
	if(event_code == LV_EVENT_CLICKED)
	{
		ui_mbox_create("开发中");
	}
}

void ui_event_ChooseBtn1(lv_event_t * e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t * target = lv_event_get_target(e);
	if(event_code == LV_EVENT_CLICKED)
	{
	
	}
}

///////////////////// SCREENS ////////////////////
void ui_NFCCardPage_screen_Init(void)
{
	ui_NFCCardPage = lv_obj_create(NULL);

    ui_Card1Panel = lv_obj_create(ui_NFCCardPage);
    lv_obj_set_width(ui_Card1Panel, 200);
    lv_obj_set_height(ui_Card1Panel, 100);
    lv_obj_set_x(ui_Card1Panel, 0);
    lv_obj_set_y(ui_Card1Panel, 20);
    lv_obj_set_align(ui_Card1Panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Card1Panel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Card1Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card1Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card1Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Card1Panel, 200, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_Card1Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Card1Panel, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Card1Btn = lv_btn_create(ui_Card1Panel);
    lv_obj_set_width(ui_Card1Btn, 40);
    lv_obj_set_height(ui_Card1Btn, 40);
    lv_obj_add_flag(ui_Card1Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Card1Btn, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Card1Btn, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card1Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card1Btn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card1icon = lv_label_create(ui_Card1Btn);
    lv_obj_set_width(ui_Card1icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card1icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Card1icon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Card1icon, "");
    lv_obj_set_style_text_color(ui_Card1icon, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Card1icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Card1icon, &ui_font_iconfont34, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card1Label = lv_label_create(ui_Card1Panel);
    lv_obj_set_width(ui_Card1Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card1Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Card1Label, 50);
    lv_obj_set_y(ui_Card1Label, 10);
    lv_label_set_text(ui_Card1Label, "校园卡");
    lv_obj_set_style_text_font(ui_Card1Label, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteBtn1 = lv_btn_create(ui_Card1Panel);
    lv_obj_set_width(ui_WriteBtn1, 80);
    lv_obj_set_height(ui_WriteBtn1, 30);
    lv_obj_set_x(ui_WriteBtn1, 0);
    lv_obj_set_y(ui_WriteBtn1, 10);
    lv_obj_set_align(ui_WriteBtn1, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_WriteBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WriteBtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_WriteBtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WriteBtn1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_WriteBtn1, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_WriteBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_WriteBtn1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteLabel1 = lv_label_create(ui_WriteBtn1);
    lv_obj_set_width(ui_WriteLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WriteLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WriteLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WriteLabel1, "改写");
    lv_obj_set_style_text_font(ui_WriteLabel1, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseBtn1 = lv_btn_create(ui_Card1Panel);
    lv_obj_set_width(ui_ChooseBtn1, 80);
    lv_obj_set_height(ui_ChooseBtn1, 30);
    lv_obj_set_x(ui_ChooseBtn1, 0);
    lv_obj_set_y(ui_ChooseBtn1, 10);
    lv_obj_set_align(ui_ChooseBtn1, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ChooseBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChooseBtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ChooseBtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChooseBtn1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChooseBtn1, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChooseBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChooseBtn1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseLabel1 = lv_label_create(ui_ChooseBtn1);
    lv_obj_set_width(ui_ChooseLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChooseLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChooseLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChooseLabel1, "选择");
    lv_obj_set_style_text_font(ui_ChooseLabel1, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card2Panel = lv_obj_create(ui_NFCCardPage);
    lv_obj_set_width(ui_Card2Panel, 200);
    lv_obj_set_height(ui_Card2Panel, 100);
    lv_obj_set_x(ui_Card2Panel, 0);
    lv_obj_set_y(ui_Card2Panel, 140);
    lv_obj_set_align(ui_Card2Panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Card2Panel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Card2Panel, lv_color_hex(0x0F800F), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card2Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card2Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Card2Panel, 200, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_Card2Panel, lv_color_hex(0x0F800F), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Card2Panel, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Card2Btn = lv_btn_create(ui_Card2Panel);
    lv_obj_set_width(ui_Card2Btn, 40);
    lv_obj_set_height(ui_Card2Btn, 40);
    lv_obj_add_flag(ui_Card2Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Card1Btn, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Card2Btn, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card2Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card2Btn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card2icon = lv_label_create(ui_Card2Btn);
    lv_obj_set_width(ui_Card2icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card2icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Card2icon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Card2icon, "");
    lv_obj_set_style_text_color(ui_Card2icon, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Card2icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Card2icon, &ui_font_iconfont34, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card2Label = lv_label_create(ui_Card2Panel);
    lv_obj_set_width(ui_Card2Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card2Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Card2Label, 50);
    lv_obj_set_y(ui_Card2Label, 10);
    lv_label_set_text(ui_Card2Label, "门禁卡");
    lv_obj_set_style_text_font(ui_Card2Label, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteBtn2 = lv_btn_create(ui_Card2Panel);
    lv_obj_set_width(ui_WriteBtn2, 80);
    lv_obj_set_height(ui_WriteBtn2, 30);
    lv_obj_set_x(ui_WriteBtn2, 0);
    lv_obj_set_y(ui_WriteBtn2, 10);
    lv_obj_set_align(ui_WriteBtn2, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_WriteBtn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WriteBtn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_WriteBtn2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WriteBtn2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_WriteBtn2, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_WriteBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_WriteBtn2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteLabel2 = lv_label_create(ui_WriteBtn2);
    lv_obj_set_width(ui_WriteLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WriteLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WriteLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WriteLabel2, "改写");
    lv_obj_set_style_text_font(ui_WriteLabel2, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseBtn2 = lv_btn_create(ui_Card2Panel);
    lv_obj_set_width(ui_ChooseBtn2, 80);
    lv_obj_set_height(ui_ChooseBtn2, 30);
    lv_obj_set_x(ui_ChooseBtn2, 0);
    lv_obj_set_y(ui_ChooseBtn2, 10);
    lv_obj_set_align(ui_ChooseBtn2, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ChooseBtn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChooseBtn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ChooseBtn2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChooseBtn2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChooseBtn2, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChooseBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChooseBtn2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseLabel2 = lv_label_create(ui_ChooseBtn2);
    lv_obj_set_width(ui_ChooseLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChooseLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChooseLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChooseLabel2, "选择");
    lv_obj_set_style_text_font(ui_ChooseLabel2, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card3Panel = lv_obj_create(ui_NFCCardPage);
    lv_obj_set_width(ui_Card3Panel, 200);
    lv_obj_set_height(ui_Card3Panel, 100);
    lv_obj_set_x(ui_Card3Panel, 0);
    lv_obj_set_y(ui_Card3Panel, 260);
    lv_obj_set_align(ui_Card3Panel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Card3Panel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Card3Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card3Panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card3Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_Card3Panel, 200, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_Card3Panel, lv_color_hex(0x0F80FF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Card3Panel, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Card3Btn = lv_btn_create(ui_Card3Panel);
    lv_obj_set_width(ui_Card3Btn, 40);
    lv_obj_set_height(ui_Card3Btn, 40);
    lv_obj_add_flag(ui_Card3Btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Card1Btn, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Card3Btn, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Card3Btn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Card3Btn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card3icon = lv_label_create(ui_Card3Btn);
    lv_obj_set_width(ui_Card3icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card3icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Card3icon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Card3icon, "");
    lv_obj_set_style_text_color(ui_Card3icon, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Card3icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Card3icon, &ui_font_iconfont30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Card3Label = lv_label_create(ui_Card3Panel);
    lv_obj_set_width(ui_Card3Label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Card3Label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Card3Label, 50);
    lv_obj_set_y(ui_Card3Label, 10);
    lv_label_set_text(ui_Card3Label, "交通卡");
    lv_obj_set_style_text_font(ui_Card3Label, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteBtn3 = lv_btn_create(ui_Card3Panel);
    lv_obj_set_width(ui_WriteBtn3, 80);
    lv_obj_set_height(ui_WriteBtn3, 30);
    lv_obj_set_x(ui_WriteBtn3, 0);
    lv_obj_set_y(ui_WriteBtn3, 10);
    lv_obj_set_align(ui_WriteBtn3, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_flag(ui_WriteBtn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WriteBtn3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_WriteBtn3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WriteBtn3, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_WriteBtn3, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_WriteBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_WriteBtn3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WriteLabel3 = lv_label_create(ui_WriteBtn3);
    lv_obj_set_width(ui_WriteLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WriteLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WriteLabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WriteLabel3, "改写");
    lv_obj_set_style_text_font(ui_WriteLabel3, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseBtn3 = lv_btn_create(ui_Card3Panel);
    lv_obj_set_width(ui_ChooseBtn3, 80);
    lv_obj_set_height(ui_ChooseBtn3, 30);
    lv_obj_set_x(ui_ChooseBtn3, 0);
    lv_obj_set_y(ui_ChooseBtn3, 10);
    lv_obj_set_align(ui_ChooseBtn3, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_flag(ui_ChooseBtn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChooseBtn3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ChooseBtn3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChooseBtn3, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChooseBtn3, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChooseBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChooseBtn3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChooseLabel3 = lv_label_create(ui_ChooseBtn3);
    lv_obj_set_width(ui_ChooseLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChooseLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChooseLabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChooseLabel3, "选择");
    lv_obj_set_style_text_font(ui_ChooseLabel3, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

		lv_obj_add_event_cb(ui_WriteBtn1, ui_event_WriteBtn1, LV_EVENT_ALL, NULL);
		lv_obj_add_event_cb(ui_ChooseBtn1, ui_event_ChooseBtn1, LV_EVENT_ALL, NULL);

}
