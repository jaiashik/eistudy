#include "Observer.h"

void ACSystem::update(int roomId, bool occupied) {
    if (occupied)
        cout << "AC in Room " << roomId << " turned ON." << endl;
    else
        cout << "AC in Room " << roomId << " turned OFF." << endl;
}

void LightSystem::update(int roomId, bool occupied) {
    if (occupied)
        cout << "Lights in Room " << roomId << " turned ON." << endl;
    else
        cout << "Lights in Room " << roomId << " turned OFF." << endl;
}
