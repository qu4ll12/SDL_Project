#pragma once

#include "renderWindow.h"
#include "entity.h"
#include "road.h"
#include "obsticale.h"
#include "button.h"
#include "player.h"
#include "item.h"
#include "soundEffect.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "def.h"
#include "fstream"

class image {
public:
    renderWindow game;

    bool menu_state;
    bool again_bro;
    bool e;
    int cnt;

    SDL_Texture* car;
    SDL_Texture* title;
    SDL_Texture* _highway;
    SDL_Texture* _taxi;
    SDL_Texture* button1;
    SDL_Texture* start_button;
    SDL_Texture* exit_button;
    SDL_Texture* setting_button;
    SDL_Texture* game_over;
    SDL_Texture* menu_window;
    SDL_Texture* exit_menubutton;
    SDL_Texture* coin;
    SDL_Texture* again;
    SDL_Texture* exit_buttonred;
    SDL_Texture* main_screen_;
    SDL_Texture* slide_but;
    SDL_Texture* ques_but;
    SDL_Texture* information;
    SDL_Texture* information_txt;
    SDL_Texture* resume_but;
    SDL_Texture* slide_black;
    SDL_Texture* traffic_light;
    SDL_Texture* instruction;
    SDL_Texture* a_button;
    SDL_Texture* d_button;
    SDL_Texture* bomb;
    SDL_Texture* amor;

    Mix_Chunk* c_levelUp;
    Mix_Chunk* c_click;
    Mix_Chunk* c_moving;
    Mix_Chunk* c_l_sound;
    Mix_Chunk* c_s_sound;
    Mix_Chunk* c_explosion;
    Mix_Chunk* c_shield_consume;
    Mix_Chunk* c_shield_break;

    TTF_Font* gFont;
    TTF_Font* gFont1;
    SDL_Color textColor;
    SDL_Color textColor1;
    SDL_Texture* esc;
    SDL_Texture* esc1;
    SDL_Texture* score_;

    image()
        : game(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE)
    {
        menu_state = true;
        again_bro = false;
        e = false;
        cnt = 0;

        car = game.loadTexture("texture\\jeep.png");
        title = game.loadTexture("texture\\road_rumble.png");
        _highway = game.loadTexture("texture\\highway1.png");
        _taxi = game.loadTexture("texture\\taxi2.png");
        start_button = game.loadTexture("texture\\start_button1.png");
        exit_button = game.loadTexture("texture\\exit_button.png");
        setting_button = game.loadTexture("texture\\setting_button.png");
        game_over = game.loadTexture("texture\\game_over1.png");
        menu_window = game.loadTexture("texture\\menu.png");
        exit_menubutton = game.loadTexture("texture\\exit_menuButton.png");
        coin = game.loadTexture("texture\\energy1.png");
        again = game.loadTexture("texture\\play_again.png");
        exit_buttonred = game.loadTexture("texture\\exit_buttonred.png");
        main_screen_ = game.loadTexture("texture\\main_screen.png");
        slide_but = game.loadTexture("texture\\slide_button.png");
        ques_but = game.loadTexture("texture\\qumark_button.png");
        information = game.loadTexture("texture\\information_button.png");
        information_txt = game.loadTexture("texture\\information.png");
        resume_but = game.loadTexture("texture\\resume_button.png");
        slide_black = game.loadTexture("texture\\slide_button-modified.png");
        traffic_light = game.loadTexture("texture\\traffic_light.png");
        instruction = game.loadTexture("texture\\instruction.png");
        a_button = game.loadTexture("texture\\a_button.png");
        d_button = game.loadTexture("texture\\d_button.png");
        bomb = game.loadTexture("texture\\tnt.png");
        amor = game.loadTexture("texture\\shield.png");

        c_levelUp = game.loadSound("sound\\levelUp.wav");
        c_click = game.loadSound("sound\\click.wav");
        c_moving = game.loadSound("sound\\moving.wav");
        c_l_sound = game.loadSound("sound\\traffic_light.wav");
        c_s_sound = game.loadSound("sound\\start_sound.wav");
        c_explosion = game.loadSound("sound\\tnt.wav");
        c_shield_consume = game.loadSound("sound\\shield.wav");
        c_shield_break = game.loadSound("sound\\shield_break.wav");

        gFont = game.loadFont("font\\upheavtt.ttf", 20);
        gFont1 = game.loadFont("font\\upheavtt.ttf", 70);
        textColor = {0, 0, 0};
        textColor1 = {255, 255, 255};
        esc = game.renderText("press esc to exit", gFont, textColor);
        esc1 = game.renderText("press esc to exit", gFont, textColor1);
        score_ = game.renderText("SCORE: ", gFont1, textColor1);
    }

