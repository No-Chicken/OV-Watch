#include "../../ui.h"
#include "../Inc/ui_ChargPage.h"
#include "../Inc/ui_HomePage.h"
#include "../../../Func/Inc/HWDataAccess.h"

///////////////////// Page Manager //////////////////
Page_t Page_Charg = {ui_ChargPage_screen_init, ui_ChargPage_screen_deinit, &ui_ChargPage};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ChargPage;
lv_obj_t * ui_CharPageBatArc;
lv_obj_t * ui_ChargPageBatIcon;
lv_obj_t * ui_ChargPageBatNum;
lv_obj_t * ui_ChargPagebHourLabel;
lv_obj_t * ui_ChargPagebMinLabel;
lv_obj_t * ui_ChargPageTimePoint;

lv_timer_t * ui_ChargPageTimer;

///////////////////// Data Init ////////////////////


/////////////////////// Timer //////////////////////
// need to be destroyed when the page is destroyed
static void ChargPage_timer_cb(lv_timer_t * timer)
{
    if(Page_Get_NowPage()->page_obj == &ui_ChargPage)
		{
			uint8_t value_strbuf[5];

			HW_DateTimeTypeDef DateTime;
      HWInterface.RealTimeClock.GetTimeDate(&DateTime);

			if(ui_TimeMinuteValue != DateTime.Minutes)
			{
				ui_TimeMinuteValue = DateTime.Minutes;
				sprintf(value_strbuf,"%02d",ui_TimeMinuteValue);
				lv_label_set_text(ui_ChargPagebMinLabel, value_strbuf);
			}

			if(ui_TimeHourValue != DateTime.Hours)
			{
				ui_TimeHourValue = DateTime.Hours;
				sprintf(value_strbuf,"%02d",ui_TimeHourValue);
				lv_label_set_text(ui_ChargPagebHourLabel, value_strbuf);
			}

			ui_BatArcValue = HWInterface.Power.BatCalculate();
			if(ui_BatArcValue>0 && ui_BatArcValue<=100)
			{
				lv_arc_set_value(ui_CharPageBatArc, ui_BatArcValue);
				sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
				lv_label_set_text(ui_ChargPageBatNum, value_strbuf);
			}
			else
			{ui_BatArcValue=0;}

		}
}


///////////////////// SCREEN init ////////////////////
void ui_ChargPage_screen_init(void)
{
		uint8_t value_strbuf[5];
    ui_ChargPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ChargPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CharPageBatArc = lv_arc_create(ui_ChargPage);
    lv_obj_set_width(ui_CharPageBatArc, 60);
    lv_obj_set_height(ui_CharPageBatArc, 60);
    lv_obj_set_x(ui_CharPageBatArc, -70);
    lv_obj_set_y(ui_CharPageBatArc, -70);
    lv_obj_set_align(ui_CharPageBatArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CharPageBatArc, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_arc_set_value(ui_CharPageBatArc, ui_BatArcValue);
    lv_arc_set_bg_angles(ui_CharPageBatArc, 270, 629);
    lv_obj_set_style_arc_width(ui_CharPageBatArc, 8, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_CharPageBatArc, lv_color_hex(0x64C864), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_CharPageBatArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_CharPageBatArc, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_CharPageBatArc, lv_color_hex(0x32C832), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CharPageBatArc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CharPageBatArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CharPageBatArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CharPageBatArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CharPageBatArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ChargPageBatIcon = lv_label_create(ui_ChargPage);
    lv_obj_set_width(ui_ChargPageBatIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargPageBatIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargPageBatIcon, -70);
    lv_obj_set_y(ui_ChargPageBatIcon, -70);
    lv_obj_set_align(ui_ChargPageBatIcon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChargPageBatIcon, "");
    lv_obj_set_style_text_color(ui_ChargPageBatIcon, lv_color_hex(0x64C864), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargPageBatIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargPageBatIcon, &ui_font_iconfont24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChargPageBatNum = lv_label_create(ui_ChargPage);
    lv_obj_set_width(ui_ChargPageBatNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargPageBatNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargPageBatNum, -70);
    lv_obj_set_y(ui_ChargPageBatNum, -25);
    lv_obj_set_align(ui_ChargPageBatNum, LV_ALIGN_CENTER);
		sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
    lv_label_set_text(ui_ChargPageBatNum, value_strbuf);
    lv_obj_set_style_text_color(ui_ChargPageBatNum, lv_color_hex(0x64C864), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargPageBatNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargPageBatNum, &ui_font_Cuyuan24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChargPagebHourLabel = lv_label_create(ui_ChargPage);
    lv_obj_set_width(ui_ChargPagebHourLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargPagebHourLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargPagebHourLabel, 50);
    lv_obj_set_y(ui_ChargPagebHourLabel, -65);
    lv_obj_set_align(ui_ChargPagebHourLabel, LV_ALIGN_CENTER);
		sprintf(value_strbuf,"%02d",ui_TimeHourValue);
    lv_label_set_text(ui_ChargPagebHourLabel, value_strbuf);
    lv_obj_set_style_text_color(ui_ChargPagebHourLabel, lv_color_hex(0x64C864), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargPagebHourLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargPagebHourLabel, &ui_font_Cuyuan100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChargPagebMinLabel = lv_label_create(ui_ChargPage);
    lv_obj_set_width(ui_ChargPagebMinLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargPagebMinLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargPagebMinLabel, 50);
    lv_obj_set_y(ui_ChargPagebMinLabel, 60);
    lv_obj_set_align(ui_ChargPagebMinLabel, LV_ALIGN_CENTER);
		sprintf(value_strbuf,"%02d",ui_TimeMinuteValue);
    lv_label_set_text(ui_ChargPagebMinLabel, value_strbuf);
    lv_obj_set_style_text_color(ui_ChargPagebMinLabel, lv_color_hex(0x64C864), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargPagebMinLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargPagebMinLabel, &ui_font_Cuyuan100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChargPageTimePoint = lv_label_create(ui_ChargPage);
    lv_obj_set_width(ui_ChargPageTimePoint, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChargPageTimePoint, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ChargPageTimePoint, -35);
    lv_obj_set_y(ui_ChargPageTimePoint, 50);
    lv_obj_set_align(ui_ChargPageTimePoint, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChargPageTimePoint, ":");
    lv_obj_set_style_text_color(ui_ChargPageTimePoint, lv_color_hex(0x64C864), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChargPageTimePoint, 160, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChargPageTimePoint, &ui_font_Cuyuan100, LV_PART_MAIN | LV_STATE_DEFAULT);

    //timer
    ui_ChargPageTimer = lv_timer_create(ChargPage_timer_cb, 2000,  NULL);

}

/////////////////// SCREEN deinit ////////////////////
void ui_ChargPage_screen_deinit(void)
{
  lv_timer_del(ui_ChargPageTimer);
}
