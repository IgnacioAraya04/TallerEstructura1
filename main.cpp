#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include "Nodo.h"
#include "Stack.h"
#include "Queue.h"
#include "Paciente.h"


using namespace std;

Queue* pacientesEspera = new Queue();
Stack* historialAtencion = new Stack();

Queue* urgencias = new Queue();
Queue* medicinaGeneral = new Queue();
Queue* cardiologia = new Queue();
Queue* neurologia = new Queue();
Queue* traumatologia = new Queue();
Queue* cirugia = new Queue();
Queue* pediatria = new Queue();
Queue* hospitalizacion = new Queue(); 

const string serviciosDisponibles[] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};

void cargarDatos(){
    string texto;
    ifstream archivo("ArchivoEntrada.txt");
    while(getline(archivo, texto)){
        stringstream ss(texto);
        int ID, edad;
        string idString,edadString,nombre, servicio;

        getline(ss, idString, ';');
        getline(ss, nombre, ';');
        getline(ss, edadString, ';');
        getline(ss, servicio, ';');


        ID = stoi(idString);
        edad = stoi(edadString);

        Paciente* paciente = new Paciente(ID, nombre, edad, servicio);
        Nodo* nodoPaciente = new Nodo(paciente);
        pacientesEspera->push(nodoPaciente);
    }
}

void atenderPacientes() {
    int cantidadPacientes;
    cout << "=== Pacientes en Espera ===" << endl;
    Nodo* cursor = pacientesEspera->front();
    Paciente* paciente = cursor->getDato();
    cout << "1" << ". " << to_string(paciente->getID()) <<" - " << paciente->getNombre() << endl; 


    for (int i = 1; i < pacientesEspera->size(); i++) {
        cursor = cursor->getSiguiente();
        paciente = cursor->getDato();
        cout << i + 1 << ". " << to_string(paciente->getID()) <<" - " << paciente->getNombre() << endl; 
    } 
    cout << "" << endl;
    cout << "Indique la cantidad de pacientes a atender: ";
    cin >> cantidadPacientes;

    Nodo* nodoPaciente = nullptr;
    Paciente* pacienteAtendido = nullptr;
    string servicio = "";
    for (int i = 0; i < cantidadPacientes; i++){
        if (pacientesEspera->empty()) {
            cout << "No hay mas pacientes en espera." << endl;
            break;
        }

        nodoPaciente = pacientesEspera->takeFront();
        pacienteAtendido = nodoPaciente->getDato();
        servicio = pacienteAtendido->getServicio();

        Nodo* nodoHistorial = new Nodo(new Paciente(
            pacienteAtendido->getID(),
            pacienteAtendido->getNombre(),
            pacienteAtendido->getEdad(),
            pacienteAtendido->getServicio()));

        if (servicio == "Urgencias") {
            urgencias->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Urgencias." << endl;
        } else if (servicio == "Medicina General") {
            medicinaGeneral->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Medicina General." << endl;
        } else if (servicio == "Cardiologia") {
            cardiologia->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Cardiologia." << endl;
        } else if (servicio == "Neurologia") {
            neurologia->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Neurologia." << endl;
        } else if (servicio == "Traumatologia") {
            traumatologia->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Traumatologia." << endl;
        } else if (servicio == "Cirugia") {
            cirugia->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Cirugia." << endl;
        } else if (servicio == "Pediatria") {
            pediatria->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Pediatria." << endl;
        } else if (servicio == "Hospitalizacion") {
            hospitalizacion->push(nodoPaciente);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Hospitalizacion." << endl;
        } else {
            cout << "Servicio no disponible, derivado a otro hospital." << endl;
        }

        historialAtencion->push(nodoHistorial);
    }

}

void menu() {
    int opcion;
    cout << "=== Hospital Marmaja ===" << endl;
    cout << "1. Atender pacientes" << endl;
    cout << "2. Ver departamento" << endl;
    cout << "3. Revisar historial de atencion" << endl;
    cout << "4. Salir" << endl;
    cout << "" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            atenderPacientes();
            menu();
            break;
        case 2:
            menu();
            break;
        case 3:
            menu();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            menu();
            break;
    }
}

int main() {
    cargarDatos();
    menu();
    return 0;
}
