#include "soundEffect.h"

using namespace std;

soundEffect::soundEffect(Mix_Chunk* gChunk)
{
    gSound = gChunk;
}

void soundEffect::soundVolume(int vol)
{
    Mix_VolumeChunk(gSound, vol);
}

void soundEffect::playSound()
{
    Mix_PlayChannel( -1, gSound, 0 );
}
