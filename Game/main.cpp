#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"
#include "energy.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

using namespace std;

int speed=2;
int m=7;
vector <obsticale> enemies;
void collision(vector<obsticale> enemies)
{
    for(int i=0;i<enemies.size();i++)
    {
        cout<<enemies[i].getY()<<endl;
        for(int j=0;j<enemies.size();j++)
        {
            if(i!=j && enemies[i].getX()== enemies[j].getX())
            {
                if(enemies[i].getY()+141+5>enemies[j].getY() )
                {
                    enemies[i].reset();
                    cout<<"reset"<<endl;
                }
            }
        }
    }
}

void res(renderWindow &game, button resume)
{
    resume.unpress(game);
    game.display();
    SDL_Delay(750);
    resume.pressed(game);
    game.display();
    SDL_Delay(750);
    resume.idle(game);
    game.display();
    SDL_Delay(750);
}
renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
SDL_Texture* car = game.loadTexture("jeep.png");
SDL_Texture* title=game.loadTexture("road_rumble.png");
SDL_Texture* _highway = game.loadTexture("highway1.png");
SDL_Texture* _taxi = game.loadTexture("taxi2.png");
SDL_Texture* button1 = game.loadTexture("template_button1.png");
SDL_Texture* start_button= game.loadTexture("start_button1.png");
SDL_Texture* exit_button= game.loadTexture("exit_button.png");
SDL_Texture* setting_button= game.loadTexture("setting_button.png");
SDL_Texture* game_over=game.loadTexture("game_over.png");
SDL_Texture* menu_window=game.loadTexture("menu.png");
SDL_Texture* exit_menubutton=game.loadTexture("exit_menuButton.png");
SDL_Texture* coin=game.loadTexture("energy1.png");
SDL_Texture* again=game.loadTexture("play_again.png");
SDL_Texture* exit_buttonred=game.loadTexture("exit_buttonred.png");
SDL_Texture* main_screen_=game.loadTexture("main_screen.png");
SDL_Texture* slide_but=game.loadTexture("slide_button.png");
SDL_Texture* ques_but=game.loadTexture("qumark_button.png");
SDL_Texture* information=game.loadTexture("information_button.png");
SDL_Texture* information_txt=game.loadTexture("information.png");
SDL_Texture* resume_but=game.loadTexture("resume_button.png");
SDL_Texture* slide_black=game.loadTexture("slide_button-modified.png");
SDL_Texture* traffic_light=game.loadTexture("traffic_light.png");
SDL_Texture* instruction=game.loadTexture("instruction.png");
SDL_Texture* a_button=game.loadTexture("a_button.png");
SDL_Texture* d_button=game.loadTexture("d_button.png");

