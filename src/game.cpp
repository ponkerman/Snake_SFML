#include "game.hpp"
#include <iostream>

Game::Game() : m_window(sf::VideoMode(800,800), "SNAKE"){
	
    if(!m_font.loadFromFile("F:/Projects/snake_SFML/assets/source-code-pro.ttf"))
        throw std::runtime_error("font file not found");
    /*
    if(!m_logo.loadFromFile("assets/logo.png"))
        throw std::runtime_error("logo file not found");
    if(!m_texture.loadFromFile("assets/texture.png"))
        throw std::runtime_error("texture file not found");
	*/
    m_gameStates[GameState::Menu] = new MenuState(this);
    m_gameStates[GameState::Playing] = new PlayingState(this);
    m_gameStates[GameState::Won] = new WonState(this);
    m_gameStates[GameState::Lost] = new LostState(this);

    changeGameState(GameState::Menu);
}

Game::~Game(){
    for(GameState* gs : m_gameStates) delete gs;
}

void Game::changeGameState(GameState::State gs){
    m_currentState = m_gameStates[gs];
}

void Game::run(){
    sf::Clock frameClock;
    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)){
            if(event.type==sf::Event::Closed)
                m_window.close();
            if(event.type==sf::Event::KeyPressed){
				if(event.key.code==sf::Keyboard::Space)
                    m_currentState->applyPressed(); // Apply
                if(event.key.code==sf::Keyboard::Left)
                    m_currentState->buttonPressed(sf::Vector2i(-1,0));// move to left
                if(event.key.code==sf::Keyboard::Right)
                    m_currentState->buttonPressed(sf::Vector2i(1,0));// move to right
                if(event.key.code==sf::Keyboard::Up)
                    m_currentState->buttonPressed(sf::Vector2i(0,-1));// move up
                if(event.key.code==sf::Keyboard::Down)
                    m_currentState->buttonPressed(sf::Vector2i(0,1));// move down
            }
        }
        m_currentState->update(frameClock.restart());
        m_window.clear();
        m_currentState->draw(m_window);
        m_window.display();
    }
}


sf::Font& Game::getFont(){
    return m_font;
}

/*
sf::Texture& Game::getLogo(){
    return m_logo;
}

sf::Texture& Game::getTexture(){
    return m_texture;
}
*/