#ifndef _UI_SETPAGE_H
#define _UI_SETPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t * ui_SetPage;
extern lv_obj_t * ui_LightTimePanel;
extern lv_obj_t * ui_LightTimeButton;
extern lv_obj_t * ui_LightTimeicon;
extern lv_obj_t * ui_LightTimeLabel;
extern lv_obj_t * ui_TurnOffTimePanel;
extern lv_obj_t * ui_TOffTimeButton;
extern lv_obj_t * ui_TOffTimeicon;
extern lv_obj_t * ui_TOffTimeLabel;
extern lv_obj_t * ui_DateTimeSetPanel;
extern lv_obj_t * ui_DateTimeSetButton;
extern lv_obj_t * ui_LOffTimeicon;
extern lv_obj_t * ui_DateTimeSetLabel;
extern lv_obj_t * ui_WristPanel;
extern lv_obj_t * ui_WristButton;
extern lv_obj_t * ui_Wristicon;
extern lv_obj_t * ui_WristLabel;
extern lv_obj_t * ui_WristSwitch;
extern lv_obj_t * ui_PasswordPanel;
extern lv_obj_t * ui_PasswordButton;
extern lv_obj_t * ui_Passwordicon;
extern lv_obj_t * ui_PasswordLabel;

extern Page_t Page_Set;

void ui_SetPage_screen_init(void);

void ui_SetPage_screen_deinit(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
