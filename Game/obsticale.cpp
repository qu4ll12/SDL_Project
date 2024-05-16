#include "renderWindow.h"
#include "entity.h"
#include "obsticale.h"
#include "def.h"

using namespace std;

obsticale::obsticale(float obsticale_x, float obsticale_y, float obsticale_w, float obsticale_h, SDL_Texture* _tex)
    : entity(obsticale_x, obsticale_y,obsticale_w, obsticale_h, _tex)
{
    o_w=obsticale_w;
    o_h=obsticale_h;
    tex=_tex;
    x=((rand() % (3 - 0 + 1)) + 0);
    x=BORDER_LEFT+LANE_WIDTH*x;
    difficulty=NORMAL_MODE;
    speed=NORMAL_SPEED;
    int difficulty1=NORMAL_MODE;
    velocity=((rand() % (-difficulty1 - -difficulty1*3 + 1)) + -difficulty1*3);
    timer=0;
    frame.push_back(entity (0,0,o_w,o_h,tex));
    frame.push_back(entity (o_w,0,o_w,o_h,tex));
}

float obsticale::getX()
{
    return x;
}

float obsticale::getY()
{
    return velocity;
}

float obsticale::getH()
{
    return o_h;
}

void obsticale::setSpeed(int s)
{
    speed=s;
}

void obsticale::setDiff(vector <obsticale> &enemies, float n)
{
    for(int i=0;i<ENEMIES_SIZE;i++)
    {
        enemies[i].difficulty=n;
    }
}

void obsticale::reset()
{
    x=((rand() % (3 - 0 + 1)) + 0);
    x=BORDER_LEFT+LANE_WIDTH*x;
    int difficulty1=difficulty;
    velocity=((rand() % (-difficulty1 - -difficulty1*3 + 1)) + -difficulty1*3);
}


void obsticale::stillO(renderWindow& a)
{
    if (velocity<=SCREEN_HEIGHT && timer<=30)
    {
        a.renderTexture(frame[0],x,velocity,o_w,o_h);
    }
    else if (velocity<SCREEN_HEIGHT && timer>30 && timer<=61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
    }
}

void obsticale::spawn(renderWindow& a)
{
    if (velocity<=SCREEN_HEIGHT && timer<=30)
    {
        a.renderTexture(frame[0],x,velocity,o_w,o_h);
        velocity+=speed;
        timer++;
    }
    else if (velocity<SCREEN_HEIGHT && timer>30 && timer<61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
        velocity+=speed;
        timer++;
    }
    else if (timer==61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
        timer=0;
    }
    else
    {
        reset();
    }
}

bool obsticale::event(float n)
{
    bool d;

    if(n==x && velocity>=SCREEN_HEIGHT-o_h*2-10 && velocity<=SCREEN_HEIGHT-15) d=true;
    else d=false;

    return d;
}

float obsticale::returnSpeed()
{
    return speed;
}
