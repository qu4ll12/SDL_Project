#pragma once

#include "renderWindow.h"
#include "entity.h"


class item : public entity
{
public:
    item(float x, float y, float w, float h, SDL_Texture* texture);
    void spawn(renderWindow &a, float speed);
    void stillE(renderWindow &a);
    void reset();
    float getX();
    float getY();
    bool event(float &n);
    bool outOfFuel();
private:
    float e_x,e_y,e_w,e_h;
    std::vector <entity> animation;
    int timer;
    float fuel;
    int xsrc[6];
    SDL_Texture* tex;
};

