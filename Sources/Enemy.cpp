//
// Created by dansecan on 10/05/23.
//

#include "../Headers/Enemy.h"

Enemy::Enemy(sf::RenderWindow *window, std::string name, int lifePts, Cell *currentCell,Cell **cells) {
    this->window=window;
    this->name=name;
    this->life=lifePts;
    this->currentCell=currentCell;
    this->tempEnemy=sf::RectangleShape(sf::Vector2f(20,20));
    this->cells=cells;
}

void Enemy::rePosition(Cell* newCurrent) {
    this->currentCell=newCurrent;
}

void Enemy::render() {
    tempEnemy.setPosition(currentCell->getX1(),currentCell->getY1());
    tempEnemy.setFillColor(sf::Color::Blue);
    tempEnemy.setOutlineThickness(1.f);
    tempEnemy.setOutlineColor(sf::Color::Blue);
}

int Enemy::getLife() const {
    return life;
}

const std::string &Enemy::getName() const {
    return name;
}

Cell *Enemy::getCurrentCell() const {
    return currentCell;
}
