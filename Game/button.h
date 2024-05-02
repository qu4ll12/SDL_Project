#pragma once

#include "renderWindow.h"
#include "entity.h"

enum LButton
{
    BUTTON_MOUSE_OUT = 0,
    BUTTON_MOUSE_DOWN = 1,
    BUTTON_MOUSE_OVER_MOTION = 2,
    BUTTON_MOUSE_UP = 3,
};

class button: public entity
{
public:
    button(float button_x, float button_y, float button_w, float button_h, SDL_Texture* texture);
    void unpress(renderWindow& a);
    void pressed(renderWindow& a);
    void idle(renderWindow& a);
    void handleEvent(SDL_Event* e);
    void render(renderWindow &a);
    bool ifPress(renderWindow &a);
    bool event();
private:
    SDL_Texture* button_tex;
    float b_x,b_y,b_w,b_h;
    LButton mCurrentSprite;
};
