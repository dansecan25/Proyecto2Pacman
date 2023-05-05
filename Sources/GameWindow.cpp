//
// Created by dansecan on 27/04/23.
//

#include "../Headers/GameWindow.h"
/**
 * @brief gamesScreen state constructor
 * @param window RenderWindow pointer
 * @param mapStructures LinkedListStructured pointer
 * @param states gameStatesStack pointer
 * @param mode int
 */
GameWindow::GameWindow(sf::RenderWindow* window, WindowStateStack* states)
        :WindowState(window,states){

    this->initVariables();
    this->initObjects();
    this->initTextures();
    this->initTablero();
}


/**
 * @brief constructor to state GameScreen
 */
GameWindow::~GameWindow() {
}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameWindow::updateInput(const float &dt) {
    //add to do something when a key is pressed


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        this->endState();
    }
}
/**
 * @brief updates the events in the window
 * @param dt const float reference
 */
void GameWindow::stateUpdate(const float& dt) {
    this->updateMousePosScreen();
    this->updateInput(dt);


}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameWindow::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    this->rectTemp.setPosition(0.f,0.f);
    rectTemp.setFillColor(sf::Color::Red);
    this->window->draw(this->rectTemp);
}



/**
 * @brief init the background objects, GUI
 */
void GameWindow::initObjects() {
    //this->backGround.setSize(sf::Vector2f(static_cast<float>(1000),static_cast<float>(60)));
    //this->backGroundTexture.loadFromFile("../Resources/Images/GUI.jpg");
    //this->backGround.setTexture(backGroundTexture);

}
/**
 * @brief inits the variables
 */
void GameWindow::initVariables() {


}
/**
 * @brief inits the textures
 */
void GameWindow::initTextures() {
//    this->textures->insertNode("PlayerTexture","../Resources/Images/SpaceShipPlayer.png");
}

void GameWindow::initTablero() {
    rectTemp=sf::RectangleShape(sf::Vector2f(50.f,50.f));
    int columns=20;
    int rows=10;
    //for(int i=0;i<)




}

