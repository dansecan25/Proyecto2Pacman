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
    this->initFonts(); //inits the font
    this->initObjects(); //inits backgound
    this->initTextures(); //nothingf
    this->initBoard(); //inits cells
    this->initVariables(); //inits the enemies
    this->initLevel(); //inits data
}


/**
 * @brief constructor to state GameScreen
 */
GameWindow::~GameWindow() {
    this->pathFinding1->cleanLists();
    this->pathFinding2->cleanLists();

    // Free memory from cells matrix
    for (int i = 0; i < 18; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    delete this->data;
    delete this->enemy1;
    delete this->enemy2;
    delete this->enemy3;
    delete this->enemy4;
    delete this->path1;
    delete this->path2;
    delete this->path3;
    delete this->path4;
    delete this->pathFinding1;
    delete this->pathFinding2;

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
    if(inputClock.getElapsedTime().asSeconds()>0.5f){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)){
            data->resetValues();
            data->nextLevel();
            this->reposition=true;
            if(this->data->getLevel()==2){
                pathFinding1->cleanLists();
            }
            if(this->data->getLevel()==3){
                pathFinding1->cleanLists();

            }
            if(this->data->getLevel()==4){
                pathFinding1->cleanLists();
                pathFinding2->cleanLists();
            }
            this->turn=0;
            inputClock.restart();
        }
        //calculate pathfinding every second and move the enemy

    }
    static sf::Clock moveCLock;
    if(moveCLock.getElapsedTime().asSeconds()>1.0f){
        int actualLevel=data->getLevel();
        //when 6 turns have passed, reset turn counter
        if(enemy1->getLife()){
            if(actualLevel>=1){
                if((path1->getLen()<=0|| this->turn>=path1->getLen()-1)&& this->turn!=0){
                    this->endState();
                }else if(path1->getLen()!=0&&this->turn>=15){
                    pathFinding1->cleanLists();
                    this->turn=0; //if reached the maximum turns
                }
            }
        }
        if(enemy2->getLife()){
            if(actualLevel>=2){
                if(actualLevel==2){
                    //do what bactracking needs
                }else{
                    if((path2->getLen()<=0|| this->turn>=path2->getLen()-1 )&& this->turn!=0){
                        this->endState();
                    }else if(path2->getLen()!=0&&this->turn>=15){
                        pathFinding2->cleanLists();
                        this->turn=0; //if path is empty, reset turn counter
                    }
                }
            }
        }
        if(enemy3->getLife()){
            if(actualLevel>=3){
                //do something else
            }
        }
        if(enemy4->getLife()){
            if(actualLevel>=4){
                //do something else
            }
        }
        if(this->turn==0) {
            if(enemy1->getLife()) {
                if (actualLevel >= 1) {
                    path1 = pathFinding1->calculatePath(this->enemy1->getPosNumber(), 99);
                }
            }
            if(enemy2->getLife()){
                if(actualLevel>=2){
                    if(actualLevel==2){
                        //the paths is backtracking made
                    }else{
                        path2 = pathFinding2->calculatePath(this->enemy2->getPosNumber(), 99);
                    }
                }
            }
            if(enemy4->getLife()) {
                if (actualLevel >= 3) {
                    //change it to backtracking
                    //path3 = pathFinding3->calculatePath(this->enemy3->getPosNumber(), 99);
                }
            }
            if(enemy4->getLife()) {
                if (actualLevel >= 4) {
                    //change it to backtracking
                    //path4 = pathFinding3->calculatePath(this->enemy4->getPosNumber(), 99);
                }
            }
        }
        //will move 1 enemy
        if(enemy1->getLife()) {
            if (actualLevel >= 1) {
                Cell *cellToMove = this->data->findCell(path1->getInt(turn + 1));
                this->enemy1->rePosition(cellToMove); //reasigns the cell location in the new position given

            }
        }
        if(enemy2->getLife()) {
            if (actualLevel >= 2) {
                if (actualLevel == 2) {

                } else {
                    this->enemy2->rePosition(this->data->findCell(
                            path2->getInt(turn + 1))); //reasigns the cell location in the new position given
                }
            }
        }
        if(enemy3->getLife()) {
            if (actualLevel >= 3) {
                //this->enemy3->rePosition(this->data->findCell(path3->getInt(turn + 1))); //reasigns the cell location in the new position given
            }
        }
        if(enemy4->getLife()) {
            if (actualLevel >= 4) {
                //this->enemy4->rePosition(this->data->findCell(path4->getInt(turn + 1))); //reasigns the cell location in the new position given
            }
        }
        this->turn+=1;
        moveCLock.restart();
    }
    if(data->pointsAreEaten()){ //hacer funcion que revise si ya se recogieron todos los puntos &&allCollected
        data->resetValues();
        data->nextLevel();
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
    if(getQuit()){
        return;
    }
    renderHub(); //renders the hub
    this->data->render(); //renders the obstacles in and points in the
    renderEnemies();
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
    this->path1=new IntegerLinkedList();
    this->path2=new IntegerLinkedList();
    this->path3=new IntegerLinkedList();
    this->path4=new IntegerLinkedList();

    this->turn=0;
    this->pathSize=0;
    this->pathFinding1=new PathFinding(cells);
    this->pathFinding2=new PathFinding(cells);


    this->reposition=true; //true so when the game starts, it repositions only once the enemies
    //gen random cell id and check if it is occupied or not
    this->enemy1=new Enemy(this->window,"Enemy1",true, checkForEmpty(),this->cells);
    this->enemy2=new Enemy(this->window,"Enemy2",true, checkForEmpty(),this->cells);
    this->enemy3=new Enemy(this->window,"Enemy2",true, checkForEmpty(),this->cells);
    this->enemy4=new Enemy(this->window,"Enemy2",true, checkForEmpty(),this->cells);

}
/**
 * @brief inits the textures
 */
