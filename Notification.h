#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() = default;
};

#endif
