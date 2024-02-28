#include "renderWindow.h"
#include "entity.h"

using namespace std;

int main(int argc, char* argv[])
{
    renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
    SDL_Texture* car = game.loadTexture("car.png");
    SDL_Texture* highway = game.loadTexture("highway.png");
    SDL_Texture* grass = game.loadTexture("grass.png");
    entity e_highway(300,750,highway);
    entity e_car(71,134,car);
    entity e_grass(75,750,grass);
    int n=75;
    SDL_Event event;
    game.renderTexture(e_highway,75,0,300,750);
    game.display();
    game.renderTexture(e_grass,0,0,75,750);
    game.display();
    game.renderTexture(e_grass,75*5,0,75,750);
    game.display();
    game.renderTexture(e_car,n,600,71,134);
    game.display();

    while(true)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    if(n-75 > 0) n-=75;
                    game.renderTexture(e_highway,75,0,300,750);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    game.renderTexture(e_car,n,600,71,134);
                    game.display();
                }

                else if(event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    if(n+75 < 75*5) n+=75;
                    game.renderTexture(e_highway,75,0,300,750);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    game.renderTexture(e_car,n,600,71,134);
                    game.display();
                }
                else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                {
                    exit(0);
                }
            }
        }
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
