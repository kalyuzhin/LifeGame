//
// Created by Марк Калюжин on 12.11.2023.
//

#include "matrix.h"
#include <random>

#ifndef EXTRATASK2_LIFE_GAME_H
#define EXTRATASK2_LIFE_GAME_H

class LifeGame : public Matrix<char> {
private:

    char _dead_cells;

    char _alive_cells;

    void fill_random() {
        std::random_device rd;
        for (size_t i = 0; i != this->_rows; ++i) {
            for (size_t j = 0; j != this->_columns; ++j) {
                _matrix[i][j] = rd() % 10 == 0 ? _alive_cells : _dead_cells;
            }
        }
    }

    size_t count_neighbours(size_t row, size_t column) {
        size_t result = 0;
        result += row == _rows - 1 ? this->operator()(0, column) == _alive_cells :
                  this->operator()(row + 1, column) == _alive_cells;
        result += column == _columns - 1 ? this->operator()(row, 0) == _alive_cells :
                  this->operator()(row, column + 1) == _alive_cells;
        result += row == 0 ? this->operator()(_rows - 1, column) == _alive_cells : this->operator()(row - 1, column) ==
                                                                                   _alive_cells;
        result +=
                column == 0 ? this->operator()(row, _columns - 1) == _alive_cells : this->operator()(row, column - 1) ==
                                                                                    _alive_cells;
        return result;
    }

    void update_generation() {
        LifeGame new_generation(_rows, _columns, _dead_cells, _alive_cells);
        for (size_t i = 0; i != _rows; ++i) {
            for (size_t j = 0; j != _columns; ++j) {
                if (count_neighbours(i, j) == 3 && this->operator()(i, j) == _dead_cells) {
                    new_generation(i, j) = _alive_cells;
                }
                if ((count_neighbours(i, j) == 3 || count_neighbours(i, j)) == 2 &&
                    this->operator()(i, j) == _alive_cells) {
                    new_generation(i, j) = _alive_cells;
                } else {
                    new_generation(i, j) = _dead_cells;
                }
            }
        }
    }

public:
    explicit LifeGame(size_t rows, size_t columns, const char &dead_cells = '#', const char &alive_cells = '*')
            : Matrix<char>(rows, columns), _dead_cells(dead_cells), _alive_cells(alive_cells) {
        this->fill(dead_cells);
        fill_random();
    }


};

#endif //EXTRATASK2_LIFE_GAME_H
