//
// Created by dansecan on 11/05/23.
//

#ifndef PROYECTO2PACMAN_INTEGERLINKEDLIST_H
#define PROYECTO2PACMAN_INTEGERLINKEDLIST_H
class IntegerNode{
public:
    IntegerNode(int data);
    int getData();
    void setNext(IntegerNode* next);
    IntegerNode* getNext();
private:
    int data;
    IntegerNode* next;

};

class IntegerLinkedList {
public:
    IntegerLinkedList();
    void insertNode(int data);
    int getInt(int pos);
    void deleteNode(int pos);
    int getLen();
    void deleteLast();
private:
    IntegerNode* head;
    int len;

};


#endif //PROYECTO2PACMAN_INTEGERLINKEDLIST_H
