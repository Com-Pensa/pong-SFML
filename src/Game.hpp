#ifndef GAME_HPP
#define GAME_HPP

//  Game objects
#include "obj/Player.hpp"

class Game
{   
private:
    //  Game Data and variables
    sf::RenderWindow   *mainWindow;
    sf::Event           mainWindowEvent;
    sf::Clock           mainClock;
    sf::Time            movimentTime;
    sf::RectangleShape  middleLine;
    Player             *rightPlayer,
                       *leftPlayer;
    
    //  Initializers
    void               init_window(),
                       init_middle_line(),
                       init_players();
    
public:
    //  Game Functions:
                        Game();
    void                run(),
                        process_events(),
                        process_live_events(),
                        show();
};

#endif
