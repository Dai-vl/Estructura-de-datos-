
// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "gestor_futbolistas.h"
using namespace std;

bool resuelveCaso() {
    string op;
    cin >> op;

    if (!std::cin)
        return false;

    string j, e;
    gestor_futbolistas g;

    while (op != "FIN") {
        try {
            if (op == "fichar") {
                cin >> j >> e;
                g.fichar(j, e);
            }
            else if (op == "equipo_actual") {
                cin >> j;
                e = g.equipo_actual(j);
                cout << "El equipo de " << j << " es " << e << '\n';
            }
            else if (op == "fichados") {
                cin >> e;
                int s = g.fichados(e);
                cout << "Jugadores fichados por " << e << ": " << s << '\n';
            }
            else if (op == "ultimos_fichajes") {
                int n;
                cin >> e >> n;
                vector<string> aux = g.ultimos_fichajes(e, n);
                cout << "Ultimos fichajes de " << e << ":";
                for (string &s : aux) {
                    cout << " " << s;
                }
                cout << '\n';
            }
            else if (op == "cuantos_equipos") {
                cin >> j;
                int aux = g.cuantos_equipos(j);
                cout << "Equipos que han fichado a " << j << ": " << aux << '\n';
            }
        }
        catch (domain_error& e) {
            cout << "ERROR: " << e.what() << '\n';
        }
        cin >> op;
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