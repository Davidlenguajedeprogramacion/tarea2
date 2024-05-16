#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("registro_horas.txt");  // Archivo de entrada
    ofstream outputFile("informe_horas_totales.txt"); // Archivo de salida

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    map<string, int> horasPorEmpleado;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string nombre;
        int horas;
        char delim = ',';

        getline(iss, nombre, delim);
        iss >> horas;

        if (horasPorEmpleado.find(nombre) == horasPorEmpleado.end()) {
            horasPorEmpleado[nombre] = horas;
        } else {
            horasPorEmpleado[nombre] += horas;
        }
    }

    
    for (map<string, int>::iterator it = horasPorEmpleado.begin(); it != horasPorEmpleado.end(); ++it) {
        outputFile << it->first << ", Horas Totales: " << it->second << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Ver 'informe_horas_totales.txt' para los resultados." << endl;

    return 0;
}
