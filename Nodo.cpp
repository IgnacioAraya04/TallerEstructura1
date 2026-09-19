#include "Nodo.h"

Nodo::Nodo(Paciente* paciente) {
    this->paciente = paciente;
    this->siguiente = nullptr;
}

Paciente* Nodo::getPaciente() {
    return paciente;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo::~Nodo() {
    delete paciente;
    delete siguiente;
};