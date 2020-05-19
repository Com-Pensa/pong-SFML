#include "Ball.hpp"

Ball::Ball()
{   
    goingRight=true, goingDown=true;
    
    ballCircle.setRadius(10);
    to_center();
}

void Ball::to_center()
{   
    positionX=590, positionY=327;
    ballCircle.setPosition(sf::Vector2f(positionX, positionY));
}

void Ball::move(sf::Time timeReference)
{   
    short moviment = 0.55 * timeReference.asMilliseconds();
    
    //  Validating moviments in Y axis
    if (positionY-moviment<0)          goingDown=true;
    else if (positionY+moviment>=655)  goingDown=false;
    
    //  Calculating the positionY
    if (goingDown) positionY += moviment;
    else           positionY -= moviment;
    
    if (goingRight) positionX += moviment;
    else            positionX -= moviment;

    //  Moving the Ball
    ballCircle.setPosition(sf::Vector2f(positionX, positionY));
}

void Ball::make_colision(sf::RectangleShape playerPaddle)
{   
    if (ballCircle.getGlobalBounds().intersects(playerPaddle.getGlobalBounds()))
    {   
        if (positionX<597)    goingRight=true;
        else                  goingRight=false;
    }
}

sf::CircleShape Ball::get_ball()
{   
    return ballCircle;
}

void Ball::bring_to_center()
{   
    if (positionX <= -80 || positionX >= 1300)
    {   
        to_center();
    }
}