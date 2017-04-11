#include "common.h"
#include "text_area_tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define DEF_MIN_VALUE 0
#define DEF_MAX_VALUE 50
#define DEF_VALUE 10
#define PLACE_ONE_SMB_PX 12
int fillDef(char *fill,float def);

listTextArea* innit_textArea_list()
{
    listTextArea* askHead = NULL;
    askHead = (listTextArea*)malloc(sizeof(listTextArea));
    askHead->pNext = NULL;
    return askHead;
}
listTextArea* add_textArea_list(listTextArea* pHead,const char* aName,int aPos_x,int aPos_y)
{
    listTextArea* crowler = pHead;
    listTextArea* newNode = NULL;
    newNode = (listTextArea*)malloc(sizeof(listTextArea));
    strcpy(&(newNode->name[0]),aName);
    newNode->mX = aPos_x;
    newNode->mY = aPos_y;
    newNode->hight = DEF_MAX_VALUE;
    newNode->low   = DEF_MIN_VALUE;
    newNode->shift_area = (int)( (strlen(&(newNode->name[0]))*PLACE_ONE_SMB_PX)/STEP_CURSOR);
    newNode->i = fillDef(&(newNode->text[0]),DEF_VALUE);
    newNode->pNext = NULL;

    while(crowler->pNext != NULL)
        crowler = crowler->pNext;
    crowler->pNext = newNode;
    return newNode;
}
void set_limit_def_area(listTextArea* pArea,double min, double max, double def)
{
    pArea->low = min;
    pArea->hight = max;
    pArea->i = fillDef(&(pArea->text[0]),def);
}
// ---------------------------------
int fillDef(char *fill,float def)
{
    char buffer[NUM_SMB] = {0};
    int length = 0;
    length=sprintf(buffer,"%.4f",def);
    int i = 0;
    for(i = 0; i < NUM_SMB; i++)
    {
        fill[i]= buffer[i];
    }
    return length;
}
//-----------------------------------------------------------
double getInputData(listTextArea* pHead,const char* namearea)
{
    double numf = 0.;
    listTextArea* crowler = pHead->pNext;
    while(crowler->pNext != NULL)
    {
        if(strcmp(namearea,&(crowler->name[0])) == 0)
        {
            numf = atof(&(crowler->text[0]));
            return numf;
        }
        crowler = crowler->pNext;
    }
    if(strcmp(namearea,&(crowler->name[0])) == 0)
    {
        numf = atof(&(crowler->text[0]));
        return numf;
    }
    return -1;
}
