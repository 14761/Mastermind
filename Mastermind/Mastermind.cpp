// Mastermind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "screens.h"
#include "game.h"

void displayMenuScreen();
void displayInstructionsScreen();
int inputMenu();

int main()
{
    int menuAnswer;
    do
    {
        displayMenuScreen();
        menuAnswer = inputMenu();

        switch (menuAnswer)
        {
        case 1:
        {
            game myGame(false);
            screens myScreens;
            do // will run until either user gets secret code or finish the 8th round
            {
                myGame.displayCode();
                myScreens.displayGameScreen();
                myGame.inputGuess();
                myGame.checkGuess();
                myScreens.updateGameScreen(myGame.getCorrectCheckList(), myGame.getWrongCheckList(), myGame.getGuess());
                std::cout << myGame.getRound() << std::endl;
            } while (myGame.getCorrectCheckList()[myGame.getRound() - 1] != '4' && myGame.getRound() != 8);

            myScreens.displayGameScreen();
            myScreens.updateResultScreen(myGame.calculatePoints());
            myScreens.displayResultScreen();

            system("pause");

            break;
        }

        case 2:
        {
            game myGame(true);
            screens myScreens;
            do
            {
                myGame.displayCode();
                myScreens.displayGameScreen();
                myGame.inputGuess();
                myGame.checkGuess();
                myScreens.updateGameScreen(myGame.getCorrectCheckList(), myGame.getWrongCheckList(), myGame.getGuess());
                std::cout << myGame.getRound() << std::endl;
            } while (myGame.getCorrectCheckList()[myGame.getRound() - 1] != '4' && myGame.getRound() != 8);

            myScreens.displayGameScreen();
            myScreens.updateResultScreen(myGame.calculatePoints());
            myScreens.displayResultScreen();

            system("pause");

            break;
        }

        case 3:
            displayInstructionsScreen();
            system("pause");

            break;

        case 4:
            return 0;

            break;
        }
    } while (true);
}

int inputMenu()
{
    std::string menuChoice;
    do
    {
        std::cout << "Your input: ";
        std::cin >> menuChoice;

        if (menuChoice.length() != 1)
        {
            std::cout << "Input must be just 1 character.\n";
        }
        else if (!isdigit(menuChoice[0]))
        {
            std::cout << "Input must be a digit.\n";
        }
        else if (menuChoice[0] < '1' || menuChoice[0] > '4')
        {
            std::cout << "Input must be between 1 and 4\n";
        }
        else
        {
            return std::stoi(menuChoice);
        }
    } while (true);
}

void displayMenuScreen()
{
    std::string menuScreen = "|--------------------------------------------------|\n"
        "|                    MASTERMIND                    |\n"
        "|                                                  |\n"
        "|         1. Start Game: No Repeat                 |\n"
        "|         2. Start Game: Repeat                    |\n"
        "|         3. Instructions                          |\n"
        "|         4. Exit                                  |\n"
        "|--------------------------------------------------|\n";
    
    std::cout << menuScreen;
}

void displayInstructionsScreen()
{
    std::string instructionsScreen = "|--------------------------------------------------|\n"
        "|               INSTRUCTIONS                       |\n"
        "|                                                  |\n"
        "| The computer will generate the secret code,      |\n"
        "| which is a random sequence of four letters       |\n"
        "| between A and F. Then the game starts. You       |\n"
        "| must have a guess of the secret code and then    |\n"
        "| the computer will tell you how many correct are  |\n"
        "| in correct positions and how many correct are in |\n"
        "| wrong position. Then you have a guess again and  |\n"
        "| the process repeats until you either guess the   |\n"
        "| correct sequence or reach the maximum attempts.  |\n"
        "|                                                  |\n"
        "| You can choose between two levels of difficulty: |\n"
        "| 1. No repeat: where the letters can't be more    |\n"
        "|    than once on the secret code.                 |\n"
        "| 2. Repeat: where the letters coud be more than   |\n"
        "|    once on the secret code.                      |\n"
        "|                                                  |\n"
        "| Tips to keep in mind:                            |\n"
        "| 1. The order matters.                            |\n"
        "| 2. Analyse the feedback.                         |\n"
        "|                                                  |\n"
        "|--------------------------------------------------|\n";
    
    std::cout << instructionsScreen;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
