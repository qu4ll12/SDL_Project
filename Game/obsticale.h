#pragma once

#include "renderWindow.h"
#include "entity.h"

class obsticale: public entity
{
public:
    obsticale(float obsticale_x, float obsticale_y, float obsticale_w, float obsticale_h, SDL_Texture* _tex);
    void stillO(renderWindow& a);
    void setSpeed(int s);
    void spawn(renderWindow& a);
    void reset();
    void setDiff(std:: vector <obsticale> &enemies, float n);
    float getX();
    float getY();
    float getH();
    float returnSpeed();
    bool event(float n);
private:
    int difficulty;
    float x,velocity;
    float o_w;
    float o_h;
    float speed;
    int initiate,timer;
    SDL_Texture* tex;
    std:: vector <entity> frame;
};
