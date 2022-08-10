// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el problema
pair<int,int> resolver(const bintree<int> &arbol) {
    if (arbol.empty()) {
        return { 0, 0 };
    }
    else {
        pair<int, int> iz = resolver(arbol.left());
        pair<int, int> dc = resolver(arbol.right());

        if (iz.first + dc.first == 0) {
            if (arbol.root() != 0)
                return { 1, arbol.root() + iz.second + dc.second};
        } //no hay equipo
        else if(iz.second > dc.second)
            return { iz.first + dc.first, iz.second + arbol.root() };
        return { iz.first + dc.first, dc.second + arbol.root() };
    }

}

void resuelveCaso() {
    bintree<int> arbolito = leerArbol(-1);
    pair<int, int> sol = resolver(arbolito);
    cout << sol.first << ' ' << sol.second << '\n';
    
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