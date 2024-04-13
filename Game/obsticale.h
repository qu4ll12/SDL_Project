#pragma once

#include "renderWindow.h"
#include "entity.h"

class obsticale: public entity
{
public:
    obsticale(float obsticale_x, float obsticale_y, float obsticale_w, float obsticale_h, SDL_Texture* _tex);
    void stillO(renderWindow& a);
    void spawn(renderWindow& a, float speed);
    bool event(float n);
    void setDiff(std:: vector <obsticale> enemies, float n);
    float getX();
    float getY();
    void reset();
protected:
    float difficulty;
private:
    float velocity;
    float x;
    SDL_Texture* tex;
    std:: vector <entity> frame;
    int cnt;
    float o_w;
    float o_h;
};
