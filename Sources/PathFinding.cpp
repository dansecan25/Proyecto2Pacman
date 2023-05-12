//
// Created by dansecan on 11/05/23.
//

#include "../Headers/PathFinding.h"

PathFinding::PathFinding() {
    this->sideMove=10;
    this->diagonal=100000;
    this->openList=new IntegerLinkedList();
    this->closedList=new IntegerLinkedList();
    this->route=new IntegerLinkedList();
    this->cells= nullptr;
}

int PathFinding::manhattanDistance(int posObjectiveRow, int posObjectiveColumn, int posObjectRow, int posObjectColumn) {
    return abs(posObjectRow - posObjectiveRow) + abs(posObjectColumn - posObjectiveColumn);
}

IntegerLinkedList *PathFinding::calculatePath(Cell **cells, int positionNumber, int destinationNumber) {
    //firstly assign manhattan distance to all cells
    this->cells=cells;
    assignManhattan(destinationNumber,positionNumber);
    return nullptr;
}

PathFinding::~PathFinding() {
    while(openList->getLen()!=0){
        openList->deleteLast();
    }
    delete this->openList;
    while(closedList->getLen()!=0){
        closedList->deleteLast();
    }
    delete this->closedList;
    while(route->getLen()!=0){
        route->deleteLast();
    }
    delete this->route;
}

void PathFinding::assignManhattan(int destination, int start) {
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){

            //cells[i][j].setManhattan(manhattanDistance())
        }
    }
}
