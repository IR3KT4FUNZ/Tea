#include <cstddef>
#include <utility>
#pragma once

namespace tea {

template <typename T>
class Vector {
   private:
    size_t m_capacity;
    size_t m_size;
    T* m_arr;

   public:
    class Iterator {
       private:
        T* m_ptr;

       public:
        Iterator(T* ptr) : m_ptr{ptr} {
        }
        T& operator*() const {
            return *m_ptr;
        }

        Iterator& operator++() {
            m_ptr += 1;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return (m_ptr != other.m_ptr);
        }
    };

    Vector() : m_capacity{1}, m_size{0}, m_arr{new T[1]} {
    }

    Vector(const Vector& other)
        : m_capacity{other.m_capacity}, m_size{other.m_size}, m_arr{new T[other.m_capacity]} {
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = other.m_arr[i];
        }
    }

    Vector(Vector&& other)
        : m_capacity{other.m_capacity}, m_size{other.m_size}, m_arr{other.m_arr} {
        other.m_arr = nullptr;
    }

    Vector& operator=(const Vector& other) {
        Vector copy = Vector(other);
        m_capacity = copy.m_capacity;
        m_size = copy.m_size;
        m_arr = copy.m_arr;

        return *this;
    }

    Vector& operator=(Vector&& other) {
        if (*this == other) {
            return this;
        }

        m_capacity = other.m_capacity;
        m_size = other.m_size;
        delete[] m_arr;
        m_arr = other.m_arr;
        other.m_arr = nullptr;

        return *this;
    }

    ~Vector() {
        delete[] m_arr;
    }

    bool resize(size_t newSize) {
        if (newSize < m_size) {
            return false;
        }

        T* newArr = new T[newSize];
        for (int i = 0; i < m_size; i++) {
            newArr[i] = m_arr[i];
        }

        delete[] m_arr;
        m_arr = newArr;
        m_capacity = newSize;

        return true;
    }

    void shrinkToFit() {
        resize(m_size);
    }

    void push_back(const T& elem) {
        if (m_size == m_capacity) {
            resize(m_capacity * 2);
            m_capacity *= 2;
        }
        m_arr[m_size] = elem;
        m_size++;
    }

    void push_back(T&& elem) {
        if (m_size == m_capacity) {
            resize(m_capacity * 2);
            m_capacity *= 2;
        }

        m_arr[m_size] = std::move(elem);
        m_size++;
    }

    void pop_back() {
        (m_arr + (m_size - 1))->~T();
        m_size -= 1;
    }

    bool isEmpty() const {
        return (m_size == 0);
    }

    T& back() {
        return m_arr[m_size - 1];
    }

    size_t size() {
        return m_size;
    }
};

}  // namespace tea