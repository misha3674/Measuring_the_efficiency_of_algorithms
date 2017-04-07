#include "common.h"
#include "load.h"
#include <stdlib.h>
#include <stdio.h>
#include "tools/text_tools.h"
#include "tools/text_area_tools.h"
#include "tools/texture_tools.h"
#include "proccessing.h"

#define NUM_CHAR 50
#define LINE_HEIGHT 2

#define SIZE_NUM_W 7
#define SIZE_NUM_H 7
#define SIZE_GRAPH_W 65
#define SIZE_GRAPH_H 45

#define SIZE_FORM_W 30
#define SIZE_FORM_H 15

void clear_massiv(char* mas);

sListText*    load_Text_result()
{
     sListText* pHead = NULL;
     pHead = innit_text_list(); // create new list

     char str_minScaleV[NUM_CHAR] = {0};// min scale value
     char str_maxScaleV[NUM_CHAR] = {0};// max scale value
     char str_minScaleT[NUM_CHAR] = {0};// min scale time
     char str_maxScaleT[NUM_CHAR] = {0};// max scale time
     char str_parent[NUM_CHAR] = {0};// parent
     char str_mutant[NUM_CHAR] = {0};// mutant
     char str_child[NUM_CHAR]  = {0};// child
     char str_numPracticle[NUM_CHAR] = {0};//num practicle
     char str_kofP[NUM_CHAR] = {0};// kof personal
     char str_kofG[NUM_CHAR] = {0};// kof global
     char str_partPrevVelocity[NUM_CHAR] = {0};// part prev velocity
     char str_parm_func[NUM_CHAR] = {0};
     char str_initalTem[NUM_CHAR] = {0};// inital temp
     char str_endTem[NUM_CHAR] = {0};// end temp

     // ----------- TOP GRAPH --------------------------
     int start_text_right_bar = 102; // the end diagram
     int start_y = 4-LINE_HEIGHT; // less on step unit because prioritet
     // print inform  about Simaulated Anealing algorothm
         add_text_list(pHead," GeneticAlgorith",start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleV,"ScaleValueL: %g",24.1);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %g",24.5 + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %g",0.5 - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %g",0.6);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_parent,"Parent: %i",(int)15);
         add_text_list(pHead,str_parent,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_child,"Child: %i",(int)14);
          add_text_list(pHead,str_child,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_mutant,"mutant: %i",(int)3);
          add_text_list(pHead,str_mutant,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- WITHIN GRAPH --------------------------
      start_y = 26-LINE_HEIGHT;
     // print inform  about practicle algorothm
        add_text_list(pHead," ParticleSwarm",start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleV,"ScaleValueL: %g",24.2);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %g",23.3 + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %g",0.4 - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %g",0.8);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_numPracticle,"NumOfPracticle: %i",(int)16);
         add_text_list(pHead,str_numPracticle,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_kofP,"kofP: %g",0.5);
         add_text_list(pHead,str_kofP,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_kofG,"kofG: %g",0.32);
         add_text_list(pHead,str_kofG,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_partPrevVelocity,"kofVeloc: %g",0.7);
         add_text_list(pHead,str_partPrevVelocity,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- BOTTON GRAPH --------------------------
     start_y = 49-LINE_HEIGHT;
        add_text_list(pHead," SimulatedAnnealing",start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleV,"ScaleValueL: %g",27.5);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %g",21.3 + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %g",0.2 - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %g",0.47);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_parm_func,"  a-%g; b-%i",0.2,(int)1);
         add_text_list(pHead,str_parm_func,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_initalTem,"initTem: %g",10.2);
         add_text_list(pHead,str_initalTem,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_endTem,"EndTem: %g",0.001);
         add_text_list(pHead,str_endTem,start_text_right_bar,start_y+=LINE_HEIGHT);
     return pHead;
}
//----------------------------------------------------------------------------------------------------
listTextArea* load_TextArea_setting()
{
    listTextArea* pHead = NULL;
    pHead = innit_textArea_list();

    int pos_x = 0;
    int pos_y = 0;

    pos_x = 95;
    pos_y = 2;
    add_textArea_list(pHead,"Parent",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"Child",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"Mutant",pos_x,pos_y);

    pos_x = 95;
    pos_y = 25;
    add_textArea_list(pHead,"Particle",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"KofP (c1)",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"KofG (c2)",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"Iner (w)",pos_x,pos_y);

    pos_x = 95;
    pos_y = 48;
    add_textArea_list(pHead,"decrease Tem",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"Innit Temp",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"End Temp",pos_x,pos_y);

    pos_x = 95;
    pos_y+=4;
    add_textArea_list(pHead,"a -",pos_x,pos_y);
    pos_y+=4;
    add_textArea_list(pHead,"b -",pos_x,pos_y);


    return pHead;
}
//----------------------------------------------------------------------------------------------------
sListTexture* load_Texture_task1()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"img/graf1.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"img/sys1.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"img/num1.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task2()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"img/graf2.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"img/sys2.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"img/num2.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task3()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"img/graf3.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"img/sys3.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"img/num3.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
sListTexture* load_Texture_task4()
{
    sListTexture* pHead = NULL;
    pHead = innit_texture_list();
    int pos_x = 1;
    int pos_y = 20;
    add_textute_list(pHead,"img/graf4.png",pos_x,pos_y,SIZE_GRAPH_W,SIZE_GRAPH_H);
    add_textute_list(pHead,"img/sys4.png",36,1,SIZE_FORM_W,SIZE_FORM_H);
    add_textute_list(pHead,"img/num4.png",10,6,SIZE_NUM_W,SIZE_NUM_H);

    return pHead;
}
//----------------------------------------------------------------------------------------------------
sListButton*  load_Button_setting()
{
    sListButton* pHead = NULL;
    sListButton* pButton = NULL;
    pHead = innit_button_list();

    pButton = add_button_list(pHead,1,6);
    set_texture_button(pButton,"img/iconl.png");
    set_action_button(pButton,&action_button_left);

    pButton = add_button_list(pHead,19,6);
    set_texture_button(pButton,"img/iconr.png");
    set_action_button(pButton,&action_button_right);

    pButton = add_button_list(pHead,120,63);
    set_name_button(pButton,"Result");
    set_action_button(pButton,&action_button_settting);
    set_size_button(pButton,9,4);
    return pHead;
}
//------------------------------------------------------------------------------------------------------
sListScale* load_scale(sResult** result)
{
    /*sListScale* pHead = NULL;
    pHead = innit_scale_list();
    // pos_x,pos_y,w,h,data
    for(int i = 0; i < NUM_ALGORITHM; i++)
        create_scale(1,23*(i+1),100,22,result[i]);*/
}
//---------------------------------------------------------------------------------------------------
void clear_massiv(char* mas)
{
    int i = 0;
    while(mas[i] != 0)
    {
        mas[i] = 0;
        i++;
    }
}
