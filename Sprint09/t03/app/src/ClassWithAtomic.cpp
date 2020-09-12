#include "ClassWithAtomic.h"

void ClassWithAtomic::addToInt(int addValue) {
    for (int i = 0; i < addValue; i++)  {
        m_int++;
    }
}
void ClassWithAtomic::subtractFromInt(int subtractValue) {
    for (int i = 0; i < subtractValue; i++)  {
        m_int--;
    }
}

void ClassWithAtomic::pushToVector(int value) {
    std::lock_guard l(m_vecMutex);
    m_vector.push_back(value);
}
void ClassWithAtomic::eraseFromVector(int value) {
    std::lock_guard l(m_vecMutex);
    m_vector.erase(
    std::remove_if(m_vector.begin(), m_vector.end(), [value](int &obj) {
        return obj == value;
    }),
    m_vector.end());
}

int ClassWithAtomic::getInt() const {
    return m_int;
}
std::vector<int> ClassWithAtomic::getVector() const {
    return m_vector;
}

