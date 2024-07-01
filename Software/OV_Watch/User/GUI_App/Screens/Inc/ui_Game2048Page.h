#ifndef _UI_GAME2048PAGE_H
#define _UI_GAME2048PAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

extern lv_obj_t * ui_Game2048Page;

extern Page_t Page_Game_2048;

void ui_Game2048Page_screen_init(void);
void ui_Game2048Page_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
