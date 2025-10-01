#include "Database.h"
#include "ConfigSingleton.h"
#include "Logger.h"
#include <iostream>

void Database::connect() {
    try {
        ConfigSingleton& config = ConfigSingleton::getInstance();

        Logger::info("Connecting to database...");
        std::cout << "Host: " << config.getData("DATABASE_HOST") << std::endl
                  << "User: " << config.getData("DATABASE_USER") << std::endl
                  << "App Mode: " << config.getData("APP_MODE") << std::endl;

    } catch (const std::exception &ex) {
        Logger::error("Database connection failed: " + std::string(ex.what()));
    }
}
