#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>

class GameEntity {
public:
    virtual ~GameEntity() = default;
    virtual void playGame() const = 0;
};

#endif // GAMEENTITY_H
