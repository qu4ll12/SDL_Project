#include "renderWindow.h"

using namespace std;

int main(int argc, char* argv[])
{
    renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
    SDL_Texture* background = game.loadTexture("bikiniBottom.jpg");
    SDL_Texture* spongeBob = game.loadTexture("testing.png");
    game.renderTexture(background, 0, 0);
    game.renderTexture(spongeBob, 200, 200);
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
