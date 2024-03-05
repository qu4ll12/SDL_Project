#include "renderWindow.h"
#include "entity.h"
#include "obsticale.h"

using namespace std;

obsticale::obsticale(float obsticale_w, float obsticale_h, SDL_Texture* _tex) : entity(obsticale_w,obsticale_h,_tex)
{
    o_w=obsticale_w;
    o_h=obsticale_h;
    tex=_tex;
    x=((rand() % (4 - 1 + 1)) + 1);
    x*=75;
    velocity=-134;
}

float obsticale::getX()
{
    return x;
}

float obsticale::getY()
{
    return velocity;
}

void obsticale::spawn(renderWindow& a, float speed)
{
    entity b(o_w, o_h, tex);

    if (velocity<750)
    {
        a.renderTexture(b, x, velocity, o_w, o_h);
        velocity+=speed;
    }
}
