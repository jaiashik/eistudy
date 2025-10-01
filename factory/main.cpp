#include "EmailCreator.h"
#include "SMSCreator.h"
#include "PushCreator.h"
#include "Logger.h"
#include <iostream>

int main() {
    try {
        Logger::info("Application started.");

        std::unique_ptr<NotificationCreator> emailCreator = std::make_unique<EmailCreator>();
        auto email = emailCreator->createNotification();
        email->send();

        std::unique_ptr<NotificationCreator> smsCreator = std::make_unique<SMSCreator>();
        auto sms = smsCreator->createNotification();
        sms->send();

        std::unique_ptr<NotificationCreator> pushCreator = std::make_unique<PushCreator>();
        auto push = pushCreator->createNotification();
        push->send();

        Logger::info("Application finished successfully.");
    }
    catch (const std::exception &ex) {
        Logger::error("Unhandled exception: " + std::string(ex.what()));
    }

    return 0;
}
