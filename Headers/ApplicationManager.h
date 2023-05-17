//
// Created by dansecan on 27/04/23.
//

#ifndef PROYECTO2PACMAN_APPLICATIONMANAGER_H
#define PROYECTO2PACMAN_APPLICATIONMANAGER_H
#define WINDOW_WIDTH 990
#define WINDOW_HEIGHT 600

#include "WindowState.h"
#include "Socket.h"
class ApplicationManager {

private:
    sf::RenderWindow * mainWindow; //will store the window
    sf::Event sfEvent;
    sf::RectangleShape generalBackGround;
    sf::Texture generalBackGroundTexture;
    sf::Clock dtClock;
    float dt;

    WindowStateStack* states;
    void createWindow();
    void initWindowState();
    void renderBackgroundGeneral();
    void initGeneralBackground();
    Socket socket;

public:
    ApplicationManager();
    virtual ~ApplicationManager();
    void run();
    void endApp();
    void updateDt();
    void update();
    void render();
    void updateEvents();


};


#endif //PROYECTO2PACMAN_APPLICATIONMANAGER_H
