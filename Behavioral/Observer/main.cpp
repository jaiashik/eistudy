#include "StockMarket.h"
#include "MobileApp.h"
#include "WebDashboard.h"
#include "EmailAlert.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    StockMarket market;

    auto mobile = make_shared<MobileApp>();
    auto web = make_shared<WebDashboard>();
    auto email = make_shared<EmailAlert>();

    // Attach observers
    market.attach(mobile);
    market.attach(web);
    market.attach(email);

    cout << "--- Stock Updates ---" << endl;
    market.setPrice("Bitcoin", 15000);
    market.setPrice("Doge", 50);

    cout << "\n--- Detaching Email Alerts ---\n" << endl;
    market.detach(email);

    market.setPrice("Bitcoin", 20000);
    market.setPrice("Doge", 30);

    return 0;
}
