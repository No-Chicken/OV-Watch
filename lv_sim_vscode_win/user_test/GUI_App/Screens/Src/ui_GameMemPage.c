#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "../../ui.h"
#include "../../ui_helpers.h"
#include "../Inc/ui_MenuPage.h"
#include "../Inc/ui_GameMemPage.h"

#include "../../../Func/Inc/HWDataAccess.h"

#define MATRIX_SIZE 4

typedef struct {
    uint8_t matrix[MATRIX_SIZE * MATRIX_SIZE + 1];
    char    * btnm_map[MATRIX_SIZE * MATRIX_SIZE + MATRIX_SIZE];
    uint8_t label_opa_map[MATRIX_SIZE * MATRIX_SIZE];
    uint8_t previous_id;
    uint8_t present_id;
} memory_game_t;


static char * num_list[] = {"0","1","2","3","4","5","6","7","8"};
void Game_Mem_Init(void);
void list_rand_number(uint8_t arry[], uint8_t max_count, uint8_t count);
void updata_btnm(char * btnm_map[], uint8_t matrix[MATRIX_SIZE * MATRIX_SIZE + 1]);
uint8_t Game_Mem_Finish(void);

///////////////////// Page Manager //////////////////
Page_t Page_GameMem = {ui_GameMemPage_screen_init, ui_GameMemPage_screen_deinit, &ui_GameMem_Page};

///////////////////// VARIABLES ////////////////////
memory_game_t Game_Mem;

lv_obj_t * ui_GameMem_Page;
lv_obj_t * ui_GameMem_BtnM;
lv_obj_t * ui_new_game_btn;

///////////////////// FUNCTIONS ////////////////////
void ui_event_GameMemBtnM_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        //const char * txt = lv_btnmatrix_get_btn_text(obj, id);
        Game_Mem.present_id = (uint8_t)id;
        if(Game_Mem.present_id != Game_Mem.previous_id)
        {

            if(Game_Mem.matrix[Game_Mem.present_id] == Game_Mem.matrix[Game_Mem.previous_id])
            {

                lv_btnmatrix_set_btn_ctrl(ui_GameMem_BtnM,Game_Mem.present_id,LV_BTNMATRIX_CTRL_HIDDEN);
                lv_btnmatrix_set_btn_ctrl(ui_GameMem_BtnM,Game_Mem.previous_id,LV_BTNMATRIX_CTRL_HIDDEN);
                Game_Mem.matrix[Game_Mem.present_id] = 0;
                Game_Mem.matrix[Game_Mem.previous_id] = 0;
                if(Game_Mem_Finish())
                {
                    lv_obj_clear_flag(ui_new_game_btn,LV_OBJ_FLAG_HIDDEN);
                }
                Game_Mem.previous_id = Game_Mem.present_id;

            }
            else
            {
								if(Game_Mem.previous_id >= 0 && Game_Mem.previous_id < 17 )
									Game_Mem.label_opa_map[Game_Mem.previous_id] = LV_OPA_0;
                Game_Mem.label_opa_map[Game_Mem.present_id] = LV_OPA_100;
                Game_Mem.previous_id = Game_Mem.present_id;
            }

        }
    }

    if(code == LV_EVENT_DRAW_PART_BEGIN)
    {
        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);


        if((dsc->id >= 0) && (dsc->label_dsc))
        {
            dsc->rect_dsc->bg_color = lv_color_hex(0xB07010);
            dsc->label_dsc->color = lv_color_white();
            dsc->label_dsc->opa = Game_Mem.label_opa_map[dsc->id];
        }
    }
}


void ui_event_NewGameBtn_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
        Game_Mem_Init();
        lv_btnmatrix_set_map(ui_GameMem_BtnM, Game_Mem.btnm_map);
        lv_btnmatrix_clear_btn_ctrl_all(ui_GameMem_BtnM,LV_BTNMATRIX_CTRL_HIDDEN);
        lv_obj_add_flag(ui_new_game_btn,LV_OBJ_FLAG_HIDDEN);
    }
}

