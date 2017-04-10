#ifndef PROCCESSING_H
#define PROCCESSING_H

void proccesing_button_list(sListButton* pHead,int click_x,int click_y);
void action_button_left();
void action_button_right();
void action_button_settting();
void action_button_result();
void proccesing_text_area(listTextArea* pHead,int x, int y);
void processing_text_textArea(int aKey);
void getState(eState* aState);
void setState(eState newState);
int getTestFunction();
void proccesing_hover(sResult** result,double* aX,double* aY);
listTextArea* getPressArea();
sResult** run_algorithm(listTextArea * data_input);

#endif // PROCCESSING_H
