#ifndef COMMAND_H
#define COMMAND_H

#include "Room.h"
#include <memory>
#include <string>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class BookRoomCommand : public Command {
private:
    shared_ptr<Room> room;
    string time;
    int duration;
public:
    BookRoomCommand(shared_ptr<Room> r, string t, int d);
    void execute() override;
};

class CancelRoomCommand : public Command {
private:
    shared_ptr<Room> room;
public:
    CancelRoomCommand(shared_ptr<Room> r);
    void execute() override;
};

class AddOccupantCommand : public Command {
private:
    shared_ptr<Room> room;
    int count;
public:
    AddOccupantCommand(shared_ptr<Room> r, int c);
    void execute() override;
};

class RoomStatusCommand : public Command {
private:
    shared_ptr<Room> room;
public:
    RoomStatusCommand(shared_ptr<Room> r);
    void execute() override;
};

#endif
