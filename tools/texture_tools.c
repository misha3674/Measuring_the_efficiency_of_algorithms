#include "common.h"
#include "texture_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include "loadimage.h"
sListTexture* innit_texture_list()
{
    sListTexture* askHead = NULL;
    askHead = (sListTexture*)malloc(sizeof(sListTexture));
    askHead->pNext = NULL;
    return askHead;
}
sListTexture* add_textute_list(sListTexture* pHead,const char* way,
                               int pos_x,int pos_y,
                               int width, int height)
{
    sListTexture* crowler = pHead;
    sListTexture* newNode = NULL;

    newNode = (sListTexture*)malloc(sizeof(sListTexture));

    newNode->mX = pos_x;
    newNode->mY = pos_y;
    newNode->width = width;
    newNode->height = height;
    newNode->texture = LoadTextureAUTO(way);
    newNode->pNext = NULL;

    while(crowler->pNext != NULL)
        crowler = crowler->pNext;
    crowler->pNext = newNode;

    return newNode;
}

