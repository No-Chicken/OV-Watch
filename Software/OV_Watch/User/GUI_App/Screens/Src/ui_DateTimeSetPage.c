#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_HomePage.h"
#include "../Inc/ui_SetPage.h"
#include "../Inc/ui_DateTimeSetPage.h"
#include "../../../Func/Inc/HWDataAccess.h"

///////////////////// Page Manager //////////////////
Page_t Page_DateTimeSet = {ui_DateTimeSetPage_screen_init, ui_DateTimeSetPage_screen_deinit, &ui_DateTimeSetPage};
Page_t Page_DateSet = {ui_DateSetPage_screen_init, ui_DateSetPage_screen_deinit, &ui_DateSetPage};
Page_t Page_TimeSet = {ui_TimeSetPage_screen_init, ui_TimeSetPage_screen_deinit, &ui_TimeSetPage};

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_DateTimeSetPage;
lv_obj_t * ui_APPSyPanel;
lv_obj_t * ui_APPSySwitch;
lv_obj_t * ui_APPSyLabel;
lv_obj_t * ui_DateSetPanel;
lv_obj_t * ui_DateSetLabel;
lv_obj_t * ui_DateSetLabel1;
lv_obj_t * ui_DateSetLabel2;
lv_obj_t * ui_DateSetLabel3;
lv_obj_t * ui_TimeSetPanel;
lv_obj_t * ui_TimeSetLabel;
lv_obj_t * ui_TimeSetLabel1;
lv_obj_t * ui_TimeSetLabel2;
lv_obj_t * ui_TimeSetLabel3;
lv_obj_t * ui_DateSetPage;
lv_obj_t * ui_YearSetRoller;
lv_obj_t * ui_MonthSetRoller;
lv_obj_t * ui_DaySetRoller;
lv_obj_t * ui_DateSetOKButton;
lv_obj_t * ui_DateSetOKicon;
lv_obj_t * ui_TimeSetPage;
lv_obj_t * ui_HourSetRoller;
lv_obj_t * ui_TimePoint;
lv_obj_t * ui_MinSetRoller;
lv_obj_t * ui_TimePoint1;
lv_obj_t * ui_SecSetRoller;
lv_obj_t * ui_TimeSetOKButton;
lv_obj_t * ui_TimeSetOKicon;


uint8_t user_APPSy_EN=0;

const char  yearoptions[] = "2022\n2023\n2024\n2025\n2026\n2027\n2028\n2029\n2030\n2031\n2032\n2033\n2034\n2035";
const char  monthoptions[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";
const char  day31options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31";
const char  day30options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30";
const char  day29options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29";
const char  day28options[] = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28";
const char  houroptions[] = "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23";
const char  minoptions[] = "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59";
///////////////////// FUNCTIONS ////////////////////
void ui_event_DateTimeSetPage(lv_event_t * e)
{
   lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_GESTURE)
    {
			if(lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT)
      {
				//  user_Stack_Pop(&ScrRenewStack);
        //  ui_SetPage_screen_init();
        //  lv_scr_load_anim(ui_SetPage,LV_SCR_LOAD_ANIM_MOVE_RIGHT,100,0,true);
        Page_Back();
      }
		}
}

void ui_event_DateSetPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
      Page_Load(&Page_DateSet);
        // ui_DateSetPage_screen_init();
        // lv_scr_load_anim(ui_DateSetPage,LV_SCR_LOAD_ANIM_MOVE_LEFT,0,0,true);
				// user_Stack_Push(&ScrRenewStack,(long long int)&ui_DateSetPage);
    }
}

void ui_event_TimeSetPanel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
      Page_Load(&Page_TimeSet);
    }
}

void ui_event_DateSetOKButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
			uint8_t setyear = lv_roller_get_selected(ui_YearSetRoller)+22;
			uint8_t setmonth = lv_roller_get_selected(ui_MonthSetRoller)+1;
			uint8_t setday = lv_roller_get_selected(ui_DaySetRoller)+1;

			HW_RTC_Set_Date(setyear, setmonth, setday);
			ui_DateMonthValue = setmonth;
			ui_DateDayValue = setday;
			ui_DataWeekdayValue = HW_weekday_calculate(setyear,setmonth,setday,20);

			Page_Back();
    }
}

void ui_event_TimeSetOKButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED)
    {
			uint8_t sethour = lv_roller_get_selected(ui_HourSetRoller);
			uint8_t setmin = lv_roller_get_selected(ui_MinSetRoller);
			uint8_t setsec = lv_roller_get_selected(ui_SecSetRoller);
			HW_RTC_Set_Time(sethour,setmin,setsec);
			ui_TimeHourValue = sethour;
			ui_TimeMinuteValue = setmin;

			Page_Back();
    }
}

