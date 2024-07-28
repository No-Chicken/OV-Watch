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

extern Page_t Page_SPO2;

void ui_SPO2Page_screen_init(void);
void ui_SPO2Page_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
