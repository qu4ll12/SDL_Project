#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"
#include "item.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "def.h"
#include "class.h"
#include "fstream"

using namespace std;

int point=0;
int point_w=35;

int caculateWidth(int value)
{
    if (value < 10) return 35;
    if (value < 100) return 70;
    if (value < 1000) return 105;
    if (value < 10000) return 140;
    return 175;
}

void spawn(vector<obsticale>& enemies, vector<item>& object, renderWindow& game)
{
    for(int i=0;i<ENEMIES_SIZE;i++) {
        if(enemies[i].getY()>750) point++;
        enemies[i].spawn(game);
    }
    for(int i=0;i<OBJECT_SIZE;i++) object[i].spawn(game,enemies[0].returnSpeed());
    for(int i=0;i<ENEMIES_SIZE-1;i++)
    {
        for(int j=i+1;j<ENEMIES_SIZE;j++)
        {
            if(i!=j && enemies[i].getX()== enemies[j].getX() && enemies[i].getY()<0 && enemies[j].getY()<0)
            {
                while(enemies[i].getY()<enemies[j].getY() && enemies[i].getY()+enemies[i].getH()+5>enemies[j].getY())
                {
                    enemies[i].reset();
                }
                while(enemies[i].getY()>enemies[j].getY() && enemies[i].getY()<enemies[j].getY()+enemies[j].getH()+5)
                {
                    enemies[j].reset();
                }
            }
        }
    }
    bool loop=true;
    while(loop)
    {
        bool error=false;
        bool losing=true;
        for(int i=0;i<ENEMIES_SIZE;i++)
        {
            for(int j=0;j<OBJECT_SIZE;j++)
            {
                if(-enemies[i].getX()+object[j].getX()<=25 && -enemies[i].getX()+object[j].getX()>=22
                   && object[j].getY()<0)
                while((enemies[i].getY()+enemies[i].getH()>object[j].getY() && enemies[i].getY()<object[j].getY())
                       || (object[j].getY()+ENERGY_HEIGHT+10>enemies[i].getY() && enemies[i].getY()>object[j].getY()))
                {
                    object[j].reset();
                    error=true;
                }
            }
        }

        for(int i=0;i<OBJECT_SIZE-1;i++)
        {
            for(int j=i+1;j<OBJECT_SIZE;j++)
            {
                if(i!=j && object[i].getX()== object[j].getX() && object[i].getY()<0 && object[j].getY()<0)
                {
                    while(object[i].getY()<object[j].getY() && object[i].getY()+ENERGY_HEIGHT+5>object[j].getY())
                    {
                        object[i].reset();
                        error=true;
                    }
                    while(object[i].getY()>object[j].getY() && object[i].getY()<object[j].getY()+ENERGY_HEIGHT+5)
                    {
                        object[j].reset();
                        error=true;
                    }
                }
            }
        }

        for(int i=0;i<ENEMIES_SIZE-1;i++)
        {
            for(int j=i+1;j<ENEMIES_SIZE;j++)
            if(i!=j && enemies[i].getX() == enemies[j].getY()) losing = false;
        }

        if(losing)
        {
            float oldX=object[0].getX();
            float remain_slot=764;
            for(int i=0;i<ENEMIES_SIZE;i++) remain_slot-=enemies[i].getX();
            if(oldX-remain_slot<=25 && oldX-remain_slot>=22 && object[0].getY()<0)
            {
                while(object[0].getX()-remain_slot<=25 && object[0].getX()-remain_slot>=22)
                {
                    object[0].reset();
                    error=true;
                }
            }
        }
        if(!error) loop=false;
    }
}

void print_score(image& resources, int point)
{
    string point_string=to_string(point);
    SDL_Texture* point_texture=resources.game.renderText(point_string.c_str(), resources.gFont1, resources.textColor1);
    point_w=caculateWidth(point);
    entity point_entity(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,point_texture);
    resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
}

void game_over_screen(renderWindow &a, SDL_Texture* game_over)
{
    vector <entity> frame;
    for(int i=0;i<101;i+=5)
    {
        frame.push_back(entity (0,0,SCREEN_WIDTH,SCREEN_HEIGHT/100*i,game_over));
    }
    for(int i=0;i<101;i+=5)
    {
        a.renderTexture(frame[i/5],0,0,SCREEN_WIDTH,SCREEN_HEIGHT/100*i);
        a.display();
        SDL_Delay(50);
    }
}

