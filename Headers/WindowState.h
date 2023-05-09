//
// Created by dansecan on 27/04/23.
//

#ifndef PROYECTO2PACMAN_WINDOWSTATE_H
#define PROYECTO2PACMAN_WINDOWSTATE_H
#include "../DataStructures/WindowStateStack.h"
#include "LevelData.h"
struct mousePositions{
    int posXi;
    int posYi;
    unsigned int posXu;
    unsigned int posYu;
    float posXf;
    float posYf;
};
class WindowState {
protected:
    WindowStateStack* states;
    mousePositions positions{};
    sf::RenderWindow* window;
    bool quit;
public:
    WindowState(sf::RenderWindow* window, WindowStateStack* states);
    virtual ~WindowState();
    [[nodiscard]] const bool& getQuit() const;
    virtual void updateInput(const float& dt)=0;
    virtual void stateUpdate(const float& dt)=0;
    virtual void stateRender(sf::RenderTarget * target)=0;
    void endState();
    void updateMousePosScreen();
};


#endif //PROYECTO2PACMAN_WINDOWSTATE_H
