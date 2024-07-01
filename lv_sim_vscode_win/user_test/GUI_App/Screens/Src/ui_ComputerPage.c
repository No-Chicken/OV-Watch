#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_ComputerPage.h"

#include "../../../Func/Inc/StrCalculate.h"

///////////////////// Page Manager //////////////////
Page_t Page_Computer = {ui_ComputerPage_screen_init, ui_ComputerPage_screen_deinit, &ui_Computerpage};

///////////////////// VARIABLES ////////////////////

#define TEXT_FULL 10

StrStack_t CalStr;
NumStack_t NumStack;
SymStack_t SymStack;
lv_obj_t * ui_Computerpage;
lv_obj_t * ui_CompageBtnM;
lv_obj_t * ui_CompageTextarea;
lv_obj_t * ui_CompageBackBtn;

static const char * ui_ComPageBtnmap[] ={"1", "2", "3", "\xEF\xBC\x8B", "\n",
                                         "4", "5", "6", "\xEF\xBC\x8D", "\n",
                                         "7", "8", "9", "\xC3\x97", "\n",
                                         ".", "0", "\xEF\xBC\x9D", "\xC3\xB7", ""};


///////////////////// FUNCTIONS ////////////////////
void ui_CompageBtnM_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_DRAW_PART_BEGIN)
    {

        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);
        if(dsc->id == 3 || dsc->id == 7 || dsc->id == 11 || dsc->id == 14 || dsc->id == 15)
        {
            dsc->rect_dsc->radius = LV_RADIUS_CIRCLE;
            if (lv_btnmatrix_get_selected_btn(obj) == dsc->id)
            {
                dsc->rect_dsc->bg_color = lv_palette_darken(LV_PALETTE_BLUE,3);
                //lv_btnmatrix_set_selected_btn(ui_CompageBtnM,NULL);
            }
            else
                dsc->rect_dsc->bg_color = lv_palette_main(LV_PALETTE_BLUE);


        }

    }
    if(code == LV_EVENT_DRAW_PART_END)
    {
        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);


    }
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj); // 获取当前选中的按键的id
        const char * txt = lv_btnmatrix_get_btn_text(obj, btn_id); // 获取当前按键的文本

        if (txt != NULL)
        {
            if (ui_CompageTextarea != NULL)
            {
							if(lv_textarea_get_cursor_pos(ui_CompageTextarea) <= TEXT_FULL)
              {
									lv_textarea_add_text(ui_CompageTextarea, txt); // 文本框追加字符
									switch(btn_id)
									{
											case 0:
													strput(&CalStr,'1');
													break;
											case 1:
													strput(&CalStr,'2');
													break;
											case 2:
													strput(&CalStr,'3');
													break;
											case 3:
													strput(&CalStr,'+');
													break;
											case 4:
													strput(&CalStr,'4');
													break;
											case 5:
													strput(&CalStr,'5');
													break;
											case 6:
													strput(&CalStr,'6');
													break;
											case 7:
													strput(&CalStr,'-');
													break;
											case 8:
													strput(&CalStr,'7');
													break;
											case 9:
													strput(&CalStr,'8');
													break;
											case 10:
													strput(&CalStr,'9');
													break;
											case 11:
													strput(&CalStr,'*');
													break;
											case 12:
													strput(&CalStr,'.');
													break;
											case 13:
													strput(&CalStr,'0');
													break;
											case 14:
													strput(&CalStr,'=');
													lv_textarea_add_text(ui_CompageTextarea,"\n");
													strput(&CalStr,'\n');
													break;
											case 15:
													strput(&CalStr,'/');
													break;
									}
							}
            }
        }

        if(lv_btnmatrix_get_selected_btn(obj) == 14)
        {
            //calculate
            if(StrCalculate(CalStr.strque,&NumStack,&SymStack))
						{lv_textarea_add_text(ui_CompageTextarea,"erro");}
						else
						{
							char strout[10];
							if(isIntNumber(NumStack.data[NumStack.Top_Point-1]))
							{sprintf(strout,"%.0f",NumStack.data[NumStack.Top_Point-1]);}
							else
							{sprintf(strout,"%.4f",NumStack.data[NumStack.Top_Point-1]);}
							lv_textarea_add_text(ui_CompageTextarea,strout);
						}
            strclear(&CalStr);
						lv_obj_clear_flag(ui_CompageBtnM,LV_OBJ_FLAG_CLICKABLE);
        }
    }
}


