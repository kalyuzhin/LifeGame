//
// Created by Марк Калюжин on 12.11.2023.
//

#include <iostream>
#include <ostream>
#include <istream>
#include "vector.h"

#ifndef EXTRATASK2_MATRIX_H
#define EXTRATASK2_MATRIX_H

//class Matrix to display game field
template<typename T>
class Matrix {
private:
    size_t _rows;
    size_t _columns;
    Vector<Vector<T>> _matrix;

public:
    explicit Matrix(size_t rows = 8, size_t columns = 16) : _rows(rows), _columns(columns), _matrix(rows) {
        for (size_t i = 0; i != _rows; ++i) {
            _matrix[i].resize(_columns);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        for (size_t i = 0; i != matrix._rows; ++i) {
            for (size_t j = 0; j != matrix._columns; ++j) {
                os << matrix(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }

    //resize operation
    Matrix &resize(size_t rows, size_t columns) {
        _rows = rows;
        _columns = columns;
        _matrix(_rows);
        for (size_t i = 0; i != _rows; ++i) {
            _matrix[i].resize(_columns);
        }
        return *this;
    }

    //Fill function
    Matrix &fill(const T &value) {
        for (size_t i = 0; i != _rows; ++i) {
            for (size_t j = 0; j != _columns; ++j) {
                _matrix[i][j] = value;
            }
        }
        return *this;
    }

    T &operator()(size_t i, size_t j) const {
        return _matrix[i][j];
    }

};


#endif //EXTRATASK2_MATRIX_H
