#include "Player.h"
#include <iostream>

void Player::play(string type) {
    if (type.find("mp3") != string::npos) {
        Mp3Player mp3;
        mp3.play(type);
    } else if (type.find("mp4") != string::npos) {
        MediaAdapter med;
        med.play(type);
    } else {
        cout << endl;
        cout << "invalid format" << endl;
    }
}
