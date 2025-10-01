#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <string>
using namespace std;

class MediaPlayer {
public:
    virtual void play(string type) = 0;
    virtual ~MediaPlayer() {}
};

#endif
