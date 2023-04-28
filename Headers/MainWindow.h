//
// Created by dansecan on 27/04/23.
//

#ifndef PROYECTO2PACMAN_MAINWINDOW_H
#define PROYECTO2PACMAN_MAINWINDOW_H
#include "WindowState.h"

class MainWindow :public WindowState{
public:
    MainWindow(sf::RenderWindow* window, WindowStateStack* states);
    virtual ~MainWindow();
    SfmlButton * startButton;
    SfmlButton * exitButton;
    SfmlButton * settingButton;

    void updateInput(const float& dt) override;
    void updateButtons();
    void renderButtons(sf::RenderTarget * target) const;
    void stateUpdate(const float& dt) override;
    void stateRender(sf::RenderTarget * target) override;
private:
    sf::Font font;
    sf::RectangleShape title;
    sf::Texture titleTexture;
    void initFonts();
    void initButtons();
    void initTitle();
    void renderTitle(sf::RenderTarget *target);


};


#endif //PROYECTO2PACMAN_MAINWINDOW_H
