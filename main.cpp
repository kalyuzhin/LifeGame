#include "matrix.h"
#include "vector.h"
#include "life_game.h"

int main() {
    std::cout << "LIFE GAME:\n";
    LifeGame lifeGame{6,12, ' ', '@'};
    lifeGame.start_game();

    return 0;
}
    
