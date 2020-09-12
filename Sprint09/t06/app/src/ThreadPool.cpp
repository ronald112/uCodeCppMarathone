#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threads) {
    for (size_t i = 0; i < threads; ++i) {
        m_workerThreads.emplace_back(std::thread([this]() {
            std::packaged_task<void()> task;
            while (m_isRunning && !m_taskQueue.empty()) {
                {
                    std::unique_lock<std::mutex> lck(m_queueMutex);

                    m_condVar.wait(lck, [this] {
                        return !m_isRunning || !m_taskQueue.empty();
                    });

                    task = std::move(m_taskQueue.front());
                    m_taskQueue.pop();
                }
            task();
            }
        }));
    }
}

ThreadPool::~ThreadPool() {
    m_isRunning = false;
    m_condVar.notify_all();
    for (auto &m_worker_thread : m_workerThreads) {
        if (m_worker_thread.joinable())
            m_worker_thread.join();
    }
}
