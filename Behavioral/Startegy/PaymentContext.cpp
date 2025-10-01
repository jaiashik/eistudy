#include "PaymentContext.h"
#include <iostream>
using namespace std;

void PaymentContext::setStrategy(unique_ptr<PaymentStrategy> s) {
    strategy = move(s);
}

void PaymentContext::checkout(double amount) {
    if (!strategy) {
        cout << "[Error] No payment method selected!" << endl;
        return;
    }
    strategy->pay(amount);
}
