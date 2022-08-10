// Nombre del alumno Daniela Vidal
// Usuario del Juez A75

#include "horas.h"
#include "linked_list_ed_plus.h"
#include <iostream>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int elem;
    cin >> elem;

    if (elem == 0)
        return false;
    horas h;

    linked_list_ed_plus<horas> lista;
    for (int i = 0; i < elem; i++) {
        cin >> h;
        lista.push_back(h);
    }
    lista.eliminarPosPares(elem);
    lista.mostrarElementos();
    // escribir sol

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
