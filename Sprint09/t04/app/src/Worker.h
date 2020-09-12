#pragma once

#include <future>

class Worker {
 public:
    Worker() = default;
    ~Worker() = default;
    Worker(const Worker &worker) = delete;
    Worker(Worker &&worker) = delete;
    Worker& operator=(Worker &&worker) = delete;

    template <typename Function, class... Args>
    auto startAsync(Function&& func, Args&&... args) {
        return std::async(func, args...);
    }
};
