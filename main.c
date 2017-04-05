#include <windows.h>
#include "common.h"
#include "load.h"

void draw_Text_list(sListText* pHead);
void draw_Texture_list(sListTexture* pHead);
void draw_TextArea_list(listTextArea* pHead);
void draw_Button_list(sListButton* pHead);
//----------------------------------------------

sListText*    pHeadList_TextSetting;
listTextArea* pHeadList_TextAreaSetting;
sListTexture* pHeadList_TextuteSetting;
sListButton*  pHeadList_TextButtonSetting;

eState state = PREPARE_SETTINGS;

int main()
{
    while( 1 )
    {
       switch(state) // state processing in the callback function
       {

           case PREPARE_SETTINGS:
           {
                pHeadList_TextSetting      = load_Text_setting();
                pHeadList_TextuteSetting   = load_Texture_setting();
                pHeadList_TextAreaSetting  = load_TextArea_setting();
                pHeadList_TextButtonSetting= load_Button_setting();
                state = SETTINGS;
           }
           break;
           case SETTINGS:
           {
               draw_Text_list(    pHeadList_TextSetting);
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
       Sleep(33);
    }
    return 0;
}
// ---------------------------------------------------------------------------------------
void draw_Text_list(sListText* pHead)
{

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

