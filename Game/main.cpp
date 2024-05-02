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
int point=0;
vector <obsticale> enemies;
vector <button> button_menu;
vector <button> button_menu_resume;
vector <button> button_menu_die;
vector <button> setting_menu;

void spawn(vector<obsticale> &enemies, energy &energy, renderWindow& game, int m)
{
    for(int i=0;i<enemies.size();i++) enemies[i].spawn(game,m);
    for(int i=0;i<enemies.size()-1;i++)
    {
        for(int j=i+1;j<enemies.size();j++)
        {
            if(i!=j && enemies[i].getX()== enemies[j].getX() && enemies[i].getY()<0 && enemies[j].getY()<0)
            {
                while(enemies[i].getY()<enemies[j].getY() && enemies[i].getY()+138+5>enemies[j].getY())
                {
                    enemies[i].reset();
                    cout<<"reset"<<endl;
                }
                while(enemies[i].getY()>enemies[j].getY() && enemies[i].getY()<enemies[j].getY()+138+5)
                {
                    enemies[j].reset();
                    cout<<"reset"<<endl;
                }
            }
        }
    }

    for(int i=0;i<enemies.size();i++)
    {
        if(-enemies[i].getX()+energy.getX()<=25 && -enemies[i].getX()+energy.getX()>=22
               && energy.getY()<0)
        while((enemies[i].getY()+138>energy.getY() && enemies[i].getY()<energy.getY())
               || (energy.getY()+37+10>enemies[i].getY() && enemies[i].getY()>energy.getY()))
        {
            energy.reset();
            cout<<"reset1111"<<endl;
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

Mix_Chunk* levelUp=game.loadSound("levelUp.wav");
Mix_Chunk* idle=game.loadSound("idle.wav");
Mix_Chunk* click=game.loadSound("click.wav");

TTF_Font* gFont=game.loadFont("font.ttf", 20);
TTF_Font* gFont1=game.loadFont("PIXELITE.ttf", 70);
SDL_Color textColor={0,0,0};
SDL_Color textColor1={255,255,255};
SDL_Texture* esc=game.renderText("press esc to exit", gFont, textColor);
SDL_Texture* esc1=game.renderText("press esc to exit", gFont, textColor1);
SDL_Texture* score_=game.renderText("SCORE: ", gFont1, textColor1);

int main(int argc, char* argv[])
{
    player player(77,600,71,140,car);
    player.loadRender();
    button b(0,0,170,85,button1);
    button start(139,250,170,85,start_button); button_menu.push_back(start);
    button resume(139,250,170,85,resume_but); button_menu_resume.push_back(resume);
    button setting(139,250+85+20,170,85,setting_button); button_menu.push_back(setting); button_menu_resume.push_back(setting);
    button exit_(139,250+170+40,170,85,exit_button); button_menu.push_back(exit_); button_menu_resume.push_back(exit_);
    button exit_menu(367,234,16,15,exit_menubutton); setting_menu.push_back(exit_menu);
    button play_again(35,510,170,85,again); button_menu_die.push_back(play_again);
    button main_screen(139,510+85+20,170,85,main_screen_); button_menu_die.push_back(main_screen);
    button exit_red(35+170+40,510,170,85,exit_buttonred); button_menu_die.push_back(exit_red);
    button infor(43+43,750-43-43,43,43,information); button_menu.push_back(infor); button_menu_resume.push_back(infor);
    button question(450-43-43-43,750-43-43,43,43,ques_but); button_menu.push_back(question); button_menu_resume.push_back(question);
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
    entity coin1(0,0,21,37,coin);
    entity taxi_(0,0,71,138,_taxi);
    entity chutinh(0,0,200,20,esc);
    entity chutinh1(0,0,200,20,esc1);
    entity score(0,0,700,700,score_);
    float n=77+76;
    float button_state=121+55+87;
    float button_state1=121+55+87;
    float button_state2=121+55+87;
    energy energy(0,0,21,37,coin);
    obsticale taxi(0,0,71,138,_taxi); enemies.push_back(taxi);
    obsticale taxi1(0,0,71,138,_taxi); enemies.push_back(taxi1);
    obsticale taxi2(0,0,71,138,_taxi); enemies.push_back(taxi2);
    game.musicVolume(87);
    game.soundVolume(levelUp, 87);
    game.soundVolume(idle, 87);
    game.soundVolume(click, 87);
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
                if(event.type == SDL_QUIT)
                {
                    exit(0);
                }

                for(int i=0;i<button_menu.size();i++)
                {
                    button_menu[i].handleEvent(&event);
                }

                for(int i=0;i<button_menu.size();i++)
                {
                    button_menu[i].render(game);
                }

                if(button_menu[0].ifPress(game))
                {
                    SDL_Delay(150);
                    d=true;
                }
                else if(button_menu[1].ifPress(game))
                {
                    SDL_Event e;
                    int x,y;
                    while(!d1)
                    {
                        game.musicVolume(button_state-186);
                        game.soundVolume(levelUp, button_state1-186);
                        game.soundVolume(idle, button_state1-186);
                        game.soundVolume(click, button_state1-186);
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
                            if(event.type == SDL_QUIT)
                            {
                                exit(0);
                            }
                            setting_menu[0].handleEvent(&e);
                            setting_menu[0].render(game);
                            if(setting_menu[0].ifPress(game)) d1=true;
                            else if(e.button.button == SDL_BUTTON_LEFT)
                            {
                                if(y>=41+230-38 && y<=41+230+30 && x>=199-13 && x<=354-13)
                                {
                                    button_state=x;
                                }
                                else if(y>=121+230-38 && y<=121+230+30 && x>=199-13 && x<=354-13)
                                {
                                    button_state1=x;
                                }
                                else if(y>=199+230-38 && y<=199+230+30 && x>=181 && x<=346)
                                {
                                    if(x<=231) {button_state2=199-13; m=5; taxi.setDiff(enemies,400);}
                                    else if(x>=309) {button_state2=354-13; m=9; taxi.setDiff(enemies,150);}
                                    else {button_state2=121+55+87; m=7; taxi.setDiff(enemies,300);}
                                    //186 276 341
                                }
                            }
                        }
                        game.display();
                    }
                    d1=false;
                }
                else if(button_menu[2].ifPress(game))
                {
                    exit(0);
                }
                else if(button_menu[3].ifPress(game))
                {
                    SDL_Event e1;
                    bool i=true;

                    while(i)
                    {
                        game.renderTexture(infor_txt,0,0,450,750);
                        game.renderTexture(chutinh,450-200,720,200,20);
                        game.display();
                        while(SDL_PollEvent(&e1))
                        {
                            if (e1.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                            {
                                i=false;
                            }
                        }
                    }
                    highway.stillRoad(game);
                    game.renderTexture(roadrumble,(450-275)/2+1,90,275,180);
                    start.unpress(game);
                    infor.unpress(game);
                    question.unpress(game);
                    exit_.unpress(game);
                    setting.unpress(game);
                }
                else if(button_menu[4].ifPress(game))
                {
                    SDL_Event e;
                    bool ques=true;
                    while(ques)
                    {
                        game.renderTexture(instruct,0,0,450,750);
                        game.renderTexture(chutinh1,450-200,720,200,20);
                        a_but.unpress(game);
                        d_but.pressed(game);
                        game.display();
                        SDL_Delay(150);

                        game.renderTexture(instruct,0,0,450,750);
                        game.renderTexture(chutinh1,450-200,720,200,20);
                        a_but.idle(game);
                        d_but.idle(game);
                        game.display();
                        SDL_Delay(150);

                        game.renderTexture(instruct,0,0,450,750);
                        game.renderTexture(chutinh1,450-200,720,200,20);
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
                    highway.stillRoad(game);
                    game.renderTexture(roadrumble,(450-275)/2+1,90,275,180);
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
            spawn(enemies,energy,game,m);
            energy.spawn(game,m);
            player.defaultPlayer(game,n);
            game.renderTexture(score,10,30,170,70);
            string dbrr=to_string(point);
            SDL_Texture* point_=game.renderText(dbrr.c_str(), gFont1, textColor1);
            entity point__(0,0,500,500,point_);
            game.renderTexture(point__,150,30,30,70);
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
                if(event.type == SDL_QUIT)
                {
                    exit(0);
                }
                else if(event.type == SDL_KEYDOWN)
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_a:
                        if(n>77)
                        {
                            for(int i=0;i<6;i++)
                            {
                                highway.animateRoad(game,speed);
                                spawn(enemies,energy,game,m);
                                energy.spawn(game,m);
                                game.renderTexture(score,10,30,170,70);
                                game.renderTexture(point__,150,30,30,70);
                                player.leftLane(game,n);
                                game.display();
                            }

                            for(int i=0;i<6;i++)
                            {
                                highway.animateRoad(game,speed);
                                spawn(enemies,energy,game,m);;
                                energy.spawn(game,m);
                                game.renderTexture(score,10,30,170,70);
                                game.renderTexture(point__,150,30,30,70);
                                player.leftLane_(game,n);
                                game.display();
                            }
                        }
                        break;

                        case SDLK_d:
                        if(n<76*4)
                        {
                            for(int i=0;i<6;i++)
                            {
                                highway.animateRoad(game,speed);
                                spawn(enemies,energy,game,m);
                                energy.spawn(game,m);
                                game.renderTexture(score,10,30,170,70);
                                game.renderTexture(point__,150,30,30,70);
                                player.rightLane(game,n);
                                game.display();
                            }

                            for(int i=0;i<6;i++)
                            {
                                highway.animateRoad(game,speed);
                                spawn(enemies,energy,game,m);
                                energy.spawn(game,m);
                                game.renderTexture(score,10,30,170,70);
                                game.renderTexture(point__,150,30,30,70);
                                player.rightLane_(game,n);
                                game.display();
                            }
                        }
                        break;

                        case SDLK_ESCAPE:

                        int x,y;
                        bool dresume=false;
                        while(!dresume)
                        {
                            while(SDL_PollEvent(&event))
                            {
                                highway.stillRoad(game);
                                for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                                energy.stillE(game);

                                if(event.type == SDL_QUIT)
                                {
                                    exit(0);
                                }
                                for(int i=0;i<button_menu_resume.size();i++)
                                {
                                    button_menu_resume[i].handleEvent(&event);
                                }

                                for(int i=0;i<button_menu_resume.size();i++)
                                {
                                    button_menu_resume[i].render(game);
                                }

                                if(button_menu_resume[0].ifPress(game))
                                {
                                    SDL_Delay(350);
                                    dresume=true;
                                }
                                else if(button_menu_resume[1].ifPress(game))
                                {
                                    SDL_Event e;
                                    int x,y;
                                    while(!d1)
                                    {
                                        game.musicVolume(button_state-186);
                                        game.soundVolume(levelUp, button_state1-186);
                                        game.soundVolume(idle, button_state1-186);
                                        game.soundVolume(click, button_state1-186);
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
                                            if(event.type == SDL_QUIT)
                                            {
                                                exit(0);
                                            }
                                            setting_menu[0].handleEvent(&e);
                                            setting_menu[0].render(game);
                                            if(setting_menu[0].ifPress(game)) d1=true;
                                            else if(e.button.button == SDL_BUTTON_LEFT)
                                            {
                                                if(y>=41+230-38 && y<=41+230+30 && x>=199-13 && x<=354-13)
                                                {
                                                    button_state=x;
                                                }
                                                else if(y>=121+230-38 && y<=121+230+30 && x>=199-13 && x<=354-13)
                                                {
                                                    button_state1=x;
                                                }
                                                else if(y>=199+230-38 && y<=199+230+30 && x>=181 && x<=346)
                                                {
                                                    if(x<=231) {button_state2=199-13; m=5; taxi.setDiff(enemies,400);}
                                                    else if(x>=309) {button_state2=354-13; m=9; taxi.setDiff(enemies,150);}
                                                    else {button_state2=121+55+87; m=7; taxi.setDiff(enemies,300);}
                                                    //186 276 341
                                                }
                                            }
                                        }
                                        game.display();
                                        }
                                        d1=false;
                                    }
                                    else if(button_menu_resume[2].ifPress(game))
                                    {
                                        exit(0);
                                    }
                                    else if(button_menu_resume[3].ifPress(game))
                                    {
                                        SDL_Event e;
                                        bool i=true;

                                        while(i)
                                        {
                                            game.renderTexture(infor_txt,0,0,450,750);
                                            game.renderTexture(chutinh,450-200,720,200,20);
                                            while(SDL_PollEvent(&e))
                                            {
                                                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {i=false;}
                                            }
                                            game.display();
                                        }
                                        highway.stillRoad(game);
                                        game.renderTexture(roadrumble,(450-275)/2+1,90,275,180);
                                        resume.unpress(game);
                                        infor.unpress(game);
                                        question.unpress(game);
                                        exit_.unpress(game);
                                        setting.unpress(game);
                                    }
                                    else if(button_menu_resume[4].ifPress(game))
                                    {
                                        SDL_Event e;
                                        bool ques=true;
                                        while(ques)
                                        {
                                            game.renderTexture(instruct,0,0,450,750);
                                            game.renderTexture(chutinh1,450-200,720,200,20);
                                            a_but.unpress(game);
                                            d_but.pressed(game);
                                            game.display();
                                            SDL_Delay(150);

                                            game.renderTexture(instruct,0,0,450,750);
                                            game.renderTexture(chutinh1,450-200,720,200,20);
                                            a_but.idle(game);
                                            d_but.idle(game);
                                            game.display();
                                            SDL_Delay(150);

                                            game.renderTexture(instruct,0,0,450,750);
                                            game.renderTexture(chutinh1,450-200,720,200,20);
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
                                        highway.stillRoad(game);
                                        game.renderTexture(roadrumble,(450-275)/2+1,90,275,180);
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
                        break;
                    }
                }
            }
            if(enemies[0].event(n) || enemies[1].event(n) || enemies[2].event(n) || energy.outOfFuel())
            {
                SDL_Event event1;
                highway.stillRoad(game);
                for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                energy.stillE(game);
                game.renderTexture(you_die,0,0,450,750);
                for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                energy.stillE(game);
                game.renderTexture(you_die,0,0,450,750);
                for(int i=0;i<button_menu_die.size();i++)
                {
                    button_menu_die[i].handleEvent(&event1);
                }

                for(int i=0;i<button_menu_die.size();i++)
                {
                    button_menu_die[i].render(game);
                }

                while(!again_bro)
                {
                    while(SDL_PollEvent(&event1))
                    {
                        highway.stillRoad(game);
                        for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                        energy.stillE(game);
                        game.renderTexture(you_die,0,0,450,750);
                        for(int i=0;i<enemies.size();i++) enemies[i].stillO(game);
                        energy.stillE(game);
                        game.renderTexture(you_die,0,0,450,750);
                        if(event1.type == SDL_QUIT)
                        {
                            exit(0);
                        }

                        for(int i=0;i<button_menu_die.size();i++)
                        {
                            button_menu_die[i].handleEvent(&event1);
                        }

                        for(int i=0;i<button_menu_die.size();i++)
                        {
                            button_menu_die[i].render(game);
                        }

                        if(button_menu_die[0].ifPress(game))
                        {
                            n=77+76;
                            for(int i=0;i<enemies.size();i++) enemies[i].reset();
                            energy.reset();
                            again_bro=true;
                            break;
                        }
                        else if(button_menu_die[1].ifPress(game))
                        {
                            d=false;
                            again_bro=true;
                            break;
                        }
                        else if(button_menu_die[2].ifPress(game))
                        {
                            SDL_Delay(150);
                            exit(0);
                        }
                    }
                    game.display();
                }
                again_bro=false;
            }
            else if(energy.event(n))
            {
                e=true;
                game.playSound(levelUp);
                point++;
            }
            game.display();
        }
    }
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
