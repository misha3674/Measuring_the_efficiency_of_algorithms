#ifndef LOAD_H
#define LOAD_H

listTextArea* load_TextArea_setting();
sListTexture* load_Texture_task1();
sListTexture* load_Texture_task2();
sListTexture* load_Texture_task3();
sListTexture* load_Texture_task4();

sListButton*  load_Button_setting();

void load_clear_listTexture(sListTexture*);
void load_clear_listTextArea(listTextArea*);
void load_clear_listButton(sListButton*);

#endif // LOAD_H
