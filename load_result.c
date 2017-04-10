#include "common.h"
#include "tools/texture_tools.h"
#include <stdlib.h>
#include <stdio.h>
#include "load_result.h"
#include "tools/text_area_tools.h"
#include "tools/text_tools.h"
#include "tools/button_tools.h"
#include "tools/scale_tools.h"
#include "proccessing.h"

#define NUM_CHAR 50
#define LINE_HEIGHT 2
void clear_massiv(char* mas);

sListButton*  load_Button_result()
{
    sListButton* pHead = NULL;
    sListButton* pButton = NULL;
    pHead = innit_button_list();

    pButton = add_button_list(pHead,120,63);
    set_name_button(pButton,"Options");
    set_action_button(pButton,&action_button_result);
    set_size_button(pButton,9,4);
    return pHead;
}
//---------------------------------------------------------------------------------------------------
sListScale* load_scale(sResult** result)
{
    sListScale* pHead = NULL;
    pHead = innit_scale_list();
    create_scale(pHead,1,LEVEL_SCALE_GA, SIZE_SCALE_W,SIZE_SCALE_H,*(result+GA));
    create_scale(pHead,1,LEVEL_SCALE_PSO,SIZE_SCALE_W,SIZE_SCALE_H,*(result+PSO));
    create_scale(pHead,1,LEVEL_SCALE_SA, SIZE_SCALE_W,SIZE_SCALE_H,*(result+SA));
    return pHead;
}
//-------------------------------------------------------------------------------------------------------
sListText*    load_Text_result(listTextArea* data_input, sResult** result)
{
     sListText* pHead = NULL;
     pHead = innit_text_list(); // create new list
     double min_value[NUM_ALGORITHM] = {0};
     double max_time[NUM_ALGORITHM] = {0};
     double max_value[NUM_ALGORITHM] = {0};
     double min_time[NUM_ALGORITHM] = {0};
     // init min - max
     for(int j = 0; j < NUM_ALGORITHM; j++)
     {
         max_time[j]  = result[j][0].time;
         min_value[j] = result[j][0].value;
     }
     for(int j = 0; j < NUM_ALGORITHM; j++)
         for(int i = 0; i < NUM_TEST; i++)
         {
             if(max_time[j] < result[j][i].time)
                 max_time[j] = result[j][i].time;
             if(min_value[j] > result[j][i].value)
                 min_value[j] = result[j][i].value;
         }
     for(int j = 0; j < NUM_ALGORITHM; j++)
     {
         min_time[j]  = max_time[j] - RANGE_SCALE_TIME;
         max_value[j] = min_value[j] + RANGE_SCALE_VALUE;
         printf("min_value %g\n",min_value[j]);
     }
     /* 0 - GA 1- SA 2 - PSO */
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
     sprintf(str_minScaleV,"ScaleValueL: %.4g",min_value[GA]);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %.4g",max_value[GA]);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %g",min_time[GA]);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %.4g",max_time[GA]);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_parent,"Parent: %i",(int)getInputData(data_input,"Parent"));
         add_text_list(pHead,str_parent,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_child,"Child: %i",(int)getInputData(data_input,"Child"));
          add_text_list(pHead,str_child,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_mutant,"Mutant: %i",(int)getInputData(data_input,"Mutant"));
          add_text_list(pHead,str_mutant,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- WITHIN GRAPH --------------------------
     int particle = (int)getInputData(data_input,"Particle");
     double c1    = (double)getInputData(data_input,"KofP (c1)");
     double c2    = (double)getInputData(data_input,"KofG (c2)");
     double w     = (double)getInputData(data_input,"Iner (w)");
      start_y = 26-LINE_HEIGHT;
     // print inform  about practicle algorothm
        add_text_list(pHead," ParticleSwarm",start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleV,"ScaleValueL: %.4g",min_value[PSO]);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %.4g",max_value[PSO]);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %.4g",min_time[PSO]);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %g",max_time[PSO]);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_numPracticle,"NumOfPracticle: %i",particle);
         add_text_list(pHead,str_numPracticle,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_kofP,"kofP: %g",c1);
         add_text_list(pHead,str_kofP,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_kofG,"kofG: %g",c2);
         add_text_list(pHead,str_kofG,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_partPrevVelocity,"kofVeloc: %g",w);
         add_text_list(pHead,str_partPrevVelocity,start_text_right_bar,start_y+=LINE_HEIGHT);
     clear_massiv(str_minScaleV);
     clear_massiv(str_maxScaleV);
     clear_massiv(str_minScaleT);
     clear_massiv(str_maxScaleT);

     // ----------- BOTTON GRAPH --------------------------
     double iTem  = (double)getInputData(data_input,"Init Temp");
     double eTem  = (double)getInputData(data_input,"End Temp");
     double a     = (double)getInputData(data_input,"a -");
     double b     = (double)getInputData(data_input,"b -");
     start_y = 49-LINE_HEIGHT;
        add_text_list(pHead," SimulatedAnnealing",start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleV,"ScaleValueL: %g",min_value[SA]);
         add_text_list(pHead,str_minScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleV,"ScaleValueH: %g",max_value[SA]);
         add_text_list(pHead,str_maxScaleV,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_minScaleT,"ScaleTimeL: %g",min_time[SA]);
         add_text_list(pHead,str_minScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_maxScaleT,"ScaleTimeH: %g",max_time[SA]);
         add_text_list(pHead,str_maxScaleT,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_parm_func,"a-%g; b-%g",a,b);
         add_text_list(pHead,str_parm_func,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_initalTem,"initTem: %g",iTem);
         add_text_list(pHead,str_initalTem,start_text_right_bar,start_y+=LINE_HEIGHT);
     sprintf(str_endTem,"EndTem: %g",eTem);
         add_text_list(pHead,str_endTem,start_text_right_bar,start_y+=LINE_HEIGHT);
     return pHead;
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
