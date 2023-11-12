#include "matrix.h"
#include "vector.h"
#include "life_game.h"

int main() {
    LifeGame lifeGame{9, 12, ' ', '@'};
    std::cout << lifeGame;

    return 0;
}
