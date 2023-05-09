#include <list>
#include <stdexcept>
#include <functional>

template <typename T>
struct MyComparator {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template <typename T>
class PriorityQueue {
public:
    void push(const T& t) {
        auto it = m_queue.begin();
        while (it != m_queue.end() && comp(*it, t)) {
            ++it;
        }
        m_queue.insert(it, t);
    }

    T poll() {
        if (m_queue.empty()) {
            throw std::out_of_range("Priority queue is empty!");
        }
        T result = m_queue.front();
        m_queue.pop_front();
        return result;
    }

private:
    std::list<T> m_queue;
    MyComparator<T> comp;
};
