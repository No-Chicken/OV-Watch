#include "../../ui.h"
#include "../../ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_mboxPanel;
lv_obj_t * ui_WarningSymbol;
lv_obj_t * ui_WarningLabel;
lv_obj_t * ui_ApplyPanel;
lv_obj_t * ui_ApplyLabel;
lv_obj_t * ui_CancelPanel;
lv_obj_t * ui_CancelLabel;

///////////////////// FUNCTIONS ////////////////////;
void ui_mbox_close(void)
{
    lv_obj_del(ui_mboxPanel);
    lv_obj_add_flag(lv_scr_act(),LV_OBJ_FLAG_SCROLLABLE);
}

void ui_mbox1_event_cb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        ui_mbox_close();
    }
}

void ui_mbox2_event_cb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        ui_mbox_close();
    }
}

///////////////////// SCREEN init ////////////////////
void ui_mbox_create(uint8_t * text)
{
    lv_obj_clear_flag(lv_scr_act(), LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_mboxPanel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(ui_mboxPanel, 200);
    lv_obj_set_height(ui_mboxPanel, 130);
    lv_obj_set_align(ui_mboxPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_mboxPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_mboxPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_mboxPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_mboxPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WarningSymbol = lv_label_create(ui_mboxPanel);
    lv_obj_set_width(ui_WarningSymbol, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WarningSymbol, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WarningSymbol, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_WarningSymbol, LV_SYMBOL_WARNING);
    lv_obj_set_style_text_color(ui_WarningSymbol, lv_color_hex(0x0080FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_WarningSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WarningLabel = lv_label_create(ui_mboxPanel);
    lv_obj_set_width(ui_WarningLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WarningLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_WarningLabel, 0);
    lv_obj_set_y(ui_WarningLabel, 25);
    lv_obj_set_align(ui_WarningLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_WarningLabel, text);
    lv_obj_set_style_text_color(ui_WarningLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_WarningLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_WarningLabel, &ui_font_Cuyuan18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ApplyPanel = lv_obj_create(ui_mboxPanel);
    lv_obj_set_width(ui_ApplyPanel, 200);
    lv_obj_set_height(ui_ApplyPanel, 30);
    lv_obj_set_x(ui_ApplyPanel, 0);
    lv_obj_set_y(ui_ApplyPanel, -16);
    lv_obj_set_align(ui_ApplyPanel, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_ApplyPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ApplyPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ApplyPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ApplyPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ApplyPanel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ApplyPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ApplyPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ApplyPanel, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ApplyPanel, lv_color_hex(0x969696), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_ApplyPanel, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ApplyLabel = lv_label_create(ui_ApplyPanel);
    lv_obj_set_width(ui_ApplyLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ApplyLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ApplyLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ApplyLabel, "OK");
    lv_obj_set_style_text_color(ui_ApplyLabel, lv_color_hex(0x5FB878), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ApplyLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CancelPanel = lv_obj_create(ui_mboxPanel);
    lv_obj_set_width(ui_CancelPanel, 200);
    lv_obj_set_height(ui_CancelPanel, 30);
    lv_obj_set_x(ui_CancelPanel, 0);
    lv_obj_set_y(ui_CancelPanel, 14);
    lv_obj_set_align(ui_CancelPanel, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_CancelPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CancelPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CancelPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CancelPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CancelPanel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CancelPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CancelPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CancelPanel, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CancelPanel, lv_color_hex(0x969696), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_CancelPanel, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_CancelLabel = lv_label_create(ui_CancelPanel);
    lv_obj_set_width(ui_CancelLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CancelLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CancelLabel, "Cancel");
    lv_obj_set_style_text_color(ui_CancelLabel, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CancelLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ApplyPanel, ui_mbox1_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CancelPanel, ui_mbox2_event_cb, LV_EVENT_ALL, NULL);
}

/////////////////// SCREEN deinit ////////////////////

