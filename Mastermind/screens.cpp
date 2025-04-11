#include "screens.h"
#include <format>

void screens::updateGameScreen(std::string correctCheckList, std::string wrongCheckList, std::string guess)
{
    gameScreen = std::format("|--------------------------------------------------|\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|      Correct:{}   ( {} - {} - {} - {} )  Wrong: {}     |\n"
        "|                                                  |\n"
        "|--------------------------------------------------|\n", correctCheckList[7], guess[28], guess[29], guess[30], guess[31], wrongCheckList[7], correctCheckList[6], guess[24], guess[25], guess[26], guess[27], wrongCheckList[6], correctCheckList[5], guess[20], guess[21], guess[22], guess[23], wrongCheckList[5], correctCheckList[4], guess[16], guess[17], guess[18], guess[19], wrongCheckList[4], correctCheckList[3], guess[12], guess[13], guess[14], guess[15], wrongCheckList[3], correctCheckList[2], guess[8], guess[9], guess[10], guess[11], wrongCheckList[2], correctCheckList[1], guess[4], guess[5], guess[6], guess[7], wrongCheckList[1], correctCheckList[0], guess[0], guess[1], guess[2], guess[3], wrongCheckList[0]);
}

void screens::updateResultScreen(double points)
{
    resultScreen = std::format("|--------------------------------------------------|\n"
        "|                     Results                      |\n"
        "|                                                  |\n"
        "|{:^50}|\n"
        "|                                                  |\n"
        "|--------------------------------------------------|\n", std::format("{} Points", points));
}

void screens::displayGameScreen()
{
	std::cout << gameScreen;
}

void screens::displayResultScreen()
{
	std::cout << resultScreen;
}