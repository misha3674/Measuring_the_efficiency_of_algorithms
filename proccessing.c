#include "common.h"
#include "proccessing.h"
#include "draw.h"
typedef struct
{
   double mX;
   double mY;
}sCoor;
typedef struct
{
    sCoor coor;
    double value;
    double time;
    int iter;
}sLine;
#include "algorithm/list2.h"
#include "tools/text_area_tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define GLFW_KEY_0                  48
#define GLFW_KEY_1                  49
#define GLFW_KEY_2                  50
#define GLFW_KEY_3                  51
#define GLFW_KEY_4                  52
#define GLFW_KEY_5                  53
#define GLFW_KEY_6                  54
#define GLFW_KEY_7                  55
#define GLFW_KEY_8                  56
#define GLFW_KEY_9                  57
#define GLFW_KEY_PERIOD             46  /* . */
#define GLFW_KEY_BACKSPACE          259

int gTest = 0;
eState gState = PREPARE_SETTINGS;
void struct_copy(sResult* dest,sLine* source);
listTextArea* pPressArea = NULL;

void proccesing_button_list(sListButton* pHead,int click_x,int click_y)
{
    sListButton* crowler = NULL;
        if(pHead == NULL)
            return;
    crowler = pHead->pNext;
    while(crowler->pNext != NULL)
    {
        // click inside the button place
        if( ((crowler->mX) <= click_x) && ( (crowler->mX+crowler->w) >= click_x))
            if( ((crowler->mY) <= click_y) && ( (crowler->mY+crowler->h) >= click_y))
            {
                crowler->action();
                return;
            }
        crowler = crowler->pNext;
    }
    if( ((crowler->mX) <= click_x) && ( (crowler->mX+crowler->w) >= click_x))
        if( ((crowler->mY) <= click_y) && ( (crowler->mY+crowler->h) >= click_y))
        {
            crowler->action();
            return;
        }
}
//-------------------------------------------------------------------------------------------------------
void action_button_left()
{
    gTest--;
    if(gTest < 0)
        gTest = 3;
}
//-------------------------------------------------------------------------------------------------------
void action_button_right()
{
    gTest++;
    if(gTest > 3)
        gTest = 0;
}
//-------------------------------------------------------------------------------------------------------
int getTest()
{
    return gTest;
}
//-------------------------------------------------------------------------------------------------------
void action_button_settting()
{
    gState = WAITING;
}
//-------------------------------------------------------------------------------------------------------
void getState(eState* aState)
{
    *aState = gState;
}
//-------------------------------------------------------------------------------------------------------
void setState(eState newState)
{
    gState=newState;
}
//-------------------------------------------------------------------------------------------------------
void action_button_result()
{
    gState = SETTINGS;
}
//-------------------------------------------------------------------------------------------------------
sResult** run_algorithm(listTextArea * data_input)
{
   sResult** resultAlgorithm;
   sResult* resGA;
   sResult* resSA;
   sResult* resPSO;
   sLine tmp;
   srand(time(0));
   resGA = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resSA = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resPSO = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resultAlgorithm = (sResult**)malloc(sizeof(sResult*)*NUM_ALGORITHM);

   int parent = (int)getInputData(data_input,"Parent");
   int child  = (int)getInputData(data_input,"Child");
   int mutant = (int)getInputData(data_input,"Mutant");
   printf("parent %i; child %i; mutant %i;\n",parent,child,mutant);
   int particle = (int)getInputData(data_input,"Particle");
   double c1    = (double)getInputData(data_input,"KofP (c1)");
   double c2    = (double)getInputData(data_input,"KofG (c2)");
   double w     = (double)getInputData(data_input,"Iner (w)");
   printf("particle %i; c1 %g; c2 %g; w %g;\n",particle,c1,c2,w);
   double iTem  = (double)getInputData(data_input,"Init Temp");
   double eTem  = (double)getInputData(data_input,"End Temp");
   double a     = (double)getInputData(data_input,"a -");
   double b     = (double)getInputData(data_input,"b -");
   printf("iTem %g; eTem %g; a %g; b %g;\n",iTem,eTem,a,b);
   int i = 0;
   // init min and max variable
   tmp  = genetic_algorithm(gTest+1,parent,child,mutant); //1,10,10,10
     struct_copy(resGA+i,&tmp);
   tmp  = simulatedAnnealing(gTest+1,iTem,eTem,a,b); //1,10,0.0001,0.1,1
     struct_copy(resSA+i,&tmp);
   tmp = particle_swarm_optimization(gTest+1,particle,c1,c2,w); //1,10,0.2,0.8,0.9
     struct_copy(resPSO+i,&tmp);
   for(i = 1; i < NUM_TEST;i++)
   {
       tmp  = genetic_algorithm(gTest+1,parent,child,mutant); //1,10,10,10
         struct_copy(resGA+i,&tmp);
       tmp  = simulatedAnnealing(gTest+1,iTem,eTem,a,b); //1,10,0.0001,0.1,1
         struct_copy(resSA+i,&tmp);
       tmp = particle_swarm_optimization(gTest+1,particle,c1,c2,w); //1,10,0.2,0.8,0.9
         struct_copy(resPSO+i,&tmp);
       printf("Test %i successful\n",i);
   }
   resultAlgorithm[GA] = resGA;
   resultAlgorithm[SA] = resSA;
   resultAlgorithm[PSO] = resPSO;
   return resultAlgorithm;
}
void struct_copy(sResult* dest,sLine* source)
{
    dest->value = source->value;
    dest->time  = source->time;
    dest->iter  = source->iter;
    dest->mX    = source->coor.mX;
    dest->mY    = source->coor.mY;
}
void proccesing_text_area(listTextArea* pHead,int x, int y)
{
    listTextArea* crowler = pHead->pNext;
    // size area;
    while(crowler->pNext != NULL)
    {
        if( ((crowler->mX+crowler->shift_area) <= x) && ( (crowler->mX+crowler->shift_area+WIDTH_AREA) >= x))
            if( ((crowler->mY-SHIFT_TOP) <= y) && ( (crowler->mY-SHIFT_TOP+HEIGHT_AREA) >= y))
            {
                pPressArea = crowler;
                return;
            }
        crowler = crowler->pNext;
    }
    if( ((crowler->mX+crowler->shift_area) <= x) && ( (crowler->mX+crowler->shift_area+WIDTH_AREA) >= x))
        if( ((crowler->mY-SHIFT_TOP) <= y) && ( (crowler->mY-SHIFT_TOP+HEIGHT_AREA) >= y))
        {
            pPressArea = crowler;
            return;
        }
    pPressArea = NULL;
}
//---------------------------------------------------------------------------------------------------------
void processing_text_textArea(int aKey)
{
    if(pPressArea != NULL)
        switch(aKey)
        {
             case GLFW_KEY_0:
             case GLFW_KEY_1:
             case GLFW_KEY_2:
             case GLFW_KEY_3:
             case GLFW_KEY_4:
             case GLFW_KEY_5:
             case GLFW_KEY_6:
             case GLFW_KEY_7:
             case GLFW_KEY_8:
             case GLFW_KEY_9:
             case GLFW_KEY_PERIOD:
             {
                if(pPressArea->i < (NUM_SMB-1))
                {
                    pPressArea->text[pPressArea->i] = aKey;
                    (pPressArea->i)++;
                }
             } break;
             case GLFW_KEY_BACKSPACE:
                if(pPressArea->i > 0)
                {
                    pPressArea->text[pPressArea->i - 1] = 0;
                    (pPressArea->i)--;
                }
            break;
            default: break;
        }
}
listTextArea* getPressArea()
{
    return pPressArea;
}
void proccesing_hover(sResult** result, double* aX,double* aY)
{
    int pos_x = 0;
    int pos_y = 0;
    pos_x = (int)(*aX/STEP_CURSOR) - 1;
    pos_y = (int)(*aY/STEP_CURSOR);

    if((pos_x >=0) && (pos_x < 100))
    {
        //top graf
        if(pos_y < LEVEL_SCALE_GA)
        {
            draw_hover( &(result[GA][pos_x]), &pos_x, &pos_y);
            return;
        }
        // bottom graf
        if((pos_y > LEVEL_SCALE_PSO) && (pos_y < LEVEL_SCALE_SA))
        {
            draw_hover( &(result[SA][pos_x]), &pos_x, &pos_y );
            return;
        }
        // middle graf
        if( (pos_y > LEVEL_SCALE_GA) && (pos_y < LEVEL_SCALE_PSO))
        {
            draw_hover( &(result[PSO][pos_x]), &pos_x, &pos_y );
            return;
        }
    }
}

