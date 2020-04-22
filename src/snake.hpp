#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "field.hpp"

class Snake : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    
    Snake();
    ~Snake();

};


#endif