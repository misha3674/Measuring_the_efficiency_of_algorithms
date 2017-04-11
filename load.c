#include "common.h"
#include "load.h"
#include <stdlib.h>
#include <stdio.h>
#include "tools/text_tools.h"
#include "tools/text_area_tools.h"
#include "tools/texture_tools.h"
#include "tools/button_tools.h"
#include "proccessing.h"


#define SIZE_NUM_W 7
#define SIZE_NUM_H 7
#define SIZE_GRAPH_W 65
#define SIZE_GRAPH_H 45
#define SIZE_FORM_W 30
#define SIZE_FORM_H 15

//----------------------------------------------------------------------------------------------------
listTextArea* load_TextArea_setting()
{
    listTextArea* pHead = NULL;
    listTextArea* currentArea = NULL;
    pHead = innit_textArea_list();

    int pos_x = 0;
    int pos_y = 0;

    pos_x = 95;
    pos_y = 2;
    currentArea = add_textArea_list(pHead,"Parent",pos_x,pos_y);
    set_limit_def_area(currentArea,1,50,10);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"Child",pos_x,pos_y);
    set_limit_def_area(currentArea,1,50,10);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"Mutant",pos_x,pos_y);
    set_limit_def_area(currentArea,1,50,10);
    pos_x = 95;
    pos_y = 25;
    currentArea = add_textArea_list(pHead,"Particle",pos_x,pos_y);
    set_limit_def_area(currentArea,1,50,10);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"KofP (c1)",pos_x,pos_y);
    set_limit_def_area(currentArea,0.05,2,0.2);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"KofG (c2)",pos_x,pos_y);
    set_limit_def_area(currentArea,0.05,2,0.8);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"Iner (w)",pos_x,pos_y);
    set_limit_def_area(currentArea,0.05,2,0.9);
    pos_x = 95;
    pos_y = 48;
    currentArea = add_textArea_list(pHead,"Init Temp",pos_x,pos_y);
    set_limit_def_area(currentArea,1,20,10);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"End Temp",pos_x,pos_y);
    set_limit_def_area(currentArea,0.0001,1,0.0001);
    pos_x = 95;
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"a -",pos_x,pos_y);
    set_limit_def_area(currentArea,0.05,2,0.1);
    pos_y+=4;
    currentArea = add_textArea_list(pHead,"b -",pos_x,pos_y);
    set_limit_def_area(currentArea,0,4,1);
    return pHead;
}
//----------------------------------------------------------------------------------------------------
sListTexture* load_Texture_task1()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/graf1.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/sys1.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/num1.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task2()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/graf2.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/sys2.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/num2.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task3()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/graf3.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/sys3.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/num3.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task4()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/graf4.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/sys4.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"../coursework_multi-objective_optimization/img/num4.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
//----------------------------------------------------------------------------------------------------
sListButton*  load_Button_setting()
{
    sListButton* pHead = NULL;
    sListButton* pButton = NULL;
    pHead = innit_button_list();

    pButton = add_button_list(pHead,1,6);
    set_texture_button(pButton,"../coursework_multi-objective_optimization/img/iconl.png");
    set_action_button(pButton,&action_button_left);

    pButton = add_button_list(pHead,19,6);
    set_texture_button(pButton,"../coursework_multi-objective_optimization/img/iconr.png");
    set_action_button(pButton,&action_button_right);

    pButton = add_button_list(pHead,120,63);
    set_name_button(pButton,"Result");
    set_action_button(pButton,&action_button_settting);
    set_size_button(pButton,9,4);
    return pHead;
}
//------------------------------------------------------------------------------------------------------
void load_clear_listTexture(sListTexture* pHead)
{

}
//---------------------------------------------------------------------------------------------------
void load_clear_listTextArea(listTextArea* pHead)
{

}
//---------------------------------------------------------------------------------------------------
void load_clear_listButton(sListButton* pHead)
{

}
