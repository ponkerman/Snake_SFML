#ifndef GAME_H
#define GAME_H

#include "gamestate.hpp"
#include <SFML/Graphics.hpp>
#include <array>

class Game{
public:
    Game();
    ~Game();
    void run();
    void changeGameState(GameState::State gs);
    sf::Font& getFont();
    //sf::Texture& getLogo();
    //sf::Texture& getTexture();
private:
    sf::RenderWindow m_window;
    GameState *m_currentState;
    std::array<GameState*, GameState::Count> m_gameStates;
    sf::Font m_font;
    //sf::Texture m_logo;
    //sf::Texture m_texture;

};

#endif