#include "game.h"

int main () {
    try
    {
        //runs the game
        game Game;
        Game.start();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}