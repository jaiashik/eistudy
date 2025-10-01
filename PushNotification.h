#ifndef PUSH_NOTIFICATION_H
#define PUSH_NOTIFICATION_H

#include "Notification.h"
#include "Logger.h"

class PushNotification : public Notification {
public:
    void send() override {
        Logger::info("Push notification sent successfully.");
    }
};

#endif
