#ifndef SMS_NOTIFICATION_H
#define SMS_NOTIFICATION_H

#include "Notification.h"
#include "Logger.h"

class SMSNotification : public Notification {
public:
    void send() override {
        Logger::info("SMS sent successfully.");
    }
};

#endif
