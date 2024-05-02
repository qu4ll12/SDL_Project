#pragma once

#include "renderWindow.h"
#include "entity.h"

class obsticale: public entity
{
public:
    obsticale(float obsticale_x, float obsticale_y, float obsticale_w, float obsticale_h, SDL_Texture* _tex);
    void stillO(renderWindow& a);
    void spawn(renderWindow& a, float speed);
    void resetX();
    void reset();
    void setDiff(std:: vector <obsticale> enemies, float n);
    float getX();
    float getY();
    bool event(float n);
protected:
    float difficulty;
private:
    float x,velocity;
    float o_w;
    float o_h;
    int initiate,cnt;
    SDL_Texture* tex;
    std:: vector <entity> frame;
};
