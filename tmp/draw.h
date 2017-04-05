#ifndef DRAW_H
#define DRAW_H

typedef enum
{
    SETTINGS = 0,
    RESULTS,
    WAITING,
    PREPARE_SETTINGS,
    PREPARE_RESULT
}eState;

void draw_settings_screen();
void draw_results_screen();
void draw_waiting_screen();
void innit_openGL(eState*); // transfer pointer ENUM
unsigned int isRun();

#endif // DRAW_H
