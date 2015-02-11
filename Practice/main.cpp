#include <SFML/Graphics.hpp>


int main()
{
    const int SWIDTH = 500;
    const int SHEIGHT = 300;

    //create the window
//    sf::RenderWindow win(sf::VideoMode(SWIDTH,SHEIGHT),"Practice",sf::Style::Close);
    sf::RenderWindow win(sf::VideoMode(SWIDTH,SHEIGHT),"Practice",sf::Style::Close | sf::Style::Titlebar);


    //run the program as long as the window is open
    while(win.isOpen())
    {

        //check all the window's events that were triggered since the lst iteration of the loop
        sf::Event e; // required

        while (win.pollEvent(e))
        {

            // "close requested" event: we close the window
            if(e.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        // clear the window the black color
        win.clear();

        //draw everything here ///
        //window.draw(...);

        // end the current frame
        win.display();
    }
    return 0;
}

