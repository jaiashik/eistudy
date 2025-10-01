#include "Logger.h"

std::string Logger::getTimestamp() {
    time_t now = time(nullptr);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", localtime(&now));
    return std::string(buf);
}

void Logger::info(const std::string &message) {
    std::cout << "[INFO] " << getTimestamp() << " - " << message << std::endl;
}

void Logger::error(const std::string &message) {
    std::cerr << "[ERROR] " << getTimestamp() << " - " << message << std::endl;
}

void Logger::warn(const std::string &message) {
    std::cout << "[WARN] " << getTimestamp() << " - " << message << std::endl;
}
