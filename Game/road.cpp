#include "road.h"

using namespace std;

road::road(float r_w, float r_h, SDL_Texture* r_tex) : entity(r_w, r_h, r_tex)
{
}

void road::textureRoad(renderWindow& a)
{
    tex.push_back(a.loadTexture("highway1.png"));
    tex.push_back(a.loadTexture("highway2.png"));
    tex.push_back(a.loadTexture("highway3.png"));
    tex.push_back(a.loadTexture("highway4.png"));
    tex.push_back(a.loadTexture("highway5.png"));
    tex.push_back(a.loadTexture("highway6.png"));
    tex.push_back(a.loadTexture("highway7.png"));
    tex.push_back(a.loadTexture("highway8.png"));
    tex.push_back(a.loadTexture("highway9.png"));
    tex.push_back(a.loadTexture("highway10.png"));
    tex.push_back(a.loadTexture("highway11.png"));
    tex.push_back(a.loadTexture("highway12.png"));
    tex.push_back(a.loadTexture("highway13.png"));
    tex.push_back(a.loadTexture("highway14.png"));
    tex.push_back(a.loadTexture("highway15.png"));
    tex.push_back(a.loadTexture("highway16.png"));
    tex.push_back(a.loadTexture("highway17.png"));
    tex.push_back(a.loadTexture("highway18.png"));
    tex.push_back(a.loadTexture("highway19.png"));
    tex.push_back(a.loadTexture("highway20.png"));
}

void road::animateRoad(renderWindow& a, float speed)
{
    for(long long unsigned int i=0;i<tex.size();i++)
    {
        frame.push_back(entity(300,750,tex[i]));
    }

    if (frame_num>=frame.size()-1)
    {
        a.renderTexture(frame[frame_num],75,0,300,750);
        frame_num=0;
    }
    else
    {
        a.renderTexture(frame[frame_num],75,0,300,750);
        frame_num+=speed;
    }
}
