#include "Paciente.h"

Paciente::Paciente(string ID, string nombre, int edad, string servicio) {
    this->ID = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

string Paciente::getID() {
    return ID;
}

string Paciente::getNombre() {
    return nombre;
}

int Paciente::getEdad() {
    return edad;
}

string Paciente::getServicio() {
    return servicio;
}
