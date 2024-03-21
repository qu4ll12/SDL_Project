#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"

using namespace std;

int speed=6;
int m=10;
renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_Texture* car = game.loadTexture("jeep.png");
SDL_Texture* grass = game.loadTexture("grass.png");
SDL_Texture* _highway = game.loadTexture("highway.png");
SDL_Texture* _taxi = game.loadTexture("taxi2.png");
SDL_Texture* button1 = game.loadTexture("template_button1.png");
SDL_Texture* start_button= game.loadTexture("start_button1.png");
SDL_Texture* exit_button= game.loadTexture("exit_button.png");
SDL_Texture* setting_button= game.loadTexture("setting_button.png");
SDL_Texture* game_over=game.loadTexture("game_over.png");
SDL_Texture* menu_window=game.loadTexture("menu.png");
SDL_Texture* exit_menubutton=game.loadTexture("exit_menuButton.png");
int main(int argc, char* argv[])
{
    player player(75,600,145,133,car);
    player.loadRender();
    button b(0,0,170,85,button1);
    button exit_(139,250+170+40,170,85,exit_button);
    button setting(139,250+85+20,170,85,setting_button);
    button start(139,250,170,85,start_button);
    button exit_menu(367,234,16,15,exit_menubutton);
    entity e_grass(0,0,75,750,grass);
    entity you_die(0,0,500,500,game_over);
    entity menu(0,0,335,335,menu_window);
    obsticale taxi(0,0,71,134,_taxi);
    obsticale taxi1(0,0,71,134,_taxi);
    obsticale taxi2(0,0,71,134,_taxi);
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
                    highway.stillRoad(game);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    start.pressed(game);
                    exit_.unpress(game);
                    setting.unpress(game);
                    player.defaultPlayer(game,n);
                    game.display();
                    SDL_Delay(350);
                d=true;
            }
            else if (event.button.button == SDL_BUTTON_LEFT && exit_.event())
            {
                    highway.stillRoad(game);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    start.unpress(game);
                    exit_.pressed(game);
                    setting.unpress(game);
                    player.defaultPlayer(game,n);
                    game.display();
                    exit(0);
            }
            else if (event.button.button == SDL_BUTTON_LEFT && setting.event())
            {
                    while(!exit_menu.event())
                    {
                        if(exit_menu.event())
                        {
                            highway.stillRoad(game);
                            game.renderTexture(e_grass,0,0,75,750);
                            game.renderTexture(e_grass,75*5,0,75,750);
                            exit_menu.idle(game);
                            player.defaultPlayer(game,n);
                            game.renderTexture(menu,55,230,335,335);
                            exit_menu.idle(game);
                            game.display();
                        }
                        else
                        {
                            highway.stillRoad(game);
                            game.renderTexture(e_grass,0,0,75,750);
                            game.renderTexture(e_grass,75*5,0,75,750);
                            exit_menu.unpress(game);
                            player.defaultPlayer(game,n);
                            game.renderTexture(menu,55,230,335,335);
                            exit_menu.unpress(game);
                            game.display();
                        }
                    }

            }
            else if (start.event())
            {
                highway.stillRoad(game);
                game.renderTexture(e_grass,0,0,75,750);
                game.renderTexture(e_grass,75*5,0,75,750);
                start.idle(game);
                exit_.unpress(game);
                setting.unpress(game);
                player.defaultPlayer(game,n);
                game.display();
            }
            else if (exit_.event())
            {
                highway.stillRoad(game);
                game.renderTexture(e_grass,0,0,75,750);
                game.renderTexture(e_grass,75*5,0,75,750);
                start.unpress(game);
                exit_.idle(game);
                setting.unpress(game);
                player.defaultPlayer(game,n);
                game.display();
            }

            else if (setting.event())
            {
                    highway.stillRoad(game);
                    game.renderTexture(e_grass,0,0,75,750);
                    game.renderTexture(e_grass,75*5,0,75,750);
                    start.unpress(game);
                    exit_.unpress(game);
                    setting.idle(game);
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
                setting.unpress(game);
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
                    for(int i=0;i<6;i++)
                    {
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        taxi.spawn(game,m);
                        taxi1.spawn(game,m);
                        taxi2.spawn(game,m);
                        player.leftLane(game,n);
                        game.display();
                    }

                    for(int i=0;i<6;i++)
                    {
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        taxi.spawn(game,m);
                        taxi1.spawn(game,m);
                        taxi2.spawn(game,m);
                        player.leftLane_(game,n);
                        game.display();
                    }
                }

                else if((event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT) && n<75*4)
                {
                    for(int i=0;i<6;i++)
                    {
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        taxi.spawn(game,m);
                        taxi1.spawn(game,m);
                        taxi2.spawn(game,m);
                        player.rightLane(game,n);
                        game.display();
                    }

                    for(int i=0;i<6;i++)
                    {
                        highway.animateRoad(game,speed);
                        game.renderTexture(e_grass,0,0,75,750);
                        game.renderTexture(e_grass,75*5,0,75,750);
                        taxi.spawn(game,m);
                        taxi1.spawn(game,m);
                        taxi2.spawn(game,m);
                        player.rightLane_(game,n);
                        game.display();
                    }
                }
                else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                {
                    exit(0);
                }
            }
        }

        if(n==taxi.getX() && taxi.getY()>=750-134*2-10 && taxi.getY()<=750-30)
        {
            highway.animateRoad(game,speed);
            game.renderTexture(e_grass,0,0,75,750);
            game.renderTexture(e_grass,75*5,0,75,750);
            player.defaultPlayer(game,n);
            game.renderTexture(you_die,-20,50,500,500);
            game.display();
            SDL_Delay(2000);
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
        taxi1.spawn(game,m);
        taxi2.spawn(game,m);
        player.defaultPlayer(game,n);
        game.display();
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
