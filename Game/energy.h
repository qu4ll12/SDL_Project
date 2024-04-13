#pragma once

#include "renderWindow.h"
#include "entity.h"


class energy : public entity
{
public:
    energy(float x, float y, float w, float h, SDL_Texture* texture);
    void spawn(renderWindow &a, float speed);
    void stillE(renderWindow &a);
    void reset();
    bool event(float &n);
private:
    float e_x,e_y,e_w,e_h;
    std::vector <entity> animation;
    int timer;
    int xsrc[6];
    SDL_Texture* tex;
};
