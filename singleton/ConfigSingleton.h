#ifndef CONFIGSINGLETON_H
#define CONFIGSINGLETON_H

#include <unordered_map>
#include <string>
#include <stdexcept>

class ConfigSingleton {
private:
    std::unordered_map<std::string, std::string> configMap;

    ConfigSingleton(); // private constructor
    ConfigSingleton(const ConfigSingleton&) = delete;
    ConfigSingleton& operator=(const ConfigSingleton&) = delete;

public:
    static ConfigSingleton& getInstance();

    void setData(const std::string &key, const std::string &value);
    std::string getData(const std::string &key);
};

#endif
