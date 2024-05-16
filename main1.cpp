#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("ventas_diarias.txt");  // Archivo de entrada
    ofstream outputFile("resumen_ventas.txt"); // Archivo de salida

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    double totalVentas = 0;
    int numDias = 0;
    string maxDate, minDate;
    double maxVenta = numeric_limits<double>::min();
    double minVenta = numeric_limits<double>::max();

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string date;
        double venta;
        char delim = ',';

        getline(iss, date, delim);
        iss >> venta;

        totalVentas += venta;
        numDias++;

        if (venta > maxVenta) {
            maxVenta = venta;
            maxDate = date;
        }
        if (venta < minVenta) {
            minVenta = venta;
            minDate = date;
        }
    }

    double promedioVentas = (numDias > 0) ? totalVentas / numDias : 0;

    outputFile << "Venta total: " << totalVentas << endl;
    outputFile << fixed << setprecision(2) << "Promedio de ventas: " << promedioVentas << endl;
    outputFile << "Día de mayor venta: " << maxDate << ", " << maxVenta << endl;
    outputFile << "Día de menor venta: " << minDate << ", " << minVenta << endl;

    inputFile.close();
    outputFile.close();

    cout << "Proceso completado. Ver 'resumen_ventas.txt' para los resultados." << endl;

    return 0;
}
