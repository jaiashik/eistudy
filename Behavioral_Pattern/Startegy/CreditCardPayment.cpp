#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const string& number) {
    cardNumber = number;
}

void CreditCardPayment::pay(double amount) {
    cout << "[CreditCard] Paid $" << amount << " using Card " << cardNumber << endl;
}
