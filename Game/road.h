#pragma once

#include "renderWindow.h"
#include "entity.h"

static float road_w=300;
static float road_h=750;
static long long unsigned int frame_num=0;

class road: public entity
{
public:
    road(float r_w, float r_h, SDL_Texture* r_tex);
    void textureRoad(renderWindow& a);
    void animateRoad(renderWindow& a, float speed);
private:
    std::vector <SDL_Texture*> tex;
    std::vector <entity> frame;
};
