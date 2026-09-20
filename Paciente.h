#pragma once

#include <string>

using namespace std;

class Paciente {
    private:
        int ID;
        string nombre;
        int edad;
        string servicio;
    public:
        Paciente(int ID, string nombre, int edad, string servicio);

        int getID();

        string getNombre();

        int getEdad();

        string getServicio();
};