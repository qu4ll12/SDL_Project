#pragma once

#include "renderWindow.h"
#include "entity.h"

static float road_w=300;
static float road_h=750;
static int frame_num=0;

class road: public entity
{
public:
    road(float r_w, float r_h, SDL_Texture* r_tex);
    void textureRoad(renderWindow& a);
    void animateRoad(renderWindow& a);
private:
    SDL_Texture* tex1;
    SDL_Texture* tex2;
    SDL_Texture* tex3;
    SDL_Texture* tex4;
};
