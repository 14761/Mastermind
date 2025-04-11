#include "game.h"
#include <random>
#include <string>

game::game(bool isRepeat)
{
    // Initialize all the following variables
    round = 0;
    guess = std::string(32, '-');
    correctCheckList = std::string(8, '-');
    wrongCheckList = std::string(8, '-');
    this->isRepeat = isRepeat;
    startTime = std::chrono::system_clock::now(); // creates a timestamp

    std::string tempCode; // temporary secret code
    char c; // c will save the value of the random letter
    for (int i = 0; i < codeLength; i++) // Iterate 4 times (length of the code)
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        if (!isRepeat) // check if the game allows to repeat lettersd
        {
            do // iterate until the letter generated is not repeated in the code
            {
                std::uniform_int_distribution<int> dist('A', 'F'); // define the range of the random number (letter) to generate
                c = dist(gen); // generate the number (letter)
            } while (std::find(tempCode.begin(), tempCode.end(), c) != tempCode.end());

            tempCode += c; // saves the letter in the temporary secret code
        }
        else // this runs if the game allows to repeat the letters in the code
        {
            std::uniform_int_distribution<int> dist('A', 'F'); // define the range of the random number (letter) to generate
            c = dist(gen); // generate the number (letter)
            tempCode += c; // saves the letter in the temporary secret code
        }
        secretCode += c; // saves the letter in the secret code 
    }

}

std::string game::getCorrectCheckList()
{
    return correctCheckList;
}

std::string game::getWrongCheckList()
{
    return wrongCheckList;
}

std::string game::getGuess()
{
    return guess;
}

int game::getRound()
{
    return round;
}

void game::displayCode()
{
    std::cout << secretCode;
}

void game::checkGuess()
{
    int correct = 0, wrong = 0; // variables to count the corrects' and wrongs'
    bool tempGuess[4]; // variable to avoid overcount the guess letters when checking
    std::fill(std::begin(tempGuess), std::end(tempGuess), false); // initialize the variable with false values
    for (int i = 0; i < codeLength; i++) // iterator on secret code
    {
        for (int j = (round * codeLength); j < (round * codeLength + codeLength); j++) // iterator on guess
        {
            if (tempGuess[j - (round * codeLength)]) // checks if the guess letter has already matched a secret code letter
            {
                continue;
            }

            if (guess[j] == secretCode[i]) // checks if the guess letter is the same as the code letter
            {
                if (i == j - (round * codeLength)) // checks if the position of the guess letter is the same as code letter
                {
                    correct++;
                    tempGuess[j - (round * codeLength)] = true; // the guess letter has matched a code letter
                    break;
                }
                else
                {
                    wrong++;
                    tempGuess[j - (round * codeLength)] = true;
                    break;
                }
                
            } 
        }
    }
    correctCheckList[round] = correct + '0';
    wrongCheckList[round] = wrong + '0';
    round++;
}

void game::inputGuess()
{
    std::string guessTemp;
    do
    {
        std::cout << "Input your guess: ";
        std::cin >> guessTemp;
        transform(guessTemp.begin(), guessTemp.end(), guessTemp.begin(), ::toupper); // converts the input to upper
        std::cout << std::endl;
        if (guessTemp.length() != codeLength)
        {
            std::cout << "Guess has to be 4 letters longer.\n";
        }
        else if (!(isalpha(guessTemp[0]) && isalpha(guessTemp[1]) && isalpha(guessTemp[2]) && isalpha(guessTemp[3])))
        {
            std::cout << "Guess must have only letters.\n";
        }
        else if ((guessTemp[0] > 'F' || guessTemp[0] < 'A') || (guessTemp[1] > 'F' || guessTemp[1] < 'A') || (guessTemp[2] > 'F' || guessTemp[2] < 'A') || (guessTemp[3] > 'F' || guessTemp[3] < 'A'))
        {
            std::cout << "Guess letters must be between A and F.\n";
        }
        else
        {
            if (!isRepeat) // if the game is no repeat, this won't allow to repeat letters in the input
            {
                bool doubleLetter = false;
                for (int i = 'A'; i <= 'F'; i++)
                {
                    int count = 0;
                    for (int j = 0; j < codeLength; j++)
                    {
                        if (guessTemp[j] == i)
                        {
                            count++;
                            if (count > 1)
                            {
                                std::cout << "Letters can't be repeated\n";
                                doubleLetter = true;
                                break;
                            }
                        }

                    }
                    if (doubleLetter)
                    {
                        break;
                    }
                }
                if (doubleLetter)
                {
                    continue;
                }
            }
            for (int i = 0; i < codeLength; i++)
            {
                guess[round * codeLength + i] = guessTemp[i];
            }

            break;
        }
    } while (true);
}

double game::calculatePoints()
{
    double points;
    endTime = std::chrono::system_clock::now(); // creates a time stamp
    std::chrono::duration<double> elapsedSeconds = endTime - startTime;
    if (round == 8 && correctCheckList[round - 1] != '4') // if user doesn't get the secret code, this will run
    {
        points = 0;
    }
    else
    {
        points = (480 - std::chrono::duration_cast<std::chrono::seconds>(elapsedSeconds).count()) * (9 - round);
    }
    
    return points;

}