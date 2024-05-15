#pragma once

#include <bits/stdc++.h>
#include "renderWindow.h"

class sound
{
public:
    sound(Mix_Chunk* gChunk);
    void playSound();
    void soundVolume(int vol);
private:
    Mix_Chunk* gSound;
};
