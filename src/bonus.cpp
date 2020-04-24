#include "bonus.hpp"
/*--------------------------*/
#include <iostream>
extern void dout();
template <typename Head, typename... Tail>
extern void dout(Head H, Tail... T);
/*----------------------------*/
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
    
    //setBonus(bonus);
    if(isConsumed) {
        moveBonus();
        isConsumed = false;
    }
}

void Bonus::moveBonus(){
    dout("PlayingState started moving bonus");
    bonus.setPosition(UNIT_SIZE_P * (std::rand() % WIDTH_U), UNIT_SIZE_P * (std::rand() % HEIGHT_U));
    setBonus(bonus);
    
}

Bonus::~Bonus()
{

}