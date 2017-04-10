#include <stdlib.h>
#include <stdio.h>
#include "../common.h"
#include "scale_tools.h"

//--------------Scale --------------------------------------------------------------
sListScale* innit_scale_list()
{
    sListScale* askHead = NULL;
    askHead = (sListScale*)malloc(sizeof(sListScale));
    askHead->pNext = NULL;
    return askHead;
}
sListScale* create_scale(sListScale* pHead, int pos_x, int pos_y, int w, int h, sResult* data)
{
    sListScale* crowler = pHead;
    sListScale* newNode = NULL;
    newNode = (sListScale*)malloc(sizeof(sListScale));
    newNode->posX = pos_x;
    newNode->posY = pos_y;
    newNode->w = w;
    newNode->h = h;
    newNode->pNext = NULL;
    newNode->dataValue = (int*)malloc(sizeof(int)*NUM_TEST);
    newNode->dataTime = (int*)malloc(sizeof(int)*NUM_TEST);
    double max_time = data[0].time;
    double min_value = data[0].value;
    double min_time = 0.;
    double max_value = 0.;
    for(int i = 0; i < NUM_TEST; i++)
    {
        if(max_time < data[i].time)
            max_time = data[i].time;
        if(min_value > data[i].value)
            min_value = data[i].value;
    }
    printf("min_value %g\n",min_value);
    min_time  = max_time - RANGE_SCALE_TIME;
    max_value = min_value + RANGE_SCALE_VALUE;
    double rateTime = 0.;
    double rateValue = 0.;
    for(int i = 0; i < NUM_TEST; i++)
    {
        if(data[i].value > max_value)
            newNode->dataValue[i] = HEIGHT_OUTRANGE_BAR;
        else
        {
            rateValue = ( (data[i].value - min_value)/RANGE_SCALE_VALUE);
            newNode->dataValue[i] = (int)( (newNode->h - MIN_HEIGHT_INRANGE_BAR)*rateValue + MIN_HEIGHT_INRANGE_BAR);
        }
        if(data[i].time < min_time)
            newNode->dataTime[i] = HEIGHT_OUTRANGE_BAR;
        else
        {
            rateTime  = ( (data[i].time - min_time)/RANGE_SCALE_TIME );
            newNode->dataTime[i]  = (int)( (newNode->h - MIN_HEIGHT_INRANGE_BAR)*rateTime + MIN_HEIGHT_INRANGE_BAR );
        }
    }
    while(crowler->pNext != NULL)
        crowler = crowler->pNext;
    crowler->pNext = newNode;
    return newNode;
}
