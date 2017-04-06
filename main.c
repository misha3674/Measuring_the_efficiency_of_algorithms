#include <windows.h>
#include "common.h"
#include "load.h"
#include "draw.h"
#include <stdio.h>

#include "glfw/include/glfw3.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <time.h>

#define SCREEN_WIDTH        1300
#define SCREEN_HEIGHT       690
#define IS_FULL_SCREEN      0
//----------------------------------------------
GLFWwindow* window;

sListText*    pHeadList_TextSetting;
listTextArea* pHeadList_TextAreaSetting;
sListTexture* pHeadList_TextuteSetting;
sListButton*  pHeadList_TextButtonSetting;

int gl_init();
void key_click_clb(GLFWwindow *pWindow, int aKey, int aScanCode, int aAction, int aMods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

eState state = PREPARE_SETTINGS;

int main()
{
    gl_init();
    while( !glfwWindowShouldClose(window) )
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClearColor(0.1,0.5,0.1,0);
       switch(state) // state processing in the callback function
       {

           case PREPARE_SETTINGS:
           {
                pHeadList_TextuteSetting   = load_Texture_setting();
                pHeadList_TextAreaSetting  = load_TextArea_setting();
                pHeadList_TextButtonSetting= load_Button_setting();
                state = SETTINGS;
           }
           break;
           case SETTINGS:
           {
               draw_Texture_list( pHeadList_TextuteSetting);
               draw_TextArea_list(pHeadList_TextAreaSetting);
               draw_Button_list(  pHeadList_TextButtonSetting);
           }
           break;
           case PREPARE_RESULT:
           {
                //run_algorithm();

           }
           break;
           case RESULTS:
           {

           }
           break;
           case WAITING:
           {

           }
           break;
           default: break;
       }
       /* Swap front and back buffers */
       glfwSwapBuffers(window);
       /* Poll for and process events */
       glfwPollEvents();
    }
    glfwTerminate();
    printf("Good bye\n");
    return 0;
}

int gl_init()
{
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              "coursework",
                              IS_FULL_SCREEN ? glfwGetPrimaryMonitor() : NULL,
                              NULL);
    glfwSetWindowPos(window,0,20);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback        (window, key_click_clb);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 1);
    glfwSwapInterval(1);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    return 1;
}
void key_click_clb(GLFWwindow *pWindow, int aKey, int aScanCode, int aAction, int aMods)
{
    if(aKey == GLFW_KEY_ESCAPE && aAction == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    if(aAction == GLFW_RELEASE)
    {
       printf("click\n");
    }
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double pos_x = 0.;
    double pos_y = 0.;
    glfwGetCursorPos(window,&pos_x,&pos_y);
    printf(" click %g %g\n",pos_x,pos_y);
}
