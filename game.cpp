#include "game.h"

//default constructor, gets the initial funds from player
game::game() {
    rulesPromt();
    totalMoney = gettingStarted();
}

//adds a delay so players can read the text
void delay(int time = 300) {
    Sleep(time);
}

//directs game
void game::start() {
    //game loop
    bool gameFinish = false;
    while(!gameFinish) {
        //gets player bet
        double betting = betPromt();
        if(betting == 0) {
            delay();
            cout << "Exiting Game! ~Come Play Again~" << endl << endl;
            gameFinish = true;
        } else {
            //gets player number
            int playerChoice = choicePromt();

            //generates the winning number
            srand (time(NULL));
            int winningNum = rand() % 5 + 1;

            //checks if the player won
            gameFinish = runGame(playerChoice, winningNum, betting);
        }
    }
}

void game::rulesPromt() {
    cout << "\n\t\t=======Welcome To The Lottery Game!=======" << endl << endl;
    cout << "\n\t\t===========Here Is How You Play!===========" << endl << endl;
    cout << "\t1. Enter The Starting Balance To Play The Game With --Only $10,000 Max Per Game Session!--" << endl;
    cout << "\t2. Enter The Amount Of The Starting Balance You Want TO Bet" << endl;
    cout << "\t3. Choose A Number from 1 To 5" << endl;
    cout << "\t4. Winner Will Recieve 2x The Amount Of the Money Bet" << endl;
    cout << "\t5. Wrong Number And You Lose The Bet" << endl;
    delay(600);
    cout << "\n\t Simple Enough Right? Lets Begin!" << endl << endl;
}

//gets initial funds from player
double game::gettingStarted() {
    double wallet;
    string temp;

    delay();

    //loops until a valid amount is entered
    bool validNum = false;
    while(!validNum) {
        cout << "Enter The Starting Balance: $";
        getline(cin, temp);

        wallet = stod(temp);

        if(wallet > 10000) {
            delay();
            cout << "Sorry Only $10,000 Per Game Session!" << endl;
        } else {
            validNum = true;
        }
    }

    return floor(wallet*100+.5)/100;
}

//gets the amount the player is betting
double game::betPromt() {
    //loops until a valid bet is made
    bool validChoice = false;
    double betting;
    while(!validChoice) {
        delay();
        cout << "\n~~~~~Enter $0 To Quit~~~~~" << endl;
        cout.precision(7);
        cout << "#### Total Funds: $" << totalMoney << " ####" << endl;
        cout << "Enter The Amount You Want To Bet: $";
        cin >> betting;

        if(betting > totalMoney) {
            cout << "--Insufficent Funds!--" << endl;
        } else if(betting < 0) {
            cout << "--Invalid Number!--" << endl;
        } else {
            validChoice = true;
        }
    }
    return betting;
}

//gets the player's choice
int game::choicePromt() {
    //loops until a valid number is picked
    bool validChoice = false;
    int choice;
    while(!validChoice) {
        delay();
        cout << endl << "Choose A Number From 1-5: ";
        cin >> choice;

        if(choice > 5 || choice < 1) {
            cout << "That Is Not A Valid Choice!" << endl;
        } else {
            validChoice = true;
        }
    }
    return choice;
}

//checks if player won or if game is over
bool game::runGame(int playerChoice, int winningNum, double betting) {
    delay();
    cout << endl << "The Winning Number Was: " << winningNum << endl;
    delay(600);

    if(playerChoice == winningNum) {
        cout << "Congrats You Won!" << endl;
        cout.precision(7);
        cout << "==Adding $" << (betting*2) << " To Your Funds!==" << endl;
        totalMoney += (betting*2);
    } else {
        cout << "Too Bad!" << endl;
        cout.precision(7);
        cout << "==Subtracting $" << betting << " From Your Funds!==" << endl;
        totalMoney -= betting;
    }

    delay();
    cout.precision(7);
    cout << "#### Total Funds: $" << totalMoney << " ####" << endl;
    delay(600);

    //exits game once player is out of money to play with
    if(totalMoney == 0) {
        delay();
        cout << "You Are Out Of Funds To Play! ~Come Play Again!~" << endl << endl;
        return true;
    }

    return false;
}