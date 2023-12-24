#ifndef BONUS_H
#define BONUS_H

#include "GameEntity.h"

class Bonus : public GameEntity {
public:
    virtual void applyBonus() const = 0;
};

#endif // BONUS_H
