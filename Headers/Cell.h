//
// Created by dansecan on 04/05/23.
//

#ifndef PROYECTO2PACMAN_CELL_H
#define PROYECTO2PACMAN_CELL_H


#include <iostream>
#include "SfmlButton.h"



class Cell {
public:
    Cell();
    Cell(float x1, float y1, float x2, float y2,int number,bool obstacle, bool point, std::string object, sf::RenderWindow* window, int col, int row);
    ~Cell();
    float getX1() const;
    float getY1() const;
    float getX2() const;
    float getY2() const;
    int getNumber() const;
    bool isObstacle() const;
    void setObstacle(bool obstacle);
    bool isPoint() const;
    void setPoint(bool point);
    const std::string &getObject() const;
    void setObject(const std::string &object);
    int getManhattan() const;
    void setManhattan(int manhattan);
    int getHeuristic() const;
    void setHeuristic(int heuristic);
    int getCol() const;
    int getRow() const;

private:
    int number;
    bool obstacle;
    bool point;
    int col;
    int row;
    std::string object;
    sf::RenderWindow* window;
    float x1;
    float y1;
    float x2;
    float y2;
    int manhattan;
    int heuristic; //value of the cost of movement + the id
    int pastCost;
public:
    int getPastCost() const;

    void setPastCost(int pastCost);


};


#endif //PROYECTO2PACMAN_CELL_H
