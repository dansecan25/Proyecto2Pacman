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
}

int PathFinding::manhattanDistance(int posObjectiveRow, int posObjectiveColumn, int posObjectRow, int posObjectColumn) {
    return abs(posObjectRow - posObjectiveRow) + abs(posObjectColumn - posObjectiveColumn);
}
