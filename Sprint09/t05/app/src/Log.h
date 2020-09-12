#pragma once

#include <sstream>

#define logDebug Log::createLog(Log::LogLevel::Debug)
#define logWarning Log::createLog(Log::LogLevel::Warning)
#define logInfo Log::createLog(Log::LogLevel::Info)

class Log final {
 public:
    enum class LogLevel { Debug, Warning, Info };

    ~Log();

    static Log createLog(LogLevel level);

    template <class T>
    Log& operator<<(T const& value);

 private:
    Log(LogLevel level);

    LogLevel m_logLevel;
    std::stringstream m_inputStream;
};

template <class T>
Log& Log::operator<<(T const& value) {
    m_inputStream << value << " ";
    return *this;
}

