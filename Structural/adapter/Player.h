#ifndef PLAYER_H
#define PLAYER_H

#include "MediaPlayer.h"
#include "Mp3Player.h"
#include "MediaAdapter.h"

class Player : public MediaPlayer {
public:
    void play(string type) override;
};

#endif
