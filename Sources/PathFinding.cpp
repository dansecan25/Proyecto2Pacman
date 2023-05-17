//
// Created by dansecan on 11/05/23.
//

#include "../Headers/PathFinding.h"

PathFinding::PathFinding(Cell** cells) {
    this->sideMove=10;
    this->openList=new IntegerLinkedList();
    this->closedList=new IntegerLinkedList();
    this->route=new IntegerLinkedList();
    this->cells= cells;
    this->objectiveCol=0;
    this->objectiveRow=0;
}
/**
 * @brief calculates the manhattan distance
 * @param posObjectiveRow int
 * @param posObjectiveColumn int
 * @param posObjectRow int
 * @param posObjectColumn int
 * @return int
 */
int PathFinding::manhattanDistance(int posObjectiveRow, int posObjectiveColumn, int posObjectRow, int posObjectColumn) {
    return abs(posObjectRow - posObjectiveRow) + abs(posObjectColumn - posObjectiveColumn);
}
/**
 * @brief calculates the pathfinding algorithm
 * @param positionNumber int
 * @param destinationNumber int
 * @return IntegerLinkedList*
 */
IntegerLinkedList *PathFinding::calculatePath(int positionNumber, int destinationNumber) {
    //firstly assign manhattan distance to all cells
    setObjectivePositions(destinationNumber); //sets where is the objective
    assignManhattan(destinationNumber,positionNumber); //assigns manhatan to all cells
    //calculates the value for all cells
    std::cout<<"Position: "<<positionNumber<<std::endl;
    printLists();
    calcCost(destinationNumber,positionNumber);
    //printLists();
    //calculates the route
    setRoute(positionNumber,destinationNumber);
    printRoute();
    return route;
}

PathFinding::~PathFinding() {
}
/**
 * @brief assigns manhattan to the cells
 * @param destination int
 * @param start int
 */
void PathFinding::assignManhattan(int destination, int start) {
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cells[i][j].setManhattan(manhattanDistance(objectiveRow,this->objectiveCol,i,j));
        }
    }
}
/**
 * @brief sets the col and row locations for the end cell for using in manhattan
 * @param id int
 */
void PathFinding::setObjectivePositions(int id) {
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(cells[i][j].getNumber()==id){
                this->objectiveCol=j;
                this->objectiveRow=i;
                return;
            }
        }
    }
}
/**
 * @brief calculates the heuristic for all cells
 * @param destination int
 * @param start int
 */
void PathFinding::calcCost(int destination, int start) {
    if(this->openList->getLen()>0 ||this->closedList->getLen()>0 ||this->route->getLen()>0 ){
        cleanLists();
    }
    int currentID=start;
    openList->insertNode(currentID);
    int columns=33;
    int rows=18;
    Cell* currentCell= getCell(currentID);
    //printLists();
    while(true){ //goes through all the cells until it reaches the end
        //check if manhattan is 0
        if(currentCell->getManhattan()<=1){
            closedList->insertNode(currentID);
            openList->deleteData(currentID);
            break;
        }
        //std::cout<<"ID in loop: "<<currentID<<std::endl;
        //gets the adyacents of each cell
        IntegerLinkedList* tempAdyacents=getAdyacents(currentID);
        //std::cout<<"Adyacents of "<<currentID<<" :";
        auto* adyacents=new IntegerLinkedList();
        //if adyacents are in open list or in closed list, discard those
        for(int i=0;i<tempAdyacents->getLen();i++){
            if(!inOpen(tempAdyacents->getInt(i))&&!inClosed(tempAdyacents->getInt(i))){
                adyacents->insertNode(tempAdyacents->getInt(i));
            }
        }
        //free adyacents memory
        while(tempAdyacents->getLen()!=0){
            tempAdyacents->deleteLast();
        }
        delete tempAdyacents;
        //printAdyacents(adyacents);
        //adds the adyacents to the open list, if not in closed list or open list
        bool addedAdyacent=false;
        if(adyacents->getLen()>0){//if there are adyacents that are not in the openList
            //give the adyacents that are not in open list the past cost as
            //now adyacents must be added to open list if not in closed list
            for(int z=0;z<adyacents->getLen();z++){
                int adyacent=adyacents->getInt(z);
                this->openList->insertNode(adyacent);
                //gives the adyacent as past cost, the cost of the current cell plus the move
                auto currentAdyacent= getCell(adyacents->getInt(z));
                currentAdyacent->setPastCost(currentCell->getPastCost()+sideMove);
            }
            //sets the heuristic movement cost for the cell
            for(int z=0;z<adyacents->getLen();z++){
                auto currentAdyacent= getCell(adyacents->getInt(z));
                if(currentAdyacent!= nullptr){
                    int cost=currentAdyacent->getPastCost(); //add a value that adds the past cost
                    int manhattan=currentAdyacent->getManhattan();
                    currentAdyacent->setHeuristic(cost+manhattan);
                }
            }
            //free adyacents memory
            while(adyacents->getLen()!=0){
                adyacents->deleteLast();
            }

        }
        delete adyacents;
        //decide to which of the open list to move
        if(!inClosed(currentID)){
            openList->deleteData(currentID);
            closedList->insertNode(currentID);
        }
        currentID=moveNext();
        currentCell=getCell(currentID);
    }

}
/**
 * @brief finds the cell in the matrix
 * @param id int
 * @return Cell*
 */
