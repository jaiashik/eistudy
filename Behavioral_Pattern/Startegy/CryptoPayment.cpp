#include "CryptoPayment.h"

CryptoPayment::CryptoPayment(const string& w) {
    wallet = w;
}

void CryptoPayment::pay(double amount) {
    cout << "[Crypto] Paid $" << amount << " using Wallet " << wallet << endl;
}
