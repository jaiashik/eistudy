#ifndef OFFICEMANAGER_H
#define OFFICEMANAGER_H

#include <vector>
#include <memory>
#include "Room.h"
using namespace std;

class OfficeManager {
private:
    static OfficeManager *instance;
    vector<shared_ptr<Room>> rooms;
    OfficeManager();
public:
    static OfficeManager *getInstance();
    void configureRooms(int count);
    shared_ptr<Room> getRoom(int id);
};

#endif
