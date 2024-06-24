#ifndef _UI_OFFTIMEPAGE_H
#define _UI_OFFTIMEPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_LOffTimeSetPage;
extern lv_obj_t * ui_LTimeSetRoller;
extern lv_obj_t * ui_LTimeSetLabel;
extern lv_obj_t * ui_LTimeSetOKButton;
extern lv_obj_t * ui_LTimeSetOKLabel;
extern lv_obj_t * ui_LTimeSeticon;

extern lv_obj_t * ui_TOffTimeSetPage;
extern lv_obj_t * ui_TTimeSetRoller;
extern lv_obj_t * ui_TTimeSetLabel;
extern lv_obj_t * ui_TTimeSetOKButton;
extern lv_obj_t * ui_TTimeSetOKLabel;
extern lv_obj_t * ui_TTimeSeticon;

extern const uint8_t ui_LTimeOptions[6];
extern const uint8_t ui_TTimeOptions[6];
extern uint8_t ui_LTimeValue;
extern uint8_t ui_TTimeValue;

void ui_LOffTimeSetPage_screen_init(void);
void ui_TOffTimeSetPage_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
