//
// Created by dansecan on 27/04/23.
//

#include "../Headers/WindowState.h"
/**
 * @brief constructor of the window state manager class
 * @param window RednerWindow pointer
 * @param states WindowStatesStack pointer
 */
WindowState::WindowState(sf::RenderWindow* window, WindowStateStack* states) {
    this->window=window;
    this->positions= {0,0,0,0,0,0};
    this->states=states;
    this->quit=false;
}
/**
 * @brief destructor of WindowState frees pointers memory
 */
WindowState::~WindowState() {

}
/**
 * @brief checks if the window has been called to quit
 * @return true if quit and false if not to quit
 */
const bool &WindowState::getQuit() const {
    return this->quit;
}
/**
 * @brief updates all the mouse positions that are stored
 */
void WindowState::updateMousePosScreen() {
    this->positions.posXi = sf::Mouse::getPosition().x;
    this->positions.posYi = sf::Mouse::getPosition().y;

    this->positions.posXu=sf::Mouse::getPosition(*this->window).x;
    this->positions.posYu=sf::Mouse::getPosition(*this->window).y;

    this->positions.posXf=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)).x;
    this->positions.posYf=this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)).y;
}

void WindowState::endState() {
    this->quit=true;

}