void ui_event_APPSySwitch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED)
    {
       if(lv_obj_has_state(ui_APPSySwitch,LV_STATE_CHECKED))
       {
            //open
                 user_APPSy_EN=1;
       }
       else
       {
            //close
                 user_APPSy_EN=0;
       }
    }
}

///////////////////// SCREEN init ////////////////////
void ui_DateTimeSetPage_screen_init(void)
{
    ui_DateTimeSetPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DateTimeSetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_APPSyPanel = lv_obj_create(ui_DateTimeSetPage);
    lv_obj_set_width(ui_APPSyPanel, 240);
    lv_obj_set_height(ui_APPSyPanel, 70);
    lv_obj_set_align(ui_APPSyPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_APPSyPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_APPSyPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_APPSyPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_APPSyPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_APPSyPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_APPSySwitch = lv_switch_create(ui_APPSyPanel);
    lv_obj_set_width(ui_APPSySwitch, 55);
    lv_obj_set_height(ui_APPSySwitch, 25);
    lv_obj_set_align(ui_APPSySwitch, LV_ALIGN_RIGHT_MID);
    if(user_APPSy_EN)
    {lv_obj_add_state(ui_APPSySwitch, LV_STATE_CHECKED);}

    ui_APPSyLabel = lv_label_create(ui_APPSyPanel);
    lv_obj_set_width(ui_APPSyLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_APPSyLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_APPSyLabel, 20);
    lv_obj_set_y(ui_APPSyLabel, 0);
    lv_obj_set_align(ui_APPSyLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_APPSyLabel, "同步APP");
    lv_obj_set_style_text_font(ui_APPSyLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DateSetPanel = lv_obj_create(ui_DateTimeSetPage);
    lv_obj_set_width(ui_DateSetPanel, 240);
    lv_obj_set_height(ui_DateSetPanel, 70);
    lv_obj_set_x(ui_DateSetPanel, 0);
    lv_obj_set_y(ui_DateSetPanel, 70);
    lv_obj_set_align(ui_DateSetPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_DateSetPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DateSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DateSetPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DateSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DateSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DateSetPanel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_DateSetPanel, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_DateSetLabel = lv_label_create(ui_DateSetPanel);
    lv_obj_set_width(ui_DateSetLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DateSetLabel, 20);
    lv_obj_set_y(ui_DateSetLabel, 0);
    lv_obj_set_align(ui_DateSetLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_DateSetLabel, "日期设置");
    lv_obj_set_style_text_font(ui_DateSetLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DateSetLabel1 = lv_label_create(ui_DateSetPanel);
    lv_obj_set_width(ui_DateSetLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DateSetLabel1, 0);
    lv_obj_set_y(ui_DateSetLabel1, -15);
    lv_obj_set_align(ui_DateSetLabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_DateSetLabel1, ".");
    lv_obj_set_style_text_font(ui_DateSetLabel1, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DateSetLabel2 = lv_label_create(ui_DateSetPanel);
    lv_obj_set_width(ui_DateSetLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DateSetLabel2, 0);
    lv_obj_set_y(ui_DateSetLabel2, -5);
    lv_obj_set_align(ui_DateSetLabel2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_DateSetLabel2, ".");
    lv_obj_set_style_text_font(ui_DateSetLabel2, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DateSetLabel3 = lv_label_create(ui_DateSetPanel);
    lv_obj_set_width(ui_DateSetLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DateSetLabel3, 0);
    lv_obj_set_y(ui_DateSetLabel3, 5);
    lv_obj_set_align(ui_DateSetLabel3, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_DateSetLabel3, ".");
    lv_obj_set_style_text_font(ui_DateSetLabel3, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeSetPanel = lv_obj_create(ui_DateTimeSetPage);
    lv_obj_set_width(ui_TimeSetPanel, 240);
    lv_obj_set_height(ui_TimeSetPanel, 70);
    lv_obj_set_x(ui_TimeSetPanel, 0);
    lv_obj_set_y(ui_TimeSetPanel, 140);
    lv_obj_set_align(ui_TimeSetPanel, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_TimeSetPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TimeSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TimeSetPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimeSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TimeSetPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TimeSetPanel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_TimeSetPanel, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_TimeSetLabel = lv_label_create(ui_TimeSetPanel);
    lv_obj_set_width(ui_TimeSetLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSetLabel, 20);
    lv_obj_set_y(ui_TimeSetLabel, 0);
    lv_obj_set_align(ui_TimeSetLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_TimeSetLabel, "时间设置");
    lv_obj_set_style_text_font(ui_TimeSetLabel, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeSetLabel1 = lv_label_create(ui_TimeSetPanel);
    lv_obj_set_width(ui_TimeSetLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSetLabel1, 0);
    lv_obj_set_y(ui_TimeSetLabel1, -15);
    lv_obj_set_align(ui_TimeSetLabel1, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_TimeSetLabel1, ".");
    lv_obj_set_style_text_font(ui_TimeSetLabel1, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeSetLabel2 = lv_label_create(ui_TimeSetPanel);
    lv_obj_set_width(ui_TimeSetLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSetLabel2, 0);
    lv_obj_set_y(ui_TimeSetLabel2, -5);
    lv_obj_set_align(ui_TimeSetLabel2, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_TimeSetLabel2, ".");
    lv_obj_set_style_text_font(ui_TimeSetLabel2, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeSetLabel3 = lv_label_create(ui_TimeSetPanel);
    lv_obj_set_width(ui_TimeSetLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSetLabel3, 0);
    lv_obj_set_y(ui_TimeSetLabel3, 5);
    lv_obj_set_align(ui_TimeSetLabel3, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_TimeSetLabel3, ".");
    lv_obj_set_style_text_font(ui_TimeSetLabel3, &ui_font_Cuyuan20, LV_PART_MAIN | LV_STATE_DEFAULT);

		lv_obj_add_event_cb(ui_DateTimeSetPage, ui_event_DateTimeSetPage, LV_EVENT_ALL, NULL);
		lv_obj_add_event_cb(ui_DateSetPanel, ui_event_DateSetPanel, LV_EVENT_ALL, NULL);
		lv_obj_add_event_cb(ui_TimeSetPanel, ui_event_TimeSetPanel, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_APPSySwitch, ui_event_APPSySwitch, LV_EVENT_ALL, NULL);

}


void ui_DateSetPage_screen_init(void)
{

    HW_DateTimeTypeDef datetime;
    HW_RTC_Get_TimeDate(&datetime);

    ui_DateSetPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DateSetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_YearSetRoller = lv_roller_create(ui_DateSetPage);
    lv_roller_set_options(ui_YearSetRoller, yearoptions ,LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_YearSetRoller, datetime.Year-22, LV_ANIM_OFF);
    lv_obj_set_height(ui_YearSetRoller, 120);
    lv_obj_set_width(ui_YearSetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_YearSetRoller, 8);
    lv_obj_set_y(ui_YearSetRoller, 0);
    lv_obj_set_align(ui_YearSetRoller, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_text_color(ui_YearSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_YearSetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_YearSetRoller, &ui_font_Cuyuan30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_YearSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_YearSetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_YearSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_YearSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_YearSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_YearSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_YearSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_YearSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_YearSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_YearSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_MonthSetRoller = lv_roller_create(ui_DateSetPage);
    lv_roller_set_options(ui_MonthSetRoller, monthoptions, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_MonthSetRoller, datetime.Month-1, LV_ANIM_OFF);
    lv_obj_set_height(ui_MonthSetRoller, 120);
    lv_obj_set_width(ui_MonthSetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_MonthSetRoller, 17);
    lv_obj_set_y(ui_MonthSetRoller, 0);
    lv_obj_set_align(ui_MonthSetRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_MonthSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MonthSetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MonthSetRoller, &ui_font_Cuyuan30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_MonthSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MonthSetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MonthSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MonthSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_MonthSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MonthSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_MonthSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_MonthSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_MonthSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_MonthSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_DaySetRoller = lv_roller_create(ui_DateSetPage);
    lv_roller_set_options(ui_DaySetRoller, day31options, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_DaySetRoller, datetime.Date-1, LV_ANIM_OFF);
    lv_obj_set_height(ui_DaySetRoller, 120);
    lv_obj_set_width(ui_DaySetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_DaySetRoller, -8);
    lv_obj_set_y(ui_DaySetRoller, 0);
    lv_obj_set_align(ui_DaySetRoller, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_text_color(ui_DaySetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DaySetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DaySetRoller, &ui_font_Cuyuan30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DaySetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DaySetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DaySetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DaySetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DaySetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DaySetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_DaySetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_DaySetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_DaySetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_DaySetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_DateSetOKButton = lv_btn_create(ui_DateSetPage);
    lv_obj_set_width(ui_DateSetOKButton, 240);
    lv_obj_set_height(ui_DateSetOKButton, 50);
    lv_obj_set_align(ui_DateSetOKButton, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_DateSetOKButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DateSetOKButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DateSetOKButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DateSetOKButton, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DateSetOKButton, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DateSetOKButton, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_DateSetOKButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_DateSetOKButton, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_DateSetOKicon = lv_label_create(ui_DateSetOKButton);
    lv_obj_set_width(ui_DateSetOKicon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DateSetOKicon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DateSetOKicon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DateSetOKicon, "");
    lv_obj_set_style_text_font(ui_DateSetOKicon, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);

		lv_obj_add_event_cb(ui_DateSetOKButton, ui_event_DateSetOKButton, LV_EVENT_ALL, NULL);

}


void ui_TimeSetPage_screen_init(void)
{

    HW_DateTimeTypeDef datetime;
    HW_RTC_Get_TimeDate(&datetime);

    ui_TimeSetPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TimeSetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HourSetRoller = lv_roller_create(ui_TimeSetPage);
    lv_roller_set_options(ui_HourSetRoller, houroptions, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_HourSetRoller, datetime.Hours, LV_ANIM_OFF);
    lv_obj_set_height(ui_HourSetRoller, 120);
    lv_obj_set_width(ui_HourSetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_HourSetRoller, 5);
    lv_obj_set_y(ui_HourSetRoller, 0);
    lv_obj_set_align(ui_HourSetRoller, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_text_color(ui_HourSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_HourSetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_HourSetRoller, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_HourSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_HourSetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HourSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HourSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_HourSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HourSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_HourSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_HourSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_HourSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_HourSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_TimePoint = lv_label_create(ui_TimeSetPage);
    lv_obj_set_width(ui_TimePoint, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimePoint, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimePoint, -40);
    lv_obj_set_y(ui_TimePoint, 0);
    lv_obj_set_align(ui_TimePoint, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimePoint, ":");
    lv_obj_set_style_text_font(ui_TimePoint, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MinSetRoller = lv_roller_create(ui_TimeSetPage);
    lv_roller_set_options(ui_MinSetRoller, minoptions, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_MinSetRoller, datetime.Minutes, LV_ANIM_OFF);
    lv_obj_set_height(ui_MinSetRoller, 120);
    lv_obj_set_width(ui_MinSetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_align(ui_MinSetRoller, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(ui_MinSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MinSetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MinSetRoller, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_MinSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_MinSetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MinSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MinSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_MinSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_MinSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_MinSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_MinSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_MinSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_MinSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_TimePoint1 = lv_label_create(ui_TimeSetPage);
    lv_obj_set_width(ui_TimePoint1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimePoint1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimePoint1, 40);
    lv_obj_set_y(ui_TimePoint1, 0);
    lv_obj_set_align(ui_TimePoint1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimePoint1, ":");
    lv_obj_set_style_text_font(ui_TimePoint1, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SecSetRoller = lv_roller_create(ui_TimeSetPage);
    lv_roller_set_options(ui_SecSetRoller, minoptions, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(ui_SecSetRoller, datetime.Seconds, LV_ANIM_OFF);
    lv_obj_set_height(ui_SecSetRoller, 120);
    lv_obj_set_width(ui_SecSetRoller, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_SecSetRoller, -5);
    lv_obj_set_y(ui_SecSetRoller, 0);
    lv_obj_set_align(ui_SecSetRoller, LV_ALIGN_RIGHT_MID);
    lv_obj_set_style_text_color(ui_SecSetRoller, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SecSetRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SecSetRoller, &ui_font_Cuyuan38, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SecSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SecSetRoller, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SecSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SecSetRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SecSetRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SecSetRoller, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_SecSetRoller, lv_color_hex(0x0064FF), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_SecSetRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_SecSetRoller, 2, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SecSetRoller, 1, LV_PART_SELECTED | LV_STATE_DEFAULT);

    ui_TimeSetOKButton = lv_btn_create(ui_TimeSetPage);
    lv_obj_set_width(ui_TimeSetOKButton, 240);
    lv_obj_set_height(ui_TimeSetOKButton, 50);
    lv_obj_set_align(ui_TimeSetOKButton, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_TimeSetOKButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TimeSetOKButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TimeSetOKButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TimeSetOKButton, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_TimeSetOKButton, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui_TimeSetOKButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_TimeSetOKButton, 128, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_TimeSetOKicon = lv_label_create(ui_TimeSetOKButton);
    lv_obj_set_width(ui_TimeSetOKicon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSetOKicon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_TimeSetOKicon, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeSetOKicon, "");
    lv_obj_set_style_text_font(ui_TimeSetOKicon, &ui_font_iconfont45, LV_PART_MAIN | LV_STATE_DEFAULT);

		lv_obj_add_event_cb(ui_TimeSetOKButton, ui_event_TimeSetOKButton, LV_EVENT_ALL, NULL);

}

/////////////////// SCREEN deinit ////////////////////
void ui_DateTimeSetPage_screen_deinit(void)
{}

void ui_DateSetPage_screen_deinit(void)
{}

void ui_TimeSetPage_screen_deinit(void)
{}
