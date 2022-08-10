// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

struct sol{
    int pos;
    int sol;

};

bool esPrimo(int numero) {

    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) return false;
    }

    return true;
}

// función que resuelve el problema
sol resolver(const bintree<int>& arbol, int altura) {
    if (arbol.empty()) {
        return {0, 0};
    }
    else {
        sol iz = resolver(arbol.left(), altura +1);
        sol dc = resolver(arbol.right(), altura +1);

        if (esPrimo(arbol.root())) { //si es primo todo lo q haya despues no vale
            return{0, 0};
        }
        else {
            if (arbol.root() % 7 == 0) {
                return{ altura, arbol.root() };
            }
            else {
                if (iz.pos == 0)
                    return dc;
                if (dc.pos == 0)
                    return iz;
                if (iz.pos <= dc.pos)
                    return iz;
                return dc;
            }
        }
    }

}

void resuelveCaso() {
    bintree<int> arbolito = leerArbol(-1);
    sol sol = resolver(arbolito, 1);
    if (sol.sol == 0)
        cout << "NO HAY\n";
    else
        cout << sol.sol << ' ' << sol.pos << '\n';
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