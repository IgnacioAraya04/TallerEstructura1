#include <iostream> 
#include <string>
#include "Nodo.h"
#pragma once

using namespace std;

class Paciente {
    private:
        string ID;
        string nombre;
        int edad;
        string servicio;
    public:
        Paciente(string ID, string nombre, int edad, string servicio);

        string getID();

        string getNombre();

        int getEdad();

        string getServicio();
};