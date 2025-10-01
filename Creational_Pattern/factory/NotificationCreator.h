#ifndef NOTIFICATION_CREATOR_H
#define NOTIFICATION_CREATOR_H

#include "Notification.h"
#include <memory>

class NotificationCreator {
public:
    virtual std::unique_ptr<Notification> createNotification() = 0;
    virtual ~NotificationCreator() = default;
};

#endif
