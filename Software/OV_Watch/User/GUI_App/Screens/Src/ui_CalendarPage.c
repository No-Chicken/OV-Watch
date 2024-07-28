#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_CalendarPage.h"
#include "../../../Func/Inc/HWDataAccess.h"

///////////////////// Page Manager //////////////////
Page_t Page_Calender = {ui_CalendarPage_screen_init, ui_CalendarPage_screen_deinit, &ui_CalendarPage};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_CalendarPage;
lv_obj_t * ui_CalendarPageCalendar;

///////////////////// FUNCTIONS ////////////////////


///////////////////// SCREEN init ////////////////////
void ui_CalendarPage_screen_init(void)
{
    HW_DateTimeTypeDef DateTime;
    HWInterface.RealTimeClock.GetTimeDate(&DateTime);

    ui_CalendarPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_CalendarPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CalendarPageCalendar = lv_calendar_create(ui_CalendarPage);
    lv_calendar_set_today_date(ui_CalendarPageCalendar, 2000+DateTime.Year, DateTime.Month, DateTime.Date);
    lv_calendar_set_showed_date(ui_CalendarPageCalendar, 2000+DateTime.Year, DateTime.Month);
    lv_obj_t * ui_CalendarPageCalendar_header = lv_calendar_header_arrow_create(ui_CalendarPageCalendar);
    lv_obj_set_width(ui_CalendarPageCalendar, 240);
    lv_obj_set_height(ui_CalendarPageCalendar, 280);
    lv_obj_set_align(ui_CalendarPageCalendar, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_CalendarPageCalendar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CalendarPageCalendar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}

///////////////////// SCREEN deinit ////////////////////
void ui_CalendarPage_screen_deinit(void)
{}
