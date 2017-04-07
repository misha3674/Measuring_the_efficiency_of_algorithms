#include "common.h"
#include "tools/texture_tools.h"
#include <stdlib.h>
#include "load_result.h"
#include "proccessing.h"

sListButton*  load_Button_result()
{
    sListButton* pHead = NULL;
    sListButton* pButton = NULL;
    pHead = innit_button_list();

    pButton = add_button_list(pHead,120,63);
    set_name_button(pButton,"Options");
    set_action_button(pButton,&action_button_result);
    set_size_button(pButton,9,4);
    return pHead;
}
