// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

pair<bool, int> resolver(const bintree<char>& tree) {
    if (tree.empty())
        return { true, 0 };
    else if (tree.left().empty() && tree.right().empty())
        return { true, 1 };
    else {

        auto iz = resolver(tree.left());
        auto dc = resolver(tree.right());

        if(iz.second > dc.second)
            return { true && iz.first && dc.first, iz.second + 1 };
        else {
            return{ false, 0 };
        }
    }
}


void resuelveCaso() {

    bintree<char> tree = leerArbol('.');

    if(resolver(tree).first)
        cout <<"SI" << '\n';
    else
        cout << "NO" << '\n';
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