#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include "MediaPlayer.h"
#include <iostream>
using namespace std;

class Mp3Player : public MediaPlayer {
public:
    void play(string type) override;
};

#endif
