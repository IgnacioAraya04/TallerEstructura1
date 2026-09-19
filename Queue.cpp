#include "Queue.h"

Queue::Queue() {
    inicio = nullptr;
}
Queue::~Queue() {
    clear();
}
bool Queue::empty() {
    return this->inicio == nullptr;
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
    if (this->inicio != nullptr) {
        Nodo* temp = this->inicio;
        this->inicio = this->inicio->getSiguiente();
        delete temp;
    }
}
Nodo* Queue::front() {
    return this->inicio;
}
void Queue::clear() {
    while (!empty()) {
        pop();
    }
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