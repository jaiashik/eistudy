#ifndef EMAILALERT_H
#define EMAILALERT_H

#include "Observer.h"
#include <iostream>

class EmailAlert : public Observer {
public:
    void update(const string& stock, double price) override;
};

#endif
