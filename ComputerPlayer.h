#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Mechanic.h"

class ComputerPlayer : public Mechanic {
public:
    void playGame() const override;
    void applyMechanic() const override;
};

#endif // COMPUTERPLAYER_H
