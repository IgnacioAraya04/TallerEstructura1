#pragma once
#include "Nodo.h"

class Queue {
private:
    Nodo* inicio;
public:
    Queue();

    void push(Nodo* nodo);
    void pop();
    Nodo* front();

    int size();
    bool empty();
    void clear();
};

