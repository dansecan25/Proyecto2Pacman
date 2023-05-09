//
// Created by dansecan on 27/04/23.
//

#ifndef PROYECTO2PACMAN_GAMEWINDOW_H
#define PROYECTO2PACMAN_GAMEWINDOW_H

#include "WindowState.h"

class GameWindow : public WindowState {
private:
    sf::RectangleShape backGround;
    sf::Texture backGroundTexture;
    void initObjects();
    void initVariables();
    void initTablero();
    void initFonts();
    void initLevel();

    void renderHub();

    sf::RectangleShape hub;
    Cell** cells;
    sf::Font font;
    LevelData* data;
    sf::Text levelText;
    sf::Text lifeText;
    sf::Text ptsText;

    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Clock enemyClock;
    sf::Clock bulletClock2;


    void initTextures();

public:
    explicit GameWindow(sf::RenderWindow * window,WindowStateStack* states);
    ~GameWindow() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
};


#endif //PROYECTO2PACMAN_GAMEWINDOW_H
