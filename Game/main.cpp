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
    SDL_Texture* car = game.loadTexture("jeep_car.png");
    SDL_Texture* grass = game.loadTexture("grass.png");
    SDL_Texture* _highway = game.loadTexture("highway.png");
    SDL_Texture* _taxi = game.loadTexture("taxi3.png");
    SDL_Texture* button1 = game.loadTexture("template_button1.png");
    SDL_Texture* start_button= game.loadTexture("start_button.png");
    SDL_Texture* exit_button= game.loadTexture("exit_button.png");
    player player(75,600,95,140,car);
    player.loadRender();
    button b(0,0,170,85,button1);
    button exit_(139,250+170,170,85,exit_button);
    button start(139,250,170,85,start_button);
    obsticale taxi(0,0,71,134,_taxi);
    taxi.getX();
    entity e_grass(0,0,75,750,grass);
    road highway(0,0,800,800,_highway);
    highway.textureRoad();
    float n=75*2;
    SDL_Event event;
    bool d=false;

    while(!d)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.button.button == SDL_BUTTON_LEFT && start.event())
            {
                for(int i=0;i<11;++i)
                {
                    highway.stillRoad(game);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    start.pressed(game);
                    player.defaultPlayer(game,n);
                    game.display();
                }

                d=true;
            }
            else if (start.event())
            {
                highway.stillRoad(game);
                game.renderTexture(e_grass,0,0,75,750);
                game.renderTexture(e_grass,75*5,0,75,750);
                start.idle(game);
                player.defaultPlayer(game,n);
                game.display();
            }
            else
            {
                highway.stillRoad(game);
                game.renderTexture(e_grass,0,0,75,750);
                game.renderTexture(e_grass,75*5,0,75,750);
                start.unpress(game);
                exit_.unpress(game);
                player.defaultPlayer(game,n);
                game.display();
            }
        }
    }

    while(d)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_KEYDOWN)
            {
                if((event.key.keysym.scancode == SDL_SCANCODE_A || event.key.keysym.scancode == SDL_SCANCODE_LEFT) && n>75)
                {
                    for(int i=0;i<8;i++)
                    {
                        if(n-75 > 0) n-=9.375;
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        player.leftLane(game,n);
                        taxi.spawn(game,m);
                        game.display();
                    }
                }

                else if((event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT) && n<75*4)
                {
                    for(int i=0;i<8;++i)
                    {
                        if(n+75 < 75*5) n+=9.375;
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        player.rightLane(game,n);
                        taxi.spawn(game,m);
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
                if (event.button.button == SDL_BUTTON_LEFT && x>41 && y>41 && x<191 && y<105)
                {
                    for(int i=0;i<11;++i)
                    {
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        player.defaultPlayer(game,n);
                        taxi.spawn(game,m);
                        game.display();
                    }
                }
            }
        }

        if(n==taxi.getX() && taxi.getY()>=750-134*2-10 && taxi.getY()<=750-30)
        {
            exit(0);
        }
//            else if(taxi.getY()>=750)
//            {
//                exit(0);
//            }
        highway.animateRoad(game,speed);
        taxi.spawn(game,m);
        game.renderTexture(e_grass,0,0,75,750);
        game.renderTexture(e_grass,75*5,0,75,750);
        player.defaultPlayer(game,n);
        game.display();
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
