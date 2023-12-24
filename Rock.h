#ifndef ROCK_H
#define ROCK_H

#include "Mechanic.h"

class Rock : public Mechanic {
public:
    void playGame() const override;
    void applyMechanic() const override;
};

#endif // ROCK_H

