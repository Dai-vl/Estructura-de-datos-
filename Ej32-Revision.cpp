// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

pair<int, int> acumulador(const bintree<int>& tree) {
    if (tree.empty())
        return { 0, 0 };
    else {
        pair<int, int> iz = acumulador(tree.left());
        pair<int, int> dc = acumulador(tree.right());

        return { (iz.second + dc.second == tree.root()) + iz.first + dc.first, iz.second + dc.second + tree.root()};
    }
}


void resuelveCaso() {
    bintree<int> tree= leerArbol(-1);
    int sol = acumulador(tree).first;
    cout << sol << '\n';
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