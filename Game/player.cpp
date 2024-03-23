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
    timer1=0;
    cnt=1;
}

void player::loadRender()
{
    for(int i=0;i<5;++i)
    {
        x[i]=i*71;
    }

    for(int i=0;i<12;i++)
    {
        drift.push_back(entity (x[i],0,p_w,p_h,tex));
    }
}

void player::defaultPlayer(renderWindow &a, int n)
{
    if(timer1<=30)
    {
        a.renderTexture(drift[0],n,600,p_w,p_h);
        timer1++;
    }
    else if(timer1>30 && timer1<60)
    {
        a.renderTexture(drift[4],n,600,p_w,p_h);
        timer1++;
    }
    else if(timer1==60)
    {
        a.renderTexture(drift[4],n,600,p_w,p_h);
        timer1=0;
    }
}

void player::levelUp(renderWindow &a, float n)
{
    if(timer1<=6)
    {
        a.renderTexture(drift[0],n,600,p_w,p_h);
        timer1++;
    }
    else if(timer1>6 && timer1<12)
    {
        a.renderTexture(drift[3],n,600,p_w,p_h);
        timer1++;
    }
    else if(timer1==12)
    {
        a.renderTexture(drift[3],n,600,p_w,p_h);
        timer1=0;
    }
}

void player::rightLane(renderWindow& a, float &n)
{
    for(int i=1;i<=cnt;i++)
    {
        if(i%2!=0) a.renderTexture(drift[1],n+15*(i-1),600,p_w,p_h);
        if(i%2==0) a.renderTexture(drift[2],n+15*(i-1),600,p_w,p_h);
        if(i==6 && n+75 < 75*5)
        {
            n+=75;
            a.renderTexture(drift[0],n,600,p_w,p_h);
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
            a.renderTexture(drift[0],n,600,p_w,p_h);
            break;
        }
        else
        {
            if(i%2!=0) a.renderTexture(drift[1],(n-75)+15*(i-1),600,p_w,p_h);
            if(i%2==0) a.renderTexture(drift[2],(n-75)+15*(i-1),600,p_w,p_h);
            a.renderTexture(drift[0],n,600,p_w,p_h);
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
        if(i%2!=0) a.renderTexture(drift[1],n-15*(i-1),600,p_w,p_h);
        if(i%2==0) a.renderTexture(drift[2],n-15*(i-1),600,p_w,p_h);
        if(i==6 && n-75 > 0)
        {
            n-=75;
            a.renderTexture(drift[0],n,600,p_w,p_h);
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
            a.renderTexture(drift[0],n,600,p_w,p_h);
            break;
        }
        else
        {
            if(i%2!=0) a.renderTexture(drift[1],(n+75)-15*(i-1),600,p_w,p_h);
            if(i%2==0) a.renderTexture(drift[2],(n+75)-15*(i-1),600,p_w,p_h);
            a.renderTexture(drift[0],n,600,p_w,p_h);
        }
    }
    timer++;
    if(timer==6)
    {
        cnt=1;
        timer=0;
    }
}


