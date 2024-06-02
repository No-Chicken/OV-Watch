// LVGL VERSION: 8.2.0

#ifndef UI_H
#define UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

#include "stdio.h"
#include "./Func/PageStack.h"
#include "./Func/pubsub.h"

LV_FONT_DECLARE(ui_font_Cuyuan18);
LV_FONT_DECLARE(ui_font_Cuyuan20);
LV_FONT_DECLARE(ui_font_Cuyuan24);
LV_FONT_DECLARE(ui_font_Cuyuan30);
LV_FONT_DECLARE(ui_font_Cuyuan38);
LV_FONT_DECLARE(ui_font_Cuyuan48);
LV_FONT_DECLARE(ui_font_Cuyuan80);
LV_FONT_DECLARE(ui_font_Cuyuan100);
LV_FONT_DECLARE(ui_font_iconfont16);
LV_FONT_DECLARE(ui_font_iconfont24);
LV_FONT_DECLARE(ui_font_iconfont28);
LV_FONT_DECLARE(ui_font_iconfont30);
LV_FONT_DECLARE(ui_font_iconfont32);
LV_FONT_DECLARE(ui_font_iconfont34);
LV_FONT_DECLARE(ui_font_iconfont45);

void ui_init(void);

void SDL_KeyBoard_Subscriber(PubSub_Message_t message);


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
