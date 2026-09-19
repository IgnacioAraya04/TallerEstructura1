#include <iostream> 
#include <string>
#include "Nodo.h"
using namespace std;

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
}
void cargarDatos(){
    // Cargar datos de pacientes desde un archivo
    // Crear nodos y agregarlos a la lista de pacientes en espera

    
}

Nodo* pacientesEspera = nullptr;
Nodo* historialPacientes = nullptr;

Nodo* urgencias = nullptr;
Nodo* medicinaGeneral = nullptr;
Nodo* cardiologia = nullptr;
Nodo* neurologia = nullptr;
Nodo* traumatologia = nullptr;
Nodo* cirugia = nullptr;
Nodo* pediatria = nullptr;
Nodo* hospitalizacion = nullptr;

int main() {
   menu();
}