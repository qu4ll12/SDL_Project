#include "sound.h"

using namespace std;

sound::sound(Mix_Chunk* gChunk)
{
    gSound = gChunk;
}

void sound::soundVolume(int vol)
{
    Mix_VolumeChunk(gSound, vol);
}

void sound::playSound()
{
    Mix_PlayChannel( -1, gSound, 0 );
}
