#ifndef LIZARD_H
#define LIZARD_H

#include "Bonus.h"

class Lizard : public Bonus {
public:
    void playGame() const override;
    void applyBonus() const override;
};

#endif // LIZARD_H

