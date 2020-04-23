#include "snake.hpp"
#include <iostream>

Snake::Snake()
: snake(START_LEN)
, prevDir(0,0)
, curDir(1,0)
{
    
    if(!snake_texture.loadFromFile("assets/snake_texture.png"))
        throw std::runtime_error("texture file not found");

    for(int i = 0; i < START_LEN; i++){
        snake[i] = sf::CircleShape(UNIT_SIZE_P/2);
        snake[i].setPosition(UNIT_SIZE_P * HEIGHT_U / 2 - i * UNIT_SIZE_P, UNIT_SIZE_P * WIDTH_U / 2);
        snake[i].setTexture(&snake_texture);
    }

    setSnake(snake, START_LEN);
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); 
    for(auto it : snake)
        target.draw(it, states);
}

void Snake::move(sf::Vector2i dir){
    snake.push_back(*snake.begin());
	std::rotate(snake.rbegin(), snake.rbegin() + 1, snake.rend());
	snake.pop_back();
    sf::Vector2f pos = snake[0].getPosition();
	snake[0].setPosition(sf::Vector2f(pos.x + dir.x * UNIT_SIZE_P, pos.y + dir.y * UNIT_SIZE_P));
}

void Snake::update(sf::Time delta){
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;
    while (timeBuffer >= sf::seconds(0.5))
    {
        move(curDir);
        timeBuffer -= sf::seconds(1);
    }
    
}

void Snake::setCurDir(sf::Vector2i dir){
    
    if(dir == oppositeDir(curDir)) return;
    curDir = dir;
}

sf::Vector2i Snake::oppositeDir(sf::Vector2i dir){
    sf::Vector2i opDir = dir;
    opDir.x *= -1;
    opDir.y *= -1;
    return opDir;
}

void Snake::expand(){
    auto last = &snake.back();
    snake.push_back(sf::CircleShape(UNIT_SIZE_P/2));
    snake.back().setPosition(last->getPosition().x + oppositeDir(curDir).x, 
                             last->getPosition().y + oppositeDir(curDir).y);
    snake.back().setTexture(&snake_texture);
    
}

Snake::~Snake(){

}