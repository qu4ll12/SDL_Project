#pragma once

#include "renderWindow.h"
#include "entity.h"

class player: public entity
{
public:
    player(float player_x, float player_y, float player_w, float player_h, SDL_Texture* texture);
    void loadRender();
    void defaultPlayer(renderWindow& a, int n);
    void rightLane(renderWindow& a, int n);
    void leftLane(renderWindow& a, int n);
private:
    float x[20];
    float p_x,p_y,p_w,p_h;
    std:: vector <entity> drift;
    SDL_Texture* tex;
    int frame_numr,frame_numl;
    int cnt;
};
