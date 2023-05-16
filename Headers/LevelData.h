//
// Created by dansecan on 04/05/23.
//

#ifndef PROYECTO2PACMAN_LEVELDATA_H
#define PROYECTO2PACMAN_LEVELDATA_H

#include "PathFinding.h"
class LevelData {
public:
    LevelData(sf::RenderWindow* window, Cell** cells, sf::Font * font);
    void render();
    void nextLevel();
    int getLevel() const;
    void addPts(int value);
    int getPts();
    void resetValues();
    bool getEnd() const;
    Cell* findCell(int number);
    bool pointsAreEaten();


private:
    int level;
    int pts;
    bool endState;
    Cell** cells;
    sf::Font font;
    sf::RenderWindow* window;
    void renderLevel1(Cell* cellRow);
    void renderLevel2(Cell* cellRow);
    void renderLevel3(Cell* cellRow);
    void renderLevel4(Cell* cellRow);
    bool inArray(int id, int * arr,int n);
    void renderPoints();




};


#endif //PROYECTO2PACMAN_LEVELDATA_H
