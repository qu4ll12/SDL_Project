#include "road.h"

using namespace std;

road::road(float r_w, float r_h, SDL_Texture* r_tex) : entity(r_w, r_h, r_tex)
{
    tex1 = r_tex;
}

void road::textureRoad(renderWindow& a)
{
    tex2 = a.loadTexture("highway2.png");
    tex3 = a.loadTexture("highway3.png");
    tex4 = a.loadTexture("highway4.png");

}

void road::animateRoad(renderWindow& a)
{
    entity frame1(300,750,tex1);
    entity frame2(300,750,tex2);
    entity frame3(300,750,tex3);
    entity frame4(300,750,tex4);

    if (frame_num==0)
    {
        a.renderTexture(frame1,75,0,300,750);
        frame_num++;
    }
    else if (frame_num==1)
    {
        a.renderTexture(frame2,75,0,300,750);
        frame_num++;
    }
    else if (frame_num==2)
    {
        a.renderTexture(frame3,75,0,300,750);
        frame_num++;
    }
    else if (frame_num==3)
    {
        a.renderTexture(frame4,75,0,300,750);
        frame_num=0;
    }
}
