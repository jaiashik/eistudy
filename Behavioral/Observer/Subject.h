#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <memory>
using namespace std;

class Subject {
public:
    virtual void attach(shared_ptr<Observer> obs) = 0;
    virtual void detach(shared_ptr<Observer> obs) = 0;
    virtual void notify(const string& stock) = 0;
    virtual ~Subject() {}
};

#endif
