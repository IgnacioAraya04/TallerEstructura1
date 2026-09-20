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
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    
    while(getline(archivo, texto)){
       try
       {
            stringstream ss(texto);
            int ID, edad;
            string idString,edadString,nombre, servicio;

            getline(ss, idString, ';');
            getline(ss, nombre, ';');
            getline(ss, edadString, ';');
            getline(ss, servicio, ';');


            ID = stoi(idString);
            edad = stoi(edadString);

            bool pacienteRepetido = false;
            Nodo* cursor = pacientesEspera->front();
            while (cursor != nullptr) {
                Paciente* pacienteExistente = cursor->getDato();
                if (pacienteExistente->getID() == ID) {
                    cout << "El paciente con ID " << ID << " ya existe en la lista de espera. Se omitira su registro." << endl;
                 pacienteRepetido = true;
                 break;
                }
                cursor = cursor->getSiguiente();
            }
            if (!pacienteRepetido) {
                Paciente* paciente = new Paciente(ID, nombre, edad, servicio);
                Nodo* nodoPaciente = new Nodo(paciente);
                pacientesEspera->push(nodoPaciente);
            }
       }
         catch(const std::exception& e)
         {
           cout << "Existe un problema con el archivo" << endl;
        }
    }    
       
       
}

void atenderPacientes() {
    int cantidadPacientes;
    cout << "" << endl;
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
    if (cantidadPacientes <= 0 || cantidadPacientes > pacientesEspera->size()) {
        cout << "Cantidad de pacientes no valida." << endl;
        return;
    }
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(100, '\n'); 
        cout << "Cantidad de pacientes no valida. Intente nuevamente." << endl;
        return;
    }

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
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Urgencias." << endl;
        } else if (servicio == "Medicina General") {
            medicinaGeneral->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Medicina General." << endl;
        } else if (servicio == "Cardiologia") {
            cardiologia->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Cardiologia." << endl;
        } else if (servicio == "Neurologia") {
            neurologia->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Neurologia." << endl;
        } else if (servicio == "Traumatologia") {
            traumatologia->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Traumatologia." << endl;
        } else if (servicio == "Cirugia") {
            cirugia->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Cirugia." << endl;
        } else if (servicio == "Pediatria") {
            pediatria->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Pediatria." << endl;
        } else if (servicio == "Hospitalizacion") {
            hospitalizacion->push(nodoPaciente);
            historialAtencion->push(nodoHistorial);
            cout << "Paciente " << pacienteAtendido->getNombre() << " atendido en el servicio de Hospitalizacion." << endl;
        } else {
            cout << "Servicio no disponible, paciente "<< pacienteAtendido->getNombre() << " fue derivado a otro hospital." << endl;
            delete nodoPaciente;
            delete nodoHistorial;
        }
    }
}

void verDepartamento() {
    cout << "" << endl;
    cout << "=== Departamentos/Servicios ===" << endl;
    int cont = 1;
    int seleccion = 0;
    for (const string& servicio : serviciosDisponibles) {
        cout << cont << " - " << servicio << endl;
        cont++;
    }
    cout << "" << endl;
    cout << "Ingrese el numero del departamento que desea ver: ";
    cin >> seleccion;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Opcion invalida. Intente nuevamente." << endl;
        return;
    }
    if (seleccion < 1 || seleccion > 8) {
        cout << "Departamento no valido." << endl;
        return;
    }else {
        cout << "=== Pacientes en " << serviciosDisponibles[seleccion - 1] << " ===" << endl;
        Queue* departamento = nullptr;

        switch (seleccion) {
            case 1:
                departamento = urgencias;
                break;
            case 2:
                departamento = medicinaGeneral;
                break;
            case 3:
                departamento = cardiologia;
                break;
            case 4:
                departamento = neurologia;
                break;
            case 5:
                departamento = traumatologia;
                break;
            case 6:
                departamento = cirugia;
                break;
            case 7:
                departamento = pediatria;
                break;
            case 8:
                departamento = hospitalizacion;
                break;
        }

        if (departamento->empty()) {
            cout << "No hay pacientes en este departamento." << endl;
        } else {
            Nodo* cursor = departamento->front();
            Paciente* paciente = cursor->getDato();
            cout << " Pacientes en el departamento de " << serviciosDisponibles[seleccion - 1] << ": " << departamento->size() << endl;
            cout << paciente->getNombre() << " (" << paciente->getEdad() << ")" << endl;

            for (int i = 1; i < departamento->size(); i++) {
                cursor = cursor->getSiguiente();
                paciente = cursor->getDato();
                cout << paciente->getNombre() << " (" << paciente->getEdad() << ")" << endl;
            } 
        }
    }
}

void revisarHistorial() {
    cout << "" << endl;
    cout << "=== Historial de Últimas Atenciones del Hospital ===" << endl;
    if (historialAtencion->empty()) {
        cout << "No hay pacientes atendidos." << endl;
    } else {
        Nodo* cursor = historialAtencion->front();
        Paciente* paciente = cursor->getDato();
        cout << "Nombre: " << paciente->getNombre() << " | " << "Edad: " << paciente->getEdad() << " | " << "Departamento: " << paciente->getServicio() << endl;
        for (int i = 1; i < historialAtencion->size(); i++) {
            cursor = cursor->getSiguiente();
            paciente = cursor->getDato();
            cout << "Nombre: " << paciente->getNombre() << " | " << "Edad: " << paciente->getEdad() << " | " << "Departamento: " << paciente->getServicio() << endl;
        } 
    }
}

void liberadorMemoria() {
    pacientesEspera->clear();
    historialAtencion->clear();
    urgencias->clear();
    medicinaGeneral->clear();
    cardiologia->clear();
    neurologia->clear();
    traumatologia->clear();
    cirugia->clear();
    pediatria->clear();
    hospitalizacion->clear();

    delete pacientesEspera;
    delete historialAtencion;
    delete urgencias;
    delete medicinaGeneral;
    delete cardiologia;
    delete neurologia;
    delete traumatologia;
    delete cirugia;
    delete pediatria;
    delete hospitalizacion;
}

void menu() {
    int opcion;
    cout << "" << endl;
    cout << "=== Hospital Marmaja ===" << endl;
    cout << "1. Atender pacientes" << endl;
    cout << "2. Ver departamento" << endl;
    cout << "3. Revisar historial de atencion" << endl;
    cout << "4. Salir" << endl;
    cout << "" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(100, '\n'); 
        cout << "Opcion invalida. Intente nuevamente." << endl;
        menu();
        return;
    }

    switch (opcion) {
        case 1:
            atenderPacientes();
            menu();
            break;
        case 2:
            verDepartamento();
            menu();
            break;
        case 3:
            revisarHistorial();
            menu();
            break;
        case 4:
            cout << "Hasta luego! :D" << endl;
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
    liberadorMemoria();
    return 0;
}
