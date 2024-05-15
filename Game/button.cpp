#include "button.h"

using namespace std;

button::button(float button_x, float button_y, float button_w, float button_h, SDL_Texture* texture)
    : entity(button_x, button_y, button_w, button_h, texture)
{
    b_x = button_x;
    b_y = button_y;
    b_w = button_w;
    b_h = button_h;
    button_tex = texture;
}

void button::unpress(renderWindow& a)
{
    entity frame1(0,0,b_w,b_h,button_tex);
    a.renderTexture(frame1,b_x,b_y,b_w,b_h);
}

void button::idle(renderWindow& a)
{
    entity frame3(0+b_w*2,0,b_w,b_h,button_tex);
    a.renderTexture(frame3,b_x,b_y,b_w,b_h);
}

void button::pressed(renderWindow& a)
{
    entity frame2(0+b_w,0,b_w,b_h,button_tex);
    a.renderTexture(frame2,b_x,b_y,b_w,b_h);
}

void button::handleEvent(SDL_Event* e)
{
    if( !event() )
    {
        mCurrentSprite = BUTTON_MOUSE_OUT;
    }
    //Mouse is inside button
    else
    {
        //Set mouse over sprite
        switch( e->type )
        {
            case SDL_MOUSEMOTION:
            mCurrentSprite = BUTTON_MOUSE_OVER_MOTION;
            break;

            case SDL_MOUSEBUTTONDOWN:
            mCurrentSprite = BUTTON_MOUSE_DOWN;
            break;

            case SDL_MOUSEBUTTONUP:
            mCurrentSprite = BUTTON_MOUSE_UP;
            break;
        }
    }
}

void button::render(renderWindow &a)
{
    entity frame(0+mCurrentSprite*b_w,0,b_w,b_h,button_tex);
    a.renderTexture(frame,b_x,b_y,b_w,b_h);
}

bool button::ifPress(renderWindow &a)
{
    int d = mCurrentSprite;
    bool result;
    if(d==1)
    {
        result=true;
        entity frame(0+b_w,0,b_w,b_h,button_tex);
        a.renderTexture(frame,b_x,b_y,b_w,b_h);
    }
    else result=false;

    return result;
}
bool button::event()
{
    bool d;
    int x,y;
    SDL_GetMouseState(&x, &y);
    if(x>b_x && y>b_y && x<b_x+b_w && y<b_y+b_h) d=true;
    else d=false;

    return d;
}
