#include "Game.hpp"

//  Builder function
Game::Game()
{   
    const int width=16*75,
              height=9*75;
    
    this-> mainWindow = new sf::RenderWindow(
        sf::VideoMode(width, height),
        "Pong SFML",
        sf::Style::Default
    );
}

//  Game functions
void Game::run()
{   
    while (this-> mainWindow-> isOpen())
    {   
        while (this-> mainWindow-> pollEvent(mainWindowEvent))
        {   
            switch (mainWindowEvent.type)
            {   
                case sf::Event::Closed:
                    this-> mainWindow-> close();
                    break;
            }
        }
        
        this-> mainWindow-> clear(sf::Color::Black);
        
        this-> mainWindow-> display();
    }
}