    ~image() {
    }
};

class graphic {
public:
    player user;
    button b;
    button start;
    button resume;
    button setting;
    button exit_;
    button exit_menu;
    button setting_resume;
    button exit_resume;
    button play_again;
    button main_screen;
    button exit_red;
    button infor;
    button question;
    button traffic;
    button a_but;
    button d_but;
    entity you_die;
    entity menu;
    entity roadrumble;
    entity slide_button;
    entity slide_button1;
    entity slide_button2;
    entity slide_button3;
    entity infor_txt;
    entity instruct;
    entity coin1;
    entity taxi_;
    entity instr_text;
    entity infor_text;
    entity score;
    float axis_X;
    item tnt;
    item shield;
    item energy1;
    obsticale taxi;
    obsticale taxi1;
    obsticale taxi2;
    road highway;
    soundEffect levelUp;
    soundEffect click;
    soundEffect moving;
    soundEffect l_sound;
    soundEffect s_sound;
    soundEffect explosion;
    soundEffect shield_consume;
    soundEffect shield_break;

    std::vector<obsticale> enemies;
    std::vector<int> button_states;
    std::vector<button> button_menu;
    std::vector<button> button_menu_resume;
    std::vector<button> button_menu_die;
    std::vector<button> setting_menu;
    std::vector<item> object;
    std::vector<soundEffect> sound;

    graphic(image& resources)
        : user(77, 600, PLAYER_WIDTH, PLAYER_HEIGHT, resources.car),
          b(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT, resources.button1),
          start(139, 250, BUTTON_WIDTH, BUTTON_HEIGHT, resources.start_button),
          resume(139, 250, BUTTON_WIDTH, BUTTON_HEIGHT, resources.resume_but),
          setting(139, 250 + 85 + 20, BUTTON_WIDTH, BUTTON_HEIGHT, resources.setting_button),
          exit_(139, 250 + 170 + 40, BUTTON_WIDTH, BUTTON_HEIGHT, resources.exit_button),
          exit_menu(367, 234, 16, 15, resources.exit_menubutton),
          setting_resume(139, 250 + 85 + 20, BUTTON_WIDTH, BUTTON_HEIGHT, resources.setting_button),
          exit_resume(139, 250 + 170 +40, BUTTON_WIDTH, BUTTON_HEIGHT, resources.exit_button),
          play_again(35, 510, BUTTON_WIDTH, BUTTON_HEIGHT, resources.again),
          main_screen(139, 510 + 85 + 20, BUTTON_WIDTH, BUTTON_HEIGHT, resources.main_screen_),
          exit_red(35 + 170 + 40, 510, BUTTON_WIDTH, BUTTON_HEIGHT, resources.exit_buttonred),
          infor(S_BUTTON_WH * 2, SCREEN_HEIGHT - S_BUTTON_WH * 2, S_BUTTON_WH, S_BUTTON_WH, resources.information),
          question(SCREEN_WIDTH - S_BUTTON_WH * 3, SCREEN_HEIGHT - S_BUTTON_WH * 2, S_BUTTON_WH, S_BUTTON_WH, resources.ques_but),
          traffic(300, -150, TRAFFIC_LIGHT_WIDTH, TRAFFIC_LIGHT_HEIGHT, resources.traffic_light),
          a_but(109 + 10, 307, BUTTON_HEIGHT, BUTTON_HEIGHT, resources.a_button),
          d_but(257 - 10, 307, BUTTON_HEIGHT, BUTTON_HEIGHT, resources.d_button),
          you_die(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.game_over),
          menu(0, 0, MENU_WIDTH, MENU_HEIGHT, resources.menu_window),
          roadrumble(0, 0, TITLE_WIDTH, TITLE_HEIGHT, resources.title),
          slide_button(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.slide_but),
          slide_button1(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.slide_but),
          slide_button2(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.slide_but),
          slide_button3(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.slide_black),
          infor_txt(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.information_txt),
          instruct(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.instruction),
          coin1(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, resources.coin),
          taxi_(0, 0, TAXI_WIDTH, TAXI_HEIGHT, resources._taxi),
          instr_text(0, 0, 200, 20, resources.esc),
          infor_text(0, 0, 200, 20, resources.esc1),
          score(0, 0, 700, 700, resources.score_),
          axis_X(default_X),
          tnt(0, 0, ENERGY_WIDTH, ENERGY_HEIGHT, resources.bomb),
          shield(0, 0, ENERGY_WIDTH, ENERGY_HEIGHT, resources.amor),
          energy1(0, 0, ENERGY_WIDTH, ENERGY_HEIGHT, resources.coin),
          taxi(0, 0, TAXI_WIDTH, TAXI_HEIGHT, resources._taxi),
          taxi1(0, 0, TAXI_WIDTH, TAXI_HEIGHT, resources._taxi),
          taxi2(0, 0, TAXI_WIDTH, TAXI_HEIGHT, resources._taxi),
          highway(0, 0, HIGHWAY_WIDTH, HIGHWAY_HEIGHT, resources._highway),
          levelUp(resources.c_levelUp),
          click(resources.c_click),
          moving(resources.c_moving),
          l_sound(resources.c_l_sound),
          s_sound(resources.c_s_sound),
          explosion(resources.c_explosion),
          shield_consume(resources.c_shield_consume),
          shield_break(resources.c_shield_break)

