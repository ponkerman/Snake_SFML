#include "bonus.hpp"

Bonus::Bonus(int x, int y)

{
    
    if(!bonus_texture.loadFromFile("assets/bonus_texture.png"))
        throw std::runtime_error("texture file not found");
    bonus.setSize(sf::Vector2f(UNIT_SIZE_P,UNIT_SIZE_P));
    bonus.setPosition(UNIT_SIZE_P * x, UNIT_SIZE_P * y);
    bonus.setTexture(&bonus_texture);
    
    setBonus(bonus);
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform(); 
    target.draw(bonus, states);
}

void Bonus::update(sf::Time delta){
    /*
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;
    while (timeBuffer >= sf::seconds(0.5))
    {
        
        timeBuffer -= sf::seconds(1);
    }
    */
}

Bonus::~Bonus()
{

}