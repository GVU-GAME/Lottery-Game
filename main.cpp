#include "game.h"

int main () {
    try
    {
        /* code */
        game Game;
        Game.start();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}