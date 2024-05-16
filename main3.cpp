#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("log_errores.txt");  // Archivo de entrada
    ofstream outputFile("resumen_errores.txt"); // Archivo de salida

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    map<string, int> errorCount;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string errorType;

        getline(iss, errorType, ':');
        errorCount[errorType]++;
    }

    for (map<string, int>::iterator it = errorCount.begin(); it != errorCount.end(); ++it) {
        outputFile << it->first << ": " << it->second << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Ver 'resumen_errores.txt' para los resultados." << endl;

    return 0;
}

