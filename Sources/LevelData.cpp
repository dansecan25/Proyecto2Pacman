//
// Created by dansecan on 04/05/23.
//

#include "../Headers/LevelData.h"
/**
 * @brief constructor for the data of the game
 * @param window RenderWindow*
 * @param cells Cell**
 * @param font Font*
 */
LevelData::LevelData(sf::RenderWindow *window, Cell **cells, sf::Font * font) {
    this->window=window;
    this->cells = cells;
    this->font = *font;
    this->level=1;
    this->pts=0;
}
/**
 * @brief renders the maze
 */
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
        }else if(level==5){
            this->endState=true;
        }

    }
}
/**
 * @brief changes the level value to the next one
 */
void LevelData::nextLevel() {
    if(level<=4){
        level+=1;
    }
}
/**
 * @brief gets the level value
 * @return level int
 */
int LevelData::getLevel() const {
    return level;
}
/**
 * @brief ads points
 * @param value int
 */
void LevelData::addPts(int value) {
    pts+=value;
}
/**
 * @brief gets the points
 * @return pts int
 */
int LevelData::getPts() {
    return pts;
}
/**
 * @brief checks if an id is in an array
 * @param id int
 * @param arr int*
 * @param n int
 * @return true if in the array
 * @return false if not in array
 */
bool LevelData::inArray(int id, int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == id) {
            return true;
        }
    }
    return false;
}
/**
 * @brief Generates data for level1 maze
 * @param cellRow Cell*
 */
void LevelData::renderLevel1(Cell *cellRow) {
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

    for (int j = 0; j < 33; j++) {
        int id = cellRow[j].getNumber();

        int size = sizeof(arr) / sizeof(arr[0]);
        if(inArray(id, arr, size)){
            sf::RectangleShape rect(sf::Vector2f(30,30));
            rect.setPosition(cellRow[j].getX1(),cellRow[j].getY1());
            rect.setFillColor(sf::Color::Blue);
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color::Blue);
            cellRow[j].setObstacle(true);
            cellRow[j].setPoint(false);
            this->window->draw(rect);
        }

    }
}
/**
 * @brief generates maze for level 2
 * @param cellRow Cell*
 */
void LevelData::renderLevel2(Cell *cellRow) {
    int arr[] = {0,1,30,
                 33,34,37,39,40,41,42,43,49,50,51,52,53,57,58,59,60,61,63,
                 66,67,70,78,79,80,81,82,
                 103,106,107,108,109,110,115,122,123,124,125,126,127,128,129,130,
                 134,136,139,141,143,146,147,148,151,152,153,154,155,162,
                 165,166,167,168,169,172,174,176,188,192,193,194,195,197,
                 205,
                 231,232,233,234,235,236,238,239,242,243,244,245,246,247,248,249,250,251,252,253,254,255,258,259,260,261,
                 282,292,294,295,296,
                 297,298,299,300,302,304,305,306,307,308,309,312,314,315,317,322,327,
                 335,339,342,345,350,353,354,355,356,357,358,359,360,
                 364,366,367,368,375,376,377,378,383,387,392,
                 401,403,404,405,406,407,414,418,419,420,425,
                 430,431,432,434,444,445,446,447,448,449,455,456,457,458,
                 467,493,494,
                 495,496,497,498,499,504,505,506,507,514,516,520,522,521,525,527,
                 532,535,541,542,543,544,545,547,549,551,552,553,555,557,558,560};

    for (int j = 0; j < 33; j++) {
        int id = cellRow[j].getNumber();

        int size = sizeof(arr) / sizeof(arr[0]);
        if(inArray(id, arr, size)){
            sf::RectangleShape rect(sf::Vector2f(30,30));
            rect.setPosition(cellRow[j].getX1(),cellRow[j].getY1());
            rect.setFillColor(sf::Color(128, 0, 128));
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color(128, 0, 128));
            cellRow[j].setObstacle(true);
            cellRow[j].setPoint(false);
            this->window->draw(rect);
        }

    }

}
/**
 * @brief genartes maze for level 3
 * @param cellRow Cell*
 */
