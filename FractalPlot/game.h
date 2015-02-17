#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
public:
    Game();
    void					run();

    void                    setDepth(const int depth);
    void                    generateFractalPoints(sf::Vector2f A,
                                                  sf::Vector2f Z,
                                                  const int depth);

private:
    void                    fractalRecursive(sf::Vector2f A,sf::Vector2f Z, int level);
    void					processEvents();
    void					update();
    void					render();

    void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    // Recursive Fractal Plot

private:
    int                     mDepth;
    int                     mWalker; // this is used to traverse recursively
    bool                    mReady;  // to tell if fractal is ready

    sf::VertexArray        *vArray;
    sf::RenderWindow		mWindow;
    sf::RectangleShape      mRect;
};

#endif // GAME_H

