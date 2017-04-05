#include "draw.h"

const eState* gState = NULL;

void draw_scale();
void draw_text();
void draw_button();
typedef struct
{
    int x;
    int y;
    int height;
    int width;
    int heightV[100];
    int heightT[100];
    /*int setheightT(int a)
    {
        printf("Hello\n");
        return a;
    }*/
}sScale;

void innit_openGL(eState* aState)
{
    gState = aState; // save adress pointer state
}
void draw_settings_screen()
{
    draw_texture();
    draw_button();
    draw_text();
    draw_input_area();
}
// ---------------------------------------------------------------------------------------
void draw_results_screen()
{
    draw_scale();
    draw_text();
    draw_button();
}
// ---------------------------------------------------------------------------------------
void draw_waiting_screen()
{

}
// ---------------------------------------------------------------------------------------
void draw_scale()
{

}
void draw_text()
{

}
void draw_button()
{

}
unsigned int isRun()
{
    return 0;
}
