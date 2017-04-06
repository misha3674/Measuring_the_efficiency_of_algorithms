#include "common.h"
#include "proccessing.h"
#include <stdlib.h>
#include <stdio.h>
int gTest = 0;
eState gState = PREPARE_SETTINGS;
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
void action_button_left()
{
    printf("Button left\n");
    gTest--;
    if(gTest < 0)
        gTest = 3;
}
void action_button_right()
{
    printf("Button right\n");
    gTest++;
    if(gTest > 3)
        gTest = 0;
}
int getTest()
{
    return gTest;
}
void action_button_result()
{
    printf("Result\n");
    gState = RESULTS;
}
void getState(eState* aState)
{
    *aState = gState;
}
void setState(eState newState)
{
    gState=newState;
}
