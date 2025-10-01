#ifndef MOBILEAPP_H
#define MOBILEAPP_H

#include "Observer.h"
#include <iostream>

class MobileApp : public Observer {
public:
    void update(const string& stock, double price) override;
};

#endif
