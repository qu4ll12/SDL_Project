#pragma once

#include "renderWindow.h"
#include "entity.h"

class player: public entity
{
public:
    player(float player_x, float player_y, float player_w, float player_h, SDL_Texture* texture);
    void loadRender();
    void defaultPlayer(renderWindow& a, float &n);
    void rightLane(renderWindow& a, float &n);
    void rightLane_(renderWindow& a, float &n);
    void leftLane(renderWindow& a, float &n);
    void leftLane_(renderWindow& a, float &n);
    void levelUp(renderWindow&a, float &n);
    void die(renderWindow&a, float &n);
    void shieldOn();
    void shieldOff();
    bool shieldStatus();
private:
    float x[20];
    float p_x,p_y,p_w,p_h;
    float cnt,timer,timer1,timer2;
    int timerE;
    std:: vector <entity> drift;
    std:: vector <entity> explosion;
    SDL_Texture* tex;
    bool shield;
};
