#ifndef _UI_MENUPAGE_H
#define _UI_MENUPAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../ui.h"

#define CALENDAR_PAGE_EN		1
#define COMPUTER_PAGE_EN		1
#define TIMER_PAGE_EN			1
#define CARD_PAGE_EN            1
#define SPROTS_PAGE_EN			0
#define HR_PAGE_EN				1
#define O2_PAGE_EN				1
#define ENVIRONMENT_PAGE_EN	    1
#define COMPASS_PAGE_EN			1
#define GAME_PAGE_EN            1
#define SET_PAGE_EN				1
#define ABOUT_PAGE_EN			1

extern lv_obj_t * ui_MenuPage;
extern lv_obj_t * ui_MenuCalPanel;
extern lv_obj_t * ui_MenuCalButton;
extern lv_obj_t * ui_MenuCalicon;
extern lv_obj_t * ui_MenuCalLabel;

extern lv_obj_t * ui_MenuComPanel;
extern lv_obj_t * ui_MenuComButton;
extern lv_obj_t * ui_MenuComicon;
extern lv_obj_t * ui_MenuComLabel;

extern lv_obj_t * ui_MenuTimPanel;
extern lv_obj_t * ui_MenuTimButton;
extern lv_obj_t * ui_MenuTimicon;
extern lv_obj_t * ui_MenuTimLabel;

extern lv_obj_t * ui_MenuCardPanel;
extern lv_obj_t * ui_MenuCardButton;
extern lv_obj_t * ui_MenuCardicon;
extern lv_obj_t * ui_MenuCardLabel;

extern lv_obj_t * ui_MenuSprPanel;
extern lv_obj_t * ui_MenuSprButton;
extern lv_obj_t * ui_MenuSpricon;
extern lv_obj_t * ui_MenuSprLabel;

extern lv_obj_t * ui_MenuHRPanel;
extern lv_obj_t * ui_MenuHRButton;
extern lv_obj_t * ui_MenuHRicon;
extern lv_obj_t * ui_MenuHRLabel;

extern lv_obj_t * ui_MenuO2Panel;
extern lv_obj_t * ui_MenuO2Button;
extern lv_obj_t * ui_MenuO2icon;
extern lv_obj_t * ui_MenuO2Label;

extern lv_obj_t * ui_MenuEnvPanel;
extern lv_obj_t * ui_MenuEnvButton;
extern lv_obj_t * ui_MenuEnvicon;
extern lv_obj_t * ui_MenuEnvLabel;

extern lv_obj_t * ui_MenuCPPanel;
extern lv_obj_t * ui_MenuCPButton;
extern lv_obj_t * ui_MenuCPicon;
extern lv_obj_t * ui_MenuCPLabel;

extern lv_obj_t * ui_MenuSetPanel;
extern lv_obj_t * ui_MenuSetButton;
extern lv_obj_t * ui_MenuSeticon;
extern lv_obj_t * ui_MenuSetLabel;

extern lv_obj_t * ui_MenuAbPanel;
extern lv_obj_t * ui_MenuAbButton;
extern lv_obj_t * ui_MenuAbicon;
extern lv_obj_t * ui_MenuAbLabel;

extern int16_t ui_MenuScrollY;

extern Page_t Page_Menu;

void ui_MenuPage_screen_init(void);
void ui_MenuPage_screen_deinit(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
