#include "game.h"

game::game() {
    totalMoney = gettingStarted();
}

void game::start() {
    bool gameFinish = false;
    while(!gameFinish) {
        double betting = betPromt();
        if(betting == 0) {
            cout << "Exiting Game! ~Come Play Again~" << endl << endl;
            gameFinish = true;
        } else {
            int playerChoice = choicePromt();

            srand (time(NULL));
            int winningNum = rand() % 3 + 1;

            gameFinish = runGame(playerChoice, winningNum, betting);
        }
    }
}

double game::gettingStarted() {
    double wallet;
    string temp;

    cout << "How Much Money Do You Want To Put In?" << endl;
    cout << "-- Only $10,000 Max Per Game Session! --" << endl;

    bool validNum = false;
    while(!validNum) {
        cout << "Amount: $";
        getline(cin, temp);

        wallet = stod(temp);

        if(wallet > 10000) {
            cout << "Sorry Only $10,000 Per Game Session!" << endl;
        } else {
            validNum = true;
        }
    }

    return floor(wallet*100+.5)/100;
}

double game::betPromt() {
    bool validChoice = false;
    double betting;
    while(!validChoice) {
        cout << endl << "How Much Do You Want To Bet?" << endl;
        cout << "~Enter 0 To Quit~" << endl;

        cout.precision(7);
        cout << "#### Total Funds: $" << totalMoney << " ####" << endl;

        cout << "Betting: $";
        cin >> betting;

        if(betting > totalMoney) {
            cout << "Insufficent Funds!" << endl;
        } else if(betting < 0) {
            cout << "Invalid Number!" << endl;
        } else {
            validChoice = true;
        }
    }
    return betting;
}

int game::choicePromt() {
    bool validChoice = false;
    int choice;
    while(!validChoice) {
        cout << endl << "Choose A Number From 1-3" << endl;
        cout << "Choice: ";
        cin >> choice;

        if(choice > 3 || choice < 1) {
            cout << "That Is Not A Valid Choice!" << endl;
        } else {
            validChoice = true;
        }
    }
    return choice;
}

bool game::runGame(int playerChoice, int winningNum, double betting) {
    cout << endl << "The Winning Number Was: " << winningNum << endl;
    if(playerChoice == winningNum) {
        cout << "Congrats You Won!" << endl;
        cout.precision(7);
        cout << "== Adding $" << betting << " To Your Funds! ==" << endl;
        totalMoney += betting;
    } else {
        cout << "Too Bad!" << endl;
        cout.precision(7);
        cout << "== Subtracting $" << betting << " From Your Funds! ==" << endl;
        totalMoney -= betting;
    }

    cout.precision(7);
    cout << "#### Total Funds: $" << totalMoney << " ####" << endl;

    if(totalMoney == 0) {
        cout << "You Are Out Of Funds To Play! ~Come Play Again!~" << endl << endl;
        return true;
    }

    return false;
}