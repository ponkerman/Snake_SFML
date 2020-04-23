#include "field.hpp"
#include <iostream>
void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    
    states.transform *= getTransform(); 
    
    //states.texture = &m_tileset;
    for(auto it : map)
        for(auto itt : it)
            target.draw(itt, states);
}


Field::Field()
: map(HEIGHT_U, vector<sf::RectangleShape>(WIDTH_U))
{
    
    if(!m_tileset.loadFromFile("assets/field_texture.png"))
        throw std::runtime_error("texture file not found");
    
    for(int i = 0; i < HEIGHT_U; i++){
        for(int j = 0; j < WIDTH_U; j++){

            map[i][j] = sf::RectangleShape(sf::Vector2f(UNIT_SIZE_P, UNIT_SIZE_P));

            map[i][j].setPosition(i * UNIT_SIZE_P, j * UNIT_SIZE_P);

            map[i][j].setTexture(&m_tileset);
        }
        
    }
    
    

}


Field::~Field(){

}