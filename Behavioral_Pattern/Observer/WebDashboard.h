#ifndef WEBDASHBOARD_H
#define WEBDASHBOARD_H

#include "Observer.h"
#include <iostream>

class WebDashboard : public Observer {
public:
    void update(const string& stock, double price) override;
};

#endif
