//
// Created by dansecan on 27/04/23.
//

#include "../Headers/ApplicationManager.h"
#include "../Headers/MainWindow.h"

ApplicationManager::ApplicationManager() {
    this->states=new WindowStateStack();
    this->createWindow();
    this->initGeneralBackground();
    this->initWindowState();

}
/**
 * @brief destructor for the class and releases the memory from the pointers
 */
ApplicationManager::~ApplicationManager() {
    delete this->mainWindow;
    while(!this->states->isEmpty())
        this->states->pop(); //will go through every element from the stack and delete every one of them
    delete this->states;
}

/**
 * @brief runs the window and executes the refresing of the screen
 */
void ApplicationManager::run() {
    while (this->mainWindow->isOpen()) //
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
void ApplicationManager::endApp() {
    std::cout <<"Closing"<<"\n";
}
/**
 * @brief initializes the main screen window
 */
void ApplicationManager::createWindow() {
    sf::ContextSettings windowSettings;
    windowSettings.antialiasingLevel=0;
    this->mainWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Battle Space Project", sf::Style::Titlebar | sf::Style::Close,windowSettings);
    this->mainWindow->setFramerateLimit(60);
    this->mainWindow->setVerticalSyncEnabled(false);

}
/**
 * @brief updates the timer of execution, show the time every time its called
 */
void ApplicationManager::updateDt() {
    this->dt=this->dtClock.restart().asSeconds();
}
/**
 * @brief updates the elements of the game window
 */
void ApplicationManager::update() {
    this->updateEvents();

    if(!this->states->isEmpty()){
        this->states->peek()->stateUpdate(this->dt); //peeks the top element of the stack
        if(this->states->peek()->getQuit()){
            //here goes something if the game is quitted, if return to mainscren
            this->states->peek()->endState();
            this->states->pop(); //pop instantly frees the memory stored in the current top
        }
    }else{
        this->endApp();
        this->mainWindow->close(); //ends the app
    }
}
/**
 * @brief renders the images and objects into the window
 */
void ApplicationManager::render() {
    //takes the state that will be rendered
    this->mainWindow->clear(sf::Color::Black);
    this->renderBackgroundGeneral();
    if(!this->states->isEmpty()){ //checks if the stack is not empty
        this->states->peek()->stateRender(this->mainWindow);
    }
    //displays the content of the window
    this->mainWindow->display();
}
/**
 * @brief updates the events on the game
 */
void ApplicationManager::updateEvents() {
    sf::Event event{};
    while (this->mainWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->mainWindow->close();
    }
}
/**
 * @brief pushes a WindowState object into the stack
 */
void ApplicationManager::initWindowState() {
    this->states->push(new MainWindow(this->mainWindow,this->states));

}

/**
 * @brief draws the background for all windows
 */
void ApplicationManager::renderBackgroundGeneral() {
    //this->mainWindow->draw(this->generalBackGround);
}
/**
 * @brief initiates the background texture and shape
 */
void ApplicationManager::initGeneralBackground() {
    //this->generalBackGround.setSize(sf::Vector2f(static_cast<float>(WINDOW_WIDTH),static_cast<float>(WINDOW_HEIGHT)));
    //if (!this->generalBackGroundTexture.loadFromFile("../Resources/Images/Pacman.jpg")){
    //    exit(50);
    //}
    //this->generalBackGround.setTexture(&this->generalBackGroundTexture);
}