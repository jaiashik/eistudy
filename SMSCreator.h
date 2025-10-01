#ifndef SMS_CREATOR_H
#define SMS_CREATOR_H

#include "NotificationCreator.h"
#include "SMSNotification.h"

class SMSCreator : public NotificationCreator {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<SMSNotification>();
    }
};

#endif
