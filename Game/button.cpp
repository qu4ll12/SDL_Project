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
    frame_num=0;
}

void button::unpress(renderWindow& a, float button_x, float button_y)
{
    entity frame1(b_x,b_y,b_w,b_h,button_tex);
    a.renderTexture(frame1,button_x,button_y,b_w,b_h);
}

void button::pressed(renderWindow& a, float button_x, float button_y)
{
    entity frame2(b_x+b_w,b_y,b_w,b_h,button_tex);
    a.renderTexture(frame2,button_x,button_y,b_w,b_h);
}
