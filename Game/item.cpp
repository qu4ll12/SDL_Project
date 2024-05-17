#include "item.h"
#include "def.h"

using namespace std;

item::item(float x, float y, float w, float h,SDL_Texture* texture) :
    entity(x,y,w,h,texture)
{
    e_w=w;
    e_h=h;
    tex=texture;
    timer=0;
    e_x=(rand() % (3 - 0 + 1)) + 0;
    e_x=102+75*e_x;
    e_y=((rand() % (-NORMAL_MODE - -NORMAL_MODE*2 + 1)) + -NORMAL_MODE*2);
    float fuel=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            xsrc[i]=i*e_w;
            animation.push_back(entity(xsrc[i],0,e_w,e_h,tex));
        }
    }

    animation.push_back(entity(0,37,FUEL_WIDTH,FUEL_HEIGHT,tex));
    animation.push_back(entity(0,85,fuel,FUEL_HEIGHT,tex));
}

void item::reset()
{
    e_x=(rand() % (3 - 0 + 1)) + 0;
    e_x=102+75*e_x;
    e_y=((rand() % (-NORMAL_MODE - -NORMAL_MODE*2 + 1)) + -NORMAL_MODE*2);
    timer=0;
}

void item::resetFuel()
{
    fuel=0;
}

void item::spawn(renderWindow &a, float speed)
{
    if(timer==ITEM_SPRITE_SIZE-1-2)
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
    if(e_y>SCREEN_HEIGHT)
    {
        reset();
    }

    animation[37] = entity (0,85,fuel,FUEL_HEIGHT,tex);
    a.renderTexture(animation[36],256,34,FUEL_WIDTH,FUEL_HEIGHT);
    a.renderTexture(animation[37],256,34,fuel,FUEL_HEIGHT);
    if (fuel+speed/15<=FUEL_WIDTH) fuel+=speed/15;
    else if(fuel+speed/15>FUEL_WIDTH) fuel=FUEL_WIDTH;
}

void item::stillE(renderWindow &a)
{
    a.renderTexture(animation[timer],e_x,e_y,e_w,e_h);
    a.renderTexture(animation[36],256,34,FUEL_WIDTH,FUEL_HEIGHT);
    a.renderTexture(animation[37],256,34,fuel,FUEL_HEIGHT);
}
float item::getX()
{
    return e_x;
}
float item::getY()
{
    return e_y;
}
bool item::event(float &n)
{   bool d;
    if(n<e_x+22*2 && n>e_x-21*2 && e_y>560 && e_y<=750) {d=true; fuel=0;}
    else d=false;

    return d;
}

bool item::outOfFuel()
{
    bool d;

    if(fuel == FUEL_WIDTH) {d=true; fuel=0;}    else d=false;

    return d;
}

