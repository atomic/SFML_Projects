#include "game.h"
#include <cmath>
#include <cassert>
#include <QDebug>


/**
 * @brief Constructor to set the size of windows
 *        and initialize objects
 */
Game::Game()
    : mWindow(sf::VideoMode(1280,768), "Fractal Plot", sf::Style::Close),
      mWalker(0), mReady(false), mDepth(0)
{
    vArray.setPrimitiveType(sf::LinesStrip);
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

    sf::Vector2f i(A.x +   cx/3, A.y +   cy/3);
    sf::Vector2f k(A.x + 2*cx/3, A.y + 2*cy/3);
    // use Joseph's Formula to find j
    sf::Vector2f j;
    j.x = A.x + 0.5*cx + (sqrt(3.0)/6.0)*cy;
    j.y = A.y + 0.5*cy - (sqrt(3.0)/6.0)*cx; // sfml y is inverted

    // 2. Check Last Level
    //
    if(level == mDepth - 1) {
        vArray[mWalker++].position = A;
        vArray[mWalker++].position = i;
        vArray[mWalker++].position = j;
        vArray[mWalker++].position = k;
    } else {
    // 3. Generate
        fractalRecursive(A, i, level + 1);
        fractalRecursive(i, j, level + 1);
        fractalRecursive(j, k, level + 1);
        fractalRecursive(k, Z, level + 1);
    }

    // this is at the end of stack
    if(level == 0) {
        vArray[mWalker].position = Z; // last one
        mReady = true;
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
    else if (key == sf::Keyboard::K) {
        mZ += sf::Vector2f(0,10);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::I) {
        mZ += sf::Vector2f(0,-10);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::J) {
        mZ += sf::Vector2f(-10,0);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::L) {
        mZ += sf::Vector2f(10,0);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::S) {
        mA += sf::Vector2f(0,10);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::W) {
        mA += sf::Vector2f(0,-10);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::A) {
        mA += sf::Vector2f(-10,0);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::D) {
        mA += sf::Vector2f(10,0);
        generateFractalPoints(mA, mZ, mDepth);
    }
    else if (key == sf::Keyboard::Up)
        generateFractalPoints(mA, mZ, ++mDepth);
    else if (key == sf::Keyboard::Down) {
        mDepth -= (mDepth != 1? 1 : 0);
        generateFractalPoints(mA, mZ, mDepth);
    }
}

/**
 * @brief set new depth of fractals and allocate memory for the vertices
 *        also reset the walker
 * @param depth of fractal
 */
void Game::setDepth(const int depth)
{
    mDepth = depth;
    mWalker = 0;
    vArray.resize(pow(4,depth) + 1); // why? see notes
    mReady = false;
    // because you havent calculate the fractal points yet
}

void Game::generateFractalPoints(sf::Vector2f A, sf::Vector2f Z, const int depth)
{
    setDepth(depth);
    fractalRecursive(A,Z,0);
    mReady = true;
    mA = A; mZ = Z;
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
    if(mReady)
        mWindow.draw(vArray);
    mWindow.display();
}
