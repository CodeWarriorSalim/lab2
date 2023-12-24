#include "GameCore.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameCore::GameCore() : playerScore(0), computerScore(0) {
    setlocale(LC_ALL, "Russian");
    initializeGameEntities();
}

GameCore::~GameCore() {
    cleanup();
}

void GameCore::startNewGame() {
    std::cout << "Enter the number of rounds: ";
    std::cin >> roundsToPlay;
    playerScore = 0;
    computerScore = 0;
}

void GameCore::playGame() {
    startNewGame();

    for (int round = 1; round <= roundsToPlay; ++round) {
        std::cout << "\nRound " << round << ":" << std::endl;
        playRound();
        printGameScore();
    }

    printFinalScore();
    askForNewGame();
}

void GameCore::playRound() {
    int userChoice;
    std::cout << "Choose a move (1 - Rock, 2 - Paper, 3 - Scissors, 4 - Lizard, 5 - Spock): ";
    std::cin >> userChoice;

    if (userChoice >= 1 && userChoice <= playerChoices.size()) {
        playerChoices[userChoice - 1]->playGame();

        if (auto mechanic = dynamic_cast<Mechanic*>(playerChoices[userChoice - 1])) {
            mechanic->applyMechanic();
        } else if (auto bonus = dynamic_cast<Bonus*>(playerChoices[userChoice - 1])) {
            bonus->applyBonus();
        }

        int computerChoice = generateComputerChoice();
        printChoice("Computer's move", computerChoice);

        determineWinner(userChoice, computerChoice);
    } else {
        std::cout << "Invalid move. Skipping the round." << std::endl;
    }
}

int GameCore::generateComputerChoice() const {
    return rand() % playerChoices.size() + 1;
}

void GameCore::printChoice(const std::string& playerName, int choice) const {
    std::cout << playerName << ": ";
    switch (choice) {
        case 1: std::cout << "Rock"; break;
        case 2: std::cout << "Paper"; break;
        case 3: std::cout << "Scissors"; break;
        case 4: std::cout << "Lizard"; break;
        case 5: std::cout << "Spock"; break;
        default: std::cout << "Unknown choice"; break;
    }
    std::cout << std::endl;
}

void GameCore::determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        std::cout << "Draw in this round!" << std::endl;
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2) ||
               (userChoice == 4 && computerChoice == 5) ||
               (userChoice == 5 && computerChoice == 4)) {
        std::cout << "You won this round!" << std::endl;
        ++playerScore;
    } else {
        std::cout << "Computer won this round!" << std::endl;
        ++computerScore;
    }
}

void GameCore::printGameScore() const {
    std::cout << "Score after the round:" << std::endl;
    std::cout << "You: " << playerScore << " | Computer: " << computerScore << std::endl;
}

void GameCore::printFinalScore() const {
    std::cout << "\nFinal score:" << std::endl;
    std::cout << "You: " << playerScore << " | Computer: " << computerScore << std::endl;

    if (playerScore > computerScore) {
        std::cout << "You won the entire game!" << std::endl;
    } else if (computerScore > playerScore) {
        std::cout << "Computer won this game." << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }
}

void GameCore::askForNewGame() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        playGame();
    } else {
        std::cout << "Thank you for playing. Goodbye!" << std::endl;
    }
}

void GameCore::initializeGameEntities() {
    playerChoices.push_back(new Rock());
    playerChoices.push_back(new Paper());
    playerChoices.push_back(new Scissors());
    playerChoices.push_back(new Lizard());
    playerChoices.push_back(new Spock());
    playerChoices.push_back(new ComputerPlayer());
    playerChoices.push_back(new DynamicChoice("Dynamic Choice 1"));
    playerChoices.push_back(new DynamicChoice("Dynamic Choice 2"));
}

void GameCore::cleanup() {
    for (auto& choice : playerChoices) {
        delete choice;
    }
}
