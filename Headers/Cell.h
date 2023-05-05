//
// Created by dansecan on 04/05/23.
//

#ifndef PROYECTO2PACMAN_CELL_H
#define PROYECTO2PACMAN_CELL_H


#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Cell {
public:
    Cell(float x1, float y1, float x2, float y2,int number,bool obstacle, bool point, std::string object, sf::RenderWindow* window);
    ~Cell();
    float getX1() const;
    float getY1() const;
    float getX2() const;
    float getY2() const;
    int getNumber() const;
    void setNumber(int number);
    bool isObstacle() const;
    void setObstacle(bool obstacle);
    bool isPoint() const;
    void setPoint(bool point);
    const std::string &getObject() const;
    void setObject(const std::string &object);

private:
    int number;
    bool obstacle;
    bool point;
    std::string object;
    sf::RenderWindow* window;
    float x1;
    float y1;
    float x2;
    float y2;


};


#endif //PROYECTO2PACMAN_CELL_H
