#ifndef EMAIL_NOTIFICATION_H
#define EMAIL_NOTIFICATION_H

#include "Notification.h"
#include "Logger.h"

class EmailNotification : public Notification {
public:
    void send() override {
        Logger::info("Email sent successfully.");
    }
};

#endif
