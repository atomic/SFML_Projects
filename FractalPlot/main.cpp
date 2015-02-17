#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

using namespace std;

int main()
{
    Game game;
    sf::Vector2f A(100,500);
    sf::Vector2f Z(1000,500);
    game.generateFractalPoints(A, Z, 3);
    game.run();
    return 0;
}


