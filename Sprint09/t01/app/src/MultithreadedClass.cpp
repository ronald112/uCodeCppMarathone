#include "MultithreadedClass.h"

int MultithreadedClass::getInt() const {
    return m_int;
}

void MultithreadedClass::add(int addValue) {
    m_mutex.lock();
    for (int i = 0; i < addValue; i++) {
        m_int++;
    }
    m_mutex.unlock();
}

void MultithreadedClass::subtract(int subtractValue) {
    std::lock_guard<std::mutex> lck(m_mutex);
    for (int i = 0; i < subtractValue; i++) {
        m_int--;
    }
}
