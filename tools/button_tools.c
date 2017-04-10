#include <stdlib.h>
#include <string.h>
#include "../common.h"
#include "tools/button_tools.h"
#include <GL/gl.h>
#include "../loadimage.h"
#define DEF_BUTTON_W 7
#define DEF_BUTTON_H 7

sListButton* innit_button_list()
{
    sListButton* askHead = NULL;
    askHead = (sListButton*)malloc(sizeof(sListButton));
    askHead->pNext = NULL;
    return askHead;
}
sListButton* add_button_list(sListButton* pHead, int pos_x, int pos_y)
{
        sListButton* crowler = pHead;
        sListButton* newNode = NULL;

        newNode = (sListButton*)malloc(sizeof(sListButton));
        newNode->name[0] = 0; // empty name
        newNode->texture = 0; // empty texture
        newNode->mX = pos_x;
        newNode->mY = pos_y;
        newNode->w = DEF_BUTTON_W;
        newNode->h = DEF_BUTTON_H;
        newNode->pNext = NULL;

        while(crowler->pNext != NULL)
            crowler = crowler->pNext;
        crowler->pNext = newNode;
        return newNode;
}
void set_name_button(sListButton* button, const char* name)
{
    strcpy( &(button->name[0]),name);
}
void set_texture_button(sListButton* button, const char* way)
{
    button->texture = LoadTextureAUTO(way);
}
void set_size_button(sListButton* button, int w, int h)
{
    button->h  = h;
    button->w  = w;
}
void set_action_button(sListButton* button, pf pAction)
{
    button->action  = pAction;
}
