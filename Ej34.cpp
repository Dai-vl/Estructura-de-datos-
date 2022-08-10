// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el 
pair<int, int> resolver(const bintree<char>& arbol) { //primero max camino, segundo camino actual
    if (arbol.empty()) {
        return { 0, 0 };
    }
    else {
        pair<int, int> iz = resolver(arbol.left());
        pair<int, int> dc = resolver(arbol.right());

        int max = iz.second + dc.second + 1;

        if (iz.second > dc.second) {
            int caminoActual = iz.second + 1;
            if (max > iz.first)
                return{ max, caminoActual };
            else
                return{ iz.first, caminoActual };
        }
        else {
            int caminoActual = dc.second + 1;
            if (max > dc.first)
                return{ max, caminoActual };
            else
                return{ dc.first, caminoActual };
        }
    }

}

void resuelveCaso() {
    bintree<char> arbolito = leerArbol('.');
    pair<int, int> sol = resolver(arbolito);

    cout << sol.first << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}