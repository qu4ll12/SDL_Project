#pragma once

#include <SDL.h>
#include <SDL_image.h>

class road
{
public:
    road (float r_x, float r_y, SDL_Texture);


private:
    float x;
    float y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
