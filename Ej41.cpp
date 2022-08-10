// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "set_eda.h"
using namespace std;


// función que resuelve el problema
void resolver() {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    int m;
    cin >> m;

    // escribir sol

    vector<set<int>> v(n);
    int aux;
    int j = 0;
    bool insertado;
    for (int i = 0; i < m; ++i) {
        cin >> aux;
        insertado = v[j].insert(aux);
        if (!insertado) {
            v[j].erase(aux);
        }
        j = (++j)%n;
    }

    aux = 1;
    for (set<int> s : v) {
        cout << "J" << aux <<": {";
        auto i = s.begin();
        if (i != s.end()) {
            cout << *i;
            ++i;
        }
        while(i != s.end()) {
            cout << ", " << (*i);
            ++i;
        }

        cout << "}\n";
        ++aux;
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