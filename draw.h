#ifndef DRAW_H
#define DRAW_H

void innit_openGL_window();
void draw_Text_list(sListText* pHead);
void draw_Texture_list(sListTexture* pHead);
void draw_TextArea_list(listTextArea* pHead);
void draw_Button_list(sListButton* pHead);

void proccesing_text_area(listTextArea* pHead,int x, int y);
void processing_text_textArea(int aKey);

#endif // DRAW_H
