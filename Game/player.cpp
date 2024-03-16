#include "player.h"

using namespace std;

player::player(float player_x, float player_y, float player_w, float player_h, SDL_Texture* texture)
    : entity(player_x, player_y, player_w, player_h, texture)
{
    p_x=player_x;
    p_y=player_y;
    p_w=player_w;
    p_h=player_h;
    tex=texture;

    frame_numr=3;
    frame_numl=3;
    cnt=0;
}

void player::loadRender()
{
    for(int i=0;i<7;++i)
    {
        x[i]=i*p_w;
    }

    for(int i=0;i<7;i++)
    {
        drift.push_back(entity (x[i],0,p_w,p_h,tex));
    }
}

void player::defaultPlayer(renderWindow &a, int n)
{
    entity b(x[3],0,p_w,p_h,tex);
    a.renderTexture(b,n,600,p_w,p_h);
}

void player::rightLane(renderWindow& a, int n)
{
    if(frame_numr<6 && cnt==0)
    {
        a.renderTexture(drift[frame_numr],n,600,p_w,p_h);
        frame_numr++;
    }
    else if(frame_numr==6)
    {
        a.renderTexture(drift[frame_numr],n,600,p_w,p_h);
        frame_numr=6;
        cnt=1;
    }

    if(cnt==1 && frame_numr>3)
    {
        a.renderTexture(drift[frame_numr],n,600,p_w,p_h);
        frame_numr-=1;
    }
    else if(cnt==1 && frame_numr==3)
    {
        a.renderTexture(drift[frame_numr],n,600,p_w,p_h);
        cnt=0;
    }
}

void player::leftLane(renderWindow& a, int n)
{
    if(frame_numl>0 && cnt==0)
    {
        a.renderTexture(drift[frame_numl],n,600,p_w,p_h);
        frame_numl--;
    }
    else if(frame_numl==0)
    {
        a.renderTexture(drift[frame_numl],n,600,p_w,p_h);
        frame_numl=0;
        cnt=1;
    }

    if(cnt==1 && frame_numl<3)
    {
        a.renderTexture(drift[frame_numl],n,600,p_w,p_h);
        frame_numl++;
    }
    else if(cnt==1 && frame_numl==3)
    {
        a.renderTexture(drift[frame_numl],n,600,p_w,p_h);
        cnt=0;
    }
}