void res(image& resources, graphic &gfx)
{
    gfx.traffic.unpress(resources.game);
    gfx.sound[6].playSound();
    resources.game.display();
    SDL_Delay(750);
    gfx.traffic.pressed(resources.game);
    gfx.sound[6].playSound();
    resources.game.display();
    SDL_Delay(750);
    gfx.traffic.idle(resources.game);
    gfx.sound[6].playSound();
    resources.game.display();
    SDL_Delay(750);
    gfx.sound[7].playSound();
}

void moving_left(image& resources, graphic& gfx, entity& point_entity)
{
    gfx.sound[1].playSound();
    for(int i=0;i<MOVING_SPRITE_SIZE;i++)
    {
        gfx.highway.animateRoad(resources.game,SPEED);
        spawn(gfx.enemies,gfx.object,resources.game);
        resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
        gfx.user.leftLane(resources.game,gfx.axis_X);
        resources.game.display();
    }

    for(int i=0;i<MOVING_SPRITE_SIZE;i++)
    {
        gfx.highway.animateRoad(resources.game,SPEED);
        spawn(gfx.enemies,gfx.object,resources.game);
        resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
        gfx.user.leftLane_(resources.game,gfx.axis_X);
        resources.game.display();
    }
}

void moving_right(image& resources, graphic& gfx, entity& point_entity)
{
    gfx.sound[1].playSound();
    for(int i=0;i<6;i++)
    {
        gfx.highway.animateRoad(resources.game,SPEED);
        spawn(gfx.enemies,gfx.object,resources.game);
        resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
        gfx.user.rightLane(resources.game,gfx.axis_X);
        resources.game.display();
    }

    for(int i=0;i<6;i++)
    {
        gfx.highway.animateRoad(resources.game,SPEED);
        spawn(gfx.enemies,gfx.object,resources.game);
        resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
        gfx.user.rightLane_(resources.game,gfx.axis_X);
        resources.game.display();
    }
}

