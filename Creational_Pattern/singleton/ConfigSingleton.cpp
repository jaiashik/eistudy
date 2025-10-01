#include "ConfigSingleton.h"
#include "Logger.h"

ConfigSingleton::ConfigSingleton() {
    configMap["DATABASE_HOST"] = "localhost";
    configMap["DATABASE_USER"] = "admin";
    configMap["DATABASE_PASS"] = "jai12345";
    configMap["APP_MODE"] = "development";
}

ConfigSingleton& ConfigSingleton::getInstance() {
    static ConfigSingleton instance;
    return instance;
}

void ConfigSingleton::setData(const std::string &key, const std::string &value) {
    if (key.empty()) {
        Logger::warn("Attempted to set an empty key.");
        return;
    }
    configMap[key] = value;
    Logger::info("Configuration updated: " + key + " = " + value);
}

std::string ConfigSingleton::getData(const std::string &key) {
    if (configMap.find(key) == configMap.end()) {
        Logger::error("Key not found: " + key);
        throw std::runtime_error("Configuration key missing: " + key);
    }
    return configMap[key];
}
