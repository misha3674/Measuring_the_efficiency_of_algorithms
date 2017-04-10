#include "common.h"
#include "draw.h"
#include "glfw/include/glfw3.h"
#include "glut/include/glut.h"
#include <stdio.h>
#include <string.h>
#include "proccessing.h"

void draw_layer(int pos_x, int pos_y, int w, int h);
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
//---------------------------------------------------------------------------------------------------------
void draw_Texture_list(sListTexture* pHead)
{
    sListTexture* crowler = NULL;
    if(pHead == NULL)
        return;
    crowler = pHead->pNext;
    glColor3ub(255,255,255);
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
//---------------------------------------------------------------------------------------------------------
void draw_TextArea_list(listTextArea* pHead)
{
    int c = 0;
    listTextArea* crowler = NULL;
    if(pHead == NULL)
        return;
    // draw layer
    listTextArea* presArea = NULL;
    presArea = getPressArea();
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
    if(presArea != NULL)
    {
        crowler = presArea;
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
//-----------------------------------------------------------------
void draw_Button_list(sListButton* pHead)
{
    sListButton* crowler = NULL;
    if(pHead == NULL)
        return;
    crowler = pHead->pNext;
    glColor3ub(255,255,255);
    while(crowler->pNext != NULL)
    {
            glBindTexture(GL_TEXTURE_2D,(crowler->texture));
        glBegin(GL_QUADS);
            glTexCoord2f(1,1);
            glVertex2i( (crowler->mX)*STEP_CURSOR,      crowler->mY*STEP_CURSOR);
            glTexCoord2f(1,0);
            glVertex2i( (crowler->mX+crowler->w)*STEP_CURSOR,    crowler->mY*STEP_CURSOR);
            glTexCoord2f(0,0);
            glVertex2i( (crowler->mX+crowler->w)*STEP_CURSOR,   (crowler->mY+crowler->h)*STEP_CURSOR);
            glTexCoord2f(0,1);
            glVertex2i( crowler->mX*STEP_CURSOR,        (crowler->mY+crowler->h)*STEP_CURSOR);
        glEnd();
        crowler = crowler->pNext;
    }
        glBindTexture(GL_TEXTURE_2D,(crowler->texture));
        glBegin(GL_QUADS);
            glTexCoord2f(1,1);
            glVertex2i( (crowler->mX)*STEP_CURSOR,      crowler->mY*STEP_CURSOR);
            glTexCoord2f(1,0);
            glVertex2i( (crowler->mX+crowler->w)*STEP_CURSOR,    crowler->mY*STEP_CURSOR);
            glTexCoord2f(0,0);
            glVertex2i( (crowler->mX+crowler->w)*STEP_CURSOR,   (crowler->mY+crowler->h)*STEP_CURSOR);
            glTexCoord2f(0,1);
            glVertex2i( crowler->mX*STEP_CURSOR,        (crowler->mY+crowler->h)*STEP_CURSOR);
        glEnd();
        crowler = pHead->pNext;
        glColor3ub(255,0,0);
        int c = 0;
        while(crowler->pNext != NULL)
        {
            glRasterPos2i((crowler->mX+1)*STEP_CURSOR,(crowler->mY+2.5)*STEP_CURSOR);
            for(c = 0; crowler->name[c] != 0; c++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,crowler->name[c]);
            crowler = crowler->pNext;
        }
        glRasterPos2i((crowler->mX+1)*STEP_CURSOR,(crowler->mY+2.5)*STEP_CURSOR);
        for(c = 0; crowler->name[c] != 0; c++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,crowler->name[c]);
}
//---------------------------------------------------------------------------------------------------------
void draw_scale(sListScale* pHead)
{
    sListScale* crowler = NULL;
    if(pHead == NULL)
        return;
    crowler = pHead->pNext;
    while(crowler->pNext != NULL)
    {
        //приймає верхній правий кут
        draw_layer(crowler->posX,crowler->posY - crowler->h,crowler->w, crowler->h);
        glLineWidth(WITH_POINT);
        glBegin(GL_LINES);
            for(int i = 0; i < NUM_TEST; i++)
            {
               if(crowler->dataValue[i] == HEIGHT_OUTRANGE_BAR)
                   glColor3ub(0,0,0);
               else
                   glColor3ub(0,255,0);
               glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY)*STEP_CURSOR);
               glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY-crowler->dataValue[i])*STEP_CURSOR);
            }
        glEnd();
        glPointSize(WITH_POINT);
        glBegin(GL_POINTS);
            for(int i = 0; i < NUM_TEST; i++)
            {
                if(crowler->dataValue[i] == HEIGHT_OUTRANGE_BAR)
                    glColor3ub(255,0,0);
                else
                    glColor3ub(0,0,255);
                glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY-crowler->dataTime[i])*STEP_CURSOR);
            }
        glEnd();
        crowler = crowler->pNext;
    }
    draw_layer(crowler->posX,crowler->posY - crowler->h,crowler->w, crowler->h);
    glColor3ub(0,0,255);
    glLineWidth(WITH_POINT);
    glBegin(GL_LINES);
        for(int i = 0; i < NUM_TEST; i++)
        {
            if(crowler->dataValue[i] == HEIGHT_OUTRANGE_BAR)
                glColor3ub(0,0,0);
            else
                glColor3ub(0,255,0);
           glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY)*STEP_CURSOR);
           glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY-crowler->dataValue[i])*STEP_CURSOR);
        }
    glEnd();
    glPointSize(WITH_POINT);
    glColor3ub(255,0,0);
    glBegin(GL_POINTS);
        for(int i = 0; i < NUM_TEST; i++)
        {
            if(crowler->dataValue[i] == HEIGHT_OUTRANGE_BAR)
                glColor3ub(255,0,0);
            else
                glColor3ub(0,0,255);
            glVertex2i((crowler->posX+i)*STEP_CURSOR+WITH_POINT/2,(crowler->posY-crowler->dataTime[i])*STEP_CURSOR);
        }
    glEnd();
}
//---------------------------------------------------------------------------------------------------------
void draw_layer(int pos_x, int pos_y, int w, int h)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex2i( (pos_x)*STEP_CURSOR,      pos_y*STEP_CURSOR);
        glVertex2i( (pos_x+w)*STEP_CURSOR,    pos_y*STEP_CURSOR);
        glVertex2i( (pos_x+w)*STEP_CURSOR,   (pos_y+h)*STEP_CURSOR);
        glVertex2i( pos_x*STEP_CURSOR,        (pos_y+h)*STEP_CURSOR);
    glEnd();

}
void draw_line(int* x, int* y, int* a, int* b)
{
    glColor3ub(0,0,255);
    glLineWidth(WITH_POINT);
    glBegin(GL_LINES);
        glVertex2i(*x*STEP_CURSOR,*y*STEP_CURSOR);
        glVertex2i(*a*STEP_CURSOR,*b*STEP_CURSOR);
    glEnd();
}
void draw_hover(sResult* res, int* x, int* y)
{
    char str_coor_x[25] = {0};
    char str_coor_y[25] = {0};
    char str_value[25] = {0};
    char str_time[25] = {0};
    char str_iter[25] = {0};

    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
        glVertex2i( (*x+2)*STEP_CURSOR,     *y*STEP_CURSOR);
        glVertex2i( (*x+12)*STEP_CURSOR,    *y*STEP_CURSOR);
        glVertex2i( (*x+12)*STEP_CURSOR,   (*y+6)*STEP_CURSOR);
        glVertex2i( (*x+2)*STEP_CURSOR,    (*y+6)*STEP_CURSOR);
    glEnd();
    glColor3ub(0, 255, 255);
    glLineWidth(2);
    glBegin(GL_LINES);
        if(*y < LEVEL_SCALE_GA)
        {
            glVertex2i( (*x+1.5)*STEP_CURSOR,     (0)*STEP_CURSOR);
            glVertex2i( (*x+1.5)*STEP_CURSOR,    (LEVEL_SCALE_GA)*STEP_CURSOR);
        }
        if((*y > LEVEL_SCALE_PSO) && (*y < LEVEL_SCALE_SA))
        {
            glVertex2i( (*x+1.5)*STEP_CURSOR,     (LEVEL_SCALE_PSO)*STEP_CURSOR);
            glVertex2i( (*x+1.5)*STEP_CURSOR,    (LEVEL_SCALE_SA)*STEP_CURSOR);
        }
        if( (*y > LEVEL_SCALE_GA) && (*y < LEVEL_SCALE_PSO))
        {
            glVertex2i( (*x+1.5)*STEP_CURSOR,     (LEVEL_SCALE_GA)*STEP_CURSOR);
            glVertex2i( (*x+1.5)*STEP_CURSOR,    (LEVEL_SCALE_PSO)*STEP_CURSOR);
        }
    glEnd();
    sprintf(str_coor_x,"x: %g",res->mX);
    sprintf(str_coor_y,"y: %g",res->mY);
    sprintf(str_value,"value: %g",res->value);
    sprintf(str_time,"time: %g",res->time);
    sprintf(str_iter,"iter: %i",res->iter);
    int c = 0;
    int h = 0;
    glColor3ub(0, 0, 0);
    glRasterPos2i((*x+2)*STEP_CURSOR,(*y+h)*STEP_CURSOR+10);
    for(c = 0; str_coor_x[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str_coor_x[c]);
    glRasterPos2i((*x+3)*STEP_CURSOR,(*y+h)*STEP_CURSOR+20);
    for(c = 0; str_coor_y[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str_coor_y[c]);
    glRasterPos2i((*x+3)*STEP_CURSOR,(*y+h)*STEP_CURSOR+30);
    for(c = 0; str_value[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str_value[c]);
    glRasterPos2i((*x+3)*STEP_CURSOR,(*y+h)*STEP_CURSOR+40);
    for(c = 0; str_time[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str_time[c]);
    glRasterPos2i((*x+3)*STEP_CURSOR,(*y+h)*STEP_CURSOR+50);
    for(c = 0; str_iter[c] != 0; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str_iter[c]);
}


