// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed_plus.h"
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    linked_list_ed_plus<int> l1;
    linked_list_ed_plus<int> l2;
    int aux;
    cin >> aux;
    while (aux != 0) {
        l1.push_back(aux);
        cin >> aux;
    }
    cin >> aux;
    while (aux != 0) {
        l2.push_back(aux);
        cin >> aux;
    }

    l1.mezclaOrdenada(l2);
    l1.mostrarElementos();
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int n;
    cin >> n;

    for(int i =0; i < n; i++)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
