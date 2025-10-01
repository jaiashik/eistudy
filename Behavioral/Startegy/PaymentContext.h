#ifndef PAYMENTCONTEXT_H
#define PAYMENTCONTEXT_H

#include "PaymentStrategy.h"
#include <memory>

class PaymentContext {
private:
    unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(unique_ptr<PaymentStrategy> s);
    void checkout(double amount);
};

#endif
