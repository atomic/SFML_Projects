#include <SFML/Graphics.hpp>


int main()
{
    const int SWIDTH = 1024;
    const int SHEIGHT = 768;

    //create the window
    sf::RenderWindow win(sf::VideoMode(SWIDTH,SHEIGHT),"%ProjectName:c%",sf::Style::Close);

    //run the program as long as the window is open
    while(win.isOpen())
    {
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
                break;
            }
        }
        //draw everything here ///
        //win.draw();

        // end the current frame
        win.display();

        // clear the window the black color 
        win.clear();

    }
    return 0;
}
