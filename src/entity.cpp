#include "entity.hpp"

/*----------------------*/
#include <iostream>
void dout() { std::cerr << endl; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
/*-------------------------*/

std::vector<sf::Vector2f> Entity::snakeCoord(0);
sf::Vector2f Entity::bonusCoord(0,0);
bool Entity::isConsumed(false);

Entity::Entity()

{
    dout("Entity::Entity():", bonusCoord.x, bonusCoord.y);
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

bool Entity::checkBonus(){
    if(snakeCoord.size() != 0){
        dout("bonus Entity::checkBonus():", bonusCoord.x, bonusCoord.y );
        dout("snake Entity::checkBonus():", snakeCoord[0].x, snakeCoord[0].y);
        if(snakeCoord[0].x == (bonusCoord.x) && snakeCoord[0].y == (bonusCoord.y)){
            isConsumed = true;
            dout("found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            return true;
        }
    }
    dout("checkBonus ended!");
    return false;
}

Entity::~Entity()
{
    dout("Entity::~Entity():", bonusCoord.x, bonusCoord.y);
}



















