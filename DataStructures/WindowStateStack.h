//
// Created by dansecan on 27/04/23.
//

#ifndef PROYECTO2PACMAN_WINDOWSTATESTACK_H
#define PROYECTO2PACMAN_WINDOWSTATESTACK_H

#include <SFML/Graphics.hpp>
#include <iostream>
class WindowState;
class StackNodeStates{
public:
    explicit StackNodeStates(WindowState * dat);
    void setData(WindowState* dat);
    WindowState* getData();
    void setLink(StackNodeStates* next);
    StackNodeStates* getLink();
private:
    WindowState * data;
    StackNodeStates* link;

};

class WindowStateStack {
public:
    WindowStateStack();
    ~WindowStateStack();
    void push(WindowState* dat);
    WindowState* peek();
    void pop();
    [[nodiscard]] bool isEmpty() const;
    StackNodeStates* top;

};


#endif //PROYECTO2PACMAN_WINDOWSTATESTACK_H
