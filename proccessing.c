#include "common.h"
#include "proccessing.h"
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
#include <stdlib.h>
#include <stdio.h>
int gTest = 0;
eState gState = PREPARE_SETTINGS;
void struct_copy(sResult* dest,sLine* source);

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
sResult** run_algorithm()
{
   sResult** resultAlgorithm;
   sResult* resGA;
   sResult* resSA;
   sResult* resPSO;
   sLine tmp;
   resGA = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resSA = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resPSO = (sResult*)malloc(sizeof(sResult)*NUM_TEST);
   resultAlgorithm = (sResult**)malloc(sizeof(sResult*)*NUM_ALGORITHM);
   //getDataTextArea();
   int i = 0;
   // init min and max variable
   tmp  = genetic_algorithm(3,7,8,9); //1,10,10,10
     struct_copy(resGA+i,&tmp);
   tmp  = simulatedAnnealing(3,10,0.0001,0.05,1); //1,10,0.0001,0.1,1
     struct_copy(resGA+i,&tmp);
   tmp = particle_swarm_optimization(3,10,0.4,0.7,0.75); //1,10,0.2,0.8,0.9
     struct_copy(resGA+i,&tmp);
   for(i = 1; i < NUM_TEST;i++)
   {
       tmp  = genetic_algorithm(3,7,8,9); //1,10,10,10
         struct_copy(resGA+i,&tmp);
       tmp  = simulatedAnnealing(3,10,0.0001,0.05,1); //1,10,0.0001,0.1,1
         struct_copy(resGA+i,&tmp);
       tmp = particle_swarm_optimization(3,10,0.4,0.7,0.75); //1,10,0.2,0.8,0.9
         struct_copy(resGA+i,&tmp);
   }
   resultAlgorithm[0] = resGA;
   resultAlgorithm[1] = resSA;
   resultAlgorithm[2] = resPSO;
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

