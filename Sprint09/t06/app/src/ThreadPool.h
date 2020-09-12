#pragma once

#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <future>
#include <iostream>

class ThreadPool final {
 public:
    explicit ThreadPool(size_t threads);
    ~ThreadPool();

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(const ThreadPool&&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    template <typename Function, class... Args>
    auto enqueueTask(Function&& func, Args&&... args) {
        using return_type = typename std::result_of<Function(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Function>(func), std::forward<Args>(args)...)
        );
        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(m_queueMutex);
            m_taskQueue.emplace([task](){(*task)();});
        }
        m_condVar.notify_one();
        return res;
    }

 private:
    std::vector<std::thread> m_workerThreads;
    std::queue<std::packaged_task<void()>> m_taskQueue;
    std::condition_variable m_condVar;
    std::mutex m_queueMutex;
    bool m_isRunning{true};
};
