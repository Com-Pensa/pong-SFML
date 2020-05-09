#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{   
private:
    sf::RenderWindow *mainWindow;
    sf::Event         mainWindowEvent;
    
public:
    Game();
    
    void run();
};

#endif
