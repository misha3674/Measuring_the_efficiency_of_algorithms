#include <windows.h>
#include <stdio.h>
#include "common.h"
#include "load.h"
#include "load_result.h"
#include "draw.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include "glfw/include/glfw3.h"
#include "proccessing.h"

GLFWwindow* window;
sListText*    pHeadList_TextSetting;
sListText*    pHeadList_TextResult;
listTextArea* pHeadList_TextAreaSetting;
sListTexture* pHeadList_TextuteTask;
sListTexture* pHeadList_TextuteTask1;
sListTexture* pHeadList_TextuteTask2;
sListTexture* pHeadList_TextuteTask3;
sListTexture* pHeadList_TextuteTask4;
sListButton*  pHeadList_TextButtonSetting;
sListButton*  pHeadList_TextButtonResult;
sListScale*   pHeadList_Scale;
sResult** result;
eState state = PREPARE_SETTINGS;

int gl_init();
void key_click_clb(GLFWwindow *pWindow, int aKey, int aScanCode, int aAction, int aMods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

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
       getState(&state);
       switch(state) // state processing in the callback function
       {

           case PREPARE_SETTINGS:
           {
                pHeadList_TextuteTask1     = load_Texture_task1();
                pHeadList_TextuteTask2     = load_Texture_task2();
                pHeadList_TextuteTask3     = load_Texture_task3();
                pHeadList_TextuteTask4     = load_Texture_task4();
                pHeadList_TextAreaSetting  = load_TextArea_setting();
                pHeadList_TextButtonSetting= load_Button_setting();
                setState(SETTINGS);
           }
           break;
           case SETTINGS:
           {
               switch(getTest())
               {
                    case 0:
                        pHeadList_TextuteTask =pHeadList_TextuteTask1;
                    break;
                   case 1:
                        pHeadList_TextuteTask =pHeadList_TextuteTask2;
                   break;
                   case 2:
                        pHeadList_TextuteTask =pHeadList_TextuteTask3;
                   break;
                   case 3:
                        pHeadList_TextuteTask =pHeadList_TextuteTask4;
                   break;
                   default: break;
               }
               draw_Texture_list( pHeadList_TextuteTask);
               draw_TextArea_list(pHeadList_TextAreaSetting);
               draw_Button_list(  pHeadList_TextButtonSetting);
           }
           break;
           case PREPARE_RESULT:
           {
                result = run_algorithm();
                pHeadList_Scale =  load_scale(result);
                pHeadList_TextResult = load_Text_result();
                pHeadList_TextButtonResult = load_Button_result();
                setState(RESULTS);
           }
           break;
           case RESULTS:
           {
                //draw_scale(pHeadList_Scale);
                draw_Text_list(pHeadList_TextResult);
                draw_Button_list(pHeadList_TextButtonResult);
           }
           break;
           case WAITING:
           {
                setState(PREPARE_RESULT);
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
       if(state == SETTINGS)
           processing_text_textArea(aKey);
    }
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    double pos_x = 0.;
    double pos_y = 0.;
    glfwGetCursorPos(window,&pos_x,&pos_y);
    getState(&state);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        if(state == SETTINGS)
        {
            proccesing_text_area(pHeadList_TextAreaSetting,(int)pos_x/STEP_CURSOR,(int)pos_y/STEP_CURSOR);
            proccesing_button_list(pHeadList_TextButtonSetting,(int)pos_x/STEP_CURSOR,(int)pos_y/STEP_CURSOR);
        }
        if(state == RESULTS)
        {
            proccesing_button_list(pHeadList_TextButtonResult,(int)pos_x/STEP_CURSOR,(int)pos_y/STEP_CURSOR);
        }
}
