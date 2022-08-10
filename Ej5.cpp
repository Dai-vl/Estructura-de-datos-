//Daniela Vidal
//A75

#include <iostream>
#include <vector>
#include "complejo.h"

using namespace std;

void resuelveCaso() {
    complejo<float> c;
    cin >> c;

    int n;
    cin >> n;

    complejo<float> zn_1, zn;
    zn_1 = complejo<float> (0);
    bool converge = true;

    for (int i = 0; i < n && converge; i++) {
        zn = zn_1 * zn_1 + c;
        if (zn.mod() > 2) converge = false;
        zn_1 = zn;
    }

    converge ? cout << "SI\n" : cout << "NO\n";

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

