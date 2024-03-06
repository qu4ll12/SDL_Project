#include "button.h"

using namespace std;

button::button(float button_x, float button_y, float button_w, float button_h, SDL_Texture* texture)
    : entity(button_x, button_y, button_w, button_h, texture)
{
    b_w = button_w;
    b_h = button_h;
    state1 = texture;
}

void button::loadPress_button(SDL_Texture* texture)
{
    state2 = texture;
}

void button::unpress(renderWindow& a, float b_x, float b_y)
{
    entity e1(0,0,b_w, b_h, state1);
    a.renderTexture(e1, b_x, b_y, b_w, b_h);
}

void button::pressed(renderWindow& a, float b_x, float b_y)
{
    entity e2(0,0,b_w, b_h, state2);
    a.renderTexture(e2, b_x, b_y, b_w, b_h);
}
