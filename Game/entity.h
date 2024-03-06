#pragma once

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

class entity
{
public:
    entity (float r_x, float r_y, float r_w, float r_h, SDL_Texture* r_tex);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
private:
    float x,y,w,h;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
