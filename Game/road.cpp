#include "road.h"

using namespace std;

road::road(float r_x, float r_y, float r_w, float r_h, SDL_Texture* r_tex)
    : entity(r_x, r_y, r_w, r_h, r_tex)
{
    tex=r_tex;
    frame_num=0;
    for(int i=0;i<30;i++)
    {
        road_y[i]=5*i;
    }
}

void road::stillRoad(renderWindow &a)
{
    for(int i=0;i<30;++i)
    {
        frame.push_back(entity (0,road_y[i],450,750,tex));
    }
    a.renderTexture(frame[frame_num],0,0,450,750);
}
void road::animateRoad(renderWindow& a, int speed)
{

    for(int i=0;i<30;++i)
    {
        frame.push_back(entity (0,road_y[i],450,750,tex));
    }
    if (frame_num>=frame.size()-1)
    {
        a.renderTexture(frame[frame_num],0,0,450,750);
        frame_num=0;
    }
    else
    {
       a.renderTexture(frame[frame_num],0,0,450,750);
       frame_num+=speed;
    }
}
