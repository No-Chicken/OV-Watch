#ifndef _UI_COMPASSPAGE_H
#define _UI_COMPASSPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t * ui_CompassPage;
extern lv_obj_t * ui_Compassneedle;
extern lv_obj_t * ui_CompassDirLabel;
extern lv_obj_t * ui_EnvAltitudeLabel;

extern uint16_t ui_CompassDirValue;
extern int16_t ui_EnvAltitudeValue;

void ui_CompassPage_screen_init(void);
LV_IMG_DECLARE(ui_img_compass_needle_png);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
