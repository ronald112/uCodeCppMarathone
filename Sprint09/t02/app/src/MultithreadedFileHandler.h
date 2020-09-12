#pragma once

#include <condition_variable>
#include <mutex>
#include <string>

class MultithreadedFileHandler {
 public:
    MultithreadedFileHandler() = default;
    ~MultithreadedFileHandler() = default;

    void processFile();
    void loadFile(const std::string& fileName);

 private:
    std::string m_file;
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_fileLoaded{false};
};
