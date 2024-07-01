#ifndef _UI_HOMEPAGE_H
#define _UI_HOMEPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

extern lv_obj_t * ui_HomePage;
extern lv_obj_t * ui_TimeHourLabel;
extern lv_obj_t * ui_TimeColonLabel;
extern lv_obj_t * ui_TimeMinuteLabel;
extern lv_obj_t * ui_BatArc;
extern lv_obj_t * ui_BaticonLabel;
extern lv_obj_t * ui_BatNumLabel;
extern lv_obj_t * ui_DateLabel;
extern lv_obj_t * ui_DayLabel;
extern lv_obj_t * ui_StepiconLabel;
extern lv_obj_t * ui_StepCnLabel;
extern lv_obj_t * ui_StepNumLabel;
extern lv_obj_t * ui_StepNumBar;
extern lv_obj_t * ui_TempArc;
extern lv_obj_t * ui_TempiconLabel;
extern lv_obj_t * ui_TempNumLabel;
extern lv_obj_t * ui_HumiiconLabel;
extern lv_obj_t * ui_HumiArc;
extern lv_obj_t * ui_HumiNumLabel;
extern lv_obj_t * ui_HRiconLabel;
extern lv_obj_t * ui_HRSpinner;
extern lv_obj_t * ui_HRNumLabel;

extern lv_obj_t * ui_DropDownPanel;
extern lv_obj_t * ui_UpBGPanel;
extern lv_obj_t * ui_NFCButton;
extern lv_obj_t * ui_NFCLabel;
extern lv_obj_t * ui_BLEButton;
extern lv_obj_t * ui_BLELabel;
extern lv_obj_t * ui_PowerButton;
extern lv_obj_t * ui_PowerLabel;
extern lv_obj_t * ui_SetButton;
extern lv_obj_t * ui_SetLabel;
extern lv_obj_t * ui_LightSlider;
extern lv_obj_t * ui_LightLabel;
extern lv_obj_t * ui_DownBGPanel;

extern uint8_t ui_TimeHourValue;
extern uint8_t ui_TimeMinuteValue;
extern uint8_t ui_DateMonthValue;
extern uint8_t ui_DateDayValue;
extern uint8_t ui_DataWeekdayValue;
extern const char * ui_Days[7];

extern uint8_t ui_BatArcValue;
extern uint16_t ui_StepNumValue;
extern uint8_t ui_LightSliderValue;

extern Page_t Page_Home;

void ui_event_HomePage_DropDownPanel(lv_event_t * e);
void ui_event_NFCButton(lv_event_t * e);
void ui_event_BLEButton(lv_event_t * e);
void ui_event_PowerButton(lv_event_t * e);
void ui_event_SetButton(lv_event_t * e);

void ui_HomePage_screen_init(void);
void ui_PowerPage_screen_init(void);

void ui_HomePage_screen_deinit(void);
void ui_PowerPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
