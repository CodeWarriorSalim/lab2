#ifndef GAMECORE_H
#define GAMECORE_H

#include <vector>
#include "GameEntity.h"
#include "Mechanic.h"
#include "Bonus.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Lizard.h"
#include "Spock.h"
#include "ComputerPlayer.h"
#include "DynamicChoice.h"

class GameCore {
private:
    int roundsToPlay;
    int playerScore;
    int computerScore;
    std::vector<GameEntity*> playerChoices;

public:
    GameCore();
    ~GameCore();

    void startNewGame();
    void playGame();

private:
    void playRound();
    int generateComputerChoice() const;
    void printChoice(const std::string& playerName, int choice) const;
    void determineWinner(int userChoice, int computerChoice);
    void printGameScore() const;
    void printFinalScore() const;
    void askForNewGame();
    void initializeGameEntities();
    void cleanup();
};

#endif // GAMECORE_H
