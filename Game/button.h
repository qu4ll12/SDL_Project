#pragma once

#include "renderWindow.h"
#include "entity.h"

class button: public entity
{
public:
    button(float button_x, float button_y, float button_w, float button_h, SDL_Texture* texture);
    void unpress(renderWindow& a);
    void pressed(renderWindow& a);
    void idle(renderWindow& a);
    bool event();
private:
    SDL_Texture* button_tex;
    float b_x,b_y,b_w,b_h;
    int frame_num;
};