void GameWindow::initTextures() {
//    this->textures->insertNode("PlayerTexture","../Resources/Images/SpaceShipPlayer.png");
}
/**
 * @brief initiates the matrix of cells in the board
 */
void GameWindow::initBoard() {
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
            cells[i][j] = Cell(x, y, x+30, y+30, id, false, true, "NONE", window,j,i);
            x += 30;
            id += 1;
        }
        y += 30;
    }
    //inits the hub rectangle
    hub=sf::RectangleShape(sf::Vector2f(1100.f,60.f));//dimensions of hub



}
/**
 * @brief defines the data variable with the data of the game
 */
void GameWindow::initLevel() {
    this->data=new LevelData(this->window, this->cells,&this->font);
}
/**
 * @brief renders the hub with texts and the rectangle
 */
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
/**
 * @brief generates a random id number of a cell that has NONE item on it and is as far as posible from the player
 */
Cell* GameWindow::checkForEmpty() {
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());  // Seed the random number generator

    std::uniform_int_distribution<int> distribution(0, 593);  // Define the range of random numbers
    
    int randomNumber = distribution(gen);  // Generate a random number
    //checks if the number is with object NONE if not, generates a new number
    int rows=18;
    int columns =33;
    for (int i =0;i<rows;i++){
        for(int j =0;j<columns;j++){
            if(cells[i][j].getNumber()==randomNumber){
                if(cells[i][j].getObject()=="NONE" && !cells[i][j].isObstacle()){
                    return &cells[i][j];
                }else{
                    return checkForEmpty(); //if the cell is not empty or is an obstacle, do it again
                }
            }
        }
    }
    return nullptr;
}
/**
 * @brief renders the enemies by level
 */
void GameWindow::renderEnemies() {
    int level = data->getLevel();
    //draws the enemies on the board depending on the level
    if(level==1){
        if(this->reposition){
            this->enemy1->rePosition(checkForEmpty());
            this->reposition=false;
        }
        this->enemy1->render();
    }else if(level==2){
        if(this->reposition){
            this->enemy1->rePosition(checkForEmpty());
            this->enemy2->rePosition(checkForEmpty());
            this->reposition=false;
        }

        this->enemy1->render();
        this->enemy2->render();
    }else if(level==3){
        if(this->reposition){
            this->enemy1->rePosition(checkForEmpty());
            this->enemy2->rePosition(checkForEmpty());
            this->enemy3->rePosition(checkForEmpty());
            this->reposition=false;
        }

        this->enemy1->render();
        this->enemy2->render();
        this->enemy3->render();
    }else if(level==4){
        if(this->reposition){
            this->enemy1->rePosition(checkForEmpty());
            this->enemy2->rePosition(checkForEmpty());
            this->enemy3->rePosition(checkForEmpty());
            this->enemy4->rePosition(checkForEmpty());
            this->reposition=false;
        }

        this->enemy1->render();
        this->enemy2->render();
        this->enemy3->render();
        this->enemy4->render();
    }
}

