#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"

static int SCREEN_HEIGHT=750;
static int SCREEN_WIDTH=450;
static const char* WINDOW_TITLE="GAME";

class renderWindow
{
public:
	renderWindow (int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
	SDL_Texture* loadTexture(const char * filename);
	void renderTexture(entity& e_entity, int x, int y, int w, int h);
	void display();
	void quitSDL();
	void waitUntilKeyPressed();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
