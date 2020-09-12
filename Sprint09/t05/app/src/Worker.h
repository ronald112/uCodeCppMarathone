#pragma once

#include <future>
#include <thread>

class Worker {
 public:
    Worker() = default;
    virtual ~Worker() = default;

    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

    void start();
    void stop();
    void join();
    bool isRunning() const;

 protected:
    virtual void run() = 0;

 private:
    std::atomic_bool m_isRunning{false};
    std::thread m_worker;
};
