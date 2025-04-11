#pragma once
#include <iostream>

class screens
{
private:
    std::string gameScreen = "|--------------------------------------------------|\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|       Correct:    ( -  -  -  - )  Wrong:         |\n"
        "|                                                  |\n"
        "|--------------------------------------------------|\n";

    std::string resultScreen = "|--------------------------------------------------|\n"
        "|                     Results                      |\n"
        "|                                                  |\n"
        "|                Points                            |\n"
        "|                                                  |\n"
        "|--------------------------------------------------|\n";

public:
    void updateGameScreen(std::string correctCheckList, std::string wrongCheckList, std::string guess);
    void updateResultScreen(double points);
    void displayGameScreen();
    void displayResultScreen();
};

