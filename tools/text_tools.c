#include "../common.h"
#include "text_tools.h"
#include <stdlib.h>
#include <string.h>

sListText* innit_text_list()
{
    sListText* askHead = NULL;
    askHead = (sListText*)malloc(sizeof(sListText));
    askHead->pNext = NULL;
    return askHead;
}
void add_text_list(sListText* pHead,char* aText,int aX, int aY)
{
    sListText* crowler = pHead;
    sListText* newNode = NULL;

    newNode = (sListText*)malloc(sizeof(sListText));

    strcpy(newNode->text,aText);
    newNode->mX = aX;
    newNode->mY = aY;
    newNode->pNext = NULL;

    while(crowler->pNext != NULL)
        crowler = crowler->pNext;
    crowler->pNext = newNode;
}
void clear_text_list(sListText* pHead)
{
    if(pHead == NULL)
        return;
    sListText* crowler = NULL;
    while(pHead->pNext != NULL)
    {
        crowler = pHead;
        pHead = crowler->pNext;
        free(crowler);
    }
    free(pHead);
    pHead = NULL;
}
