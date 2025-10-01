#include "MediaAdapter.h"

MediaAdapter::MediaAdapter() {
    mp4 = make_unique<Mp4Player>();
}

void MediaAdapter::play(string type) {
    mp4->playMp4(type);
}
