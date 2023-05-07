#ifndef _UI_TIMERPAGE_H
#define _UI_TIMERPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern lv_obj_t * ui_TimerPage;

extern uint8_t ui_TimerPageFlag;
extern uint8_t ui_TimerPage_min;
extern uint8_t ui_TimerPage_sec;
extern uint8_t ui_TimerPage_10ms;
extern uint8_t ui_TimerPage_ms;

void ui_TimerPage_screen_init(void);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