///////////////////// SCREEN init ////////////////////
void ui_GameMemPage_screen_init(void)
{

    Game_Mem_Init();
    ui_GameMem_Page = lv_obj_create(NULL);;
    ui_GameMem_BtnM = lv_btnmatrix_create(ui_GameMem_Page);
    lv_btnmatrix_set_map(ui_GameMem_BtnM, Game_Mem.btnm_map);
    lv_obj_set_style_text_font(ui_GameMem_BtnM, &ui_font_Cuyuan24, 0);
    lv_btnmatrix_set_one_checked(ui_GameMem_BtnM,true);
    lv_obj_set_style_border_width(ui_GameMem_BtnM,0,0);
    lv_obj_set_style_bg_opa(ui_GameMem_BtnM,0,0);
    lv_obj_set_size(ui_GameMem_BtnM,240,240);
    lv_obj_set_align(ui_GameMem_BtnM,LV_ALIGN_CENTER);


    ui_new_game_btn = lv_btn_create(ui_GameMem_Page);
    lv_obj_align(ui_new_game_btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(ui_new_game_btn,90,45);
    lv_obj_t * new_game_btn_label = lv_label_create(ui_new_game_btn);
    lv_label_set_text(new_game_btn_label,"重 玩");
    lv_obj_align(new_game_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(new_game_btn_label, &ui_font_Cuyuan24, 0);
    lv_obj_add_flag(ui_new_game_btn,LV_OBJ_FLAG_HIDDEN);

    //lv_btnmatrix_set_btn_ctrl(ui_GameMem_BtnM,1,LV_BTNMATRIX_CTRL_HIDDEN);
    lv_obj_add_event_cb(ui_GameMem_BtnM, ui_event_GameMemBtnM_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_new_game_btn, ui_event_NewGameBtn_handler, LV_EVENT_ALL, NULL);
}

///////////////////// SCREEN deinit ////////////////////
void ui_GameMemPage_screen_deinit(void)
{}

///////////////////// FUNCTIONS ////////////////////
void Game_Mem_Init(void)
{
    uint8_t x;

    for (x = 0; x < MATRIX_SIZE * MATRIX_SIZE + 1; x++) {
            Game_Mem.matrix[x] = 0;
    }

    for (x = 0; x < MATRIX_SIZE * MATRIX_SIZE; x++) {
        Game_Mem.label_opa_map[x] = LV_OPA_0;
    }
    Game_Mem.previous_id = -1;
    Game_Mem.present_id = -1;
    list_rand_number(Game_Mem.matrix,MATRIX_SIZE * MATRIX_SIZE,MATRIX_SIZE*MATRIX_SIZE/2);
    updata_btnm(Game_Mem.btnm_map,Game_Mem.matrix);
    //Game_Mem.label_opa_map[6] = LV_OPA_100;

}

void list_rand_number(uint8_t arry[], uint8_t max_count, uint8_t count)
{
    int w, t;
	int time=0;
	HW_DateTimeTypeDef nowtime;
	HWInterface.RealTimeClock.GetTimeDate(&nowtime);
	time = nowtime.Seconds;
    srand(time);

    for (int i = 0; i < max_count; i++)
        arry[i] = (i % count) + 1;
    for (int i = 0; i < max_count; i++)
    {
        w = rand() % (count - (i % count)) + i;
        if (w > max_count)  w = max_count - 1;

        t = arry[i];
        arry[i] = arry[w];
        arry[w] = t;
    }
}

void updata_btnm(char * btnm_map[], uint8_t matrix[MATRIX_SIZE * MATRIX_SIZE + 1])
{
    uint8_t x,index;
    index = 0;
    for(x=0;x<MATRIX_SIZE * MATRIX_SIZE;x++)
    {
        if((index + 1) % (MATRIX_SIZE + 1) == 0)
        {
            btnm_map[index] = "\n";
            index++;
        }
        btnm_map[index] = num_list[matrix[x]];
        index++;
    }
    btnm_map[MATRIX_SIZE * MATRIX_SIZE + MATRIX_SIZE - 1] = "";
}

uint8_t Game_Mem_Finish(void)
{
    for(uint16_t x = 0; x < MATRIX_SIZE*MATRIX_SIZE; x++)
    {
        if(Game_Mem.matrix[x]!=0)
            return 0;
    }
    return 1;
}

