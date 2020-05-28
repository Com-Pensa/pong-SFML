#ifndef GAME_HPP
#define GAME_HPP

#include "obj/Constants.hpp"
#include "obj/Player.hpp"
#include "obj/Ball.hpp"

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
    Ball               *mainBall;
    
    //  Initializers
    void               init_window(),
                       init_middle_line(),
                       init_players(),
                       init_ball();
    
public:
    //  Game Functions:
                        Game();
    void                run(),
                        process_events(),
                        process_live_events(),
                        show();
};

#endif
