#ifndef TEXT_AREA_TOOLS_H
#define TEXT_AREA_TOOLS_H

listTextArea* innit_textArea_list();
listTextArea* add_textArea_list(listTextArea* pHead,const char* aName,int aPos_x,int aPos_y);
void set_limit_def_area(listTextArea* pArea,double min, double max, double def);
double getInputData(listTextArea* pHead,const char* namearea);
#endif // TEXT_AREA_TOOLS_H