void ui_CompageBackBtn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED)
    {
        if (ui_CompageTextarea != NULL)
        {
            if(!strstack_isEmpty(&CalStr))
            {
                lv_textarea_del_char(ui_CompageTextarea);
                strdel(&CalStr);
            }
            else
            {
                int i = 0;
                for (i = 0; i < (TEXT_FULL*2); i++)
                {
                    lv_textarea_del_char(ui_CompageTextarea);
                }
								lv_obj_add_flag(ui_CompageBtnM,LV_OBJ_FLAG_CLICKABLE);
            }
        }
    }
		if(code == LV_EVENT_LONG_PRESSED)
		{
			if (ui_CompageTextarea != NULL)
			{
				if(!strstack_isEmpty(&CalStr))
				{
						strclear(&CalStr);
						int i = 0;
						for (i = 0; i < (TEXT_FULL*2); i++)
						{
								lv_textarea_del_char(ui_CompageTextarea);
						}
				}
			}
		}
}


///////////////////// SCREEN init ////////////////////
void ui_ComputerPage_screen_init(void)
{
		strclear(&CalStr);
		NumStackClear(&NumStack);
		SymStackClear(&SymStack);
    ui_Computerpage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Computerpage,LV_OBJ_FLAG_SCROLLABLE);
    ui_CompageBtnM = lv_btnmatrix_create(ui_Computerpage);
    lv_btnmatrix_set_map(ui_CompageBtnM, ui_ComPageBtnmap);

    lv_obj_set_style_text_font(ui_CompageBtnM, &ui_font_Cuyuan24, 0);
    lv_btnmatrix_set_one_checked(ui_CompageBtnM,true);
    int i = 0;
    for (i = 0; i < 16; i++)
    {
        lv_btnmatrix_set_btn_ctrl(ui_CompageBtnM, i, LV_BTNMATRIX_CTRL_NO_REPEAT); // 长按按钮时禁用重复
    }
    lv_obj_clear_flag(ui_CompageBtnM, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_set_style_border_width(ui_CompageBtnM,0,0);
    lv_obj_set_style_bg_opa(ui_CompageBtnM,0,0);
    lv_obj_set_size(ui_CompageBtnM,240,220);
    lv_obj_set_align(ui_CompageBtnM,LV_ALIGN_BOTTOM_MID);


    ui_CompageTextarea = lv_textarea_create(ui_Computerpage);
    lv_textarea_set_one_line(ui_CompageTextarea, false); // 将文本区域配置为一行
    //lv_textarea_set_password_mode(obj_text_area, true); // 将文本区域配置为密码模式
    lv_textarea_set_max_length(ui_CompageTextarea, TEXT_FULL*2); // 设置文本区域可输入的字符长度最大值
    lv_obj_add_state(ui_CompageTextarea, LV_STATE_FOCUSED); // 显示光标
    lv_obj_set_style_radius(ui_CompageTextarea, 0, 0); // 设置样式的圆角弧度
    lv_obj_set_style_border_width(ui_CompageTextarea, 0, 0); //设置边框宽度
    lv_obj_set_style_bg_color(ui_CompageTextarea, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CompageTextarea, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui_CompageTextarea, 200, 60); // 设置对象大小
    lv_obj_align(ui_CompageTextarea, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_clear_flag(ui_CompageTextarea,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_text_font(ui_CompageTextarea, &ui_font_Cuyuan24, 0);
    lv_textarea_set_align(ui_CompageTextarea, LV_TEXT_ALIGN_RIGHT);

    ui_CompageBackBtn = lv_btn_create(ui_Computerpage);
    lv_obj_align(ui_CompageBackBtn,LV_ALIGN_RIGHT_MID,-10,-110);
    lv_obj_set_width(ui_CompageBackBtn,40);
    lv_obj_set_height(ui_CompageBackBtn,30);
    lv_obj_set_style_bg_opa(ui_CompageBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btnlabel = lv_label_create(ui_CompageBackBtn);
    lv_label_set_text(btnlabel, LV_SYMBOL_BACKSPACE);
    lv_obj_set_style_text_font(btnlabel, &lv_font_montserrat_24, 0);
    lv_obj_center(btnlabel);

    lv_obj_add_event_cb(ui_CompageBtnM, ui_CompageBtnM_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CompageBackBtn, ui_CompageBackBtn_event_cb, LV_EVENT_ALL, NULL);

}

/////////////////// SCREEN deinit ////////////////////
void ui_ComputerPage_screen_deinit(void)
{}
