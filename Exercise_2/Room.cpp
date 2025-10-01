#include "Room.h"
#include <algorithm>

Room::Room(int id, int capacity) : id(id), capacity(capacity), occupants(0), booked(false), startTime(""), endTime("") {}

int Room::getId() const { return id; }
int Room::getCapacity() const { return capacity; }
bool Room::isBooked() const { return booked; }

void Room::setCapacity(int c) {
    if (c <= 0) {
        cout << "Invalid capacity. Please enter a valid positive number." << endl;
        return;
    }
    if (c > 500) {
        cout << "Maximum allowed room capacity is 500. Please select a number under or equal to 500." << endl;
        return;
    }
    capacity = c;
    cout << "Room " << id << " maximum capacity set to " << c << "." << endl;
}

void Room::attach(shared_ptr<ISensorObserver> obs) {
    observers.push_back(obs);
}

void Room::notify() {
    bool occupied = (occupants >= 2);
    for (auto &obs : observers) obs->update(id, occupied);
}

void Room::setOccupants(int count) {
    if (count < 0) {
        cout << "Invalid occupant count for Room " << id << "." << endl;
        return;
    }
    if (count > 500) {
        cout << "Maximum allowed occupants per room is 500. Please select a number under or equal to 500." << endl;
        return;
    }
    if (count > capacity) {
        cout << "Cannot exceed room capacity (" << capacity << ")." << endl;
        return;
    }

    occupants = count;

    if (occupants >= 2) {
        cout << "Room " << id << " is now occupied by " << occupants << " persons." << endl;
    } else if (occupants == 1) {
        cout << "Room " << id << " occupancy insufficient to mark as occupied." << endl;
    } else {
        cout << "Room " << id << " is now unoccupied. AC and lights turned off." << endl;
        booked = false;
    }
    notify();
}

void Room::book(const string &time, int duration) {
    if (booked) {
        cout << "Room " << id << " is already booked during this time. Cannot book." << endl;
        return;
    }

    startTime = time;
    int startHour = stoi(time);
    int endHour = startHour + duration;
    endTime = to_string(endHour);

    booked = true;
    cout << "Room " << id << " booked from " << startTime << " to " << endTime << "." << endl;
}

void Room::cancelBooking() {
    if (!booked) {
        cout << "Room " << id << " is not booked. Cannot cancel booking." << endl;
        return;
    }
    booked = false;
    startTime = "";
    endTime = "";
    cout << "Booking for Room " << id << " cancelled successfully." << endl;
}

void Room::status() {
    bool occupied = (occupants >= 2);
    cout << "Room " << id << " Status:" << endl;
    cout << "  Occupants: " << occupants << "/" << capacity << endl;
    if (booked)
        cout << "  Booked: Yes (" << startTime << " to " << endTime << ")" << endl;
    else
        cout << "  Booked: No" << endl;
    cout << "  AC: " << (occupied ? "ON" : "OFF") << endl;
    cout << "  Lights: " << (occupied ? "ON" : "OFF") << endl;
}
