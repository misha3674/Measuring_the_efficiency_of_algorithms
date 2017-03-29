#include <stdio.h>
typedef enum
{
    SETTINGS = 0,
    RESULTS
}eState;

eState state = SETTINGS;

int main()
{
    innit_openGL(); // return window
    innit_settings(); // all that need calculate before loop
    init_results();   // // all that need calculate before loop

    while( isRun() ) // check run window
    {
       state = getState();
       switch(state)
       {
           case SETTINGS:
               processing_settings();
           break;
           case RESULTS:
               processing_results();
           break;
           default: break;
       }
    }
    return 0;
}
