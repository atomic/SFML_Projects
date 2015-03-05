#include "game.h"
#include <QDebug>


/**
 * @brief Constructor to set the size of windows
 *        and initialize objects
 */
Game::Game()
    : mWindow(sf::VideoMode(750,500), "SFML Application", sf::Style::Close)
    , mAngle(0), mOrigin(0,0)
{
    // Example
    mRect.setSize(sf::Vector2f(50,50));
    mRect.setFillColor(sf::Color::Green);
    mRect.setOutlineThickness(2.0);
    mRect.setOutlineColor(sf::Color::Red);
    mRect.setPosition(sf::Vector2f(50,50));

    myFont.loadFromFile("fira.ttf");
    mText.setFont(myFont);
    mText.setString("Test fonts");
    mText.setColor(sf::Color::Blue);


    mRotate.rotate(mAngle, 0, 0);
}

/**
 * @brief a function to start the whole game mode
 */
void Game::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

/**
 * @brief receives events and
 *          and acts accordingly
 */
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;

        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;

        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

/**
 * @brief Based on the key inputs, do actions
 * @param key inputted, whether key is pressed or released
 */
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Escape)
        mWindow.close();
    else if (key == sf::Keyboard::BackSpace)
        mWindow.close();
    else if (key == sf::Keyboard::Period)
//        mRect.setRotation(++mAngle);
        mRotate.rotate(1, mOrigin);
//        ++mAngle;
    else if (key == sf::Keyboard::Comma)
//        mRect.setRotation(--mAngle);
        mRotate.rotate(-1, mOrigin);
//    else if (key == sf::Keyboard::Return)
//        setNewOrigin();
    else if (key == sf::Keyboard::Num0)
        mOrigin.x += 100;
    else if (key == sf::Keyboard::Num9)
        mOrigin.y += 100;
//    else if (key == sf::Keyboard::Slash)
    //        mRect = mRotate.transformRect(mRect);
    mDebugStr = "Angle : " + std::to_string(mAngle) + "\n" +
            "x : " + std::to_string(mOrigin.x)      + "\n" +
            "y : " + std::to_string(mOrigin.y);
    qDebug() << mOrigin.x << endl;
    qDebug() << mOrigin.y << endl;

    mText.setString(mDebugStr);

}

void Game::setNewOrigin()
{
    sf::Vector2f oldPos = mRect.getPosition();

    // later on, this will apply to every point, not sure if theres more efficient way
    // to do it
    oldPos = sf::Vector2f(oldPos - distance(oldPos, mOrigin));
    // setting new origin
    mRect.setOrigin(mOrigin);
    mRect.setPosition(oldPos); // reset back its previous position
}

/**
 * @brief update informations to next thread
 */
void Game::update()
{
}

/**
 * @brief a function to draw objects
 */
void Game::render()
{
    mWindow.clear();
    // later on draw 2 things? one for fixed, one for rotate?
    mWindow.draw(mRect, mRotate);
    mWindow.draw(mText);
    mWindow.display();
}

