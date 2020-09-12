#include <Worker.h>

void Worker::joinAllThreads() {
    for (auto& i : m_workerThreads) {
        i.join();
    }
    m_workerThreads.clear();
}

Worker::~Worker() {
    joinAllThreads();
}
