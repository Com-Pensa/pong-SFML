#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape  paddle;
    sf::Keyboard::Key   upKey,
                        downKey;
    short int           positionX,
                        positionY;
    
public:
    Player();
    
    void   set_position_x(unsigned short int position_x),
           set_up_key(sf::Keyboard::Key up_key),
           set_down_key(sf::Keyboard::Key down_key),
           move(sf::Time timeReference);
    
    sf::RectangleShape  get_paddle();
};

#endif