Cell *PathFinding::getCell(int id) {
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(id==cells[i][j].getNumber()){
                return &cells[i][j];
            }
        }
    }
    return nullptr;
}
/**
 * @brief seacrhes the the cell in open list with the least cost
 * @return int
 */
int PathFinding::moveNext() {
    int nextCell=openList->getInt(0);
    for(int i=0;i<openList->getLen();i++){
        auto currentCell=getCell(openList->getInt(i));
        auto leastCell=getCell(nextCell);
        if(currentCell->getHeuristic()<=leastCell->getHeuristic()){
            nextCell=openList->getInt(i);
        }
    }
    return nextCell;
}
/**
 * @brief prints openlist and closed list
 */
void PathFinding::printLists() {
    std::cout<<"Open List: ";
    if(openList->getLen()!=0){
        for(int i=0;i<openList->getLen();i++){
            std::cout<<openList->getInt(i)<<", ";
        }
    }
    std::cout<<""<<std::endl;
    std::cout<<"Closed List: ";
    if(closedList->getLen()!=0){
        for(int i=0;i<closedList->getLen();i++){
            std::cout<<closedList->getInt(i)<<", ";
        }
    }
    std::cout<<""<<std::endl;


}
/**
 * @brief delets data in the closed and open list and route
 */
void PathFinding::cleanLists() {
    if(openList->getLen()!=0 && closedList->getLen()!=0){
        while(openList->getLen()>0){
            openList->deleteLast();
        }
        while(closedList->getLen()>0){
            closedList->deleteLast();
        }
    }
    int rows=18;
    int columns=33;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cells[i][j].setPastCost(0);
            cells[i][j].setHeuristic(0);
        }

    }
    while(route->getLen()>0){
        route->deleteLast();
    }
}
/**
 * @brief checks if a value is in the closed list
 * @param value int
 * @return true if it is, false if not
 */
bool PathFinding::inClosed(int value) {
    for(int i=0;i<closedList->getLen();i++){
        if(closedList->getInt(i)==value){
            return true;
        }
    }
    return false;
}
/**
 * @brief checks if a value is in the open list
 * @param value int
 * @return true if it is, false if not
 */
bool PathFinding::inOpen(int value) {
    for(int i=0;i<openList->getLen();i++){
        if(openList->getInt(i)==value){
            return true;
        }
    }
    return false;
}
/**
 * @brief gets the cells that are adyacent to the current cell
 * @param value int
 * @return IntegerLinkedList*
 */
IntegerLinkedList *PathFinding::getAdyacents(int value) {
    int columns=33;
    int rows=18;
    auto* adyacents=new IntegerLinkedList();
    Cell* currentCell=getCell(value);
    int i=currentCell->getRow();
    int j=currentCell->getCol();
    //gets the cells adyacent to the current cell
    if(j==0){ //if the cell is at the beginning
        if( i==0){//if the cell is in the top row
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
        }else if( i==rows-1){//if the cell is in the last row
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        }else{//if the cell is in between the top and bottom rows
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        }
    }else if(j==columns-1) { //if the cell is at the end of the row
        if (i != 0 && i != rows - 1) {//if the cell is at the end of the row
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        } else if (i == 0) {//if the cell is at the end of the row and in the top row
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
        } else if (i == rows - 1) {//if the cell is at the end of the row and in the last row
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        }
    }else{//if the cell is in between
        if(i!=0 && i!=rows-1){//if the cell is in between edges
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        }else if(i==0){//if the cell is in between edges and at the top
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int below=cells[i+1][j].getNumber();
            if(!getCell(below)->isObstacle()){
                adyacents->insertNode(below);//inserts the cell below
            }
        }else if(i==rows-1){//if the cell is at the end row
            int before=cells[i][j-1].getNumber();
            if(!getCell(before)->isObstacle()){
                adyacents->insertNode(before);//inserts the node before
            }
            int after=cells[i][j+1].getNumber();
            if(!getCell(after)->isObstacle()){
                adyacents->insertNode(after);//inserts the node after
            }
            int above=cells[i-1][j].getNumber();
            if(!getCell(above)->isObstacle()){
                adyacents->insertNode(above);//inserts the cell above
            }
        }

    }
    return adyacents;
}
/**
 * @brief finds the next adyacent with the least cost
 * @param adyacents IntegerLinkedList*
 * @return int
 */
