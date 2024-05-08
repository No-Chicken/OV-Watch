#include "ui.h"
#include "ui_helpers.h"
#include "ui_AboutPage.h"
///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_AboutPage;


///////////////////// FUNCTIONS ////////////////////


///////////////////// SCREENS ////////////////////
void ui_AboutPage_screen_init(void)
{
    lv_obj_t * ui_NameLabel;
    lv_obj_t * ui_NameTextLabel;
    lv_obj_t * ui_VersionLabel;
    lv_obj_t * ui_VersionTextLabel;
    lv_obj_t * ui_MCULabel;
    lv_obj_t * ui_MCUTextLabel;
    lv_obj_t * ui_OSLabel;
    lv_obj_t * ui_OSTextLabel;
    lv_obj_t * ui_GUILabel;
    lv_obj_t * ui_GUITextLabel;
    lv_obj_t * ui_AuthorHLabel;
    lv_obj_t * ui_AuthorHTextLabel;
    lv_obj_t * ui_AuthorSLabel;
    lv_obj_t * ui_AuthorSTextLabel;
		lv_obj_t * ui_AuthorGLabel;
    lv_obj_t * ui_AuthorGTextLabel;

    ui_AboutPage = lv_obj_create(NULL);

    ui_NameLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_NameLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NameLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NameLabel, 20);
    lv_obj_set_y(ui_NameLabel, 15);
    lv_label_set_text(ui_NameLabel, "手表型号");
    lv_obj_set_style_text_color(ui_NameLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NameLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NameLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NameTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_NameTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_NameTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_NameTextLabel, 25);
    lv_obj_set_y(ui_NameTextLabel, 40);
    lv_label_set_text(ui_NameTextLabel, "OV-Watch");
    lv_obj_set_style_text_font(ui_NameTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VersionLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_VersionLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VersionLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_VersionLabel, 20);
    lv_obj_set_y(ui_VersionLabel, 65);
    lv_label_set_text(ui_VersionLabel, "固件型号");
    lv_obj_set_style_text_color(ui_VersionLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_VersionLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_VersionLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VersionTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_VersionTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VersionTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_VersionTextLabel, 25);
    lv_obj_set_y(ui_VersionTextLabel, 90);
    lv_label_set_text(ui_VersionTextLabel, "V2.3.2");
    lv_obj_set_style_text_font(ui_VersionTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MCULabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_MCULabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MCULabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MCULabel, 20);
    lv_obj_set_y(ui_MCULabel, 115);
    lv_label_set_text(ui_MCULabel, "主控芯片");
    lv_obj_set_style_text_color(ui_MCULabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MCULabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MCULabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MCUTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_MCUTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MCUTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MCUTextLabel, 25);
    lv_obj_set_y(ui_MCUTextLabel, 140);
    lv_label_set_text(ui_MCUTextLabel, "STM32F411CEU6");
    lv_obj_set_style_text_font(ui_MCUTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_OSLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_OSLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OSLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OSLabel, 20);
    lv_obj_set_y(ui_OSLabel, 165);
    lv_label_set_text(ui_OSLabel, "操作系统");
    lv_obj_set_style_text_color(ui_OSLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_OSLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_OSLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_OSTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_OSTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OSTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_OSTextLabel, 25);
    lv_obj_set_y(ui_OSTextLabel, 190);
    lv_label_set_text(ui_OSTextLabel, "FreeRTOS");
    lv_obj_set_style_text_font(ui_OSTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GUILabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_GUILabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GUILabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GUILabel, 20);
    lv_obj_set_y(ui_GUILabel, 215);
    lv_label_set_text(ui_GUILabel, "图形界面");
    lv_obj_set_style_text_color(ui_GUILabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_GUILabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GUILabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GUITextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_GUITextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GUITextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_GUITextLabel, 25);
    lv_obj_set_y(ui_GUITextLabel, 240);
    lv_label_set_text(ui_GUITextLabel, "LVGL");
    lv_obj_set_style_text_font(ui_GUITextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuthorHLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorHLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorHLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorHLabel, 20);
    lv_obj_set_y(ui_AuthorHLabel, 265);
    lv_label_set_text(ui_AuthorHLabel, "硬件开发者");
    lv_obj_set_style_text_color(ui_AuthorHLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AuthorHLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AuthorHLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuthorHTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorHTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorHTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorHTextLabel, 25);
    lv_obj_set_y(ui_AuthorHTextLabel, 290);
    lv_label_set_text(ui_AuthorHTextLabel, "Kingham");
    lv_obj_set_style_text_font(ui_AuthorHTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuthorSLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorSLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorSLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorSLabel, 20);
    lv_obj_set_y(ui_AuthorSLabel, 315);
    lv_label_set_text(ui_AuthorSLabel, "软件开发者");
    lv_obj_set_style_text_color(ui_AuthorSLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AuthorSLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AuthorSLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuthorSTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorSTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorSTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorSTextLabel, 25);
    lv_obj_set_y(ui_AuthorSTextLabel, 340);
    lv_label_set_text(ui_AuthorSTextLabel, "Kingham");
    lv_obj_set_style_text_font(ui_AuthorSTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
		
		ui_AuthorGLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorGLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorGLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorGLabel, 20);
    lv_obj_set_y(ui_AuthorGLabel, 365);
    lv_label_set_text(ui_AuthorGLabel, "界面设计者");
    lv_obj_set_style_text_color(ui_AuthorGLabel, lv_color_hex(0x1980E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AuthorGLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AuthorGLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuthorGTextLabel = lv_label_create(ui_AboutPage);
    lv_obj_set_width(ui_AuthorGTextLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AuthorGTextLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AuthorGTextLabel, 25);
    lv_obj_set_y(ui_AuthorGTextLabel, 390);
    lv_label_set_text(ui_AuthorGTextLabel, "Kingham");
    lv_obj_set_style_text_font(ui_AuthorGTextLabel, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

}