void menu(image& resources, graphic& gfx)
{
    SDL_Event event;
    gfx.axis_X = ORIGIN_X;

    while (resources.menu_state) {
        while (SDL_PollEvent(&event)) {
            gfx.highway.stillRoad(resources.game);
            resources.game.renderTexture(gfx.roadrumble, (SCREEN_WIDTH - 275) / 2 + 1, 90, TITLE_WIDTH, TITLE_HEIGHT);
            if (event.type == SDL_QUIT) {
                exit(0);
            }
            if (event.button.button == SDL_BUTTON_LEFT) {
                gfx.sound[0].playSound();
                if (gfx.button_menu[0].event()) {
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        if (i == 0) gfx.button_menu[i].pressed(resources.game);
                        else gfx.button_menu[i].unpress(resources.game);
                    }
                    gfx.user.defaultPlayer(resources.game, gfx.axis_X);
                    resources.game.display();
                    SDL_Delay(350);
                    resources.menu_state = false;
                } else if (gfx.button_menu[1].event()) {
                    bool setting_state = true;
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        if (i == 1) gfx.button_menu[i].pressed(resources.game);
                        else gfx.button_menu[i].unpress(resources.game);
                    }
                    SDL_Delay(150);
                    SDL_Event e;
                    int x, y;
                    while (setting_state) {
                        resources.game.musicVolume(gfx.button_states[0] - 181);
                        resources.game.resumeMusic();
                        SDL_GetMouseState(&x, &y);
                        while (SDL_PollEvent(&e)) {
                            resources.game.renderTexture(gfx.menu, 55, 230, MENU_WIDTH, MENU_HEIGHT);
                            resources.game.renderTexture(gfx.slide_button, gfx.button_states[0], 41 + 230, SLIDE_WIDTH, SLIDE_HEIGHT);
                            resources.game.renderTexture(gfx.slide_button1, gfx.button_states[1], 121 + 230, SLIDE_WIDTH, SLIDE_HEIGHT);
                            resources.game.renderTexture(gfx.slide_button2, gfx.button_states[2], 199 + 230, SLIDE_WIDTH, SLIDE_HEIGHT);
                            for(int i=0;i<SOUND_EFFECT_SIZE;i++) {gfx.sound[i].soundVolume(gfx.button_states[1] - 186);}
                            if (e.type == SDL_QUIT) {
                                exit(0);
                            }
                            ofstream output("setting.txt");
                            for(int i=0;i<BUTTON_STATES_SIZE;i++) {
                                output<<gfx.button_states[i];
                                output<<endl;
                            }
                            output.close();
                             if (e.button.button == SDL_BUTTON_LEFT) {
                                if (gfx.exit_menu.event()) {
                                    gfx.exit_menu.pressed(resources.game);
                                    setting_state = false;
                                } else if (y >= SLIDE1_BOTTOM_BORDER_Y && y <= SLIDE1_UPPER_BORDER_Y && x >= SLIDE_BOTTOM_BORDER_X && x <= SLIDE_UPPER_BORDER_X) {
                                    gfx.button_states[0] = x;
                                } else if (y >= SLIDE2_BOTTOM_BORDER_Y && y <= SLIDE2_UPPER_BORDER_Y && x >= SLIDE_BOTTOM_BORDER_X && x <= SLIDE_UPPER_BORDER_X) {
                                    gfx.button_states[1] = x;
                                } else if (y >= SLIDE3_BOTTOM_BORDER_Y && y <= SLIDE3_UPPER_BORDER_Y && x >= SLIDE_BOTTOM_BORDER_X && x <= SLIDE_UPPER_BORDER_X) {
                                    if (x <= 231) {
                                        gfx.button_states[2] = 199 - 13;
                                        for (int i = 0; i < ENEMIES_SIZE; i++) {
                                            gfx.enemies[i].setSpeed(EASY_SPEED);
                                            gfx.enemies[i].setDiff(gfx.enemies, EASY_MODE);
                                        }
                                    } else if (x >= 309) {
                                        gfx.button_states[2] = 354 - 13;
                                        for (int i = 0; i < ENEMIES_SIZE; i++) {
                                            gfx.enemies[i].setSpeed(HARD_SPEED);
                                            gfx.enemies[i].setDiff(gfx.enemies, HARD_MODE);
                                        }
                                    } else {
                                        gfx.button_states[2] = 121 + 55 + 87;
                                        for (int i = 0; i < ENEMIES_SIZE; i++) {
                                            gfx.enemies[i].setSpeed(NORMAL_SPEED);
                                            gfx.enemies[i].setDiff(gfx.enemies, NORMAL_MODE);
                                        }
                                    }
                                }
                            } else if (gfx.exit_menu.event()) {
                                gfx.exit_menu.idle(resources.game);
                            } else {
                                gfx.exit_menu.unpress(resources.game);
                            }
                        }
                        gfx.user.defaultPlayer(resources.game, gfx.axis_X);
                        resources.game.display();
                    }
                } else if (gfx.button_menu[2].event()) {
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        if (i == 2) gfx.button_menu[i].pressed(resources.game);
                        else gfx.button_menu[i].unpress(resources.game);
                    }
                    resources.game.display();
                    exit(0);
                } else if (gfx.button_menu[3].event()) {
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        if (i == 3) gfx.button_menu[i].pressed(resources.game);
                        else gfx.button_menu[i].unpress(resources.game);
                    }
                    resources.game.display();
                    SDL_Delay(150);
                    SDL_Event i1;
                    bool i = true;

                    while (i) {
                        resources.game.renderTexture(gfx.infor_txt, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                        resources.game.renderTexture(gfx.infor_text, 450 - 210, 720, 200, 20);
                        while (SDL_PollEvent(&i1)) {
                            if (i1.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                                i = false;
                                break;
                            }
                        }
                        resources.game.display();
                    }
                    i = true;
                } else if (gfx.button_menu[4].event()) {
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        if (i == 4) gfx.button_menu[i].pressed(resources.game);
                        else gfx.button_menu[i].unpress(resources.game);
                    }
                    SDL_Delay(150);
                    SDL_Event e;
                    bool ques = true;
                    while (ques) {
                        for(int i=0;i<3;i++)
                        {
                            resources.game.renderTexture(gfx.instruct, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
                            resources.game.renderTexture(gfx.instr_text, 450 - 210, 720, 200, 20);
                            if(i==0) {gfx.a_but.unpress(resources.game); gfx.d_but.pressed(resources.game); gfx.sound[0].playSound();}
                            else if(i==1) {gfx.a_but.idle(resources.game); gfx.d_but.idle(resources.game);}
                            else if(i==2) {gfx.a_but.pressed(resources.game); gfx.d_but.unpress(resources.game); gfx.sound[0].playSound();}
                            resources.game.display();
                            SDL_Delay(150);
                        }
                        while (SDL_PollEvent(&e)) {
                            if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                                ques = false;
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                        gfx.button_menu[i].unpress(resources.game);
                    }
                }
            } else {
                for (int i = 0; i < BUTTON_MENU_SIZE; i++) {
                    if (gfx.button_menu[i].event()) {
                        gfx.button_menu[i].idle(resources.game);
                    } else {
                        gfx.button_menu[i].unpress(resources.game);
                    }
                }
            }
        }
        gfx.user.defaultPlayer(resources.game, gfx.axis_X);
        resources.game.display();
    }
}

