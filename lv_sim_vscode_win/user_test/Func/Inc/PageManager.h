#ifndef PAGE_STACK_H
#define PAGE_STACK_H

#include "../../GUI_App/ui.h"

// 页面栈深度
#define MAX_DEPTH 6

// 页面结构体
typedef struct {
    void (*init)(void);
    void (*deinit)(void);
    lv_obj_t **page_obj;
} Page_t;


// 页面堆栈结构体
typedef struct {
    Page_t* pages[MAX_DEPTH];
    uint8_t top;
} PageStack_t;

extern PageStack_t PageStack;


Page_t* Page_Get_NowPage(void);
void Page_Back(void);
void Page_Back_Bottom(void);
void Page_Load(Page_t *newPage);
void Pages_init(void);


#endif // PAGE_STACK_H
