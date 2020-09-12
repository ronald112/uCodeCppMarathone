#pragma once
#include <utility>
#include <thread>

class Worker {
 public:
    Worker() = default;
    ~Worker();
    Worker(const Worker &worker) = delete;
    Worker(Worker &&worker) = delete;
    Worker& operator=(Worker &&worker) = delete;

    template <typename Function, class... Args>
    void startWorker(Function&& func, Args&&... args) {
        if (m_thread != nullptr)
            joinThread();
        m_thread = new std::thread(func, args...);
    }

    void joinThread();

 private:
    std::thread* m_thread{nullptr};
};
