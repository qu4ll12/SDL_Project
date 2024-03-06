#pragma once

#include "renderWindow.h"
#include "entity.h"

class button: public entity
{
public:
    button(float button_x, float button_y, float button_w, float button_h, SDL_Texture* texture);
    void loadPress_button(SDL_Texture* texture);
    void unpress(renderWindow& a, float b_x, float b_y);
    void pressed(renderWindow& a, float b_x, float b_y);
private:
    SDL_Texture* state1;
    SDL_Texture* state2;
    float b_x,b_y,b_w,b_h;
};
