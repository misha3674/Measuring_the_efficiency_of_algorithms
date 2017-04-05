#include "common.h"
#include "load.h"
#include <stdlib.h>
#include "tools/text_tools.h"
#define NUM_CHAR 50
#define LINE_HEIGHT 2


void clear_massiv(char* mas);

sListText*    load_Text_setting()
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

     // ----------- BOTTON GRAPH --------------------------
     int start_text_right_bar = 101; // the end diagram
     int start_y = 60-LINE_HEIGHT; // less on step unit because prioritet
     // print inform  about Simaulated Anealing algorothm
         add_text_list(pHead," GeneticAlgorith",start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleV,"ScaleValueL: %g",aInfrom->minGA);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleV,"ScaleValueH: %g",aInfrom->minGA + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleT,"ScaleTimeL: %g",aInfrom->maxGAt - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleT,"ScaleTimeH: %g",aInfrom->maxGAt);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_parent,"Parent: %i",(int)ga_parm->p);
         add_text_list(pHead,str_parent,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_child,"Child: %i",(int)ga_parm->c);
          add_text_list(pHead,str_child,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_mutant,"mutant: %i",(int)ga_parm->m);
          add_text_list(pHead,str_mutant,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- WITHIN GRAPH --------------------------
      start_y = 31-LINE_HEIGHT;
     // print inform  about practicle algorothm
        add_text_list(pHead," ParticleSwarm",start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleV,"ScaleValueL: %g",aInfrom->minPA);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleV,"ScaleValueH: %g",aInfrom->minPA + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleT,"ScaleTimeL: %g",aInfrom->maxPAt - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleT,"ScaleTimeH: %g",aInfrom->maxPAt);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_numPracticle,"NumOfPracticle: %i",(int)pa_parm->num);
         add_text_list(pHead,str_numPracticle,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_kofP,"kofP: %g",pa_parm->p);
         add_text_list(pHead,str_kofP,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_kofG,"kofG: %g",pa_parm->g);
         add_text_list(pHead,str_kofG,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_partPrevVelocity,"kofVeloc: %g",pa_parm->i);
         add_text_list(pHead,str_partPrevVelocity,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- TOP GRAPH --------------------------
     start_y = 4-LINE_HEIGHT;
        add_text_list(pHead," SimulatedAnnealing",start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleV,"ScaleValueL: %g",aInfrom->minSA);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleV,"ScaleValueH: %g",aInfrom->minSA + 1);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_minScaleT,"ScaleTimeL: %g",aInfrom->maxSAt - 0.01);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_maxScaleT,"ScaleTimeH: %g",aInfrom->maxSAt);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_parm_func,"a-%g; b-%i",sa_parm->a,(int)sa_parm->b);
         add_text_list(pHead,str_parm_func,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_initalTem,"initTem: %g",sa_parm->inn);
         add_text_list(pHead,str_initalTem,start_text_right_bar,start_y+=LINE_HEIGHT);
     //sprintf(str_endTem,"EndTem: %g",sa_parm->end);
         add_text_list(pHead,str_endTem,start_text_right_bar,start_y+=LINE_HEIGHT);

     return pHead;
}
listTextArea* load_TextArea_setting()
{
    return (listTextArea*)malloc(sizeof(listTextArea));
}
sListTexture* load_Texture_setting()
{
    return (sListTexture*)malloc(sizeof(sListTexture));
}
sListButton*  load_Button_setting()
{
    return (sListButton*)malloc(sizeof(sListButton));
}
//--------------------------------------
void clear_massiv(char* mas)
{
    int i = 0;
    while(mas[i] != 0)
    {
        mas[i] = 0;
        i++;
    }
}
