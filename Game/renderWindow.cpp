#include "renderWindow.h"
#include "entity.h"
using namespace std;

renderWindow::renderWindow (int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
    :window(NULL), renderer(NULL)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("SDL Init is unnable to run: ",SDL_GetError());
    }

    window = SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        printf("SDL Window is unnable to run: ",SDL_GetError());
    }

    int IMG_Init(int IMG_INIT_PNG);

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        printf("SDL Image is unnable to run: ",SDL_GetError());
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    gMusic= Mix_LoadMUS("sound\\background_music.wav");
    if( gMusic == NULL )
    {
        printf( "Failed to load Music! SDL_Mixer Error: %s\n", Mix_GetError() );
    }

    if (TTF_Init() == -1)
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
}

SDL_Window* renderWindow::getWindow()
{
    return window;
}

SDL_Texture* renderWindow::loadTexture(const char* filename)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer,filename);

    if (texture == nullptr)
    {
        printf("SDL Texture is unnable to run: ",SDL_GetError());
    }

    return texture;
}

TTF_Font* renderWindow::loadFont(const char* path, int size)
{
    TTF_Font* gFont = TTF_OpenFont( path, size );
    if (gFont == nullptr)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Load font %s", TTF_GetError());
    }

    return gFont;
}

SDL_Texture* renderWindow::renderText(const char* text,
                        TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* textSurface =
            TTF_RenderText_Solid( font, text, textColor );

    if( textSurface == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Render text surface %s", TTF_GetError());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
    if( texture == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
                       "Create texture from text %s", SDL_GetError());
    }
    SDL_FreeSurface( textSurface );
    return texture;
}

Mix_Chunk* renderWindow::loadSound(const char * filename)
{
    Mix_Chunk* gChunk = Mix_LoadWAV(filename);

    if (gChunk == nullptr)
    {
        printf( "Failed to load Sound! SDL_Mixer Error: %s\n", Mix_GetError() );
    }

    return gChunk;
}

void renderWindow::playSound(Mix_Chunk* sound)
{
    Mix_PlayChannel( -1, sound, 0 );
}

void renderWindow::playMusic()
{
    Mix_PlayMusic( gMusic, -1 );
}

void renderWindow::musicVolume(int a)
{
    Mix_VolumeMusic(a);
}

void renderWindow::soundVolume(Mix_Chunk* &sound, int vol)
{
    Mix_VolumeChunk(sound, vol);
}

void renderWindow::resumeMusic()
{
    Mix_ResumeMusic();
}

void renderWindow::renderTexture(entity& e_entity, float x, float y, float w, float h)
{
    SDL_Rect src;
    src.x=e_entity.getCurrentFrame().x;
    src.y=e_entity.getCurrentFrame().y;
    src.w=e_entity.getCurrentFrame().w;
    src.h=e_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x=x;
    dst.y=y;
    dst.w=w;
    dst.h=h;

    SDL_RenderCopy(renderer, e_entity.getTexture(), &src, &dst);
}

void renderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void renderWindow::waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void renderWindow::quitSDL()
{
    TTF_Quit();
    Mix_FreeMusic( gMusic );
    gMusic= NULL;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    SDL_Quit();
    IMG_Quit();
}
