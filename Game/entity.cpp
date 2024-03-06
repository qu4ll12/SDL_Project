#include "entity.h"

using namespace std;

entity::entity(float r_x, float r_y, float r_w, float r_h, SDL_Texture* r_tex)
    :x(r_x), y(r_y), w(r_w), h(r_h), texture(r_tex)
{
    currentFrame.x=x;
    currentFrame.y=y;
    currentFrame.w=w;
    currentFrame.h=h;
}

SDL_Texture* entity::getTexture()
{
    return texture;
}

SDL_Rect entity::getCurrentFrame(){
    return currentFrame;
}
