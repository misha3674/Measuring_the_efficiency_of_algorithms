#include "common.h"
#include "proccessing.h"
#include <stdlib.h>

void proccesing_button_list(sListButton* pHead,int click_x,int click_y)
{
    sListButton* crowler = NULL;
        if(pHead == NULL)
            return;
    crowler = pHead->pNext;
    while(crowler->pNext != NULL)
    {
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
