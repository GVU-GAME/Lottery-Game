#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class game {
    public:
        game();
        void start();

    private:
        double totalMoney;
        void promt();
        double gettingStarted();
        bool endGame();
};


#endif