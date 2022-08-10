// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "horas.h"
#include<list>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    list<horas> l;

    for (int i = 0; i < n; i++) {
        horas aux;
        cin >> aux;
        l.push_back(aux);
    }

    //eliminar pares
    auto r = l.begin();
    while (r != l.end()) {
        r++;
        if(r != l.end())
           r = l.erase(r);
    }


    // escribir sol
    auto it = l.begin();
    if (it != l.end()) {
        horas h = *it;
        cout << h;
        ++it;
    }
    while (it != l.end()) {
        horas h = *it;
        cout << ' ' << h;
        ++it;
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