    {
        button_menu_resume.push_back(resume);
        button_menu_resume.push_back(setting_resume);
        button_menu_resume.push_back(exit_resume);
        button_menu_resume.push_back(setting_resume);
        button_menu_resume.push_back(exit_resume);

        button_menu.push_back(start);
        button_menu.push_back(setting);
        button_menu.push_back(exit_);
        button_menu.push_back(infor);
        button_menu.push_back(question);

        setting_menu.push_back(exit_menu);

        button_menu_die.push_back(play_again);
        button_menu_die.push_back(main_screen);
        button_menu_die.push_back(exit_red);

        object.push_back(tnt);
        object.push_back(shield);
        object.push_back(energy1);

        enemies.push_back(taxi1);
        enemies.push_back(taxi2);

        sound.push_back(click);
        sound.push_back(moving);
        sound.push_back(explosion);
        sound.push_back(shield_consume);
        sound.push_back(levelUp);
        sound.push_back(shield_break);
        sound.push_back(l_sound);
        sound.push_back(s_sound);

        user.loadRender();

        std::ifstream input("setting.txt");
        for(int i=0;i<BUTTON_STATES_SIZE;i++)
        {
            int value; input>>value;
            button_states.push_back(value);
        }
        input.close();

        resources.game.musicVolume(button_states[0] - 186);
        for(int i=0;i<SOUND_EFFECT_SIZE;i++) sound[i].soundVolume(button_states[1] - 186);

        enemies.push_back(taxi);
        enemies.push_back(taxi1);
        enemies.push_back(taxi2);

        if (button_states[2] == SLIDE_BOTTOM_BORDER_X) {
            for (int i = 0; i < ENEMIES_SIZE; i++) {
                enemies[i].setSpeed(EASY_SPEED);
                enemies[i].setDiff(enemies, EASY_MODE);
            }
        } else if (button_states[2] == SLIDE_UPPER_BORDER_X) {
            for (int i = 0; i < ENEMIES_SIZE; i++) {
                enemies[i].setSpeed(HARD_SPEED);
                enemies[i].setDiff(enemies, HARD_MODE);
            }
        } else {
            for (int i = 0; i < ENEMIES_SIZE; i++) {
                enemies[i].setSpeed(NORMAL_SPEED);
                enemies[i].setDiff(enemies, NORMAL_MODE);
            }
        }
        resources.game.playMusic();
    }
};
