#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

class game {
    public:
        game();
        void start();

    private:
        double totalMoney;
        double betPromt();
        double gettingStarted();
        int choicePromt();
        bool runGame(int, int, double);
};


#endif