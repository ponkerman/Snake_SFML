#include "snake.hpp"


void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    states.transform *= getTransform(); 
    sf::CircleShape circle(UNIT_SIZE_P);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(300,300);
    target.draw(circle, states);
}

Snake::Snake(){

}

Snake::~Snake(){

}