#include "ui.h"
#include "ui_helpers.h"
#include "ui_TimerPage.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_TimerPage;
lv_obj_t * ui_TimerMeter;
lv_obj_t * ui_TimerStartBtn;
lv_obj_t * ui_TimerReBtn;
lv_obj_t * ui_TimerStartLabel;
lv_obj_t * ui_TimerReLabel;
lv_obj_t * ui_TimerMinLabel;
lv_obj_t * ui_TimerSecColonLabel;
lv_obj_t * ui_TimerSecLabel;
lv_obj_t * ui_TimerMilSecColonLabel;
lv_obj_t * ui_TimerMilSecLabel;

lv_timer_t * ui_TimerPageTimer;

uint8_t ui_TimerPageFlag=0;
uint8_t ui_TimerPage_min=0;
uint8_t ui_TimerPage_sec=0;
uint8_t ui_TimerPage_10ms=0;
uint8_t ui_TimerPage_ms=0;

///////////////////// ANIMATIONS ////////////////////


///////////////////// FUNCTIONS ////////////////////
void ui_event_TimerStartBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        //checked
        ui_TimerPageFlag = 1;
        lv_label_set_text(ui_TimerStartLabel, LV_SYMBOL_PAUSE);
        lv_timer_resume(ui_TimerPageTimer);

    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        //released
        ui_TimerPageFlag = 0;
        lv_label_set_text(ui_TimerStartLabel, LV_SYMBOL_PLAY);
        lv_timer_pause(ui_TimerPageTimer);

    }
}

void ui_event_TimerReBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED && !lv_obj_has_state(ui_TimerStartBtn, LV_STATE_CHECKED))
    {
        //clear
        lv_timer_pause(ui_TimerPageTimer);
        lv_label_set_text(ui_TimerMinLabel, "00");
        lv_label_set_text(ui_TimerSecLabel, "00");
        lv_label_set_text(ui_TimerMilSecLabel, "00");
        ui_TimerPage_min = 0;
        ui_TimerPage_sec = 0;
				ui_TimerPage_10ms = 0;
        ui_TimerPage_ms = 0;

    }

}


void LabelRefresh_timer(lv_timer_t * timer)
{
    uint8_t strbuf[2];

    sprintf(strbuf,"%02d",ui_TimerPage_min);
    lv_label_set_text(ui_TimerMinLabel, strbuf);
    sprintf(strbuf,"%02d",ui_TimerPage_sec);
    lv_label_set_text(ui_TimerSecLabel, strbuf);
    sprintf(strbuf,"%02d",ui_TimerPage_10ms);
    lv_label_set_text(ui_TimerMilSecLabel, strbuf);


}

void ui_TimerPage_screen_init(void)
{
    ui_TimerPageFlag=0;
    ui_TimerPage_min=0;
    ui_TimerPage_sec=0;
		ui_TimerPage_10ms=0;
    ui_TimerPage_ms=0;

    ui_TimerPage = lv_obj_create(NULL);

    ui_TimerMeter = lv_meter_create(ui_TimerPage);
    lv_obj_set_size(ui_TimerMeter, 240, 240);
    lv_obj_center(ui_TimerMeter);

    lv_obj_remove_style(ui_TimerMeter, NULL, LV_PART_INDICATOR);
    lv_meter_scale_t * scale_min = lv_meter_add_scale(ui_TimerMeter);
    lv_meter_set_scale_ticks(ui_TimerMeter, scale_min, 61, 1, 10, lv_palette_main(LV_PALETTE_BLUE));
    lv_meter_set_scale_range(ui_TimerMeter, scale_min, 0, 60, 360, 270);

    ui_TimerStartBtn = lv_btn_create(ui_TimerMeter);
    lv_obj_set_width(ui_TimerStartBtn, 60);
    lv_obj_set_height(ui_TimerStartBtn, 60);
    lv_obj_set_style_radius(ui_TimerStartBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimerStartBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(ui_TimerStartBtn, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerStartBtn,40,50);
    lv_obj_add_flag(ui_TimerStartBtn, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TimerStartBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    ui_TimerReBtn = lv_btn_create(ui_TimerMeter);
    lv_obj_set_width(ui_TimerReBtn, 60);
    lv_obj_set_height(ui_TimerReBtn, 60);
    lv_obj_set_style_radius(ui_TimerReBtn, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimerReBtn, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(ui_TimerReBtn, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerReBtn,-40,50);

    ui_TimerStartLabel = lv_label_create(ui_TimerStartBtn);
    lv_label_set_text(ui_TimerStartLabel, LV_SYMBOL_PLAY);//LV_SYMBOL_PAUSE
    lv_obj_center(ui_TimerStartLabel);
    lv_obj_set_style_text_font(ui_TimerStartLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerReLabel = lv_label_create(ui_TimerReBtn);
    lv_label_set_text(ui_TimerReLabel, LV_SYMBOL_REFRESH);
    lv_obj_center(ui_TimerReLabel);
    lv_obj_set_style_text_font(ui_TimerReLabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerMinLabel = lv_label_create(ui_TimerMeter);
    lv_obj_set_align(ui_TimerMinLabel, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerMinLabel,-60,-20);
    lv_label_set_text(ui_TimerMinLabel, "00");
    lv_obj_set_style_text_font(ui_TimerMinLabel, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerSecColonLabel = lv_label_create(ui_TimerMeter);
    lv_obj_set_align(ui_TimerSecColonLabel, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerSecColonLabel,-30,-20);
    lv_label_set_text(ui_TimerSecColonLabel, ":");
    lv_obj_set_style_text_font(ui_TimerSecColonLabel, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerSecLabel = lv_label_create(ui_TimerMeter);
    lv_obj_set_align(ui_TimerSecLabel, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerSecLabel,0,-20);
    lv_label_set_text(ui_TimerSecLabel, "00");
    lv_obj_set_style_text_font(ui_TimerSecLabel, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerMilSecColonLabel = lv_label_create(ui_TimerMeter);
    lv_obj_set_align(ui_TimerMilSecColonLabel, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerMilSecColonLabel,30,-20);
    lv_label_set_text(ui_TimerMilSecColonLabel, ".");
    lv_obj_set_style_text_font(ui_TimerMilSecColonLabel, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimerMilSecLabel = lv_label_create(ui_TimerMeter);
    lv_obj_set_align(ui_TimerMilSecLabel, LV_ALIGN_CENTER);
    lv_obj_set_pos(ui_TimerMilSecLabel,60,-20);
    lv_label_set_text(ui_TimerMilSecLabel, "00");
    lv_obj_set_style_text_font(ui_TimerMilSecLabel, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    //events
    lv_obj_add_event_cb(ui_TimerStartBtn, ui_event_TimerStartBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TimerReBtn, ui_event_TimerReBtn, LV_EVENT_ALL, NULL);

    //timer
    ui_TimerPageTimer = lv_timer_create(LabelRefresh_timer, 10,  NULL);
    lv_timer_pause(ui_TimerPageTimer);

}



