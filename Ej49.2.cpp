// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool resuelveCaso() {
    // leer los datos de la entrada
    int p;
    cin >> p;

    if (p == 0)
        return false;

    unordered_map<string, unordered_set<pair<string, int>>> descripcion;
    string pelicula, actor;
    int actores, minutos;
    for (int i = 0; i < p; ++i) {
        cin >> pelicula >> actores;
        for (int j = 0; j < actores; ++j) {
            cin >> actor >> minutos;
            descripcion[pelicula].insert({ actor, minutos });
        }
    }

    int e;
    cin >> e;
    unordered_map<string, int> programacion;
    for (int i = 0; i < e; ++i) {
        ++programacion[pelicula];
    }



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
