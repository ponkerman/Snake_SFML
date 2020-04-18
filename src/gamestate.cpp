#include "gamestate.hpp"
#include "game.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

/*
template <class T> std::string to_string(T param){
    std::string str = "";
    std::stringstream ss;
    ss<<param;
    std::getline(ss,str);
    return str;
}


template <typename T> void centerOrigin(T& drawable){
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width/2, bound.height/2);
}
*/

GameState::GameState(Game *game) : m_game(game) {}
Game* GameState::getGame() const{
    return m_game;
}

//------------MenuState------------
MenuState::MenuState(Game* game) 
: GameState(game)
{
    m_text.push_back(sf::Text("start", game->getFont()));
    m_text.push_back(sf::Text("options", game->getFont()));
    m_text.push_back(sf::Text("exit", game->getFont()));
    int i = 0;
    for(auto& it : m_text){
        it.setPosition(400 , 400 + i);
        i+=50;
    }
    display_text = true;
    active_text = &m_text[0];
    active_text->setColor(sf::Color::Green);
}

void MenuState::applyPressed(){
    if(active_text == &m_text[0])
        getGame()->changeGameState(GameState::Playing);
}

void MenuState::buttonPressed(sf::Vector2i dir){
    active_text->setColor(sf::Color::White);
    if(dir.y == 1 && active_text != &m_text.back()) 
        active_text += 1;
    if(dir.y == -1 && active_text != &m_text[0]) 
        active_text -= 1;
    active_text->setColor(sf::Color::Green);    
}

void MenuState::update(sf::Time delta){
    return;
}

void MenuState::draw(sf::RenderWindow &window){
    if(display_text)
        for(auto it : m_text) window.draw(it);
}

//----------------PlayingState------------
PlayingState::PlayingState(Game* game) 
: GameState(game)
{

}

void PlayingState::applyPressed(){

}

void PlayingState::buttonPressed(sf::Vector2i dir){

}

void PlayingState::update(sf::Time delta){

}

void PlayingState::draw(sf::RenderWindow &window){

}
//------------WonState------------
WonState::WonState(Game* game) : GameState(game){

}


void WonState::applyPressed(){

}

void WonState::buttonPressed(sf::Vector2i dir){

}

void WonState::update(sf::Time delta){

}

void WonState::draw(sf::RenderWindow &window){

}
//----------------LostState----------------------
LostState::LostState(Game* game) : GameState(game){

}

void LostState::applyPressed(){

}

void LostState::buttonPressed(sf::Vector2i dir){

}

void LostState::update(sf::Time delta){

}

void LostState::draw(sf::RenderWindow &window){

}
