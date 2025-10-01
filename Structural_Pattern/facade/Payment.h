#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class Payment {
public:
    void payfees(const string& student_name, double requiredfee, double paidfee);
};

#endif
