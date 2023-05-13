//
// Created by dansecan on 11/05/23.
//

#ifndef PROYECTO2PACMAN_PATHFINDING_H
#define PROYECTO2PACMAN_PATHFINDING_H
#include "Cell.h"
#include "../DataStructures/IntegerLinkedList.h"

class PathFinding {
public:
    PathFinding();
    ~PathFinding();
    static int manhattanDistance(int posObjectiveRow, int posObjectiveColumn,int posObjectRow, int posObjectColumn);
    IntegerLinkedList* calculatePath(Cell** cells, int positionNumber, int destinationNumber);
private:
    IntegerLinkedList* openList;
    IntegerLinkedList* closedList;
    IntegerLinkedList* route;
    int sideMove;
    int diagonal;
    Cell** cells;

    int objectiveCol;
    int objectiveRow;
    void setObjectivePositions(int id);
    void assignManhattan(int destination, int start);
    void calcCost(int destination,int start);

};


#endif //PROYECTO2PACMAN_PATHFINDING_H
