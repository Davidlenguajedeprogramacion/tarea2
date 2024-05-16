#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("temperaturas.txt");
    ofstream outputFile("extremas.txt");

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    string maxDate, minDate;
    double maxTemp = numeric_limits<double>::min();
    double minTemp = numeric_limits<double>::max();

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string date;
        double temp;
        char delim = ',';

        getline(iss, date, delim);
        iss >> temp;

        if (temp > maxTemp) {
            maxTemp = temp;
            maxDate = date;
        }
        if (temp < minTemp) {
            minTemp = temp;
            minDate = date;
        }
    }

    outputFile << "Día de temperatura máxima: " << maxDate << ", " << maxTemp << endl;
    outputFile << "Día de temperatura mínima: " << minDate << ", " << minTemp << endl;

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Ver 'extremas.txt' para los resultados." << endl;

    return 0;
}

