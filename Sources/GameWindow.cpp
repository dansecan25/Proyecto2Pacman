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
GameWindow::GameWindow(sf::RenderWindow* window, WindowStateStack* states):WindowState(window,states){
    this->initFonts();
    this->initVariables();
    this->initObjects();
    this->initTextures();
    this->initTablero();
    this->initLevel();
}


/**
 * @brief constructor to state GameScreen
 */
GameWindow::~GameWindow() {
    // Free memory from cells matrix
    for (int i = 0; i < 18; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}
/**
 * @brief updates the inputs events on the current state of the window
 * @param dt const float reference
 */
void GameWindow::updateInput(const float &dt) {
    //add to do something when a key is pressed
    if(data->getEnd()){
        this->endState(); //replace to win screen
    }
    static sf::Clock inputClock; //prevents key spam
    if(inputClock.getElapsedTime().asSeconds()>1.0f){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)){
            data->resetValues();
            data->nextLevel();
            inputClock.restart();
        }
    }


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
 * @brief loads the font to the font attribute
 */
void GameWindow::initFonts() {
    if (!this->font.loadFromFile("../Resources/Fonts/arial.ttf"))
    {
        exit(200); //200 will be the unique code for this space
    }
}
/**
 * @brief states what will be drawn in the window
 * @param target RenderTarget pointer
 */
void GameWindow::stateRender(sf::RenderTarget * target) {
    if(!target){
        target=this->window;
    }
    renderHub();
    this->data->render();
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
    int columns = 33;
    int rows = 18;
    float y = 60;
    int id = 0;

    // allocate memory for the matrix
    cells = new Cell*[rows];
    for (int i = 0; i < rows; i++) {
        cells[i] = new Cell[columns];
    }

    //initialize each cell in the matrix
    for (int i = 0; i < rows; i++) {
        float x = 0;
        for (int j = 0; j < columns; j++) {
            cells[i][j] = Cell(x, y, x+30, y+30, id, false, false, "NONE", window);
            x += 30;
            id += 1;
        }
        y += 30;
    }
    //inits the hub rectangle
    hub=sf::RectangleShape(sf::Vector2f(1100.f,60.f));//dimensions of hub



}

void GameWindow::initLevel() {
    this->data=new LevelData(this->window, this->cells,&this->font);
}

void GameWindow::renderHub() {
    this->hub.setPosition(0.f,0.f);
    this->hub.setFillColor(sf::Color::White);
    this->window->draw(this->hub);
    //sets the fonts for the hub texts
    this->levelText.setFont(this->font);
    this->lifeText.setFont(this->font);
    this->ptsText.setFont(this->font);
    //sets the string of the texts
    this->levelText.setString("Level: "+std::to_string(this->data->getLevel()));
    this->lifeText.setString("Life points: "+std::to_string(0));
    this->ptsText.setString("Points: "+std::to_string(this->data->getPts()));
    //sets the fill color for the texts
    this->levelText.setFillColor(sf::Color::Black);
    this->lifeText.setFillColor(sf::Color::Black);
    this->ptsText.setFillColor(sf::Color::Black);
    //sets the char size in the hub
    this->levelText.setCharacterSize(15);
    this->lifeText.setCharacterSize(15);
    this->ptsText.setCharacterSize(15);
    //sets the position of the texts
    this->levelText.setPosition(50,20);
    this->lifeText.setPosition(300,20);
    this->ptsText.setPosition(700,20);
    //draws the texts
    this->window->draw(this->levelText);
    this->window->draw(this->lifeText);
    this->window->draw(this->ptsText);
}

