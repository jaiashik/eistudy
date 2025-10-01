#ifndef PUSH_CREATOR_H
#define PUSH_CREATOR_H

#include "NotificationCreator.h"
#include "PushNotification.h"

class PushCreator : public NotificationCreator {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<PushNotification>();
    }
};

#endif
