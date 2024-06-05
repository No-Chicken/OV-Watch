#ifndef _DATEDAYSETPAGE_UI_H
#define _DATEDAYSETPAGE_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_DateTimeSetPage;
extern lv_obj_t * ui_APPSyPanel;
extern lv_obj_t * ui_APPSySwitch;
extern lv_obj_t * ui_APPSyLabel;
extern lv_obj_t * ui_DateSetPanel;
extern lv_obj_t * ui_DateSetLabel;
extern lv_obj_t * ui_DateSetLabel1;
extern lv_obj_t * ui_DateSetLabel2;
extern lv_obj_t * ui_DateSetLabel3;
extern lv_obj_t * ui_TimeSetPanel;
extern lv_obj_t * ui_TimeSetLabel;
extern lv_obj_t * ui_TimeSetLabel1;
extern lv_obj_t * ui_TimeSetLabel2;
extern lv_obj_t * ui_TimeSetLabel3;
extern lv_obj_t * ui_DateSetPage;
extern lv_obj_t * ui_YearSetRoller;
extern lv_obj_t * ui_MonthSetRoller;
extern lv_obj_t * ui_DaySetRoller;
extern lv_obj_t * ui_DateSetOKButton;
extern lv_obj_t * ui_DateSetOKicon;
extern lv_obj_t * ui_TimeSetPage;
extern lv_obj_t * ui_HourSetRoller;
extern lv_obj_t * ui_TimePoint;
extern lv_obj_t * ui_MinSetRoller;
extern lv_obj_t * ui_TimePoint1;
extern lv_obj_t * ui_SecSetRoller;
extern lv_obj_t * ui_TimeSetOKButton;
extern lv_obj_t * ui_TimeSetOKicon;

void ui_DateTimeSetPage_screen_init(void);
void ui_DateSetPage_screen_init(void);
void ui_TimeSetPage_screen_init(void);

extern uint8_t user_APPSy_EN;

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

