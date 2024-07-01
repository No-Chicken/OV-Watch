#ifndef _UI_GAMESELECTPAGE_H
#define _UI_GAMESELECTPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

extern lv_obj_t * ui_GameSelectPage;
extern Page_t Page_GameSelect;

void ui_GameSelectPage_screen_init(void);
void ui_GameSelectPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
