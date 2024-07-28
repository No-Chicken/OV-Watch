#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_HRPage.h"
#include "../../../Func/Inc/HWDataAccess.h"

///////////////////// Page Manager //////////////////
Page_t Page_HR = {ui_HRPage_screen_init, ui_HRPage_screen_deinit, &ui_HRPage};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_HRPage;
lv_obj_t * ui_HRPageNumLabel;
lv_obj_t * ui_HRPageUnitLabel;
lv_obj_t * ui_HRPaggiconLabel;
lv_obj_t * ui_HRPageNoticeLabel;

lv_timer_t * ui_HRPageTimer;

///////////////////// ANIMATIONS ////////////////////


/////////////////// private timer ///////////////////
// need to be destroyed when the page is destroyed
static void HRPage_timer_cb(lv_timer_t * timer)
{
    uint8_t value_strbuf[6];
    //set text
    sprintf(value_strbuf, "%d", HWInterface.HR_meter.HrRate);
    lv_label_set_text(ui_HRPageNumLabel, value_strbuf);
}

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREEN init ////////////////////
void ui_HRPage_screen_init(void)
{
    uint8_t value_strbuf[5];

    ui_HRPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_HRPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HRPageNumLabel = lv_label_create(ui_HRPage);
    lv_obj_set_width(ui_HRPageNumLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRPageNumLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_HRPageNumLabel, LV_ALIGN_CENTER);
    sprintf(value_strbuf, "%d", HWInterface.HR_meter.HrRate);
    lv_label_set_text(ui_HRPageNumLabel, value_strbuf);
    lv_obj_set_style_text_font(ui_HRPageNumLabel, &ui_font_Cuyuan80, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HRPageUnitLabel = lv_label_create(ui_HRPage);
    lv_obj_set_width(ui_HRPageUnitLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRPageUnitLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HRPageUnitLabel, 85);
    lv_obj_set_y(ui_HRPageUnitLabel, 18);
    lv_obj_set_align(ui_HRPageUnitLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HRPageUnitLabel, "次/分");
    lv_obj_set_style_text_color(ui_HRPageUnitLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HRPageUnitLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HRPageUnitLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HRPaggiconLabel = lv_label_create(ui_HRPage);
    lv_obj_set_width(ui_HRPaggiconLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRPaggiconLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HRPaggiconLabel, 0);
    lv_obj_set_y(ui_HRPaggiconLabel, 30);
    lv_obj_set_align(ui_HRPaggiconLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_HRPaggiconLabel, "");
    lv_obj_set_style_text_color(ui_HRPaggiconLabel, lv_color_hex(0xFF1919), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HRPaggiconLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HRPaggiconLabel, &ui_font_iconfont34, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HRPageNoticeLabel = lv_label_create(ui_HRPage);
    lv_obj_set_width(ui_HRPageNoticeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HRPageNoticeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HRPageNoticeLabel, 0);
    lv_obj_set_y(ui_HRPageNoticeLabel, 90);
    lv_obj_set_align(ui_HRPageNoticeLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HRPageNoticeLabel, "正在测量...");
    lv_obj_set_style_text_color(ui_HRPageNoticeLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HRPageNoticeLabel, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HRPageNoticeLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    //timer
    ui_HRPageTimer = lv_timer_create(HRPage_timer_cb, 50,  NULL);

}

/////////////////// SCREEN deinit ////////////////////
void ui_HRPage_screen_deinit(void)
{
    lv_timer_del(ui_HRPageTimer);
}
