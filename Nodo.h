#pragma once
#include <iostream>
#include "Paciente.h"

class Nodo {
    private:
        Paciente* paciente;
        Nodo* siguiente;
    public:
        Nodo(Paciente* paciente);
        
        Paciente* getPaciente();

        Nodo* getSiguiente();

        void setSiguiente(Nodo* siguiente);
};