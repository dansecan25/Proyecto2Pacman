//
// Created by dansecan on 11/05/23.
//

#include <iostream>
#include "../DataStructures/IntegerLinkedList.h"
/**
 * @brief constructor for the node
 * @param data int
 */
IntegerNode::IntegerNode(int data) {
    this->data=data;
    this->next= nullptr;
}
/**
 * @brief gets the data in the node
 * @return int
 */
int IntegerNode::getData() {
    return this->data;
}
/**
 * @brief sets the pointer to the next node
 * @param next IntegerNode*
 */
void IntegerNode::setNext(IntegerNode *next) {
    this->next=next;
}
/**
 * @brief returns the direction to the next node
 * @return IntegerNode*
 */
IntegerNode *IntegerNode::getNext() {
    return this->next;
}

/**
 * @brief constructor of the linked list
 */
IntegerLinkedList::IntegerLinkedList() {
    this->head= nullptr;
    this->len=0;
}
/**
 * @brief inserts a node into the end of the list
 * @param data
 */
void IntegerLinkedList::insertNode(int data) {
    auto* newNode = new IntegerNode(data);
    newNode->setNext(nullptr);
    if(head== nullptr){
        head=newNode;
        len++;
    }else{
        IntegerNode* temp = head;
        while(temp->getNext()!= nullptr){
            temp=temp->getNext(); //moves to the next pointer
        }
        temp->setNext(newNode); //once it reaches the end, it sets the end node next pointer to the next one
        len++; //increases size of the list
    }
}
/**
 * @brief Returns the int in a certain position
 * @return int
 */
int IntegerLinkedList::getInt(int pos) {
    IntegerNode* temp;
    temp=head;
    int count=0;
    if(pos>=this->len||pos<0){
        return -10;
    }else{
        while(count!= pos){
            count++;
            temp=temp->getNext();
        }
        return temp->getData();
    }
}
/**
 * @brief deletes a node in a specific position
 * @param pos int
 */
void IntegerLinkedList::deleteNode(int pos) {
    IntegerNode * temp1=head,*temp2= head;
    if(len==0) {
        len=0;
        return;
    }else if(pos==1){//if the position is the head
        head=head->getNext();
        delete temp1;
        len--;
        return;
    }else{
        for(int i=0; i<len;i++){
            if(pos==i){
                temp2->setNext(temp1->getNext());
                delete temp1;
                len--;
                break;
            }else{
                temp2=temp1;
                temp1=temp1->getNext();
            }
        }
    }
}
/**
 * @brief returns the list lenght
 * @return int
 */
int IntegerLinkedList::getLen() {
    return this->len;
}
/**
 * @brief deletes the last node in the list
 */
void IntegerLinkedList::deleteLast() {
    IntegerNode * temp1=head;
    if(len==0) {
        len=0;
        return;
    }else if(len==1){
        head=nullptr;
        delete temp1;
        len--;
    }else{
        while(temp1!= nullptr){
            IntegerNode* nextTemp=temp1->getNext();
            if(nextTemp->getNext()== nullptr){
                temp1->setNext(nextTemp->getNext());
                nextTemp->setNext(nullptr);
                delete nextTemp;
                len--;
                return;
            }
            temp1=nextTemp;
            nextTemp=nextTemp->getNext();
        }
    }
}
/**
 * @brief deletes a specific position
 * @param data
 */
void IntegerLinkedList::deleteData(int data) {
    IntegerNode * temp1=head,*temp2= head;
    if(len==0) {
        len=0;
        return;
    }else if(getInt(0)==data){//if the position is the head
        head=head->getNext();
        delete temp1;
        len--;
        return;
    }else{
        for(int i=0; i<len;i++){
            if(getInt(i)==data){
                temp2->setNext(temp1->getNext());
                delete temp1;
                len--;
                break;
            }else{
                temp2=temp1;
                temp1=temp1->getNext();
            }
        }
    }
}


