// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"
using namespace std;

bintree<int> reconstruir(const vector<int>& in, const vector<int>& pre, int pos, int ini, int fin) {
    if (ini == fin || pos >= pre.size())
        return{};
    if (ini + 1 == fin) { 
        return { in[ini] };
    }
    else { // leer recursivamente los hijos
        int raiz = pre[pos];

        int i = ini;
        while (in[i] != pre[pos] && i < fin)
            i++;

        bintree<int> iz = reconstruir(in, pre, pos +1, ini, i);
        bintree<int> dr = reconstruir(in, pre, pos + i - ini +1, i+1, fin);
        return { iz, raiz, dr };
    }
}

bool resuelveCaso() {
    std::string v1, v2;

    std::getline(std::cin, v1);

    if (!std::cin)
        return false;

    std::getline(std::cin, v2);

    std::stringstream ss1(v1), ss2(v2);
    std::vector<int> pre, in;

    int aux;

    while (ss1) {
        ss1 >> aux;
        if (ss1)
            pre.push_back(aux);
    }

    while (ss2) {
        ss2 >> aux;
        if (ss2)
            in.push_back(aux);
    }

    std::vector<int> sol = reconstruir(in, pre, 0, 0, in.size()).postorder();

    std::cout << sol[0];

    for (int i = 1; i < sol.size(); i++)
        std::cout << ' ' << sol[i];

    std::cout << '\n';

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