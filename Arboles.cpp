// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

pair<int, int> resolver(const bintree<int>& tree) {
    if (tree.empty())
        return{ 0,0 };
    else {

        auto iz = resolver(tree.left());
        auto dc = resolver(tree.right());

        if ((tree.root() % 2) == 0) {
            int camino = iz.first + dc.first + 1;
            int max;
            if (camino > iz.second && camino > dc.second)
                max = camino;
            else if (iz.second > camino)
                max = iz.second;
            else if (dc.second > camino)
                max = dc.second;
            return{ camino, max };
        }
        else {
            int camino = 0;
            int max; 
            if (dc.second > iz.second)
                max = dc.second;
            else if (iz.second > dc.second)
                max = iz.second;
            return{ camino, max };
        }
    }
}


void resuelveCaso() {


    bintree<int> tree = leerArbol(-1);

    pair<int, int> sol = resolver(tree);
    cout << sol.second << '\n';
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