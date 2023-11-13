//
// Created by Марк Калюжин on 12.11.2023.
//

#include "matrix.h"
#include <random>
#include <chrono>
#include <thread>
#include <limits>
#include <cstdlib>

#ifndef EXTRATASK2_LIFE_GAME_H
#define EXTRATASK2_LIFE_GAME_H

class LifeGame : public Matrix<char> {
private:

    char _dead_cells;

    char _alive_cells;

    void fill_random();

    size_t count_neighbours(size_t row, size_t column);

    void update_generation();

    void display_field();

    bool is_all_dead();

public:
    explicit LifeGame(size_t rows, size_t columns, const char &dead_cells = '#', const char &alive_cells = '*')
            : Matrix<char>(rows, columns), _dead_cells(dead_cells), _alive_cells(alive_cells) {
        this->fill(dead_cells);
        fill_random();
    }

    void start_game();
};

#endif //EXTRATASK2_LIFE_GAME_H
