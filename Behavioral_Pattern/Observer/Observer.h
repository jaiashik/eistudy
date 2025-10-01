#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
using namespace std;

class Observer {
public:
    virtual void update(const string& stock, double price) = 0;
    virtual ~Observer() {}
};

#endif
