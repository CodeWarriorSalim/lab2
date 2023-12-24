#ifndef MECHANIC_H
#define MECHANIC_H

#include "GameEntity.h"

class Mechanic : public GameEntity {
public:
    virtual void applyMechanic() const = 0;
};

#endif // MECHANIC_H
