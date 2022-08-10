// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "bintree_eda.h"
using namespace std;

struct datos{
    bool binario = true;
    int max;
    int min;
};


// función que resuelve el problema
datos resolver(bintree<int> const& tree) {
    if (tree.empty())
        return{ true, 0, 0 };
    if (tree.left().empty() && tree.right().empty())
        return{ true, tree.root(), tree.root() };
    else {
        datos iz, dc;
        int max = tree.root(), min = tree.root();
        bool cumple = true;
        if (!tree.left().empty()) {
            iz = resolver(tree.left());
            cumple = tree.root() > iz.max;
            min = iz.min;
        }
        if (!tree.right().empty()) {
            dc = resolver(tree.right());
            cumple = cumple && tree.root() < dc.min;
            max = dc.max;
        }

        if (cumple) {
            return{ true && iz.binario && dc.binario, max, min };
        }
        else
            return { false, 0, 0 };
    }
    

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    bintree<int> tree = leerArbol(-1);

    if (resolver(tree).binario)
        cout << "SI\n";
    else
        cout << "NO\n";

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