#include "ConfigSingleton.h"
#include "Database.h"
#include "Logger.h"
#include <iostream>

int main() {
    ConfigSingleton &config = ConfigSingleton::getInstance();

    Logger::info("Application started.");
    std::cout << "Before modification: " << config.getData("APP_MODE") << std::endl;

    config.setData("APP_MODE", "production");

    Database db;
    db.connect();

    std::cout << std::endl;

    Logger::info("Applying another update...");
    std::cout << "Current mode: " << config.getData("APP_MODE") << std::endl;

    config.setData("APP_MODE", "development");
    Database db1;
    db1.connect();

    Logger::info("Application shutting down.");
    return 0;
}
