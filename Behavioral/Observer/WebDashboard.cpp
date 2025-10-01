#include "WebDashboard.h"
using namespace std;

void WebDashboard::update(const string& stock, double price) {
    cout << "[WebDashboard] Display refresh: " << stock << " = $" << price << endl;
}
