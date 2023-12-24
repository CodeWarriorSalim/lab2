#ifndef PAPER_H
#define PAPER_H

#include "Mechanic.h"

class Paper : public Mechanic {
public:
    void playGame() const override;
    void applyMechanic() const override;
};

#endif // PAPER_H

