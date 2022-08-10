// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed_plus.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    double_linked_list_ed_plus<int> lista;
    double_linked_list_ed_plus<int> lista2;
    int aux;
    cin >> aux;
    while(aux != 0) {
        lista.push_back(aux);
        cin >> aux;
    }
    cin >> aux;
    while (aux != 0) {
        lista2.push_back(aux);
        cin >> aux;
    }
    // escribir sol
    lista.interseccion(lista2);
    lista.mostrarElementos();

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