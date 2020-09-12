#pragma once

#include <fstream>
#include <memory>
#include <queue>
#include <string>

#include "Log.h"
#include "Worker.h"

class LoggerWorker final : public Worker {
 public:
    ~LoggerWorker() override;

    static LoggerWorker& getLogger();

    void log(Log::LogLevel level, const std::string& logMessage);

 private:
    struct LogMessage {
        std::string message;
        Log::LogLevel logLevel;
    };

    LoggerWorker();

    void run() override;

    std::mutex m_runMutex;
    std::condition_variable m_condVar;
    std::ofstream m_logFileStream;
    std::queue<LogMessage> m_logQueue;

    inline static std::shared_ptr<LoggerWorker> m_logger{nullptr};
};
