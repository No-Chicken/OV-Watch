#include "ui.h"
#include "ui_helpers.h"
#include "ui_SPO2Page.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_SPO2Page;
lv_obj_t * ui_SPO2NumLabel;
lv_obj_t * ui_SPO2UnitLabel;
lv_obj_t * ui_SPO2NoticeLabel;
lv_obj_t * ui_SPO2Icon;

uint8_t ui_SPO2Value = 99;

///////////////////// SCREENS ////////////////////
void ui_SPO2Page_screen_init(void)
{
    uint8_t value_strbuf[5];

    ui_SPO2Page = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SPO2Page, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SPO2NumLabel = lv_label_create(ui_SPO2Page);
    lv_obj_set_width(ui_SPO2NumLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SPO2NumLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SPO2NumLabel, LV_ALIGN_CENTER);
    sprintf(value_strbuf, "%d", ui_SPO2Value);
    lv_label_set_text(ui_SPO2NumLabel, value_strbuf);
    lv_obj_set_style_text_font(ui_SPO2NumLabel, &ui_font_Cuyuan80, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SPO2UnitLabel = lv_label_create(ui_SPO2Page);
    lv_obj_set_width(ui_SPO2UnitLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SPO2UnitLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SPO2UnitLabel, 70);
    lv_obj_set_y(ui_SPO2UnitLabel, 18);
    lv_obj_set_align(ui_SPO2UnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SPO2UnitLabel, "%");
    lv_obj_set_style_text_font(ui_SPO2UnitLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SPO2NoticeLabel = lv_label_create(ui_SPO2Page);
    lv_obj_set_width(ui_SPO2NoticeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SPO2NoticeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SPO2NoticeLabel, 0);
    lv_obj_set_y(ui_SPO2NoticeLabel, 90);
    lv_obj_set_align(ui_SPO2NoticeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SPO2NoticeLabel, "正在测量...");
    lv_obj_set_style_text_color(ui_SPO2NoticeLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SPO2NoticeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SPO2NoticeLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SPO2Icon = lv_label_create(ui_SPO2Page);
    lv_obj_set_width(ui_SPO2Icon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SPO2Icon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SPO2Icon, 0);
    lv_obj_set_y(ui_SPO2Icon, 30);
    lv_obj_set_align(ui_SPO2Icon, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_SPO2Icon, "");
    lv_obj_set_style_text_color(ui_SPO2Icon, lv_color_hex(0x0080FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SPO2Icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SPO2Icon, &ui_font_iconfont34, LV_PART_MAIN | LV_STATE_DEFAULT);

}


