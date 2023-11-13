#include "matrix.h"
#include "vector.h"
#include "life_game.h"

int main() {
    std::cout << "LIFE GAME:\n";
    size_t height, width;
    std::cout << "Enter height and width:\n";
    std::cin >> height >> width;
    LifeGame lifeGame{height, width, ' ', '@'};
    lifeGame.start_game();

    return 0;
}
    
