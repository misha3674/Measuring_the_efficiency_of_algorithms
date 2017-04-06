#ifndef PROCCESSING_H
#define PROCCESSING_H

void proccesing_button_list(sListButton* pHead,int click_x,int click_y);

void action_button_left();
void action_button_right();
void action_button_result();

void getState(eState* aState);
void setState(eState newState);
int getTest();

#endif // PROCCESSING_H
