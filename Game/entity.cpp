#include "entity.h"

using namespace std;

entity::entity(float r_w, float r_h, SDL_Texture* r_tex)
    :w(r_w), h(r_h), texture(r_tex)
{
    currentFrame.x=0;
    currentFrame.y=0;
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
