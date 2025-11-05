#include "Vector.h"

#pragma once
namespace tea {

template <typename T>
class Queue {
   private:
    size_t m_size;
    Vector<T> m_inVec;
    Vector<T> m_outVec;

    void moveToOut() {
        while (!m_inVec.empty()) {
            m_outVec.push_back(m_inVec.back());
            m_inVec.pop_back();
        }
    }

   public:
    Queue() {
    }
    ~Queue() {
    }
    Queue(const Queue& other) {
    }
    Queue(Queue&& other) {
    }
    Queue& operator=(const Queue& other) {
    }
    Queue& operator=(Queue&& other) {
    }

    void push(const T& elem) {
        m_inVec.push_back(elem);
        m_size++;
    }

    T& top() {
        // assert that the size of m is nonzero
        if (m_outVec.empty()) {
            moveToOut();
        }
        return m_outVec.back();
    }

    T& pop() {
        if (m_outVec.empty()) {
            moveToOut();
        }

        m_outVec.pop_back();
    }
}
};  // namespace tea