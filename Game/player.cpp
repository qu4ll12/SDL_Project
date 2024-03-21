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
    timer=0;
    cnt=1;
}

void player::loadRender()
{
    for(int i=0;i<3;++i)
    {
        x[i]=i*71;
    }

    for(int i=0;i<12;i++)
    {
        drift.push_back(entity (x[i],0,71,133,tex));
    }
}

void player::defaultPlayer(renderWindow &a, int n)
{
    a.renderTexture(drift[0],n,600,71,133);
}

void player::rightLane(renderWindow& a, float &n)
{
    for(int i=1;i<=cnt;i++)
    {
        if(i%2!=0) a.renderTexture(drift[1],n+15*(i-1),600,71,133);
        if(i%2==0) a.renderTexture(drift[2],n+15*(i-1),600,71,133);
        if(i==6 && n+75 < 75*5)
        {
            n+=75;
            a.renderTexture(drift[0],n,600,71,133);
            break;
        }
    }
    cnt++;
}

void player::rightLane_(renderWindow& a, float n)
{
    for(int i=1+timer;i<=cnt;i++)
    {   if(timer==5)
        {
            a.renderTexture(drift[0],n,600,71,133);
            break;
        }
        else
        {
            if(i%2!=0) a.renderTexture(drift[1],(n-75)+15*(i-1),600,71,133);
            if(i%2==0) a.renderTexture(drift[2],(n-75)+15*(i-1),600,71,133);
            a.renderTexture(drift[0],n,600,71,133);
        }
    }
    timer++;
    if(timer==6)
    {
        cnt=1;
        timer=0;
    }
}

void player::leftLane(renderWindow& a, float &n)
{
    for(int i=1;i<=cnt;i++)
    {
        if(i%2!=0) a.renderTexture(drift[1],n-15*(i-1),600,71,133);
        if(i%2==0) a.renderTexture(drift[2],n-15*(i-1),600,71,133);
        if(i==6 && n-75 > 0)
        {
            n-=75;
            a.renderTexture(drift[0],n,600,71,133);
            break;
        }
    }
    cnt++;
}

void player::leftLane_(renderWindow& a, float n)
{
    for(int i=1+timer;i<=cnt;i++)
    {   if(timer==5)
        {
            a.renderTexture(drift[0],n,600,71,133);
            break;
        }
        else
        {
            if(i%2!=0) a.renderTexture(drift[1],(n+75)-15*(i-1),600,71,133);
            if(i%2==0) a.renderTexture(drift[2],(n+75)-15*(i-1),600,71,133);
            a.renderTexture(drift[0],n,600,71,133);
        }
    }
    timer++;
    if(timer==6)
    {
        cnt=1;
        timer=0;
    }
}
