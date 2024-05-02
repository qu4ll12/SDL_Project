#pragma once

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>

static int SCREEN_HEIGHT=750;
static int SCREEN_WIDTH=450;
static const char* WINDOW_TITLE="Car Race";

class renderWindow
{
public:
	renderWindow (int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
	SDL_Texture* loadTexture(const char * filename);
	SDL_Window* getWindow();
	Mix_Chunk* loadSound(const char * filename);
	TTF_Font* loadFont(const char * filename, int size);
	SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
	void renderTexture(entity& e_entity, float x, float y, float w, float h);
	void playSound(Mix_Chunk* sound);
	void playMusic();
	void resumeMusic();
	void musicVolume(int vol);
	void soundVolume(Mix_Chunk* &sound, int vol);
	void display();
	void quitSDL();
	void waitUntilKeyPressed();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Mix_Music* gMusic;
};