int main(int argc, char* argv[])
{
    player player(77,600,71,140,car);
    player.loadRender();
    button b(0,0,170,85,button1);
    button exit_(139,250+170+40,170,85,exit_button);
    button setting(139,250+85+20,170,85,setting_button);
    button start(139,250,170,85,start_button);
    button resume(139,250,170,85,resume_but);
    button exit_menu(367,234,16,15,exit_menubutton);//367 234
    button play_again(35,510,170,85,again);
    button exit_red(35+170+40,510,170,85,exit_buttonred);
    button main_screen(139,510+85+20,170,85,main_screen_);
    button question(450-43-43-43,750-43-43,43,43,ques_but);
    button infor(43+43,750-43-43,43,43,information);
    button traffic(300,-150,83,288,traffic_light);
    button a_but(109+10,307,85,85,a_button);
    button d_but(257-10,307,85,85,d_button);
    entity you_die(0,0,450,750,game_over);
    entity menu(0,0,335,335,menu_window);
    entity roadrumble(0,0,275,180,title);
    entity slide_button(0,0,26,32,slide_but);
    entity slide_button1(0,0,26,32,slide_but);
    entity slide_button2(0,0,26,32,slide_but);
    entity slide_button3(0,0,26,32,slide_black);
    entity infor_txt(0,0,450,750,information_txt);
    entity instruct(0,0,450,750,instruction);
    float n=77+76;
    float button_state=121+55+87;
    float button_state1=121+55+87;
    float button_state2=121+55+87;
    energy energy(0,0,21,37,coin);
    obsticale taxi(0,0,71,141,_taxi); enemies.push_back(taxi);
    obsticale taxi1(0,0,71,141,_taxi); enemies.push_back(taxi1);
    obsticale taxi2(0,0,71,141,_taxi); enemies.push_back(taxi2);
    game.musicVolume(87);
    game.playMusic();
//    obsticale taxi3(0,0,71,141,_taxi); enemies.push_back(taxi3);
//    obsticale taxi4(0,0,71,141,_taxi); enemies.push_back(taxi4);
//    obsticale taxi5(0,0,71,141,_taxi); enemies.push_back(taxi5);
//    obsticale taxi6(0,0,71,141,_taxi); enemies.push_back(taxi6);
//    obsticale taxi7(0,0,71,141,_taxi); enemies.push_back(taxi7);
//    obsticale taxi8(0,0,71,141,_taxi); enemies.push_back(taxi8);
//    obsticale taxi9(0,0,71,141,_taxi); enemies.push_back(taxi9);
//    obsticale taxi10(0,0,71,141,_taxi); enemies.push_back(taxi10);
    road highway(0,0,800,800,_highway);
    SDL_Event event;
    bool d=false;
    bool d1=false;
    bool again_bro=false;
    bool e=false;
    int cnt=0;

    while(true)
    {
        n=77+76;
        for(int i=0;i<enemies.size();i++) enemies[i].reset();
        energy.reset();
        while(!d)
        {
            while(SDL_PollEvent(&event))
            {
                highway.stillRoad(game);
                game.renderTexture(roadrumble,(450-275)/2+1,90,275,180);
                if (event.button.button == SDL_BUTTON_LEFT && start.event())
                {
                    start.pressed(game);
                    exit_.unpress(game);
                    question.unpress(game);
                    setting.unpress(game);
                    infor.unpress(game);
                    player.defaultPlayer(game,n);
                    game.display();
                    SDL_Delay(350);
                    d=true;
                }
                else if (event.button.button == SDL_BUTTON_LEFT && exit_.event())
                {
                    start.unpress(game);
                    exit_.pressed(game);
                    question.unpress(game);
                    setting.unpress(game);
                    infor.unpress(game);
                    game.display();
                    exit(0);
                }
                else if (event.button.button == SDL_BUTTON_LEFT && question.event())
                {
                    start.unpress(game);
                    exit_.unpress(game);
                    setting.unpress(game);
                    infor.unpress(game);
                    question.pressed(game);
                    SDL_Delay(150);
                    SDL_Event e;
                    bool ques=true;
                    while(ques)
                    {
                        game.renderTexture(instruct,0,0,450,750);
                        a_but.unpress(game);
                        d_but.pressed(game);
                        game.display();
                        SDL_Delay(150);

                        game.renderTexture(instruct,0,0,450,750);
                        a_but.idle(game);
                        d_but.idle(game);
                        game.display();
                        SDL_Delay(150);

                        game.renderTexture(instruct,0,0,450,750);
                        a_but.pressed(game);
                        d_but.unpress(game);
                        game.display();
                        SDL_Delay(150);

                        while(SDL_PollEvent(&e))
                        {
                            if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                            {
                                ques=false;
                            }
                        }
                    }
                }
                else if (event.button.button == SDL_BUTTON_LEFT && infor.event())
                {
                    start.unpress(game);
                    infor.pressed(game);
                    question.unpress(game);
                    exit_.unpress(game);
                    setting.unpress(game);
                    game.display();
                    SDL_Delay(150);
                    SDL_Event i1;
                    bool i=true;

                    while(i)
                    {
                        game.renderTexture(infor_txt,0,0,450,750);
                        while(SDL_PollEvent(&i1))
                        {
                            if (i1.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {i=false; break;}
                        }
                        game.display();
                    }
                    i=true;
                }
                else if (event.button.button == SDL_BUTTON_LEFT && setting.event())
                {
                    start.unpress(game);
                    exit_.unpress(game);
                    infor.unpress(game);
                    setting.pressed(game);
                    question.unpress(game);
                    SDL_Delay(150);
                    SDL_Event e;
                    int x,y;
                    while(!d1)
                    {
                        game.musicVolume(button_state-186);
                        game.resumeMusic();
                        while(SDL_PollEvent(&e))
                        {
                            SDL_GetMouseState(&x,&y);
                            game.renderTexture(roadrumble,25,0,400,180);
                            highway.stillRoad(game);
                            game.renderTexture(menu,55,230,335,335);
                            game.renderTexture(slide_button,button_state,41+230,26,32);
                            game.renderTexture(slide_button1,button_state1,121+230,26,32);
                            game.renderTexture(slide_button2,button_state2,199+230,26,32);
                            if(exit_menu.event() && e.button.button==SDL_BUTTON_LEFT)
                            {
                                exit_menu.pressed(game);
                                d1=true;
                            }
                            else if(y>=41+230-38 && y<=41+230+30 && x>=199-13 && x<=354-13 && e.button.button==SDL_BUTTON_LEFT)
                            {
                                button_state=x;
                            }
                            else if(y>=121+230-38 && y<=121+230+30 && x>=199-13 && x<=354-13 && e.button.button==SDL_BUTTON_LEFT)
                            {
                                button_state1=x;
                            }
                            else if(y>=199+230-38 && y<=199+230+30 && x>=181 && x<=346 && e.button.button==SDL_BUTTON_LEFT)
                            {
                                if(x<=231) {button_state2=199-13; m=5; taxi.setDiff(enemies,400);}
                                else if(x>=309) {button_state2=354-13; m=9; taxi.setDiff(enemies,150);}
                                else {button_state2=121+55+87; m=7; taxi.setDiff(enemies,300);}
                                //186 276 341
                            }
                            else if(exit_menu.event())
                            {
                                exit_menu.idle(game);
                            }
                            else
                            {
                                exit_menu.unpress(game);
                            }
                        }
                        player.defaultPlayer(game,n);
                        game.display();
                    }
                    d1=false;
                }
                else if (question.event())
                {
                    start.unpress(game);
                    question.idle(game);
                    exit_.unpress(game);
                    infor.unpress(game);
                    setting.unpress(game);
                }
                else if (infor.event())
                {
                    start.unpress(game);
                    question.unpress(game);
                    exit_.unpress(game);
                    infor.idle(game);
                    setting.unpress(game);
                }
                else if (start.event())
                {
                    start.idle(game);
                    exit_.unpress(game);
                    infor.unpress(game);
                    question.unpress(game);
                    setting.unpress(game);
                }
                else if (exit_.event())
                {
                    start.unpress(game);
                    exit_.idle(game);
                    infor.unpress(game);
                    question.unpress(game);
                    setting.unpress(game);
                }

                else if (setting.event())
                {
                    start.unpress(game);
                    infor.unpress(game);
                    exit_.unpress(game);
                    question.unpress(game);
                    setting.idle(game);
                }
                else
                {
                    start.unpress(game);
                    infor.unpress(game);
                    question.unpress(game);
                    exit_.unpress(game);
                    setting.unpress(game);
                }
            }
            player.defaultPlayer(game,n);
            game.display();
        }

        highway.stillRoad(game);
        player.defaultPlayer(game,n);
        res(game,traffic);
        for(int i=0;i<enemies.size();i++) enemies[i].reset();
        energy.reset();

        while(d)
        {
            highway.animateRoad(game,speed);
            energy.spawn(game,m);
            collision(enemies);
            for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
            player.defaultPlayer(game,n);
            if(e==true)
            {
                if(cnt>=24) {e=false; cnt=0;}
                player.levelUp(game,n);
                cnt++;
            }
//            taxi3.spawn(game,m);
//            taxi4.spawn(game,m);
//            taxi5.spawn(game,m);
//            taxi6.spawn(game,m);
//            taxi7.spawn(game,m);
//            taxi8.spawn(game,m);
//            taxi9.spawn(game,m);
//            taxi10.spawn(game,m);
            while(SDL_PollEvent(&event))
            {
                if(event.type == SDL_KEYDOWN)
                {
                    if((event.key.keysym.scancode == SDL_SCANCODE_A || event.key.keysym.scancode == SDL_SCANCODE_LEFT) && n>77)
                    {
                        for(int i=0;i<6;i++)
                        {
                            highway.animateRoad(game,speed);
                            energy.spawn(game,m);
                            collision(enemies);
                            for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
                            player.leftLane(game,n);
                            game.display();
                        }

                        for(int i=0;i<6;i++)
                        {
                            highway.animateRoad(game,speed);
                            energy.spawn(game,m);
                            collision(enemies);
                            for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
                            player.leftLane_(game,n);
                            game.display();
                        }
                    }

                    else if((event.key.keysym.scancode == SDL_SCANCODE_D || event.key.keysym.scancode == SDL_SCANCODE_RIGHT) && n<76*4)
                    {
                        for(int i=0;i<6;i++)
                        {
                            highway.animateRoad(game,speed);
                            energy.spawn(game,m);
                            collision(enemies);
                            for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
                            player.rightLane(game,n);
                            game.display();
                        }

                        for(int i=0;i<6;i++)
                        {
                            highway.animateRoad(game,speed);
                            energy.spawn(game,m);
                            collision(enemies);
                            for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
                            player.rightLane_(game,n);
                            game.display();
                        }
                    }
                    else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    {
                        SDL_Event e;
                        int x,y;
                        bool dresume=false;

                        while(!dresume)
                        {
                            while(SDL_PollEvent(&event))
                            {
                                highway.stillRoad(game);
                                for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                                energy.stillE(game);
                                if (event.button.button == SDL_BUTTON_LEFT && resume.event())
                                {
                                    resume.pressed(game);
                                    exit_.unpress(game);
                                    question.unpress(game);
                                    setting.unpress(game);
                                    infor.unpress(game);
                                    player.defaultPlayer(game,n);
                                    SDL_Delay(200);
                                    game.display();
                                    dresume=true;
                                }
                                else if (event.button.button == SDL_BUTTON_LEFT && exit_.event())
                                {
                                    resume.unpress(game);
                                    exit_.pressed(game);
                                    question.unpress(game);
                                    setting.unpress(game);
                                    infor.unpress(game);
                                    game.display();
                                    exit(0);
                                }
                                else if (event.button.button == SDL_BUTTON_LEFT && question.event())
                                {
                                    resume.unpress(game);
                                    exit_.unpress(game);
                                    setting.unpress(game);
                                    infor.unpress(game);
                                    question.pressed(game);
                                }
                                else if (event.button.button == SDL_BUTTON_LEFT && infor.event())
                                {
                                    resume.unpress(game);
                                    infor.pressed(game);
                                    question.unpress(game);
                                    exit_.unpress(game);
                                    setting.unpress(game);
                                    game.display();
                                    SDL_Delay(150);
                                    SDL_Event i1;
                                    bool i=true;

                                    while(i)
                                    {
                                        game.renderTexture(infor_txt,0,0,450,750);
                                        while(SDL_PollEvent(&i1))
                                        {
                                            if (i1.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {i=false; break;}
                                        }
                                        game.display();
                                    }
                                    i=true;
                                }
                                else if (event.button.button == SDL_BUTTON_LEFT && setting.event())
                                {
                                    resume.unpress(game);
                                    exit_.unpress(game);
                                    infor.unpress(game);
                                    setting.pressed(game);
                                    question.unpress(game);
                                    SDL_Delay(150);
                                    SDL_Event e;
                                    int x,y;
                                    while(!d1)
                                    {
                                        while(SDL_PollEvent(&e))
                                        {
                                            SDL_GetMouseState(&x,&y);
                                            game.renderTexture(roadrumble,25,0,400,180);
                                            highway.stillRoad(game);
                                            game.renderTexture(menu,55,230,335,335);
                                            game.renderTexture(slide_button,button_state,41+230,26,32);
                                            game.renderTexture(slide_button1,button_state1,121+230,26,32);
                                            game.renderTexture(slide_button3,button_state2,199+230,26,32);
                                            if(exit_menu.event() && e.button.button==SDL_BUTTON_LEFT)
                                            {
                                                exit_menu.pressed(game);
                                                d1=true;
                                            }
                                            else if(y>=41+230-38 && y<=41+230+30 && x>=181 && x<=346 && e.button.button==SDL_BUTTON_LEFT)
                                            {
                                                button_state=x;
                                            }
                                            else if(y>=121+230-38 && y<=121+230+30 && x>=181 && x<=346 && e.button.button==SDL_BUTTON_LEFT)
                                            {
                                                button_state1=x;
                                            }
                                            else if(exit_menu.event())
                                            {
                                                exit_menu.idle(game);
                                            }
                                            else
                                            {
                                                exit_menu.unpress(game);
                                            }
                                        }
                                        player.defaultPlayer(game,n);
                                        game.display();
                                    }
                                    d1=false;
                                }
                                else if (question.event())
                                {
                                    resume.unpress(game);
                                    question.idle(game);
                                    exit_.unpress(game);
                                    infor.unpress(game);
                                    setting.unpress(game);
                                }
                                else if (infor.event())
                                {
                                    resume.unpress(game);
                                    question.unpress(game);
                                    exit_.unpress(game);
                                    infor.idle(game);
                                    setting.unpress(game);
                                }
                                else if (resume.event())
                                {
                                    resume.idle(game);
                                    exit_.unpress(game);
                                    infor.unpress(game);
                                    question.unpress(game);
                                    setting.unpress(game);
                                }
                                else if (exit_.event())
                                {
                                    resume.unpress(game);
                                    exit_.idle(game);
                                    infor.unpress(game);
                                    question.unpress(game);
                                    setting.unpress(game);
                                }

                                else if (setting.event())
                                {
                                    resume.unpress(game);
                                    infor.unpress(game);
                                    exit_.unpress(game);
                                    question.unpress(game);
                                    setting.idle(game);
                                }
                                else
                                {
                                    resume.unpress(game);
                                    infor.unpress(game);
                                    question.unpress(game);
                                    exit_.unpress(game);
                                    setting.unpress(game);
                                }
                            }
                            player.defaultPlayer(game,n);
                            game.display();
                        }
                        highway.stillRoad(game);
                        for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                        energy.stillE(game);
                        player.defaultPlayer(game,n);
                        res(game,traffic);
                    }
                }
            }
            if(enemies[0].event(n) || enemies[1].event(n) || enemies[2].event(n))
            {
                SDL_Event event1;
                highway.stillRoad(game);
                for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                energy.stillE(game);
                game.renderTexture(you_die,0,0,450,750);
                play_again.unpress(game);
                exit_red.unpress(game);
                main_screen.unpress(game);
                game.display();
                while(!again_bro)
                {
                    while(SDL_PollEvent(&event1))
                    {
                        highway.stillRoad(game);
                        for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                        energy.stillE(game);
                        game.renderTexture(you_die,0,0,450,750);
                        if(event1.button.button == SDL_BUTTON_LEFT && play_again.event())
                        {
                            play_again.pressed(game);
                            exit_red.unpress(game);
                            main_screen.unpress(game);
                            n=77+76;
                            for(int i=0;i<enemies.size();i++) enemies[i].reset();
                            energy.reset();
                            again_bro=true;
                            break;
                        }
                        else if(event1.button.button == SDL_BUTTON_LEFT && exit_red.event())
                        {
                            play_again.unpress(game);
                            exit_red.pressed(game);
                            main_screen.unpress(game);
                            SDL_Delay(150);
                            exit(0);
                        }
                        else if(event1.button.button == SDL_BUTTON_LEFT && main_screen.event())
                        {
                            play_again.unpress(game);
                            exit_red.unpress(game);
                            main_screen.pressed(game);
                            d=false;
                            again_bro=true;
                            break;
                        }
                        else if(play_again.event())
                        {
                            play_again.idle(game);
                            exit_red.unpress(game);
                            main_screen.unpress(game);
                        }
                        else if(exit_red.event())
                        {
                            play_again.unpress(game);
                            exit_red.idle(game);
                            main_screen.unpress(game);
                        }
                        else if(main_screen.event())
                        {
                            play_again.unpress(game);
                            exit_red.unpress(game);
                            main_screen.idle(game);
                        }
                        else
                        {
                            play_again.unpress(game);
                            exit_red.unpress(game);
                            main_screen.unpress(game);
                        }
                        game.display();
                    }
                }
                again_bro=false;
            }
            else if(energy.event(n))
            {
                energy.reset();
                e=true;
            }
            game.display();
        }
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
