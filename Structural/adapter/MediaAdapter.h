#ifndef MEDIAADAPTER_H
#define MEDIAADAPTER_H

#include "MediaPlayer.h"
#include "Mp4Player.h"
#include <memory>
using namespace std;

class MediaAdapter : public MediaPlayer {
private:
    unique_ptr<Mp4Player> mp4;
public:
    MediaAdapter();
    void play(string type) override;
};

#endif
