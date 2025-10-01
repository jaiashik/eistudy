#include "PaymentContext.h"
#include "CreditCardPayment.h"
#include "PayPalPayment.h"
#include "CryptoPayment.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    PaymentContext context;

    cout << "=== Payment Processing ===" << endl;

    context.setStrategy(make_unique<CreditCardPayment>("1234-5678-9876"));
    context.checkout(250.0);

    context.setStrategy(make_unique<PayPalPayment>("okaxis@123"));
    context.checkout(99.9);

    context.setStrategy(make_unique<CryptoPayment>("wallet007"));
    context.checkout(500.5);

    return 0;
}
