#include "Command.h"
#include <iostream>

BookRoomCommand::BookRoomCommand(shared_ptr<Room> r, string t, int d) : room(r), time(t), duration(d) {}
void BookRoomCommand::execute() { if(room) room->book(time, duration); else cout<<"Invalid room number."<<endl; }

CancelRoomCommand::CancelRoomCommand(shared_ptr<Room> r) : room(r) {}
void CancelRoomCommand::execute() { if(room) room->cancelBooking(); else cout<<"Invalid room number."<<endl; }

AddOccupantCommand::AddOccupantCommand(shared_ptr<Room> r, int c) : room(r), count(c) {}
void AddOccupantCommand::execute() { if(room) room->setOccupants(count); else cout<<"Room does not exist."<<endl; }

RoomStatusCommand::RoomStatusCommand(shared_ptr<Room> r) : room(r) {}
void RoomStatusCommand::execute() { if(room) room->status(); else cout<<"Room does not exist."<<endl; }
