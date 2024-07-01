#ifndef _UI_COMPUTERPAGE_H
#define _UI_COMPUTERPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

extern lv_obj_t * ui_Computerpage;
extern lv_obj_t * ui_CompageBtnM;
extern lv_obj_t * ui_CompageTextarea;
extern lv_obj_t * ui_CompageBackBtn;

extern Page_t Page_Computer;

void ui_ComputerPage_screen_init(void);
void ui_ComputerPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
