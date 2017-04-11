#ifndef DRAW_H
#define DRAW_H

void innit_openGL_window();
void draw_Text_list(sListText* pHead);
void draw_Texture_list(sListTexture* pHead);
void draw_TextArea_list(listTextArea* pHead);
void draw_Button_list(sListButton* pHead);

void draw_Scale_list(sListScale* pHead);
void draw_line(int* x, int* y, int* a, int* b);
void draw_hover(sResult* res, int* x, int* y);
#endif // DRAW_H
