#include "Ball.hpp"

Ball::Ball()
{   
    goingRight=true, goingDown=true;
    
    ballCircle.setRadius(10);
    to_center();
}

void Ball::to_center()
{   
    positionX=590, positionY=327;  // Updating the data
    goingRight = (goingRight) ? false : true; // Invert
    ballCircle.setPosition(sf::Vector2f(positionX, positionY));
}

void Ball::move(sf::Time timeReference)
{   
    //  Converting the time to an integer:
    short moviment = 0.55 /* Speed */ * timeReference.asMilliseconds();
    
    //  Validating moviments in Y axis:
    if (positionY-moviment<0)          goingDown=true;
    else if (positionY+moviment>=655)  goingDown=false;
    
    //  Calculating the positionY:
    if (goingDown) positionY += moviment;
    else           positionY -= moviment;
    
    if (goingRight) positionX += moviment;
    else            positionX -= moviment;

    //  Moving the Ball
    ballCircle.setPosition(sf::Vector2f(positionX, positionY));
}

void Ball::make_colision(sf::RectangleShape playerPaddle)
{   
    // If The ball collides with the paddle:
    if (ballCircle.getGlobalBounds().intersects(playerPaddle.getGlobalBounds()))
    {   
        if (positionX<597)    goingRight=true;
        else                  goingRight=false;
    }
    
    // If the ball reach the limits in X of the sides window:
    if (positionX <= -80 || positionX >= 1300)
    {   
        to_center();
    }
}

sf::CircleShape Ball::get_ball()  // To print...
{   
    return ballCircle;
}
