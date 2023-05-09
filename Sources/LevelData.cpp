//
// Created by dansecan on 04/05/23.
//

#include "../Headers/LevelData.h"

LevelData::LevelData(sf::RenderWindow *window, Cell **cells, sf::Font * font) {
    this->window=window;
    this->cells = cells;
    this->font = *font;
    this->level=1;
    this->pts=0;
}

void LevelData::render() {
    for (int i = 0; i < 18; i++) {
        if(level==1){
            renderLevel1(cells[i]);
        }else if(level==2){
            renderLevel2(cells[i]);
        }else if(level==3){
            renderLevel3(cells[i]);
        }else if(level==4){
            renderLevel4(cells[i]);
        }

    }
}

void LevelData::nextLevel() {
    level+=1;
}
int LevelData::getLevel() const {
    return level;
}
void LevelData::addPts(int value) {
    pts+=value;
}
int LevelData::getPts() {
    return pts;
}

bool LevelData::inArray(int id, int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == id) {
            return true;
        }
    }
    return false;
}

void LevelData::renderLevel1(Cell *cellRow) {
    for (int j = 0; j < 33; j++) {
        int id = cellRow[j].getNumber();

        int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,26,27,28,29,30,31,32,
                     46,48,49,50,51,52,53,54,55,60,63,65,
                     67,68,69,70,71,72,73,74,76,77,78,79,88,98,
                     109,112,113,114,115,116,117,118,119,120,121,123,124,125,126,128,129,130,131,
                     132,133,134,135,136,137,138,142,145,157,164,
                     166,175,182,183,184,185,186,187,188,189,190,194,197,
                     199,201,202,203,204,206,208,210,211,223,225,226,227,228,230,
                     232,241,246, 260,263,
                     265,270,279,282,281,282,283,284,285,286,287,288,289,293,296,
                     298,300,301,302,303,307,312,329,
                     331,336,340,341,342,343,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,361,362,
                     364,366,367,368,369,370,371,373,378,381,383,
                     406,411,414,416,419,422,426,
                     429};
        int size = sizeof(arr) / sizeof(arr[0]);
        if(inArray(id, arr, size)){
            sf::RectangleShape rect(sf::Vector2f(30,30));
            rect.setPosition(cellRow[j].getX1(),cellRow[j].getY1());
            rect.setFillColor(sf::Color::Blue);
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color::Blue);
            cellRow[j].setObstacle(true);
            this->window->draw(rect);
        }



    }
}

void LevelData::renderLevel2(Cell *cellRow) {

}

void LevelData::renderLevel3(Cell *cellRow) {

}

void LevelData::renderLevel4(Cell *cellRow) {

}
