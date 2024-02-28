#pragma once

#include "renderWindow.h"
#include "entity.h"

static float road_w=300;
static float road_h=750;

class road: public entity
{
public:
    road(float r_w, float r_h, SDL_Texture* r_tex);
    animateRoad();
private:
    SDL_Texture* tex1;
    SDL_Texture* tex2;
    SDL_Texture* tex3;
    SDL_Texture* tex4;
};
