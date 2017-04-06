#ifndef TEXT_AREA_TOOLS_H
#define TEXT_AREA_TOOLS_H

listTextArea* innit_textArea_list();
listTextArea* add_textArea_list(listTextArea* pHead,const char* aName,int aPos_x,int aPos_y);
listTextArea* clear_textArea_list(listTextArea* pHead);

void set_range_last_area();
void set_default_last_area();

#endif // TEXT_AREA_TOOLS_H
