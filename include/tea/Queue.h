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
        while (!m_inVec.isEmpty()) {
            m_outVec.push_back(m_inVec.back());
            m_inVec.pop_back();
        }
    }

   public:
    /* ========================================================
       ====================     BIG 5    ======================
       ======================================================== */

    Queue() : m_size{0}, m_inVec{Vector<T>()}, m_outVec{Vector<T>()}, {
    }
    ~Queue() {
    }
    Queue(const Queue& other)
        : m_size{other.m_size}, m_inVec(other.m_inVec), m_outVec(other.m_outVec) {
    }
    Queue(Queue&& other) {
    }
    Queue& operator=(const Queue& other) {
    }
    Queue& operator=(Queue&& other) {
    }

    /* ========================================================
       =================  Queue Operations  ===================
       ======================================================== */

    void push(const T& elem) {
        m_inVec.push_back(elem);
        m_size++;
    }

    void push(T&& elem) {
        m_inVec.push_back(elem);
        m_size++;
    }

    void pop() {
        if (m_outVec.isEmpty()) {
            moveToOut();
        }

        m_outVec.pop_back();
    }

    T& front() {
        // assert that the size of m is nonzero
        if (m_outVec.isEmpty()) {
            moveToOut();
        }
        return m_outVec.back();
    }

    const T& front() const {
        // assert that the size of m is nonzero
        if (m_outVec.isEmpty()) {
            moveToOut();
        }
        return m_outVec.back();
    }

    /* ========================================================
       =====================  Accessors  ======================
       ======================================================== */
    bool isEmpty() {
        return (m_size == 0);
    }

    size_t size() {
        return m_size;
    }
};
}  // namespace tea