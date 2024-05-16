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
    e_y=((rand() % (-300 - -600 + 1)) + -600);
    float fuel=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            xsrc[i]=i*e_w;
            animation.push_back(entity(xsrc[i],0,e_w,e_h,tex));
        }
    }

    animation.push_back(entity(0,37,186,48,tex));
    animation.push_back(entity(0,85,fuel,48,tex));
}

void energy::reset()
{
    e_x=(rand() % (3 - 0 + 1)) + 0;
    e_x=102+75*e_x;
    e_y=((rand() % (-300 - -600 + 1)) + -600);
    timer=0;
    fuel=0;
}

void energy::spawn(renderWindow &a, float speed)
{
    if(timer==animation.size()-1-2)
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
        reset();
    }

    animation[37] = entity (0,85,fuel,48,tex);
    a.renderTexture(animation[36],256,34,186,48);
    a.renderTexture(animation[37],256,34,fuel,48);
    if (fuel+speed/15<=186) fuel+=speed/15;
    else if(fuel+speed/15>186) fuel=186;
}

void energy::stillE(renderWindow &a)
{
    a.renderTexture(animation[timer],e_x,e_y,e_w,e_h);
    a.renderTexture(animation[36],256,34,186,48);
    a.renderTexture(animation[37],256,34,fuel,48);
}
float energy::getX()
{
    return e_x;
}
float energy::getY()
{
    return e_y;
}
bool energy::event(float &n)
{   bool d;
    if(n<e_x+22+22 && n>e_x-21-21 && e_y>560 && e_y<=740) {d=true; reset();}
    else d=false;

    return d;
}

bool energy::outOfFuel()
{
    bool d;

    if(fuel == 186) {fuel=0; d=true;}    else d=false;

    return d;
}
