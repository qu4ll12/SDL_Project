#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"

using namespace std;

int speed=4;
int m=4;

int main(int argc, char* argv[])
{
    renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
    SDL_Texture* car = game.loadTexture("car.png");
    SDL_Texture* grass = game.loadTexture("grass.png");
    SDL_Texture* _highway = game.loadTexture("highway.png");
    SDL_Texture* _taxi = game.loadTexture("taxi2.png");
    SDL_Texture* button1 = game.loadTexture("template_button1.png");
    player player(75,600,71,134,car);
    player.loadRender();
    button b(0,0,170,85,button1);
    obsticale taxi(0,0,71,134,_taxi);
    taxi.getX();
    entity e_grass(0,0,75,750,grass);
    road highway(0,0,800,800,_highway);
    highway.textureRoad();
    float n=75;
    SDL_Event event;
    game.renderTexture(e_grass,0,0,75,750);
    game.renderTexture(e_grass,75*5,0,75,750);
    highway.animateRoad(game,speed);
    taxi.spawn(game,m);
    player.defaultPlayer(game,n);
    b.unpress(game,30,30);
    game.display();

    while(true)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.scancode == SDL_SCANCODE_A || event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                    for(int i=0;i<8;i++)
                    {
                        if(n-75 > 0) n-=9.375;
                        highway.animateRoad(game,speed);
                        taxi.spawn(game,m);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        b.unpress(game,30,30);
                        player.leftLane(game,n);
                        game.display();
                    }
                }

                else if(event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                    for(int i=0;i<8;++i)
                    {
                        if(n+75 < 75*5) n+=9.375;
                        highway.animateRoad(game,speed);
                        taxi.spawn(game,m);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        b.unpress(game,30,30);
                        player.rightLane(game,n);
                        game.display();
                    }
                }
                else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                {
                    exit(0);
                }
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x,y;
                SDL_GetMouseState(&x, &y);
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    for(int i=0;i<11;++i)
                    {
                        highway.animateRoad(game,speed);
                        taxi.spawn(game,m);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        player.defaultPlayer(game,n);
                        b.pressed(game,30,30);
                        game.display();
                    }
                }
            }
        }

            if(n==taxi.getX() && taxi.getY()>=750-134*2-10 && taxi.getY()<=750)
            {
                exit(0);
            }
//            else if(taxi.getY()>=750)
//            {
//                exit(0);
//            }
            highway.animateRoad(game,speed);
            game.renderTexture(e_grass,0,0,75,750);
            game.renderTexture(e_grass,75*5,0,75,750);
            taxi.spawn(game,m);
            player.defaultPlayer(game,n);
            b.unpress(game,30,30);
            game.display();
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
