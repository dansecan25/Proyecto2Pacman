//
// Created by dansecan on 04/05/23.
//

#include "../Headers/Cell.h"

Cell::Cell(float x1, float y1, float x2, float y2, int number,bool obstacle, bool point, std::string object, sf::RenderWindow* window) {
    this->number=number;
    this->obstacle=obstacle;
    this->point=point;
    this->object=object;
    this->window=window;
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
}
Cell::~Cell(){
}
int Cell::getNumber() const {
    return number;
}

void Cell::setNumber(int number) {
    Cell::number = number;
}

bool Cell::isObstacle() const {
    return obstacle;
}

void Cell::setObstacle(bool obstacle) {
    Cell::obstacle = obstacle;
}

bool Cell::isPoint() const {
    return point;
}

void Cell::setPoint(bool point) {
    Cell::point = point;
}

const std::string &Cell::getObject() const {
    return object;
}

void Cell::setObject(const std::string &object) {
    Cell::object = object;
}

float Cell::getX1() const {
    return x1;
}

float Cell::getY1() const {
    return y1;
}

float Cell::getX2() const {
    return x2;
}

float Cell::getY2() const {
    return y2;
}

Cell::Cell() {
    this->number=0;
    this->obstacle=false;
    this->point=false;
    this->object="";
    this->window= nullptr;
    this->x1=0;
    this->y1=0;
    this->x2=0;
    this->y2=0;
}
