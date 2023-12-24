#include "DynamicChoice.h"
#include <iostream>

DynamicChoice::DynamicChoice(const std::string& userChoice) : choice(userChoice) {}

void DynamicChoice::playGame() const {
    std::cout << "You chose: " << choice << std::endl;
}

