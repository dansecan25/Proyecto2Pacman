//
// Created by dansecan on 10/05/23.
//

#ifndef PROYECTO2PACMAN_ENEMY_H
#define PROYECTO2PACMAN_ENEMY_H
#include <iostream>
#include "../Headers/Cell.h"

class Enemy {
public:
    Enemy(sf::RenderWindow* window,std::string name,bool alive,Cell* currentCell,Cell **cells);
    void rePosition(Cell* newCurrent);
    void render();
    bool getLife();
    const std::string &getName() const;
    Cell *getCurrentCell() const;
    int getPosNumber();

private:
    bool alive;
    std::string name;
public:
    void setAlive(bool alive);

private:
    sf::RenderWindow* window;
    Cell* currentCell;
    sf::RectangleShape tempEnemy;
    Cell** cells;

};


#endif //PROYECTO2PACMAN_ENEMY_H
