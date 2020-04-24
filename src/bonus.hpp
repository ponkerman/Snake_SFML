#ifndef BONUS_H
#define BONUS_H

#include "entity.hpp"

class Bonus : public Entity 
{
private:
    sf::RectangleShape bonus;
    sf::Texture bonus_texture;
    void moveBonus();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Bonus(int, int);
    void update(sf::Time delta);
    void setCurPos(sf::Vector2i pos);
    ~Bonus();
};


#endif