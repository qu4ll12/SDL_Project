#include "road.h"

using namespace std;

road::road(float road_x, float road_y, float road_w, float road_h, SDL_Texture* r_tex)
    : entity(road_x, road_y, road_w, road_h, r_tex)
{
    tex=r_tex;
    frame_num=0;
}
void road::textureRoad()
{
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
