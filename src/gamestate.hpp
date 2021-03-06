#ifndef GMAESTATE_H
#define GMAESTATE_H

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "bonus.hpp"
#include "field.hpp"

class Game;

class GameState{
public:
    enum State{
        Menu,
        Playing,
        Won,
        Lost,
        Count
    };
    static unsigned int record;
    static unsigned int last_try;
    GameState(Game *game);
    Game* getGame() const;
    virtual void applyPressed() = 0;
    virtual void buttonPressed(sf::Vector2i dir)=0;
    virtual void update(sf::Time delta)=0;
    virtual void draw(sf::RenderWindow& window)=0;
private:
    Game *m_game;
};

//1-------Menu------------------------
class MenuState : public GameState{
public:
    MenuState(Game *game);
    virtual void applyPressed();
    void buttonPressed(sf::Vector2i dir);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
private:
    std::vector<sf::Text> m_text;
    sf::Text* active_text;
    bool display_text;
};

//2-------Playing-------------------
class PlayingState : public GameState{
private:
    Snake snake;
    Bonus bonus;
    Field field;
public:
    PlayingState(Game *game);
    virtual void applyPressed();
    void buttonPressed(sf::Vector2i dir);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
    
};

//3--------------Won-----------------
class WonState : public GameState{
public:
    WonState(Game *game);
    virtual void applyPressed();
    void buttonPressed(sf::Vector2i dir);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
};

//4-------------Lost-----------
class LostState : public GameState{
public:
    LostState(Game *game);
    virtual void applyPressed();
    void buttonPressed(sf::Vector2i dir);
    void update(sf::Time delta);
    void draw(sf::RenderWindow& window);
private:
    sf::Text m_last_try;
    sf::Text m_record;
    sf::Text m_continue;
};
#endif //GAMESTATE_H
