#ifndef TEXTURE_TOOLS_H
#define TEXTURE_TOOLS_H

sListTexture* innit_texture_list();
sListTexture* add_textute_list(sListTexture* pHead,
                               const char* way,
                               int pos_x,int pos_y,
                               int width, int height);

sListButton* innit_button_list();
sListButton* add_button_list(sListButton* pHead, int pos_x, int pos_y);

void set_name_button(sListButton* button, const char* name);
void set_texture_button(sListButton* button, const char* way);

void set_size_button(sListButton* button, int w, int h);
void set_action_button(sListButton* button, pf pAction);

#endif // TEXTURE_TOOLS_H
