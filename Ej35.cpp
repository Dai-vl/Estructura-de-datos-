// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// función que resuelve el 
bool resolver(const bintree<char>& iz, const bintree<char>& dc) {
    if (iz.empty() || dc.empty()) {
        if(iz.empty() && dc.empty())
            return true;
        return false;
    }
    else{
        return (iz.root() == dc.root()) && resolver(iz.left(), dc.right()) && resolver(iz.right(), dc.left());
    }
}

void resuelveCaso() {
    bintree<char> arbolito = leerArbol('.');
    if (arbolito.empty())
        cout << "NO\n";
    else {
        bool sol = resolver(arbolito.left(), arbolito.right());
        if (sol)
            cout << "SI\n";
        else
            cout << "NO\n";
    }

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