#include "common.h"
#include "texture_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include "freeimage/FreeImage.h"
#define DEF_BUTTON_W 7
#define DEF_BUTTON_H 7
//===================================================================================
//===================================================================================
FIBITMAP *loadImage(const char *filename)
{
    FIBITMAP *dib1 = NULL;
    FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(filename);

    dib1 = FreeImage_Load(fif, filename, JPEG_DEFAULT);
    if (!dib1)
    {
       printf("Not found\n");
       return NULL;
    }
    return dib1;
}

GLuint loadTexture (FIBITMAP  * dib1)
{
    GLuint tex_id = 0;
    int x, y;
    int height, width;

    RGBQUAD rgbquad;
    FREE_IMAGE_TYPE type;
    BITMAPINFOHEADER *header;

    type = FreeImage_GetImageType(dib1);
    height = FreeImage_GetHeight(dib1);
    width = FreeImage_GetWidth(dib1);

    header = FreeImage_GetInfoHeader(dib1);
    int scanLineWidh = ((3*width)%4 == 0) ? 3*width : ((3*width)/4)*4+4;
    unsigned char * texels= (GLubyte*)calloc(height*scanLineWidh, sizeof(GLubyte));
    for (x=0 ; x<width ; x++)
        for (y=0 ; y<height; y++)
        {
          FreeImage_GetPixelColor(dib1,x,y,&rgbquad);

          texels[(y*scanLineWidh+3*x)]=((GLubyte*)&rgbquad)[2];
          texels[(y*scanLineWidh+3*x)+1]=((GLubyte*)&rgbquad)[1];
          texels[(y*scanLineWidh+3*x)+2]=((GLubyte*)&rgbquad)[0];
         }

        glGenTextures (1, &tex_id);
        glBindTexture (GL_TEXTURE_2D, tex_id);

        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB,
            width, height, 0, GL_RGB,
            GL_UNSIGNED_BYTE, texels);

      free(texels);
      return tex_id;
}
GLuint  LoadTextureAUTO(const char * filename)
{
    GLuint texID;
    FIBITMAP  *dib1 = loadImage(filename);
    texID = loadTexture(dib1);
        FreeImage_Unload(dib1);
    return texID;
}
//=============================================================================
//=============================================================================
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
//-------------------------------------------------------------------
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

