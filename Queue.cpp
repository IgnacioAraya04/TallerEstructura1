#include "Queue.h"

Queue::Queue() {
    inicio = nullptr;
}
Queue::~Queue() {
    clear();
}
void Queue::push(Nodo* nodo) {
    if (this->inicio == nullptr) {
        this->inicio = nodo;
    } else {
        Nodo* cursor = this->inicio;
        while (cursor->getSiguiente() != nullptr) {
            cursor = cursor->getSiguiente();
        }
        cursor->setSiguiente(nodo);
    }
}
void Queue::pop() {
    Nodo* nodo = takeFront();
    delete nodo;
}
Nodo* Queue::takeFront() {
    if (this->inicio == nullptr) {
        return nullptr;
    }

    Nodo* nodo = this->inicio;
    this->inicio = nodo->getSiguiente();
    nodo->setSiguiente(nullptr);
    return nodo;
}
Nodo* Queue::front() {
    return this->inicio;
}
int Queue::size() {
    int contador = 0;
    Nodo* cursor = this->inicio;
    while (cursor != nullptr) {
        contador++;
        cursor = cursor->getSiguiente();
    }
    return contador;
}
bool Queue::empty() {
    return this->inicio == nullptr;
}
void Queue::clear() {
    while (!empty()) {
        pop();
    }
}   