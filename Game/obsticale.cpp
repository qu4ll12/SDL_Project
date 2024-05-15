#include "renderWindow.h"
#include "entity.h"
#include "obsticale.h"

using namespace std;

obsticale::obsticale(float obsticale_x, float obsticale_y, float obsticale_w, float obsticale_h, SDL_Texture* _tex)
    : entity(obsticale_x, obsticale_y,obsticale_w, obsticale_h, _tex)
{
    o_w=obsticale_w;
    o_h=obsticale_h;
    tex=_tex;
    x=((rand() % (3 - 0 + 1)) + 0);
    x=77+76*x;
    difficulty=300;
    speed=7;
    int difficulty1=300;
    velocity=((rand() % (-difficulty1 - -difficulty1*3 + 1)) + -difficulty1*3);
    cnt=0;
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

void obsticale::resetX()
{
    x=((rand() % (3 - 0 + 1)) + 0);
    x=77+76*x;
}

void obsticale::setSpeed(int s)
{
    speed=s;
}

void obsticale::setDiff(vector <obsticale> &enemies, float n)
{
    for(int i=0;i<enemies.size();i++)
    {
        enemies[i].difficulty=n;
    }
}

void obsticale::reset()
{
    x=((rand() % (3 - 0 + 1)) + 0);
    x=77+76*x;
    int difficulty1=difficulty;
    velocity=((rand() % (-difficulty1 - -difficulty1*3 + 1)) + -difficulty1*3);
}


void obsticale::stillO(renderWindow& a)
{
    if (velocity<=750 && cnt<=30)
    {
        a.renderTexture(frame[0],x,velocity,o_w,o_h);
    }
    else if (velocity<750 && cnt>30 && cnt<=61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
    }
}

void obsticale::spawn(renderWindow& a)
{
    //cout<<velocity<<endl;
    if (velocity<=750 && cnt<=30)
    {
        a.renderTexture(frame[0],x,velocity,o_w,o_h);
        velocity+=speed;
        cnt++;
    }
    else if (velocity<750 && cnt>30 && cnt<61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
        velocity+=speed;
        cnt++;
    }
    else if (cnt==61)
    {
        a.renderTexture(frame[1],x,velocity,o_w,o_h);
        cnt=0;
    }
    else
    {
        reset();
    }
    if(difficulty-0.5>150) difficulty-=0.5;
    if(speed+0,05<9) speed+=0,05;
}

bool obsticale::event(float n)
{
    bool d;

    if(n==x && velocity>=750-o_h*2-10 && velocity<=750-50) d=true;
    else d=false;

    return d;
}

float obsticale::returnSpeed()
{
    return speed;
}
