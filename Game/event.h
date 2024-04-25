#pragma once

#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"

class event
{
public:
    void Menu();
    void Movement();
    void Resume();
    void Die();
private:
    SDL_Event event;
};
