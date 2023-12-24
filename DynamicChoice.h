#ifndef DYNAMICCHOICE_H
#define DYNAMICCHOICE_H

#include "GameEntity.h"
#include <string>

class DynamicChoice : public GameEntity {
private:
    std::string choice;

public:
    DynamicChoice(const std::string& userChoice);

    void playGame() const override;
};

#endif // DYNAMICCHOICE_H

