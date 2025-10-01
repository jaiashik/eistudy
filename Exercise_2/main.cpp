#include <iostream>
#include <sstream>
#include <algorithm>
#include "OfficeManager.h"
#include "Command.h"
using namespace std;

int main() {
    OfficeManager *manager = OfficeManager::getInstance();

    cout << "Welcome to Smart Office Facility System" << endl;
    cout << "Type 'help' to see available commands, 'exit' to quit." << endl;

    string line;
    while (true) {
        cout << "> ";
        getline(cin, line);
        if (line == "exit") break;
        if (line.empty()) continue;

        // Convert input to lowercase for case-insensitive commands
        string lowerLine = line;
        transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

        stringstream ss(lowerLine);
        string cmd;
        ss >> cmd;

        if (cmd == "help") {
            cout << "Available commands:\n"
                 << "  config room count <n>\n"
                 << "  config room max capacity <roomId> <capacity>\n"
                 << "  add occupant <roomId> <count>\n"
                 << "  block room <roomId> <start> <duration>\n"
                 << "  cancel room <roomId>\n"
                 << "  room status <roomId>\n"
                 << "  exit\n";
        }
        else if (cmd == "config") {
            string sub;
            ss >> sub;
            if (sub == "room") {
                string type;
                ss >> type;

                if (type == "count") {
                    int n;
                    if (!(ss >> n)) {
                        cout << "Invalid room number." << endl;
                        continue;
                    }
                    if (n < 1 || n > 100) {
                        cout << "The maximum allowed number of rooms is 100. Please select a number under or equal to 100." << endl;
                        continue;
                    }
                    manager->configureRooms(n);
                }
                else if (type == "max") {
                    string dummy; int roomId, cap;
                    ss >> dummy >> roomId >> cap;
                    auto r = manager->getRoom(roomId);
                    if (r) r->setCapacity(cap);
                    else cout << "Room " << roomId << " does not exist." << endl;
                }
            }
        }
        else if (cmd == "block") {
            string dummy; int id, dur; string time;
            if (!(ss >> dummy >> id >> time >> dur)) { cout << "Invalid input." << endl; continue; }
            auto r = manager->getRoom(id);
            BookRoomCommand c(r, time, dur);
            c.execute();
        }
        else if (cmd == "cancel") {
            string dummy; int id;
            if (!(ss >> dummy >> id)) { cout << "Invalid input." << endl; continue; }
            auto r = manager->getRoom(id);
            CancelRoomCommand c(r);
            c.execute();
        }
        else if (cmd == "add") {
            string dummy; int id, occ;
            if (!(ss >> dummy >> id >> occ)) { cout << "Invalid input." << endl; continue; }
            auto r = manager->getRoom(id);
            AddOccupantCommand c(r, occ);
            c.execute();
        }
        else if (cmd == "room") {
            string sub; int id;
            ss >> sub >> id;
            auto r = manager->getRoom(id);
            RoomStatusCommand c(r);
            c.execute();
        }
        else {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}
