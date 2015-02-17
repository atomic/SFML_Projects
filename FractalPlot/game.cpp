#include "game.h"
#include <cmath>
#include <cassert>


/**
 * @brief Constructor to set the size of windows
 *        and initialize objects
 */
Game::Game()
    : mWindow(sf::VideoMode(750,500), "SFML Application", sf::Style::Close),
      mWalker(0), mReady(false)
{
    // Example
    mRect.setSize(sf::Vector2f(50,50));
    mRect.setFillColor(sf::Color::Green);
    mRect.setOutlineThickness(2.0);
    mRect.setOutlineColor(sf::Color::Red);
    mRect.setPosition(sf::Vector2f(50,50));
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
 * @brief Will generate the list of points to add to VectexArray
 * @param point A, point Z
 * @return none
 */
void Game::fractalRecursive(sf::Vector2f A, sf::Vector2f Z, int level)
{
    /*           j
     *          / \
     *   A----i/   \k----Z
     */
    // Recursively add to the VertexArray when exiting stack
    // 1. Calculate, then Generate
    // When at last level, calculate, but don't generate
    // store A->k when at last level

    assert( A != Z); // check for error
    // 1. Calculate
    // first, find i and k
    // Let cx be x_distance
    // let cy be y_distance
    float cx = (Z.x - A.x);
    float cy = (Z.y - A.y);

    sf::Vector2f i(  cx/3,   cy/3);
    sf::Vector2f k(2*cx/3, 2*cy/3);
    // use Joseph's Formula to find j
    sf::Vector2f j;
    j.x = A.x + 0.5(cx) + (sqrt(3.0)/6.0)*cy;
    j.y = A.y - 0.5(cy) - (sqrt(3.0)/6.0)*cx; // sfml y is inverted

    // 2. Check Last Level
    //
    if(level == mDepth) {
        vArray[walker++].position = A;
        vArray[walker++].position = i;
        vArray[walker++].position = j;
        vArray[walker++].position = k;
    } else {
    // 3. Generate
        fractalRecursive(A, i, level + 1);
        fractalRecursive(i, j, level + 1);
        fractalRecursive(j, k, level + 1);
        fractalRecursive(k, Z, level + 1);
    }

    // this is at the end of stack
    if(level == 0) {
        vArray[walker].position = Z; // last one
        ready = true;
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
}

void Game::setDepth(const int depth)
{
    if(ready) delete vArray; // delete previously stored points
    mDepth = depth;
    mWalker = 0;
    vArray = new sf::VertexArray(sf::LinesStrip, pow(4, depth)); // why? see notes
    ready = false;
    // because you havent calculate the fractal points yet
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
    mWindow.draw(mRect);
    mWindow.display();
}