void LevelData::renderLevel3(Cell *cellRow) {
    int arr[] = {1,11,15,17,28,31,
                 34,36,37,42,46,50,52,53,54,55,56,57,58,59,61,63,64,
                 67,72,73,74,75,76,77,85,94,100,102,103,110,114,115,116,117,118,119,120,121,122,123,127,129,130,131,
                 133,136,140,143,150,156,158,159,160,162,164,
                 166,169,173,176,178,183,185,189,197,
                 199,202,204,205,206,209,211,215,216,217,218,219,220,221,222,226,230,
                 232,233,234,235,242,244,255,259,260,261,262,263,
                 277,280,282,288,292,
                 300,303,305,307,308,309,310,315,316,317,318,321,323,324,325,328,
                 330,331,333,336,338,348,349,350,351,354,358,361,
                 366,371,376,379,381,384,387,391,392,393,394,
                 396,397,401,402,403,404,407,412,414,417,420,424,426,
                 432,440,445,447,450,455,456,457,459,
                 463,463,465,473,475,476,477,478,480,492,494,
                 504,513,514,515,516,517,518,519,520,522,523,524,525,527,
                 529,530,531,532,533,536,537,538,539,540,51,542,543,560,
                 561,562,578,581,582,583,584,585,586,587,588,589,590,591,592,593};

    for (int j = 0; j < 33; j++) {
        int id = cellRow[j].getNumber();


        int size = sizeof(arr) / sizeof(arr[0]);
        if(inArray(id, arr, size)){
            sf::RectangleShape rect(sf::Vector2f(30,30));
            rect.setPosition(cellRow[j].getX1(),cellRow[j].getY1());
            rect.setFillColor(sf::Color::Red);
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color::Red);
            cellRow[j].setObstacle(true);
            cellRow[j].setPoint(false);
            this->window->draw(rect);
        }

    }

}
/**
 * @brief generates maze for level 4
 * @param cellRow Cell*
 */
void LevelData::renderLevel4(Cell *cellRow) {
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,16,18,32,
                 54,55,56,57,58,59,60,61,62,64,65,
                 68,71,72,73,74,75,76,77,79,80,81,82,83,84,87,98,
                 100,101,104,116,120,125,131,
                 134,143,155,156,160,161,164,
                 170,171,172,173,174,175,176,177,178,179,180,181,182,
                 198,200,201,202,203,204,205,206,207,212,217,218,219,220,221,222,223,224,225,226,227,228,229,
                 231,234,242,
                 275,276,279,280,281,282,283, 285,286,287,288,289,290,291,292,294,295,296,
                 297,298,299,300,301,302,303,304,305,309,315,324,
                 365,366,367,368,369,370,371,372,373,374,376,377,378,379,380,381,382,384,385,386,387,489,390,391,392,393,394,395,
                 399,428,
                 435,436,437,438,439,440,441,442,443,444,445,446,451,455,459,461,
                 462,463,464,465,466,482,486,488,492,494,
                 501,504,507,510,519,523,
                 530,531,547,550,552,556,558,
                 561,562,563,564,565,566,567,568,569,570,571,572,573,574,575,576,579,580,581,582,583,584,585,586,587,588,591,592,593};
    for (int j = 0; j < 33; j++) {
        int id = cellRow[j].getNumber();


        int size = sizeof(arr) / sizeof(arr[0]);
        if(inArray(id, arr, size)){
            sf::RectangleShape rect(sf::Vector2f(30,30));
            rect.setPosition(cellRow[j].getX1(),cellRow[j].getY1());
            rect.setFillColor(sf::Color(51,255,0));
            rect.setOutlineThickness(1.f);
            rect.setOutlineColor(sf::Color(51,255,0));
            cellRow[j].setObstacle(true);
            this->window->draw(rect);
        }

    }

}
/**
 * @brief resets the values of all the cells
 */
void LevelData::resetValues() {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 33; j++) {
            Cell cellSpace=cells[i][j];
            cellSpace.setObstacle(false);
            cellSpace.setPoint(true);
            cellSpace.setObject("None");
        }
    }

}
/**
 * @brief signals if the game ended by winning
 * @return true if ended
 * @return false if didnt end
 */
bool LevelData::getEnd() const {
    return this->endState;
}

Cell *LevelData::findCell(int number) {
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(number==cells[i][j].getNumber()){
                return &cells[i][j];
            }
        }
    }
    return nullptr;
}
