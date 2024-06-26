#pragma once

#include "renderWindow.h"
#include "entity.h"

class road: public entity
{
public:
    road(float road_x, float road_y, float road_w, float road_h, SDL_Texture* r_tex);
    void animateRoad(renderWindow& a, int speed);
    void stillRoad(renderWindow &a);
private:
    SDL_Texture* tex;
    std::vector <entity> frame;
    float road_y[30];
    int cnt;
    int frame_num;
};
