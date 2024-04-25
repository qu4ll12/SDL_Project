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
    velocity=((rand() % (3 - 1 + 1)) + 1);
    difficulty=300;
    velocity*=-difficulty;
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

void obsticale::setDiff(vector <obsticale> enemies, float n)
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
    velocity=((rand() % (3 - 1 + 1)) + 1);
    velocity*=-difficulty;
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

void obsticale::spawn(renderWindow& a, float speed)
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
}

bool obsticale::event(float n)
{
    bool d;

    if(n==x && velocity>=750-o_h*2-10 && velocity<=750-30) d=true;
    else d=false;

    return d;
}
