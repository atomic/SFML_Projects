#include <SFML/Graphics.hpp>


int main()
{
    const int SWIDTH = 750;
    const int SHEIGHT = 500;

    //create the window
    sf::RenderWindow win(sf::VideoMode(SWIDTH,SHEIGHT),"TestStuffs",sf::Style::Close);
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Green);
    rect.setOutlineThickness(2.0);
    rect.setOutlineColor(sf::Color::Red);
    sf::Vector2f rPos(100,100);
    uint angleRot = 0;
    rect.setPosition(rPos);

    //run the program as long as the window is open
    while(win.isOpen())
    {

        //check all the window's events that were triggered since the lst iteration of the loop
        sf::Event e;
        while (win.pollEvent(e))
        {
            switch (e.type) {
            case sf::Event::Closed:
                win.close();
                break;
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Escape)
                    win.close();
                else if(e.key.code == sf::Keyboard::K)
                    rPos.y -= 10;
                else if(e.key.code == sf::Keyboard::J)
                    rPos.y += 10;
                else if(e.key.code == sf::Keyboard::H)
                    rPos.x -= 10;
                else if(e.key.code == sf::Keyboard::L)
                    rPos.x += 10;
                break;
            }
        }
        sf::Vector2f dimension(50,50);
        for (int i = 0; i < SWIDTH / dimension.x; ++i) {
            for (int j = 0; j < SHEIGHT / dimension.y; ++j) {
                sf::VertexArray vArray(sf::LinesStrip, 4);
                vArray[0].position = sf::Vector2f(i*dimension.x, j*dimension.y);
                vArray[1].position = sf::Vector2f(i*dimension.x +dimension.x,
                                                  j*dimension.y);
                vArray[2].position = sf::Vector2f(i*dimension.x + dimension.x,
                                                  j*dimension.y + dimension.y);
                vArray[3].position = sf::Vector2f(i*dimension.x, j*dimension.y
                                                  + dimension.y);
                for (int k = 0; k < 4; ++k) {
                    int red = rand() % 255;
                    int green = rand() % 255;
                    int blue = rand() % 255;

                    vArray[k].color = sf::Color(red, green, blue);
                }

//                win.draw(vArray);
            }
        }

        // for the fractal thing, we can try to figure out how much to draw first,
        // then, add the points in order to the VertexArray
        sf::VertexArray lines(sf::LinesStrip, 5);
        lines[0].position = sf::Vector2f(10, 10);
        lines[1].position = sf::Vector2f(10, 20);
        lines[2].position = sf::Vector2f(15, 25);
        lines[3].position = sf::Vector2f(20, 20);
        lines[4].position = sf::Vector2f(20, 10);

        win.draw(lines);

        rect.setPosition(rPos);
        rect.setRotation(angleRot+=5);
//        draw everything here ///
//        win.draw(rect);

        // end the current frame
        win.display();
        // clear the window the black color
        win.clear();
    }
    return 0;
}

