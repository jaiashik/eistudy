#ifndef CRYPTOPAYMENT_H
#define CRYPTOPAYMENT_H

#include "PaymentStrategy.h"

class CryptoPayment : public PaymentStrategy {
private:
    string wallet;
public:
    CryptoPayment(const string& w);
    void pay(double amount) override;
};

#endif
