#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    Game game;
    sf::Vector2f A(10,50);
    sf::Vector2f Z(10,100);
    game.generateFractalPoints(A, Z, 2);
//    game.run();
    return 0;
}


