//
// Created by Марк Калюжин on 12.11.2023.
//

#include <iostream>
#include <ostream>
#include <istream>
#include <cassert>
#include <algorithm>

#ifndef EXTRATASK2_VECTOR_H
#define EXTRATASK2_VECTOR_H

//Vector class from lectures
template<typename T>
class Vector {
private:
    size_t _size;

    T *_data;
public:
    //Default constructor
    Vector(size_t size) : _size(size) {
        _data = new T[size];
        std::fill(_data, _data + size, T());
    }


    //Copy constructor
    Vector(const Vector &vector) : _size(vector._size) {
        _data = new T[_size];
        std::copy(vector._data, vector._data + _size, _data);
    }

    //Move constructor
    Vector(Vector &&vector) noexcept {
        _size = vector._size;
        _data = vector._data;
        vector._data = nullptr;
    }

    //Operator []
    T &operator[](size_t i) const {
        return _data[i];
    }

    //Copy assignment operation
    T &operator=(Vector<T> &other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            std::copy(other._data, other._data + other._size, _data);
        }
        return *this;
    }

    //Move assignment operation
    Vector &operator=(Vector &&vector) noexcept {
        delete[] _data;
        _size = vector._size;
        _data = vector._data;
        vector._data = nullptr;
        return *this;
    }

    //Destructor
    ~Vector() {
        delete[] _data;
    }

    //Getter of _size
    size_t getSize() const {
        return _size;
    }

    //resize operation
    Vector &resize(size_t size, const T &fill_with = T()) {
        delete[] _data;
        _size = size;
        _data = new T[_size];
        std::fill(_data, _data + _size, fill_with);
    }

    //std::cout operation
    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
        for (size_t i = 0; i != vector._size; ++i) {
            os << vector[i] << " ";
        }
        return os;
    }

    //std::cin operation
    friend std::istream &operator>>(std::istream &is, Vector<T> &vector) {
        for (size_t i = 0; i != vector._size; ++i) {
            T a;
            is >> a;
            vector._data[i] = a;
        }
        return is;
    }
};

//operator +
template<typename T>
Vector<T> operator+(const Vector<T> &v1, const Vector<T> &v2) {
    assert(v1.getSize() == v2.getSize());
    Vector<T> result(v1.getSize());
    for (size_t i = 0; i != v1.getSize(); ++i) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}

#endif //EXTRATASK2_VECTOR_H
