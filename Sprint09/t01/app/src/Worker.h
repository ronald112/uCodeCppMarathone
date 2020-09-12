#pragma once
#include <utility>
#include <thread>
#include <vector>

class Worker {
 public:
    Worker() = default;
    ~Worker();
    Worker(const Worker &worker) = delete;
    Worker(Worker &&worker) = delete;
    Worker& operator=(Worker &&worker) = delete;

    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&... args) {
        m_workerThreads.push_back(std::thread(func, args...));
    }

    void joinAllThreads();

 private:
    std::vector<std::thread> m_workerThreads;
};

