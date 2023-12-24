#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameCore.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    GameCore gameCore;
    gameCore.playGame();

    return 0;
}
