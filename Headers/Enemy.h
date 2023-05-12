//
// Created by dansecan on 10/05/23.
//

#ifndef PROYECTO2PACMAN_ENEMY_H
#define PROYECTO2PACMAN_ENEMY_H
#include <iostream>
#include "../Headers/Cell.h"

class Enemy {
public:
    Enemy(sf::RenderWindow* window,std::string name,int lifePts,Cell* currentCell,Cell **cells);
    void rePosition(Cell* newCurrent);
    void render();
    int getLife() const;
    const std::string &getName() const;
    Cell *getCurrentCell() const;
    int getPosNumber();

private:
    int life;
    std::string name;
    sf::RenderWindow* window;
    Cell* currentCell;
    sf::RectangleShape tempEnemy;
    Cell** cells;

};


#endif //PROYECTO2PACMAN_ENEMY_H
