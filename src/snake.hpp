#ifndef SNAKE_H
#define SNAKE_H

#include "entity.hpp"

class Snake : public Entity 
{
private:
    std::vector<sf::CircleShape> snake;
    sf::Texture snake_texture;
    sf::Vector2i prevDir;
    sf::Vector2i curDir;
    sf::Vector2i oppositeDir(sf::Vector2i);
    bool is_dead;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Snake();
    void expand();
    void update(sf::Time delta);
    void move(sf::Vector2i dir);
    void setCurDir(sf::Vector2i dir);
    bool isDead();
    unsigned int getLen();
    ~Snake();

};


#endif