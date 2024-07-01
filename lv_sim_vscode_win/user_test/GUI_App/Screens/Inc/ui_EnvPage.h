#ifndef _UI_ENVPAGE_H
#define _UI_ENVPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t * ui_EnvPage;
extern lv_obj_t * ui_EnvTempBar;
extern lv_obj_t * ui_EnvHumiBar;
extern lv_obj_t * ui_EnvTempNumLabel;
extern lv_obj_t * ui_EnvHumiNumLabel;
extern lv_obj_t * ui_EnvTempUnitLabel;
extern lv_obj_t * ui_EnvHumiUnitLabel;
extern lv_obj_t * ui_EnvHumiIcon;
extern lv_obj_t * ui_EnvTempIcon;

extern int8_t ui_EnvTempValue;
extern int8_t ui_EnvHumiValue;

extern Page_t Page_Env;

void ui_EnvPage_screen_init(void);
void ui_EnvPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
