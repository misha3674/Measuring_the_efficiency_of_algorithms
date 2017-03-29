#include "draw.h"
#include "innit.h"
eState state = WAITING;
// callback
//switch(state)
//  check_buttonIsPress_change_state(*state)
int main()
{
    innit_openGL(&state); // save pointer in draw_file//for changed state in calback function
    while( isRun() ) // check run window
    {
       switch(state) // state processing in the callback function
       {
           case SETTINGS:
               draw_settings_screen(); // return    waitnig OR settings
           break;
           case RESULTS:
               draw_results_screen(); // return settings OR results
           break;
           case WAITING:
               innit_settings(); //calculate before loop
               init_results();   //calculate
               draw_waiting_screen();//state = RESULTS;  // go to results
           break;
           default: break;
       }
    }
    return 0;
}

