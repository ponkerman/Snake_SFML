#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "field.hpp"

class Snake 
{
private:

    vector<sf::CircleShape> snake;
    sf::Vector2i m_nextDir;
    sf::Vector2i m_currentDir;
    int cur_len;
public:
    int get_len();
    Snake(int);
    ~Snake();
    void update(sf::Time delta);
    void setDirection(sf::Vector2i);
    sf::Vector2i getDirection() const;
    vector<sf::CircleShape> getSnake();
};


#endif