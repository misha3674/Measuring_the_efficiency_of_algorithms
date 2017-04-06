#ifndef TEXTURE_TOOLS_H
#define TEXTURE_TOOLS_H

sListTexture* innit_texture_list();
sListTexture* add_textute_list(sListTexture* pHead,
                               const char* way,
                               int pos_x,int pos_y,
                               int width, int height);
#endif // TEXTURE_TOOLS_H
