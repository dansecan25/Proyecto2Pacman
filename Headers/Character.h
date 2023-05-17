//
// Created by jorgegc on 15/05/23.
//

#ifndef PROYECTO2PACMAN_CHARACTER_H
#define PROYECTO2PACMAN_CHARACTER_H

#endif //PROYECTO2PACMAN_CHARACTER_H

#include "../Headers/Cell.h"
#include "LevelData.h"

class Character {
public:
    Character(bool power, Cell** cells,LevelData* data);
    sf::RenderWindow window;
    sf::Texture textureCharacter;
    sf::Sprite spriteCharacter;
    sf::Vector2f positionCharacter;
    void renderCharacter();
    void moveCharacter();
    void search(int value);
    std::pair<int, int> randPositions();
    void gotHit();
    int getLives();


private:
    bool power;
    Cell** cells;
    int lives;
    LevelData* data;
    void eatPoint();
public:
    int getId() const;
};