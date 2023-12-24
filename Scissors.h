#ifndef SCISSORS_H
#define SCISSORS_H

#include "Mechanic.h"

class Scissors : public Mechanic {
public:
    void playGame() const override;
    void applyMechanic() const override;
};

#endif // SCISSORS_H

