#pragma once

#include <cstddef>
#include <initializer_list>

namespace CBL {
template <class T>
class Vector {
    public:
    using iterator = T*;

    Vector()  {
        m_buffer = nullptr;
        m_size = 0;
        m_capacity = 0;
    };
    explicit Vector(size_t size) {
        m_buffer = new T[size];
        m_size = size;
        m_capacity = size;
    };
    Vector(size_t size, const T& value) : Vector(size) {
        for (size_t i = 0; i < m_size; i++) {
            m_buffer[i] = value;
        }
    };
    Vector(iterator first, iterator last) : Vector(std::distance(first, last)) {
        std::copy(first, last, m_buffer);
    };
    Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
        std::copy(lst.begin(), lst.end(), m_buffer);
    };
    Vector(const Vector<T>& other) : Vector(std::distance(other.begin(), other.end())){
        std::copy(other.begin(), other.end(), this->m_buffer);
    };
    ~Vector() {
        delete []m_buffer;
    };

    Vector<T>& operator=(const Vector<T>& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        delete[]m_buffer;
        m_buffer = new T[m_capacity];
        std::copy(other.m_buffer, other.m_buffer + other.size(), m_buffer);
        return *this;
    };
    bool operator==(const Vector<T>& other) const {
        if (other.size() != m_size)
            return false;
        for (size_t i = 0; i < other.size(); i++) {
            if (m_buffer[i] != other.m_buffer[i])
                return false;
        }
        return true;
    };
    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    };
    bool operator<(const Vector<T>& other) const {
        for (size_t i = 0; i < (other.m_size < m_size ? other.m_size : m_size); i++) {
            if (m_buffer[i] > other.m_buffer[i])
                return false;
        }
        if (m_size > other.m_size)
            return false;
        return true;
    };
    bool operator>(const Vector<T>& other) const {
        return !(*this < other);
    };
    bool operator<=(const Vector<T>& other) const {
        return *this < other || *this == other;
    };
    bool operator>=(const Vector<T>& other) const {
        return *this > other || *this == other;
    };

    // iterators
    iterator begin() const {
        return m_buffer;
    };
    iterator end() const {
        return m_buffer + m_size;
    };

    // capacity
    size_t size() const  {
      return m_size;
    };
    size_t capacity() const {
        return m_capacity;
    };
    bool isEmpty() const {
        return begin() == end();
    };
    void resize(size_t size, const T& value = T()) {
        T* new_vector = NULL;
        if (size > m_capacity) {
            new_vector = new T[size];
            size_t it = 0;
            for (; it < m_size; ++it) {
                new_vector[it] = m_buffer[it];
            }
            for (; it < size - m_size; ++it) {
                new_vector[it] = value;
            }
        } else if (size < m_capacity) {
            new_vector = new T[size];
            std::copy(m_buffer, m_buffer + size, new_vector);
        }
        delete[] m_buffer;
        m_size = size;
        m_buffer = new_vector;
    };
    void reserve(size_t size) {
        if (size > m_capacity) {
            m_capacity = size;
            T*buffer = new T[m_capacity];
            std::copy(m_buffer, m_buffer + size, buffer);
            delete[]m_buffer;
            m_buffer = buffer;
        }
    };

    // element access
    T& operator[](size_t index) const {
        return m_buffer[index];
    };
    T& at(size_t index) const {
        if (!(index < size()))
            throw(std::out_of_range("Vector: out_of_range"));
        return m_buffer[index];
    };
    T* data() const {
        return m_buffer;
    };

    // modifiers
    void push_back(const T& value) {
        size_t size = m_size;
        m_size++;
        if (m_capacity == 0 || m_capacity < 0) {
            m_capacity = 1;
            m_buffer = new T[m_capacity];
        }
        if (m_size > m_capacity) {
            m_capacity *= 2;
            T* buffer = new T[m_capacity];
            std::copy(m_buffer, m_buffer + size, buffer);
            delete []m_buffer;
            m_buffer = buffer;
        }
        m_buffer[m_size - 1] = value;
    };
    void pop_back() {
        T*new_vector = new T[--m_size];
        std::copy(m_buffer, m_buffer + m_size, new_vector);
        delete[] m_buffer;
        m_buffer = new_vector;
    };
    iterator insert(iterator pos, const T& value) {
        iterator iter;
        size_t distance = std::distance(begin(), pos);

        if (distance == m_size) {
            push_back(value);
            iter = m_buffer + m_size - 1;
        }
        else {
            m_size++;
            if (m_size > m_capacity) {
                m_capacity *= 2;
                T* buffer = new T[m_capacity];
                std::copy(m_buffer, m_buffer + m_size - 1, buffer);
                delete []m_buffer;
                m_buffer = buffer;
            }
            iter = m_buffer + distance;
            for(iterator cur = (m_buffer + m_size - 1); cur != iter; --cur) {
                *(cur) = *(cur - 1);
            }
            m_buffer[distance] = value;
        }
        return iter;
    };
    iterator erase(iterator pos) {
        if (pos == (m_buffer + m_size)) {
            pop_back();
            return m_buffer + m_size;
        }
        T* buffer = new T[--m_size];
        iterator res = buffer;
        for (size_t i = 0, j = 0; i < m_size + 1; j++) {
            if (*pos != m_buffer[j])
                buffer[i++] = m_buffer[j];
            else
                res += i;
        }
        delete []m_buffer;
        m_buffer = buffer;
        return res;
    };
    iterator erase(iterator first, iterator last) {
        size_t n_size = std::distance(first, last);
        m_size -= n_size;
        T* buffer = new T[m_size];
        size_t i = 0;
        size_t j = 0;

        for (; i < std::distance(m_buffer, first); i++) {
            buffer[i] = m_buffer[j++];
        }
        j += n_size;
        for (; i < m_size; i++) {
            buffer[i] = m_buffer[j++];
        }
        delete[]m_buffer;
        m_buffer = buffer;
        if (m_size == 0)
            return nullptr;
        return first;
    };
    void clear() {
        resize(0);
    };

    private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};
} // end namespace CBL