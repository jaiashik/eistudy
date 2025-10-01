#include "OfficeManager.h"
#include "Observer.h"
#include <iostream>

OfficeManager* OfficeManager::instance = nullptr;

OfficeManager::OfficeManager() {}

OfficeManager* OfficeManager::getInstance() {
    if (!instance) instance = new OfficeManager();
    return instance;
}

void OfficeManager::configureRooms(int count) {
    if (count < 1) {
        cout << "Invalid room count. Must be at least 1." << endl;
        return;
    }
    if (count > 100) {
        cout << "The maximum allowed number of rooms is 100. Please select a number under or equal to 100." << endl;
        return;
    }

    rooms.clear();
    for (int i = 1; i <= count; i++) {
        auto room = make_shared<Room>(i, 5);
        room->attach(make_shared<ACSystem>());
        room->attach(make_shared<LightSystem>());
        rooms.push_back(room);
    }

    cout << "Office configured with " << count << " meeting rooms:" << endl;
    for (int i = 1; i <= count; i++)
        cout << "Room " << i << endl;
}

shared_ptr<Room> OfficeManager::getRoom(int id) {
    if (id < 1 || id > (int)rooms.size()) return nullptr;
    return rooms[id-1];
}
