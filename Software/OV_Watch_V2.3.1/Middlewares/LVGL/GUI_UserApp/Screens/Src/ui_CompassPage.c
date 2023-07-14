#include "ui.h"
#include "ui_helpers.h"
#include "ui_CompassPage.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_CompassPage;
lv_obj_t * ui_CompassMeter;
lv_obj_t * ui_Compassneedle;

lv_obj_t * ui_CompassDirBtn;
lv_obj_t * ui_CompassDirLabel;
lv_obj_t * ui_CompassDirIcon;

lv_obj_t * ui_EnvAltitudeBtn;
lv_obj_t * ui_EnvAltitudeLabel;
lv_obj_t * ui_EnvAltitudeIcon;

uint16_t ui_CompassDirValue = 0;
int16_t ui_EnvAltitudeValue = 0;

///////////////////// FUNCTIONS ////////////////////


///////////////////// SCREENS ////////////////////
void ui_CompassPage_screen_init(void)
{
    uint8_t value_strbuf[10];
		
		ui_CompassPage = lv_obj_create(NULL);

    ui_CompassMeter = lv_meter_create(ui_CompassPage);
    lv_obj_set_size(ui_CompassMeter, 230, 230);
    lv_obj_center(ui_CompassMeter);
    lv_obj_set_pos(ui_CompassMeter,0,-20);

    lv_meter_scale_t * scale_360 = lv_meter_add_scale(ui_CompassMeter);
    lv_meter_set_scale_ticks(ui_CompassMeter, scale_360, 61, 1, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(ui_CompassMeter, scale_360, 0, 360, 360, 0);

    lv_meter_scale_t * scale_12 = lv_meter_add_scale(ui_CompassMeter);
    lv_meter_set_scale_ticks(ui_CompassMeter, scale_12, 12, 0, 0, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(ui_CompassMeter, scale_12, 1, 2, 15, lv_color_white(), 15);
    lv_meter_set_scale_range(ui_CompassMeter, scale_12, 0, 330, 330, 270);


    ui_Compassneedle = lv_img_create(ui_CompassMeter);
    lv_img_set_src(ui_Compassneedle, &ui_img_compass_needle_png);
    lv_obj_set_width(ui_Compassneedle, LV_SIZE_CONTENT);   /// 23
    lv_obj_set_height(ui_Compassneedle, LV_SIZE_CONTENT);    /// 171
    lv_obj_set_align(ui_Compassneedle, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Compassneedle, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Compassneedle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_angle(ui_Compassneedle, ui_CompassDirValue*10);


    ui_EnvAltitudeBtn = lv_btn_create(ui_CompassPage);
    lv_obj_set_size(ui_EnvAltitudeBtn, 100, 30);
    lv_obj_align_to(ui_EnvAltitudeBtn,ui_CompassMeter,LV_ALIGN_BOTTOM_MID,60,50);
    lv_obj_add_flag(ui_EnvAltitudeBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_EnvAltitudeBtn, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_EnvAltitudeBtn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_EnvAltitudeBtn, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_EnvAltitudeBtn, 128, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EnvAltitudeIcon = lv_label_create(ui_EnvAltitudeBtn);
    lv_obj_set_align(ui_EnvAltitudeIcon,LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(ui_EnvAltitudeIcon,-10,0);
    lv_label_set_text(ui_EnvAltitudeIcon, "\xEE\x9A\x9B");
    lv_obj_set_style_text_opa(ui_EnvAltitudeIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_EnvAltitudeIcon, &ui_font_iconfont28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_EnvAltitudeLabel = lv_label_create(ui_EnvAltitudeBtn);
    lv_obj_set_align(ui_EnvAltitudeLabel,LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(ui_EnvAltitudeLabel,17,0);
		sprintf(value_strbuf,":%dm",ui_EnvAltitudeValue);
    lv_label_set_text(ui_EnvAltitudeLabel, value_strbuf);
    lv_obj_set_style_text_font(ui_EnvAltitudeLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CompassDirBtn = lv_btn_create(ui_CompassPage);
    lv_obj_set_size(ui_CompassDirBtn, 100, 30);
    lv_obj_align_to(ui_CompassDirBtn,ui_CompassMeter,LV_ALIGN_BOTTOM_MID,-60,50);
    lv_obj_add_flag(ui_CompassDirBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CompassDirBtn, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CompassDirBtn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CompassDirBtn, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CompassDirBtn, 128, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CompassDirIcon = lv_label_create(ui_CompassDirBtn);
    lv_obj_set_align(ui_CompassDirIcon,LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(ui_CompassDirIcon,-10,0);
    lv_label_set_text(ui_CompassDirIcon, "\xee\x9e\x88");
    lv_obj_set_style_text_opa(ui_CompassDirIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CompassDirIcon, &ui_font_iconfont28, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CompassDirLabel = lv_label_create(ui_CompassDirBtn);
    lv_obj_set_align(ui_CompassDirLabel,LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(ui_CompassDirLabel,17,0);
		sprintf(value_strbuf,":%d",ui_CompassDirValue);
    lv_label_set_text(ui_CompassDirLabel, value_strbuf);
    lv_obj_set_style_text_font(ui_CompassDirLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);
	

}
