#pragma once
#include "Nodo.h"

class Stack {
private:
    Nodo* inicio;
public:
    Stack();

    void push(Nodo* nodo);
    void pop();
    Nodo* front();

    bool empty();
    void clear();
    int size();
};