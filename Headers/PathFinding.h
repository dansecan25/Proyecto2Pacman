//

#ifndef PROYECTO2PACMAN_PATHFINDING_H
#define PROYECTO2PACMAN_PATHFINDING_H
#include "Cell.h"
#include "../DataStructures/IntegerLinkedList.h"

//
// Created by dansecan on 11/05/23.
//
class PathFinding {
public:
    explicit PathFinding(Cell** cells);
    ~PathFinding();
    int manhattanDistance(int posObjectiveRow, int posObjectiveColumn,int posObjectRow, int posObjectColumn);
    IntegerLinkedList* calculatePath(int positionNumber, int destinationNumber);
    void cleanLists();
private:
    IntegerLinkedList* openList;
    IntegerLinkedList* closedList;
    IntegerLinkedList* route;
    int sideMove;
    Cell** cells;

    int objectiveCol;
    int objectiveRow;
    void setObjectivePositions(int id);
    void assignManhattan(int destination, int start);
    void calcCost(int destination,int start);
    Cell* getCell(int id);
    int moveNext();
    void printLists();
    bool inClosed(int value);
    bool inOpen(int value);
    IntegerLinkedList* getAdyacents(int value);
    int findNextInAdyacents(IntegerLinkedList* adyacents);
    void setRoute(int start, int end);
    void printRoute();
    static void printAdyacents(IntegerLinkedList* list);
    static bool inList(IntegerLinkedList* list,int value);
};
#endif //PROYECTO2PACMAN_PATHFINDING_H