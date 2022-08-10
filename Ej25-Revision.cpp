// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<list>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string linea;
    getline(cin, linea);

    if (!std::cin)
        return false;

    string lineaF;
    auto it = lineaF.begin();

    for (int i = 0; i < linea.size(); ++i) {
        if (linea[i] == '-') {
            it = lineaF.begin();
        }
        else if (linea[i] == '+') {
            it = lineaF.end();
        }
        else if (linea[i] == '*') {
            if (it != lineaF.end())
                ++it;
        }
        else if (linea[i] == '3') {
            if (it != lineaF.end())
                it = lineaF.erase(it);
        }
        else {
            lineaF.insert(it, linea[i]);
            ++it;
        }
    }
    
    auto c = lineaF.begin();
    for (int i = 0; i < (int)lineaF.size(); i++) {
        cout << (*c);
        ++c;
    }
    cout << '\n';
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}