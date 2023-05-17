//
// Created by jorgegc on 15/05/23.
//

#include <random>
#include "../Headers/Character.h"


static bool moving;
static bool created= true;
static bool moveAccepted= false;
static int changePosition;
static int desiredPosition;

Character::Character(bool power,Cell** cells,LevelData* data) {
    this->power=power;
    this->cells=cells;
    this->data=data;
    this->lives=3;
}

void Character::renderCharacter() {
    std::pair<int, int> ramdonPos = randPositions();
    int p = ramdonPos.first;
    int q = ramdonPos.second;
        if(created==true) {
            int r,s,t;
            r=p/30;
            s=-2+q/30;
            t=r+s*33;
            changePosition=t;
            textureCharacter.loadFromFile("../Resources/Images/PacmanRight.png");
            spriteCharacter.setTexture(this->textureCharacter);
            positionCharacter = sf::Vector2f(p,q);
            spriteCharacter.setPosition(this->positionCharacter);
            created=false;
            return;
        }
}
void Character::moveCharacter() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        desiredPosition=changePosition-33;
        search(desiredPosition);
        if(moveAccepted){
            if(!moving && positionCharacter.y!=60) {
                positionCharacter.y -= 30.0f;
                textureCharacter.loadFromFile("../Resources/Images/PacmanUp.png");
                spriteCharacter.setTexture(textureCharacter);
                moving = true;
                changePosition=changePosition-33;//
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        desiredPosition=changePosition+33;
        search(desiredPosition);
        if(moveAccepted) {
            if (!moving && positionCharacter.y != 570) {
                positionCharacter.y += 30.0f;
                textureCharacter.loadFromFile("../Resources/Images/PacmanDown.png");
                spriteCharacter.setTexture(textureCharacter);
                moving = true;
                changePosition = changePosition + 33;
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        desiredPosition=changePosition-1;
        search(desiredPosition);
        if(moveAccepted) {
            if (!moving && positionCharacter.x != 0) {
                positionCharacter.x -= 30.0f;
                textureCharacter.loadFromFile("../Resources/Images/PacmanLeft.png");
                spriteCharacter.setTexture(textureCharacter);
                moving = true;
                changePosition = changePosition - 1;
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        desiredPosition=changePosition+1;
        search(desiredPosition);
        if(moveAccepted) {
            if (!moving && positionCharacter.x != 960) {
                positionCharacter.x += 30.0f;
                textureCharacter.loadFromFile("../Resources/Images/PacmanRight.png");
                spriteCharacter.setTexture(textureCharacter);
                moving = true;
                changePosition = changePosition + 1;
            }
        }
    }
    else
    {
        moving = false; // Si la tecla ya no está presionada, restablece el estado de movimiento a falso
    }
    // Actualizar la posición del spriteCharacter
    eatPoint();
    spriteCharacter.setPosition(positionCharacter);
}
void Character::search(int x) {
    if(data->getEnd()){
        return;
    }
    for(int i=0;i<18;i++){
        for(int j=0;j<33;j++){
            if(cells[i][j].getNumber()==x){
                if(cells[i][j].isObstacle()){
                    moveAccepted= false;
                }else{
                    moveAccepted=true;
                }
            }
        }
    }
}

std::pair<int, int> Character::randPositions() {

    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,26,27,28,29,30,31,32,
                 48,49,50,51,52,53,54,55,60,63,65,
                 67,68,69,70,71,72,73,74,76,77,78,79,88,98,
                 109,112,113,114,115,116,118,119,120,121,123,124,125,126,128,129,130,131,
                 132,133,134,135,136,137,138,142,145,157,164,
                 166,175,182,183,184,185,186,187,188,189,190,194,197,
                 199,201,202,203,204,206,208,210,211,223,225,226,227,228,230,
                 232,241,246, 260,263,
                 265,270,279,282,281,282,283,284,285,286,287,288,289,293,296,
                 298,300,301,302,303,307,312,329,
                 331,336,340,341,342,343,345,346,348,349,350,351,352,353,354,355,356,357,358,359,361,362,
                 364,366,367,368,369,370,371,373,378,381,383,
                 406,411,416,419,422,426,
                 429,431,432,433,434,435,436,437,438,439,440,443,444,447,449,459,
                 462,473,477,479,480,482,483,484,485,486,487,488,489,491,492,
                 495,497,498,499,500,501,502,503,506,510,515,525,
                 528,536,539,543,546,548,552,553,554,555,556,557,558,
                 561,569,579};
    std::srand(std::time(0)); // Inicializar la semilla con el tiempo actual
    std::pair<int, int> positions;
    int x,y,z;
    bool posAccepted=false;
    while(!posAccepted) {
        x = positions.first / 30;
        y = -2 + positions.second / 30;
        z = x + y * 33;

        for (int i = 0; i < 228; i++) {
            if (arr[i] == z) {
                posAccepted = true;
                break;
            } else {
                posAccepted = false;
                positions.first = std::rand() % 32 * 30; // Generar primer número aleatorio múltiplo de 30 entre 0 y 960
                positions.second = std::rand() % 18 * 30 + 60; // Generar segundo número aleatorio múltiplo de 30 entre 60 y 570
            }
        }
    }
    return positions;
}

int Character::getId() const {
    return changePosition;
}

void Character::eatPoint() {
    if(data->getEnd()){
        return;
    }
    for(int i=0;i<18;i++){
        for(int j=0;j<33;j++){
            if(cells[i][j].getNumber()==changePosition){
                if(cells[i][j].isPoint()){
                    cells[i][j].setPoint(false);
                    this->data->addPts(10);
                }
            }
        }
    }
}

void Character::gotHit() {
    this->lives-=1;
}

int Character::getLives() {
    return this->lives;
}


