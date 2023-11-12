//
// Created by Марк Калюжин on 12.11.2023.
//

#include <iostream>
#include <ostream>
#include <istream>
#include "vector.h"

#ifndef EXTRATASK2_MATRIX_H
#define EXTRATASK2_MATRIX_H

template<typename T>
class Matrix {
private:
    size_t _rows;
    size_t _columns;
    Vector<Vector<T>> _matrix;

public:
    Matrix(size_t rows = 8, size_t columns = 16) : _rows(rows), _columns(columns) {
        _matrix =
        for (size_t i = 0; i != _matrix.getSize(); ++i) {
            _matrix[i].resize(_columns);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        for (size_t i = 0; i != matrix._rows; ++i) {
            for (size_t j = 0; j != matrix._columns; ++j) {
                os << matrix[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    T &operator()(size_t i, size_t j) const {
        return _matrix[i][j];
    }
};


#endif //EXTRATASK2_MATRIX_H
