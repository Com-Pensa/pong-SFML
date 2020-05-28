#include "Player.hpp"

Player::Player()
{   
    paddle.setSize(sf::Vector2f(paddleSize[0], paddleSize[1]));
    paddle.setFillColor(sf::Color::White);
}

// the single difference between the player X to Y:
void Player::set_position_x(unsigned short int position_x)
{   
    positionX=position_x, positionY=window[1]/2-paddleSize[1]/2;
    paddle.setPosition(sf::Vector2f(position_x, positionY));
}

//  Setting the keyboard keys to listen...
void Player::set_up_key(sf::Keyboard::Key up_key)
{   
    upKey=up_key;
}
void Player::set_down_key(sf::Keyboard::Key down_key)
{   
    downKey=down_key;
}

void Player::move(sf::Time timeReference)
{   
    // Converting the time to an integer:
    short moviment = playerVelocity * timeReference.asMilliseconds();
    
    //  Listen to keyboard:
    if (sf::Keyboard::isKeyPressed(upKey))    positionY-=moviment;
    if (sf::Keyboard::isKeyPressed(downKey))  positionY+=moviment;
    
    //  Validating moviments (don't leave the screen):
    if (positionY<0)                positionY=0;
    else if (positionY>maxPaddleY)  positionY=maxPaddleY;
    
    paddle.setPosition(sf::Vector2f(positionX, positionY));
}

sf::RectangleShape Player::get_paddle()
{   
    return paddle;
}
