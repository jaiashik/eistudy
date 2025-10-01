#include "PayPalPayment.h"

PayPalPayment::PayPalPayment(const string& u) {
    upi = u;
}

void PayPalPayment::pay(double amount) {
    cout << "[PayPal] Paid $" << amount << " using PayPal account " << upi << endl;
}
