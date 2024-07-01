#ifndef _UI_GAMEMEMPAGE_H
#define _UI_GAMEMEMPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

extern lv_obj_t * ui_GameMem_Page;
extern Page_t Page_GameMem;

void ui_GameMemPage_screen_init(void);
void ui_GameMemPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
