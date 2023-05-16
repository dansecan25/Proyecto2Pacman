//
// Created by dansecan on 10/05/23.
//

#include "../Headers/Enemy.h"

Enemy::Enemy(sf::RenderWindow *window, std::string name, bool alive, Cell *currentCell,Cell **cells) {
    this->window=window;
    this->name=name;
    this->alive=alive;
    this->currentCell=currentCell;
    this->tempEnemy=sf::RectangleShape(sf::Vector2f(20,20));
    this->cells=cells;
}

void Enemy::rePosition(Cell* newCurrent) {
    this->currentCell=newCurrent;
}

void Enemy::render() {
    tempEnemy.setPosition(currentCell->getX1()+5,currentCell->getY1()+5);
    tempEnemy.setFillColor(sf::Color::White);
    tempEnemy.setOutlineThickness(1.f);
    tempEnemy.setOutlineColor(sf::Color::White);
    this->window->draw(this->tempEnemy);
}
/**
 * @brief gets the enemies life state
 * @return bool
 */
bool Enemy::getLife() {
    return alive;
}

const std::string &Enemy::getName() const {
    return name;
}

Cell *Enemy::getCurrentCell() const {
    return currentCell;
}

int Enemy::getPosNumber() {
    return this->currentCell->getNumber();
}

void Enemy::setAlive(bool alive) {
    this->alive = alive;
}
