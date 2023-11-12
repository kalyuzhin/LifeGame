//
// Created by Марк Калюжин on 12.11.2023.
//

#include "matrix.h"

#ifndef EXTRATASK2_LIFE_GAME_H
#define EXTRATASK2_LIFE_GAME_H

class LifeGame : public Matrix<char> {
private:

public:
    explicit LifeGame(size_t rows, size_t columns, const char &dead_cells = '#', const char &alive_cells = '*')
            : Matrix<char>(rows, columns) {
        this->fill(dead_cells);
    }


};

#endif //EXTRATASK2_LIFE_GAME_H
