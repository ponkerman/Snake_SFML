#include "entity.hpp"

Entity::Entity()

{

}

void Entity::setBonus(const sf::RectangleShape& bonus){
    bonusCoord.x = bonus.getPosition().x;
    bonusCoord.y = bonus.getPosition().y;
}

void Entity::setSnake(const std::vector<sf::CircleShape>& snake, int len){
    snakeCoord.resize(len);
    for(int i = 0; i < len; i++){
       snakeCoord[i].x = snake[i].getPosition().x;
       snakeCoord[i].y = snake[i].getPosition().y;
    }
}

sf::Vector2f Entity::checkCollision(){
    

}


Entity::~Entity()
{
}



















