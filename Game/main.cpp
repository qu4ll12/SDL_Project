#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"

using namespace std;

int main(int argc, char* argv[])
{
    renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
    SDL_Texture* car = game.loadTexture("car.png");
    SDL_Texture* grass = game.loadTexture("grass.png");
    SDL_Texture* _highway = game.loadTexture("highway1.png");
    SDL_Texture* _taxi = game.loadTexture("taxi.png");
    obsticale taxi(71,134,_taxi);
    taxi.getX();
    entity e_car(71,134,car);
    entity e_grass(75,750,grass);
    road highway(800,800,_highway);
    highway.textureRoad(game);
    int n=75;
    SDL_Event event;
    game.renderTexture(e_grass,0,0,75,750);
    game.renderTexture(e_grass,75*5,0,75,750);
    highway.animateRoad(game,4);
    taxi.spawn(game,10);
    game.renderTexture(e_car,75,600,71,134);
    game.display();

    while(true)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.scancode == SDL_SCANCODE_A || event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                    if(n-75 > 0) n-=75;
                    highway.animateRoad(game,4);
                    game.renderTexture(e_car,n,600,71,134);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    game.display();
                }

                else if(event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                    if(n+75 < 75*5) n+=75;
                    highway.animateRoad(game,4);
                    game.renderTexture(e_car,n,600,71,134);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    game.display();
                }
                else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                {
                    exit(0);
                }
            }
        }
                highway.animateRoad(game,4);
                taxi.spawn(game,2);
                game.renderTexture(e_car,n,600,71,134);
                game.display();
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
