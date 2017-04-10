#ifndef SCALE_TOOLS_H
#define SCALE_TOOLS_H

sListScale* innit_scale_list();
// bottom left corner
sListScale* create_scale(sListScale* pHead, int pos_x, int pos_y, int w, int h, sResult* data);

#endif // SCALE_TOOLS_H
