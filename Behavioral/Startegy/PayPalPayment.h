#ifndef PAYPALPAYMENT_H
#define PAYPALPAYMENT_H

#include "PaymentStrategy.h"

class PayPalPayment : public PaymentStrategy {
private:
    string upi;
public:
    PayPalPayment(const string& u);
    void pay(double amount) override;
};

#endif
