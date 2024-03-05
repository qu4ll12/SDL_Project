#pragma once

#include "renderWindow.h"
#include "entity.h"

class obsticale: public entity
{
public:
    obsticale(float obsticale_w, float obsticale_h, SDL_Texture* _tex);
    void spawn(renderWindow& a, float speed);
    float getX();
    float getY();
private:
    float velocity;
    float x;
    SDL_Texture* tex;
    float o_w;
    float o_h;
};
