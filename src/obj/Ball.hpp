#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape  ballCircle;
    short int        positionX,
                     positionY;
    bool             goingRight,
                     goingDown;
    
public:
    Ball();
    
    void  to_center(),
          bring_to_center(),
          make_colision(sf::RectangleShape playerPaddle),
          move(sf::Time timeReference);
    
    sf::CircleShape get_ball();
};

#endif
