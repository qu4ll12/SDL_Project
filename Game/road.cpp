#include "renderWindow.h"
#include "entity.h"
#include "road.h"

using namespace std;

road::road(float r_w, float r_h, SDL_Texture* r_tex) : entity(r_w, r_h, r_tex)
    renderWindow a;

    SDL_Texture* tex1 = a.loadTexture("highway.png");
    SDL_Texture* tex2 = a.loadTexture("highway2.png");
    SDL_Texture* tex3 = a.loadTexture("highway3.png");
    SDL_Texture* tex4 = a.loadTexture("highway4.png");

}
