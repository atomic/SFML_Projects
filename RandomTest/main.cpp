#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;
const int GRID_WIDTH = 200;
const int GRID_HEIGHT = 110;
const int CELL_SIZE = 5;
struct Point{
    Point(int X, int Y, int type=0):x(X),y(Y),pointType(type){}
    int x;
    int y;
    int pointType;
};

class Anim{
public:
    Anim();
    int MonteCarlo(int limit);
    int MonteCarloRange(int origin, int range);
    void Walk();
    void Draw();
    int Random(int lo, int hi);
    void run();
    void processEvents();
    void update();
    void render();
    void ShowShapes();
private:
    sf::RenderWindow window;
    vector<Point> points;
    //    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];
//    int grid[GRID_HEIGHT][GRID_WIDTH];
};

Anim::Anim(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    //
    //or... window.create(sf::VideoMode(...
    //
    // FRAME RATE:
    //    window.setFramerateLimit(60);

    int x = SCREEN_WIDTH/2;
    int y = SCREEN_HEIGHT/2;
    points.push_back(Point(x,y));
    window.clear();
    sf::CircleShape c(20);
    c.setPosition(sf::Vector2f(x,y));
    c.setFillColor(sf::Color::Magenta);
    window.draw(c);
}


int Anim::MonteCarlo(int limit){
    while (true){
        int first = Random(0,limit);
        int second = Random(0,limit);
        if (second<first)
            return second;
    }

}

int Anim::MonteCarloRange(int origin, int range){
    while (true){
        int first = Random(origin, range);
        int second = Random(origin, range);
        if (second < first && second > first -2*range)
            return second;
    }
}

void Anim::Walk(){
    {
        int randx = Random(0,SCREEN_WIDTH);
        int randy = Random(0,SCREEN_HEIGHT);
        Point nextPoint = Point(randx, randy,0);
        points.push_back(nextPoint);
    }

    {
        int randx = MonteCarlo(SCREEN_WIDTH);
        int randy = MonteCarlo(SCREEN_HEIGHT);

        Point nextPoint = Point(randx, randy,1);
        points.push_back(nextPoint);
    }
    {
        int mousePointx = MonteCarloRange(SCREEN_WIDTH/2,200);
        int mousePointy = MonteCarloRange(SCREEN_HEIGHT/2,200);
        Point nextPoint = Point(mousePointx, mousePointy,2);
        points.push_back(nextPoint);



    }

    return;
}

int Anim::Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}

void Anim::Draw(){
    for (int i=0; i<points.size(); i++){
//        cout<<"("<<points[i].x<<", "<<points[i].y<<")";
        sf::CircleShape c(1);
        c.setPosition(sf::Vector2f(points[i].x,points[i].y));
        if (i!=points.size()-1){
            switch (points[i].pointType){
            case 0: c.setFillColor(sf::Color::Magenta);
                break;
            case 1: c.setFillColor(sf::Color::Blue);
                break;
            case 2: c.setFillColor(sf::Color::Cyan);
                break;
            case 3: c.setFillColor(sf::Color::Yellow);
                break;
            default:
                cout<<"Unknown Point Type: "<<points[i].pointType<<endl;
            }


        }else
            c.setFillColor(sf::Color::Red);
        window.draw(c);
    }

    cout<<endl<<endl<<"----------------"<<endl<<endl;
}

void Anim::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render();
   }
}

void Anim::processEvents()
   {
       sf::Event event;
       while (window.pollEvent(event))//or waitEvent
           {
           // check the type of the event...
               switch (event.type)
               {
                   // window closed
                   // "close requested" event: we close the window
                   case sf::Event::Closed:
                       window.close();
                       break;

                   // key pressed
                   case sf::Event::KeyPressed:
                       //...
                       break;
               case sf::Event::MouseButtonReleased:
                       if (event.mouseButton.button == sf::Mouse::Right)
                       {
                           std::cout << "the right button was pressed" << std::endl;
                           std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                           std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                       }
                       else
                           std::cout<<"left button?"<<std::endl;
                       break;
                   default:
                       break;
               }
           }
    }


void Anim::update()
{
    Walk();
}

void Anim::render()
   {
       window.clear();
       Draw();
       window.display();
}

int main()
{
    srand(time(0));
    Anim Animation;
    Animation.run();
    return 0;
//    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];
//    int grid[GRID_HEIGHT][GRID_WIDTH];
//    ShowGrid(grid, shapeArray);
//    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
//    //VideoMode class has functions to detect screen size etc.
//    //RenderWindow constructor has a third argumnet to set style
//    //of the window: resize, fullscreen etc.
//    //
//    //or... window.create(sf::VideoMode(...

//    window.setVerticalSyncEnabled(true); // call it once, after creating the window
//    //Application runs at the same freq as monitor

//    sf::CircleShape shape(250.f);
//    shape.setFillColor(sf::Color::Green);
//    // set a 10-pixel wide orange outline
//    shape.setOutlineThickness(1);
//    shape.setOutlineColor(sf::Color(250, 150, 100));


//    // define a 120x50 rectangle
//    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
//    // change the size to 100x100
//    //rectangle.setSize(sf::Vector2f(10, 10));




//    // run the program as long as the window is open
//    while (window.isOpen())
//        {
//        ShowGrid(grid, shapeArray);

//        // check all the window's events that were triggered since the last iteration of the loop

//        sf::Event event;

//        //go through all the pending events: keyboard, mouse, close, resize, etc.
//        //pollEvent and waitEvent are the only two functions that can fill event
//        while (window.pollEvent(event))//or waitEvent
//            {
//            // check the type of the event...
//                switch (event.type)
//                {
//                    // window closed
//                    // "close requested" event: we close the window
//                    case sf::Event::Closed:
//                        window.close();
//                        break;

//                    // key pressed
//                    case sf::Event::KeyPressed:
//                        //...
//                        break;
//                case sf::Event::MouseButtonReleased:
//                        if (event.mouseButton.button == sf::Mouse::Right)
//                        {
//                            std::cout << "the right button was pressed" << std::endl;
//                            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//                            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
//                        }
//                        else
//                            std::cout<<"left button?"<<std::endl;
//                        break;
//                    default:
//                        break;
//                }
//            }
//        window.clear();
////        window.draw(shape);
////        window.draw(rectangle);
//        ShowShapes(window, shapeArray);
//        window.display();;
//        }

    return 0;
}
