#ifndef _UI_SPO2PAGE_H
#define _UI_SPO2PAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t * ui_SPO2Page;
extern lv_obj_t * ui_SPO2NumLabel;
extern lv_obj_t * ui_SPO2UnitLabel;
extern lv_obj_t * ui_SPO2NoticeLabel;
extern lv_obj_t * ui_SPO2Icon;

extern uint8_t ui_SPO2Value;

void ui_SPO2Page_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
