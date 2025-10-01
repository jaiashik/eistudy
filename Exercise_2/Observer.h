#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using namespace std;

class ISensorObserver {
public:
    virtual void update(int roomId, bool occupied) = 0;
    virtual ~ISensorObserver() = default;
};

class ACSystem : public ISensorObserver {
public:
    void update(int roomId, bool occupied) override;
};

class LightSystem : public ISensorObserver {
public:
    void update(int roomId, bool occupied) override;
};

#endif
