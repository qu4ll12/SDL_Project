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
    SDL_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
