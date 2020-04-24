#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
private:
    static std::vector<sf::Vector2f> snakeCoord;
    static sf::Vector2f bonusCoord;
protected:
    Entity();
    static bool isConsumed;
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
    virtual void update(sf::Time) = 0;
    void setBonus(const sf::RectangleShape&);
    void setSnake(const std::vector<sf::CircleShape>&, int);
    bool checkBonus();
    bool checkBorder();
    ~Entity();

};



/////////////////////////////////////////////////


#endif