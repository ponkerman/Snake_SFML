#include "snake.hpp"

Snake::Snake(int len) 
: m_currentDir(1,0)
, m_nextDir(0,0)
, cur_len(4)
{
    for (size_t i = 0; i < len; i++)
    {
        snake.push_back(sf::CircleShape());
        snake.back().setScale(UNIT_SIZE_P, UNIT_SIZE_P);
        snake.back().setFillColor(SNAKE_COLOR);
        snake.back().setPosition(HEIGHT_P/2 - i * UNIT_SIZE_P, WIDTH_P/2);
    }
    
}

vector<sf::CircleShape> Snake::getSnake(){
    return snake;
}

int Snake::get_len(){
    return cur_len;
}