#include "Stack.h"

Stack::Stack() {
    inicio = nullptr;
}

Stack::~Stack() {
    clear();
}

bool Stack::empty() {
    return this->inicio == nullptr;
}

void Stack::push(Nodo* nodo) {
    if (this->inicio == nullptr) {
        this->inicio = nodo;
    } else {
        nodo->setSiguiente(this->inicio);
        this->inicio = nodo;
    }
}

void Stack::pop() {
    if (this->inicio != nullptr) {
        Nodo* temp = this->inicio;
        this->inicio = this->inicio->getSiguiente();
        delete temp;
    }
}

Nodo* Stack::front() {
    return this->inicio;
}

void Stack::clear() {
    while (!empty()) {
        pop();
    }
}

int Stack::size() {
    int contador = 0;
    Nodo* cursor = this->inicio;
    while (cursor != nullptr) {
        contador++;
        cursor = cursor->getSiguiente();
    }
    return contador;
}