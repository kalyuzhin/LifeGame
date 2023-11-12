//
// Created by Марк Калюжин on 12.11.2023.
//

#include "life_game.h"

void LifeGame::fill_random() {
    std::random_device rd;
    for (size_t i = 0; i != this->_rows; ++i) {
        for (size_t j = 0; j != this->_columns; ++j) {
            _matrix[i][j] = rd() % 2 == 0 ? _alive_cells : _dead_cells;
        }
    }
}

size_t LifeGame::count_neighbours(size_t row, size_t column) {
    size_t result = 0;
    int x_positions[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_positions[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (size_t i = 0; i != 8; ++i) {
        size_t x = (x_positions[i] + column);
        x = x == std::numeric_limits<size_t>::max() ? _columns - 1 : x % _columns;
        size_t y = (y_positions[i] + row);
        y = y == std::numeric_limits<size_t>::max() ? _rows - 1 : y % _rows;
        result += this->operator()(y, x) == _alive_cells;
    }
    return result;
}

void LifeGame::update_generation() {
    LifeGame new_generation(_rows, _columns, _dead_cells, _alive_cells);
    for (size_t i = 0; i != _rows; ++i) {
        for (size_t j = 0; j != _columns; ++j) {
            if (count_neighbours(i, j) == 3 && this->operator()(i, j) == _dead_cells) {
                new_generation(i, j) = _alive_cells;
            } else if (((count_neighbours(i, j) > 3) || (count_neighbours(i, j) < 2)) &&
                       this->operator()(i, j) == _alive_cells) {
                new_generation(i, j) = _dead_cells;
            } else if ((count_neighbours(i, j) == 3 || count_neighbours(i, j) == 2) &&
                       this->operator()(i, j) == _alive_cells) {
                new_generation(i, j) = _alive_cells;
            } else {
                new_generation(i, j) = _dead_cells;
            }
        }
    }
    *this = new_generation;
}

void LifeGame::display_field() {
    std::cout << *this;
}

void LifeGame::start_game() {
    while (true) {
        this->display_field();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
#ifdef __APPLE__
        std::system("clear");
#elif __linux__
        std::system("clear");
#elif _WIN32
        std::system("cls");
#endif
        this->update_generation();
    }
}
