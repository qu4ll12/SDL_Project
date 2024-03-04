#include "renderWindow.h"
#include "entity.h"
#include "obsticale.h"

using namespace std;

obsticale::obsticale(float obsticale_w, float obsticale_h, SDL_Texture* _tex) : entity(obsticale_w,obsticale_h,_tex)
{
    o_w=obsticale_w;
    o_h=obsticale_h;
    tex=_tex;
}

void obsticale::getX()
{
    x=((rand() % (4 - 1 + 1)) + 1);
    x*=75;
}

void obsticale::spawn(renderWindow& a, float speed)
{
    entity b(o_w, o_h, tex);

    if (y<750)
    {
        a.renderTexture(b, x, y, o_w, o_h);
        y+=speed;
    }
}
