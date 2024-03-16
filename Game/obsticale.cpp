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
    x=((rand() % (4 - 1 + 1)) + 1);
    x*=75;
    velocity=-134;
    cnt=0;
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
    frame.push_back(entity (0,0,71,134,tex));
    frame.push_back(entity (72,0,71,134,tex));

    if (velocity<=750 && cnt<=30)
    {
        a.renderTexture(frame[0],x,velocity,o_w,o_h);
        velocity+=speed;
        cnt++;
    }
    else if (velocity<750 && cnt>=30 && cnt<61)
    {
        a.renderTexture(frame[1],x,velocity,71,134);
        velocity+=speed;
        cnt++;
    }
    else if (cnt==61)
    {
        cnt=0;
    }
}
