#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <list>

template <typename T>
class PriorityQueue {
public:
    void push(const T& t) {
        typename std::list<T>::iterator it = m_data.begin();
        while (it != m_data.end() && *it < t) {
            ++it;
        }
        m_data.insert(it, t);
    }

    T poll() {
        if (m_data.empty()) {
            throw std::exception("Queue is empty!");
        }
        T front = m_data.front();
        m_data.pop_front();
        return front;
    }

private:
    std::list<T> m_data;
};

