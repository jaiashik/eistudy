#include "EmailAlert.h"
using namespace std;

void EmailAlert::update(const string& stock, double price) {
    cout << "[EmailAlert] Sending email: " << stock << " now $" << price << endl;
}
