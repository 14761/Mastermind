#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

class game
{
    private:
        bool isRepeat;
        const int codeLength = 4;
        std::string secretCode;
        int round;
        std::string guess;
        std::string correctCheckList;
        std::string wrongCheckList;
        std::chrono::system_clock::time_point startTime;
        std::chrono::system_clock::time_point endTime;

    public:
        game(bool isRepeat);
        std::string getCorrectCheckList();
        std::string getWrongCheckList();
        std::string getGuess();
        int getRound();
        void checkGuess();
        void inputGuess();
        double calculatePoints();
        void displayCode();
};

