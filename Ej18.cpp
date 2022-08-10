// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "fecha.h"
using namespace std;


struct dato {
    fecha f;
    int a;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    stack<dato> pila;
    dato f;

    for (int i = 0; i < n; i++) {
        cin >> f.f >> f.a;
        while (!pila.empty() && pila.top().a <= f.a) {
            pila.pop();
        }
        if (!pila.empty()) {
            cout << pila.top().f << '\n';
        }
        else
            cout << "NO HAY\n";
        pila.push(f);
    }
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