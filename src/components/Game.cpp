#include "Game.hpp"

//  Initializer functions
void Game::init_window()
{   
    this-> mainWindow = new sf::RenderWindow(
        sf::VideoMode(window[0], window[1]),
        "Pong SFML",
        sf::Style::Default
    );
    this-> mainWindow-> setFramerateLimit(framerateLimit);
}

void Game::init_middle_line()
{   
    middleLine.setFillColor(sf::Color::White);
    middleLine.setPosition(sf::Vector2f(middleLinePosition[0], middleLinePosition[1]));
    middleLine.setSize(sf::Vector2f(middleLineSize[0], middleLineSize[1]));
}

void Game::init_players()
{   
    this-> rightPlayer = new Player();
    this-> leftPlayer  = new Player();
    
    this-> rightPlayer-> set_position_x(window[0]-paddleSize[0]-paddleDistanceBorder);
    this-> leftPlayer -> set_position_x(paddleDistanceBorder);
    
    //  Setting the Keyboard
    this-> rightPlayer-> set_up_key(sf::Keyboard::Up);
    this-> rightPlayer-> set_down_key(sf::Keyboard::Down);
    
    this-> leftPlayer-> set_up_key(sf::Keyboard::W);
    this-> leftPlayer-> set_down_key(sf::Keyboard::S);
}

void Game::init_ball()
{   
    this-> mainBall = new Ball();
}

//  Builder function
Game::Game()
{   
    init_window();
    init_middle_line();

    init_players();
    init_ball();
}

//  Game functions
void Game::run()
{   
    while (this-> mainWindow-> isOpen())
    {   
        process_events();
        process_live_events();
        
        show();
    }
}

void Game::process_events()
{   
    while (this-> mainWindow-> pollEvent(mainWindowEvent))
    {   
        switch (mainWindowEvent.type)
        {   
            case sf::Event::Closed:
                this-> mainWindow-> close();
                break;
            
            case sf::Event::KeyReleased: // Keyboard events:
                switch(mainWindowEvent.key.code)
                {   
                    //  Reseting the Game:
                    case sf::Keyboard::Space:
                        this-> mainBall-> to_center();
                        init_players();
                        break;
                }
                break;
        }
    }
}

void Game::process_live_events()
{   
    movimentTime=mainClock.getElapsedTime();
    
    // Player moviment:
    this-> rightPlayer-> move(movimentTime);
    this-> leftPlayer -> move(movimentTime);
    
    // Detecting colision:
    this-> mainBall-> make_colision(this-> rightPlayer-> get_paddle());
    this-> mainBall-> make_colision(this-> leftPlayer -> get_paddle());
    
    this-> mainBall-> move(movimentTime); // Ball moviment

    mainClock.restart().asMilliseconds();
}

void Game::show()
{   
    // Setting the black color on screen:
    this-> mainWindow-> clear(sf::Color::Black);
    
    //  Drawing items
    this-> mainWindow-> draw(this-> middleLine);
    this-> mainWindow-> draw(this-> rightPlayer-> get_paddle());
    this-> mainWindow-> draw(this-> leftPlayer -> get_paddle());
    this-> mainWindow-> draw(this-> mainBall-> get_ball());
    
    this-> mainWindow-> display();
}
