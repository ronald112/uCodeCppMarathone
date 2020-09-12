#include "LoggerWorker.h"
#include <chrono>
#include <iomanip>

LoggerWorker::~LoggerWorker() {
    stop();
    m_condVar.notify_one();
    join();
    m_logFileStream.close();
}

static std::string getCuteTime() {
    time_t in_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::stringstream ss;

    ss << std::put_time(std::localtime(&in_time_t), "%d_%m_%YT%H_%M_%S");
    return ss.str();
}

LoggerWorker::LoggerWorker() {
    m_logFileStream.open(getCuteTime() + ".txt");
    start();
}

LoggerWorker& LoggerWorker::getLogger() {
    if (m_logger == nullptr)
        m_logger = std::shared_ptr<LoggerWorker>();
    return *m_logger;
}

void LoggerWorker::log(Log::LogLevel level, const std::string& logMessage) {
    std::unique_lock<std::mutex> lock(m_runMutex);
    m_logQueue.push(LogMessage{logMessage, level});
    lock.~unique_lock();
    m_condVar.notify_one();
}

static std::string getLogLevel(Log::LogLevel level) {
    if (level == Log::LogLevel::Info)
        return "Info";
    else if (level == Log::LogLevel::Debug)
        return "Debug";
    else if (level == Log::LogLevel::Warning)
        return "Warning";
    else
        return "";
}

void LoggerWorker::run() {
    while(isRunning() && !m_logQueue.empty()) {
        std::unique_lock<std::mutex> lck(m_runMutex);
        m_condVar.wait(lck, [this] {
            return !this->isRunning() || !this->m_logQueue.empty();
        });
        auto elem = m_logQueue.front();
        m_logFileStream << "[" << getCuteTime() << "] " << "[" << getLogLevel(elem.logLevel) << "] " << elem.message << std::endl;
        m_logQueue.pop();
    }
}

