#pragma once

#include <bits/stdc++.h>
#include "renderWindow.h"

class soundEffect
{
public:
    soundEffect(Mix_Chunk* gChunk);
    void playSound();
    void soundVolume(int vol);
private:
    Mix_Chunk* gSound;
};
