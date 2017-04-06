#include "common.h"
#include "draw.h"
#include "glfw/include/glfw3.h"
#include "glut/include/glut.h"
#include <stdio.h>

void draw_Text_list(sListText* pHead)
{
    int c = 0;
    sListText* crowler = pHead->pNext;
    if(pHead == NULL)
        return;

    while(crowler->pNext != NULL)
    {
        glColor3ub(255,255,255);
        glRasterPos2i(crowler->mX*STEP_CURSOR,crowler->mY*STEP_CURSOR);
        for(c = 0; crowler->text[c] != 0; c++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->text[c]);
        crowler = crowler->pNext;
    }
    glRasterPos2i(crowler->mX*STEP_CURSOR,crowler->mY*STEP_CURSOR);
    for(c = 0; crowler->text[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->text[c]);
}
void draw_Texture_list(sListTexture* pHead)
{

}
void draw_TextArea_list(listTextArea* pHead)
{

}
void draw_Button_list(sListButton* pHead)
{

}

//--------------------------------------------------------------
