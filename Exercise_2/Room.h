#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Observer.h"
using namespace std;

class Room {
private:
    int id;
    int capacity;
    int occupants;
    bool booked;
    string startTime;
    string endTime;
    vector<shared_ptr<ISensorObserver>> observers;

public:
    Room(int id, int capacity = 5);

    int getId() const;
    int getCapacity() const;
    bool isBooked() const;

    void setCapacity(int c);
    void attach(shared_ptr<ISensorObserver> obs);
    void notify();
    void setOccupants(int count);
    void book(const string &time, int duration);
    void cancelBooking();
    void status();
};

#endif
