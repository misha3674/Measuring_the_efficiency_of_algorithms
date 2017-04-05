#ifndef TEXT_TOOLS_H
#define TEXT_TOOLS_H

sListText* innit_text_list();
void add_text_list(const sListText*,char* aText,int aX, int aY);
void clear_text_list(sListText*);
void draw_text_list(const sListText*);

#endif // TEXT_TOOLS_H
