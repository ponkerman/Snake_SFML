#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "field.hpp"

class Snake : public sf::Drawable, public sf::Transformable
{
private:
    std::vector<sf::CircleShape> snake;
    sf::Texture snake_texture;
    sf::Vector2i prevDir;
    sf::Vector2i curDir;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    void update(sf::Time delta);
    void move(sf::Vector2i dir);
    void setCurDir(sf::Vector2i dir);
    Snake();
    ~Snake();

};
//TODO: ограничить выход за пределы поля
//TODO: раскрасить голову змеи

#endif