void game_loop(image& resources, graphic& gfx)
{
    SDL_Event event;

    while(!resources.menu_state)
    {
        gfx.highway.animateRoad(resources.game,SPEED);
        spawn(gfx.enemies,gfx.object,resources.game);
        gfx.user.defaultPlayer(resources.game,gfx.axis_X);
        string point_string=to_string(point);
        SDL_Texture* point_texture=resources.game.renderText(point_string.c_str(), resources.gFont1, resources.textColor1);
        point_w=caculateWidth(point);
        entity point_entity(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,point_texture);
        resources.game.renderTexture(point_entity,50,18,point_w,SCORE_HEIGHT);
        if(resources.e==true)
        {
            if(resources.cnt>=24) {resources.e=false; resources.cnt=0;}
            gfx.user.levelUp(resources.game,gfx.axis_X);
            resources.cnt++;
        }
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
                    if(gfx.axis_X>BORDER_LEFT)
                    {
                        moving_left(resources, gfx, point_entity);
                    }
                    break;

                    case SDLK_d:
                    if(gfx.axis_X<BORDER_RIGHT)
                    {
                        moving_right(resources, gfx, point_entity);
                    }
                    break;

                    case SDLK_ESCAPE:
                    bool dresume=false;
                    for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++) gfx.button_menu_resume[i].unpress(resources.game);
                    resources.game.display();

                    while(!dresume)
                    {
                        while(SDL_PollEvent(&event))
                        {
                            gfx.highway.stillRoad(resources.game);
                            for(int i=0;i<ENEMIES_SIZE;i++) gfx.enemies[i].stillO(resources.game);
                            for(int i=0;i<OBJECT_SIZE;i++) gfx.object[i].stillE(resources.game);

                            if(event.type == SDL_QUIT)
                            {
                                exit(0);
                            }
                            if (event.button.button == SDL_BUTTON_LEFT)
                            {
                                gfx.sound[0].playSound();
                                if (gfx.button_menu_resume[0].event())
                                {
                                    for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++)
                                    {
                                        if(i==0) gfx.button_menu_resume[i].pressed(resources.game);
                                        else gfx.button_menu_resume[i].unpress(resources.game);
                                    }
                                    gfx.user.defaultPlayer(resources.game,gfx.axis_X);
                                    SDL_Delay(200);
                                    resources.game.display();
                                    dresume=true;
                                }
                                else if (gfx.button_menu_resume[3].event())
                                {
                                    bool menu_state=true;
                                    for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++)
                                    {
                                        if(i==3) gfx.button_menu_resume[i].pressed(resources.game);
                                        else gfx.button_menu_resume[i].unpress(resources.game);
                                    }
                                    SDL_Delay(150);
                                    SDL_Event e;
                                    int x,y;
                                    while(menu_state)
                                    {
                                        resources.game.musicVolume(gfx.button_states[0]-181);
                                        resources.game.resumeMusic();
                                        while(SDL_PollEvent(&e))
                                        {
                                            SDL_GetMouseState(&x,&y);
                                            resources.game.renderTexture(gfx.menu,55,230,MENU_WIDTH,MENU_HEIGHT);
                                            resources.game.renderTexture(gfx.slide_button,gfx.button_states[0],41+230,SLIDE_WIDTH,SLIDE_HEIGHT);
                                            resources.game.renderTexture(gfx.slide_button1,gfx.button_states[1],121+230,SLIDE_WIDTH,SLIDE_HEIGHT);
                                            resources.game.renderTexture(gfx.slide_button3,gfx.button_states[2],199+230,SLIDE_WIDTH,SLIDE_HEIGHT);
                                            for(int i=0;i<SOUND_EFFECT_SIZE;i++) gfx.sound[i].soundVolume(gfx.button_states[1] - 186);
                                            ofstream output("setting.txt");
                                            for(int i=0;i<BUTTON_STATES_SIZE;i++) {
                                                output<<gfx.button_states[i];
                                                output<<endl;
                                            }
                                            output.close();
                                            if(e.button.button==SDL_BUTTON_LEFT)
                                            {
                                                if(gfx.exit_menu.event())
                                                {
                                                    gfx.exit_menu.pressed(resources.game);
                                                    menu_state=false;
                                                }
                                                else if(y>=SLIDE1_BOTTOM_BORDER_Y && y<=SLIDE1_UPPER_BORDER_Y && x>=SLIDE_BOTTOM_BORDER_X && x<=SLIDE_UPPER_BORDER_X)
                                                {
                                                    gfx.button_states[0]=x;
                                                }
                                                else if(y>=SLIDE2_BOTTOM_BORDER_Y && y<=SLIDE2_UPPER_BORDER_Y && x>=SLIDE_BOTTOM_BORDER_X && x<=SLIDE_UPPER_BORDER_X)
                                                {
                                                    gfx.button_states[1]=x;
                                                }
                                                else if(gfx.exit_menu.event())
                                                {
                                                    gfx.exit_menu.idle(resources.game);
                                                }
                                                else
                                                {
                                                    gfx.exit_menu.unpress(resources.game);
                                                }
                                            }
                                        }
                                        gfx.user.defaultPlayer(resources.game,gfx.axis_X);
                                        resources.game.display();
                                    }
                                    menu_state=false;
                                }
                                else if (gfx.button_menu_resume[4].event())
                                {
                                    for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++)
                                    {
                                        if(i==4) gfx.button_menu_resume[i].pressed(resources.game);
                                        else gfx.button_menu_resume[i].unpress(resources.game);
                                    }
                                    resources.game.display();
                                    exit(0);
                                }
                                else for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++) gfx.button_menu_resume[i].unpress(resources.game);
                            }
                            else
                            {
                                for(int i=0;i<BUTTON_MENU_RESUME_SIZE;i++)
                                {
                                    if(gfx.button_menu_resume[i].event())
                                    {
                                        gfx.button_menu_resume[i].idle(resources.game);
                                    }
                                    else
                                    {
                                        gfx.button_menu_resume[i].unpress(resources.game);
                                    }
                                }
                            }
                        }
                        gfx.user.defaultPlayer(resources.game,gfx.axis_X);
                        resources.game.display();
                    }

                    gfx.highway.stillRoad(resources.game);
                    for(int i=0;i<ENEMIES_SIZE;i++) gfx.enemies[i].stillO(resources.game);
                    for(int i=0;i<OBJECT_SIZE;i++) gfx.object[i].stillE(resources.game);
                    gfx.user.defaultPlayer(resources.game,gfx.axis_X);
                    res(resources, gfx);
                    break;
                }
            }
        }
        if(gfx.enemies[0].event(gfx.axis_X) || gfx.enemies[1].event(gfx.axis_X) || gfx.enemies[2].event(gfx.axis_X)
           || gfx.object[2].outOfFuel() || (gfx.object[0].event(gfx.axis_X) && !gfx.user.shieldStatus()))
        {
            SDL_Event event1;
            gfx.sound[2].playSound();
            int best_w=0,best;
            ifstream input("score.txt");
            input>>best;
            input.close();
            string best_string=to_string(best);
            if(point>best) {
                ofstream output("score.txt");
                best_string = point_string;
                output << best_string;
                output.close();
            }
            best = stoi(best_string);
            best_w=caculateWidth(best);
            SDL_Texture* best_=resources.game.renderText(best_string.c_str(), resources.gFont1, resources.textColor1);
            entity best__(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,best_);
            for(int i=0;i<EXPLOSION_SPRITE_SIZE;i++)
            {
                gfx.highway.stillRoad(resources.game);
                for(int i=0;i<ENEMIES_SIZE;i++) gfx.enemies[i].stillO(resources.game);
                for(int i=0;i<OBJECT_SIZE;i++) gfx.object[i].stillE(resources.game);
                gfx.user.die(resources.game,gfx.axis_X);
                resources.game.display();
                SDL_Delay(50);
            }
            game_over_screen(resources.game,resources.game_over);
            resources.game.renderTexture(gfx.you_die,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
            for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++) gfx.button_menu_die[i].unpress(resources.game);
            resources.game.display();

            while(!resources.again_bro)
            {
                while(SDL_PollEvent(&event1))
                {
                    resources.game.renderTexture(gfx.you_die,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
                    resources.game.renderTexture(point_entity,280,290,point_w,SCORE_HEIGHT);
                    resources.game.renderTexture(best__,230,405,best_w,SCORE_HEIGHT);
                    if(event1.type == SDL_QUIT)
                    {
                        exit(0);
                    }
                    if(event1.button.button == SDL_BUTTON_LEFT)
                    {
                        gfx.sound[0].playSound();
                        if(gfx.button_menu_die[0].event())
                        {
                            for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++){
                                if(i==0) gfx.button_menu_die[i].pressed(resources.game);
                                else gfx.button_menu_die[i].unpress(resources.game);
                            }
                            gfx.object[2].resetFuel();
                            resources.again_bro=true;
                        }
                        else if(gfx.button_menu_die[1].event())
                        {
                            for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++){
                                if(i==1) gfx.button_menu_die[i].pressed(resources.game);
                                else gfx.button_menu_die[i].unpress(resources.game);
                            }
                            resources.menu_state=true;
                            resources.again_bro=true;
                        }
                        else if(gfx.button_menu_die[2].event())
                        {
                            for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++){
                                if(i==2) gfx.button_menu_die[i].pressed(resources.game);
                                else gfx.button_menu_die[i].unpress(resources.game);
                            }
                            SDL_Delay(150);
                            exit(0);
                        }
                        else
                        {
                            for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++)
                        {
                                gfx.button_menu_die[i].unpress(resources.game);
                            }
                        }
                    }
                    else
                    {
                        for(int i=0;i<BUTTON_MENU_DIE_SIZE;i++)
                        {
                            if(gfx.button_menu_die[i].event())
                            {
                                gfx.button_menu_die[i].idle(resources.game);
                            }
                            else
                            {
                                gfx.button_menu_die[i].unpress(resources.game);
                            }
                        }
                    } resources.game.display();
                }
            }
            point=0;
            gfx.axis_X=ORIGIN_X;
            gfx.object[2].reset();
            gfx.user.shieldOff();
            for(int i=0;i<ENEMIES_SIZE;i++) gfx.enemies[i].reset();
            for(int i=0;i<OBJECT_SIZE;i++) gfx.object[i].reset();
            resources.again_bro=false;
        }
        else if(gfx.object[0].event(gfx.axis_X) && gfx.user.shieldStatus())
        {
            gfx.sound[5].playSound();
            gfx.user.shieldOff();
            gfx.object[0].reset();
            point++;
        }
        else if(gfx.object[2].event(gfx.axis_X))
        {
            resources.e=true;
            gfx.sound[4].playSound();
            gfx.object[2].reset();
            point++;
        }
        else if(gfx.object[1].event(gfx.axis_X))
        {
            gfx.sound[3].playSound();
            gfx.user.shieldOn();
            gfx.object[1].reset();
        }
        resources.game.display();
    }
}
int main(int argc, char* argv[])
{
    image resources;
    graphic gfx(resources);
    SDL_Event e;

    while (true) {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT) exit(0);
        }
        menu(resources, gfx);

        gfx.highway.stillRoad(resources.game);
        gfx.user.defaultPlayer(resources.game, gfx.axis_X);
        res(resources, gfx);
        for(int i=0;i<ENEMIES_SIZE;i++) gfx.enemies[i].reset();
        for(int i=0;i<OBJECT_SIZE;i++) gfx.object[i].reset();

        game_loop(resources, gfx);
    }
    resources.game.waitUntilKeyPressed();
    resources.game.quitSDL();
    return 0;
}
