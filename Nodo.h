#pragma once

#include <iostream>
#include "Paciente.h"

class Nodo {
    private:
        Paciente* dato;
        Nodo* siguiente;
    public:
        Nodo(Paciente* dato) {
            this->dato = dato;
            this->siguiente = nullptr;
        }

        Paciente* getDato(){
            return dato;
        }

        Nodo* getSiguiente(){
            return siguiente;
        }

        void setSiguiente(Nodo* siguiente){
            this->siguiente = siguiente;
        }

        ~Nodo(){
            delete dato;
            delete siguiente;
        }
};