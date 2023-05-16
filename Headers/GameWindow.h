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
    void initBoard();
    void initFonts();
    void initLevel();
    Cell* checkForEmpty();

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

    PathFinding* pathFinding1;
    PathFinding* pathFinding2;
    PathFinding* pathFinding3;
    PathFinding* pathFinding4;

    Enemy* enemy1;
    Enemy* enemy2;
    Enemy* enemy3;
    Enemy* enemy4;

    IntegerLinkedList* path1;
    IntegerLinkedList* path2;
    IntegerLinkedList* path3;
    IntegerLinkedList* path4;

    int turn;

    int pathSize;

    bool reposition;




    void initTextures();

public:
    explicit GameWindow(sf::RenderWindow * window,WindowStateStack* states);
    ~GameWindow() override;
    void updateInput(const float& dt) override;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
};


#endif //PROYECTO2PACMAN_GAMEWINDOW_H
