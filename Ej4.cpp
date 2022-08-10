// Nombre del alumno Daniela Vidal
// Usuario del Juez A67


#include <iostream>
#include <iomanip>
#include <fstream>
#include "peliculas.h"
#include <vector>
#include <algorithm>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nPel;
    cin >> nPel;

    if (nPel == 0)
        return false;

    vector<peliculas> p(nPel);
    for (peliculas& pe : p) cin >> pe;
    
    sort(p.begin(), p.end());
    // escribir sol
    for (peliculas& pe : p) cout << pe << '\n';
    cout << "---\n";
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
