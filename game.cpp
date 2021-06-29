#include "game.h"

game::game() {
    totalMoney = gettingStarted();
}

void game::promt() {

}

double game::gettingStarted() {
    double wallet;
    string temp;

    cout << "How much money do you have to play with?" << endl;
    cout << "(only $10,000 max per game session!)" << endl;

    bool validNum = false;
    while(!validNum) {
        cout << "amount: ";
        getline(cin, temp);

        wallet = stod(temp);

        if(wallet > 10000) {
            cout << "Sorry only $10,000 per game session" << endl;
        } else {
            validNum = true;
        }
    }

    return floor(wallet*100+.5)/100;
}

bool game::endGame() {

}

void game::start() {
    //cout.precision(7);
    //cout << totalMoney << endl;
    bool gameFinish = false;
    while(!gameFinish) {
        
    }
}