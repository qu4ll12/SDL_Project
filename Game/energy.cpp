#include "energy.h"
using namespace std;

energy::energy(float x, float y, float w, float h,SDL_Texture* texture) :
    entity(x,y,w,h,texture)
{
    e_w=w;
    e_h=h;
    tex=texture;
    timer=0;
    e_x=(rand() % (3 - 0 + 1)) + 0;
    e_x=102+75*e_x;
    e_y=((rand() % (3 - 1 + 1)) + 1);
    e_y*=-300;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            xsrc[i]=i*e_w;
            animation.push_back(entity(xsrc[i],0,e_w,e_h,tex));
        }
    }
}

void energy::reset()
{
    timer=0;
    e_x=(rand() % (3 - 0 + 1)) + 0;
    e_x=102+75*e_x;
    e_y=((rand() % (3 - 1 + 1)) + 1);
    e_y*=-300;
}

void energy::spawn(renderWindow &a, float speed)
{
    if(timer==animation.size()-1)
    {
        a.renderTexture(animation[timer],e_x,e_y,e_w,e_h);
        timer=0;
        e_y+=speed;
    }
    else
    {
        a.renderTexture(animation[timer],e_x,e_y,e_w,e_h);
        timer++;
        e_y+=speed;
    }
    if(e_y>830)
    {
        timer=0;
        e_x=(rand() % (3 - 0 + 1)) + 0;
        e_x=102+75*e_x;
        e_y=((rand() % (3 - 1 + 1)) + 1);
        e_y*=-300;
    }
}

void energy::stillE(renderWindow &a)
{
    a.renderTexture(animation[timer],e_x,e_y,e_w,e_h);
}
bool energy::event(float &n)
{   bool d;
    if(n<e_x+22+22 && n>e_x-21-21 && e_y>560 && e_y<=830) d=true;
    else d=false;

    return d;
}
