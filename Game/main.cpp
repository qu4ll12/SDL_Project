#include "renderWindow.h"

using namespace std;

int main(int argc, char* argv[])
{
    renderWindow game(SCREEN_WIDTH,SCREEN_HEIGHT,WINDOW_TITLE);
    SDL_Texture* background = game.loadTexture("road.png");
    SDL_Texture* spongeBob = game.loadTexture("Spongebob.png");
    game.renderTexture(background, 0, 0);
    game.display();
    game.renderTexture(spongeBob, 200, 200);
    game.display();
    game.waitUntilKeyPressed();
    game.quitSDL();
    return 0;
}
