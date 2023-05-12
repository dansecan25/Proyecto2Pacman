//
// Created by dansecan on 11/05/23.
//

#ifndef PROYECTO2PACMAN_PATHFINDING_H
#define PROYECTO2PACMAN_PATHFINDING_H
#include "Cell.h"
#include "../DataStructures/IntegerLinkedList.h"

class PathFinding {
public:
    int sideMove;
    int diagonal;

    PathFinding();
    int manhattanDistance(int posObjectiveRow, int posObjectiveColumn,int posObjectRow, int posObjectColumn);
private:
    IntegerLinkedList* openList;
    IntegerLinkedList* closedList;
    IntegerLinkedList* route;


};


#endif //PROYECTO2PACMAN_PATHFINDING_H
