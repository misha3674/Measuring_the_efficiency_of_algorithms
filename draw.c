#include "common.h"
#include "draw.h"
#include "glfw/include/glfw3.h"
#include "glut/include/glut.h"
#include <stdio.h>
#include <string.h>

#define HEIGHT_AREA 2
#define WIDTH_AREA 8
#define SHIFT_TOP 1.5
listTextArea* pPressArea = 0;

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
    sListTexture* crowler = NULL;
    if(pHead == NULL)
        return;
    crowler = pHead->pNext;
    glColor3ub(10,10,130);
    while(crowler->pNext != NULL)
    {
            glBindTexture(GL_TEXTURE_2D,(crowler->texture));
        glBegin(GL_QUADS);
            glTexCoord2f(1,1);
            glVertex2i( (crowler->mX)*STEP_CURSOR,      crowler->mY*STEP_CURSOR);
            glTexCoord2f(1,0);
            glVertex2i( (crowler->mX+crowler->width)*STEP_CURSOR,    crowler->mY*STEP_CURSOR);
            glTexCoord2f(0,0);
            glVertex2i( (crowler->mX+crowler->width)*STEP_CURSOR,   (crowler->mY+crowler->height)*STEP_CURSOR);
            glTexCoord2f(0,1);
            glVertex2i( crowler->mX*STEP_CURSOR,        (crowler->mY+crowler->height)*STEP_CURSOR);
        glEnd();
        crowler = crowler->pNext;
    }
        glBindTexture(GL_TEXTURE_2D,(crowler->texture));
        glBegin(GL_QUADS);
            glTexCoord2f(1,1);
            glVertex2i( (crowler->mX)*STEP_CURSOR,      crowler->mY*STEP_CURSOR);
            glTexCoord2f(1,0);
            glVertex2i( (crowler->mX+crowler->width)*STEP_CURSOR,    crowler->mY*STEP_CURSOR);
            glTexCoord2f(0,0);
            glVertex2i( (crowler->mX+crowler->width)*STEP_CURSOR,   (crowler->mY+crowler->height)*STEP_CURSOR);
            glTexCoord2f(0,1);
            glVertex2i( crowler->mX*STEP_CURSOR,        (crowler->mY+crowler->height)*STEP_CURSOR);
        glEnd();
}
void draw_TextArea_list(listTextArea* pHead)
{
    int c = 0;
    listTextArea* crowler = NULL;
    if(pHead == NULL)
        return;

    // draw layer
    crowler = pHead->pNext;
    glColor3ub(255, 255, 255);
    while(crowler->pNext != NULL)
    {
        glBegin(GL_QUADS);
            glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                        (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
            glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                        (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
            glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                        (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
            glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                        (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
        glEnd();
        crowler = crowler->pNext;
    }
    glBegin(GL_QUADS);
        glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                    (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
        glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                    (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
        glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                    (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
        glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                    (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
    glEnd();

    // border
    glColor3ub(0, 0, 255);
    if(pPressArea != NULL) // getPressArea()
    {
        crowler = pPressArea;
        glLineWidth(2);
            glBegin(GL_LINES);
                glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
                glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP)*STEP_CURSOR);

                glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
                glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);

                glVertex2i( (crowler->mX+WIDTH_AREA+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
                glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);

                glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP+HEIGHT_AREA)*STEP_CURSOR);
                glVertex2i( (crowler->mX+crowler->shift_area)*STEP_CURSOR,
                            (crowler->mY-SHIFT_TOP)*STEP_CURSOR);
            glEnd();
    }
    //---------------------------
    crowler = pHead->pNext;
    while(crowler->pNext != NULL)
    {
        glColor3ub(0,0,0);
        glRasterPos2i(crowler->mX*STEP_CURSOR,crowler->mY*STEP_CURSOR);
        for(c = 0; crowler->name[c] != 0; c++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->name[c]);

        glRasterPos2i((crowler->mX+crowler->shift_area+1)*STEP_CURSOR,crowler->mY*STEP_CURSOR);
        for(c = 0; crowler->text[c] != 0; c++)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->text[c]);

        crowler = crowler->pNext;
    }
    glRasterPos2i(crowler->mX*STEP_CURSOR,crowler->mY*STEP_CURSOR);
    for(c = 0; crowler->name[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->name[c]);

    glRasterPos2i((crowler->mX+crowler->shift_area+1)*STEP_CURSOR,crowler->mY*STEP_CURSOR);
    for(c = 0; crowler->text[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,crowler->text[c]);

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
    printf("%i %i\n",x,y);
    pPressArea = NULL;
}
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
                if(pPressArea->i < NUM_SMB)
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
//-----------------------------------------------------------------
void draw_Button_list(sListButton* pHead)
{

}

//--------------------------------------------------------------
