#pragma once

#include "renderWindow.h"
#include "entity.h"

class button: public entity
{
public:
    button(float b_w, float b_h, SDL_Texture* texture);
};
