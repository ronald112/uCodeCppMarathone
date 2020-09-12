#include "LoggerWorker.h"

Log::~Log() {
    LoggerWorker& worker = LoggerWorker::getLogger();
    std::string str;
    std::getline(m_inputStream, str);
    worker.log(m_logLevel, str);
}

Log Log::createLog(LogLevel level) {
    return Log(level);
}

Log::Log(LogLevel level) : m_logLevel(level) {}