int PathFinding::findNextInAdyacents(IntegerLinkedList *adyacents) {
    Cell* nextCell=getCell(adyacents->getInt(0));
    for(int i=0;i<adyacents->getLen();i++){
        Cell* current=getCell(adyacents->getInt(i));
        if(current->getHeuristic()<nextCell->getHeuristic()){
            nextCell=current;
        }
    }
    return nextCell->getNumber();
}
/**
 * @brief sets the path found
 */
void PathFinding::setRoute(int start, int end) {
    route->insertNode(start);
    int endId=closedList->getInt(closedList->getLen()-1);
    int currentID=start;
    auto* visitedNodes=new IntegerLinkedList();
    //loop while true
    while(route->getLen()!=0&&route->getInt(route->getLen() - 1) != endId) {
        //ends if the current id is the end of the closed list
        if(currentID==endId){
            route->insertNode(currentID);
            break;
        }
        //start with the actual cell position, start
        Cell *current = getCell(currentID);
        //gets the adyacents of the cell
        //checks which of this adyacents is on the closed list and and those that are not, are discarded
        //gets the adyacents of each cell
        IntegerLinkedList* tempAdyacents=getAdyacents(currentID);
        //std::cout<<"Adyacents of "<<currentID<<" :";
        auto* adyacents=new IntegerLinkedList();
        //if adyacents are in open list, discard those
        for(int i=0;i<tempAdyacents->getLen();i++){
            if(inClosed(tempAdyacents->getInt(i))&&!inList(visitedNodes,tempAdyacents->getInt(i))){//if its in the closed list
                adyacents->insertNode(tempAdyacents->getInt(i)); //remember it
            }
        }
        //printAdyacents(adyacents);
        //free adyacents memory
        while(tempAdyacents->getLen()!=0){
            tempAdyacents->deleteLast();
        }
        delete tempAdyacents;
        //checks for the adyacents to be greater than 0
        //adds the current id to visited nodes
        visitedNodes->insertNode(currentID);
        if(adyacents->getLen()>0){
            //adds the visited node to the route
            if(route->getInt(route->getLen()-1)!=currentID){
                route->insertNode(currentID);
            }
            //finds the next adyacent to move to
            int nextInRoute = findNextInAdyacents(adyacents);
            //sets the next int to visit
            currentID = nextInRoute;
            //printRoute();
        }else{//if there are no more adyacents, that path didnt work, so it returns to the previous node
            //std::cout<<"adyacents error, going back"<<std::endl;
            int lastInRoute=route->getInt(route->getLen()-1);
            if(lastInRoute==currentID){
                route->deleteLast();//returns to previous node until it finds one whre it can move
            }
            currentID=route->getInt(route->getLen()-1);
            //printRoute();
        }
    }


}
/**
 * @brief prints the route
 */
void PathFinding::printRoute() {
    std::cout<<"Route: ";
    for(int i=0;i<route->getLen();i++){
        std::cout<<route->getInt(i)<<", ";
    }
    std::cout<<" "<<std::endl;

}
/**
 * @brief prints the adyacents
 * @param list IntegerLinkedList *
 */
void PathFinding::printAdyacents(IntegerLinkedList *list) {
    for(int i=0;i<list->getLen();i++){
        std::cout<<list->getInt(i)<<", ";
    }
    std::cout<<" "<<std::endl;
}
/**
 * @brief checks if the element is in a list
 * @param list IntegerLinkedList *
 * @param value int
 * @return bool
 */
bool PathFinding::inList(IntegerLinkedList *list,int value) {
    for(int i=0;i<list->getLen();i++){
        if(list->getInt(i)==value){
            return true;
        }
    }
    return false;
}
