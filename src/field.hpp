#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include <array>

class Field : public sf::Drawable, public sf::Transformable
{
private:
    std::vector<std::vector<sf::RectangleShape>> map;
    sf::Texture m_tileset;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Field();
    ~Field();
};








#endif