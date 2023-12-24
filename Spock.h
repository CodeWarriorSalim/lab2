#ifndef SPOCK_H
#define SPOCK_H

#include "Bonus.h"

class Spock : public Bonus {
public:
    void playGame() const override;
    void applyBonus() const override;
};

#endif // SPOCK_H
