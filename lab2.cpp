#include <iostream>    // Library for standard input/output
#include <cstdlib>     // Library for general functions
#include <ctime>       // Library for time-related functions
#include <vector>      // Library for dynamic arrays

// Abstract base class for all game entities
class GameEntity {
public:
    virtual ~GameEntity() = default;
    virtual void playGame() const = 0;  // Virtual function for playing the game
};

// Abstract base class for entities with mechanics
class Mechanic : public GameEntity {
public:
    virtual void applyMechanic() const = 0;  // Virtual function for applying mechanics
};

// Abstract base class for entities with bonuses
class Bonus : public GameEntity {
public:
    virtual void applyBonus() const = 0;  // Virtual function for applying bonuses
};

// Concrete classes with mechanics

class Rock : public Mechanic {
public:
    void playGame() const override {
        std::cout << "You chose: Rock" << std::endl;
    }

    void applyMechanic() const override {
        std::cout << "Rock mechanics applied" << std::endl;
    }
};

class Paper : public Mechanic {
public:
    void playGame() const override {
        std::cout << "You chose: Paper" << std::endl;
    }

    void applyMechanic() const override {
        std::cout << "Paper mechanics applied" << std::endl;
    }
};

class Scissors : public Mechanic {
public:
    void playGame() const override {
        std::cout << "You chose: Scissors" << std::endl;
    }

    void applyMechanic() const override {
        std::cout << "Scissors mechanics applied" << std::endl;
    }
};

// Concrete classes with bonuses

class Lizard : public Bonus {
public:
    void playGame() const override {
        std::cout << "You chose: Lizard" << std::endl;
    }

    void applyBonus() const override {
        std::cout << "Lizard bonus applied" << std::endl;
    }
};

class Spock : public Bonus {
public:
    void playGame() const override {
        std::cout << "You chose: Spock" << std::endl;
    }

    void applyBonus() const override {
        std::cout << "Spock bonus applied" << std::endl;
    }
};

// Class representing a computer player with mechanics
class ComputerPlayer : public Mechanic {
public:
    void playGame() const override {
        std::cout << "Computer chose a random move" << std::endl;
    }

    void applyMechanic() const override {
        std::cout << "Computer mechanics applied" << std::endl;
    }
};

// Class representing a dynamic choice
class DynamicChoice : public GameEntity {
private:
    std::string choice;

public:
    DynamicChoice(const std::string& userChoice) : choice(userChoice) {}

    void playGame() const override {
        std::cout << "You chose: " << choice << std::endl;
    }
};

// Class for managing the game process
class GameCore {
private:
    int roundsToPlay;
    int playerScore;
    int computerScore;

    std::vector<GameEntity*> playerChoices;

public:
    GameCore() : playerScore(0), computerScore(0) {
        setlocale(LC_ALL, "Russian");
        initializeGameEntities();
    }

    ~GameCore() {
        cleanup();
    }

    // Start a new game
    void startNewGame() {
        std::cout << "Enter the number of rounds: ";
        std::cin >> roundsToPlay;
        playerScore = 0;
        computerScore = 0;
    }

    // Start the game
    void playGame() {
        startNewGame();

        for (int round = 1; round <= roundsToPlay; ++round) {
            std::cout << "\nRound " << round << ":" << std::endl;
            playRound();
            printGameScore();
        }

        printFinalScore();
        askForNewGame();
    }

private:
    // Play a round
    void playRound() {
        int userChoice;
        std::cout << "Choose a move (1 - Rock, 2 - Paper, 3 - Scissors, 4 - Lizard, 5 - Spock): ";
        std::cin >> userChoice;

        if (userChoice >= 1 && userChoice <= playerChoices.size()) {
            playerChoices[userChoice - 1]->playGame();

            // Apply bonus or mechanic
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

    // Generate computer's choice
    int generateComputerChoice() const {
        return rand() % playerChoices.size() + 1;
    }

    // Print a player's or computer's choice
    void printChoice(const std::string& playerName, int choice) const {
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

    // Determine the winner of the round
    void determineWinner(int userChoice, int computerChoice) {
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

    // Print the game score after a round
    void printGameScore() const {
        std::cout << "Score after the round:" << std::endl;
        std::cout << "You: " << playerScore << " | Computer: " << computerScore << std::endl;
    }

    // Print the final game score
    void printFinalScore() const {
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

    // Ask if the player wants to play again
    void askForNewGame() {
        char choice;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            playGame();
        } else {
            std::cout << "Thank you for playing. Goodbye!" << std::endl;
        }
    }

    // Initialize game entities
    void initializeGameEntities() {
        playerChoices.push_back(new Rock());
        playerChoices.push_back(new Paper());
        playerChoices.push_back(new Scissors());
        playerChoices.push_back(new Lizard());
        playerChoices.push_back(new Spock());
        playerChoices.push_back(new ComputerPlayer());
        playerChoices.push_back(new DynamicChoice("Dynamic Choice 1"));
        playerChoices.push_back(new DynamicChoice("Dynamic Choice 2"));
    }

    // Clean up memory used by entities
    void cleanup() {
        for (auto& choice : playerChoices) {
            delete choice;
        }
    }
};

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    GameCore gameCore;
    gameCore.playGame();

    return 0;
}

