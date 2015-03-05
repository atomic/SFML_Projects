#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
public:
    Game();
    void					run();

private:
    void					processEvents();
    void					update();
    void					render();

    void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void					setNewOrigin();

    // Vector math functions
    sf::Vector2f            distance(sf::Vector2f A, sf::Vector2f B)
    {
        return sf::Vector2f(B.x - A.x, B.y - A.y);
    }


private:
    sf::RenderWindow		mWindow;
    float_t                 mAngle;
    sf::Vector2f            mOrigin;
    sf::RectangleShape      mRect;
    sf::Transform           mRotate;

    std::string             mDebugStr;

    sf::Text                mText;
    sf::Font                myFont;
};

#endif // GAME_H

