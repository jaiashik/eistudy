#ifndef EMAIL_CREATOR_H
#define EMAIL_CREATOR_H

#include "NotificationCreator.h"
#include "EmailNotification.h"

class EmailCreator : public NotificationCreator {
public:
    std::unique_ptr<Notification> createNotification() override {
        return std::make_unique<EmailNotification>();
    }
};

#endif
