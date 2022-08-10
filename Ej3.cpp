// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "horas.h"
#include <vector>
using namespace std;

horas busqueda(const vector<horas>& v, int ini, int fin, const horas& consulta) {
    if (ini + 1 >= fin) return v[ini];
    else {
        int m = (ini + fin - 1) / 2;
        if (v[m] < consulta) return busqueda(v, m+1, fin, consulta);
        else {
            return busqueda(v, ini, m + 1, consulta);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int v1, v2;
    cin >> v1 >> v2;

    if (v1 == 0 && v2 == 0)
        return false;

    try {
        vector<horas> t(v1);
        horas hora;

        for (horas& tren : t)
            cin >> tren;
        for (int i = 0; i < v2; i++) {
            try {
                cin >> hora;
                horas aux = busqueda(t, 0, v1, hora);
                hora < aux || hora == aux ? cout << aux : cout << "NO";
            }
            catch (invalid_argument const& ia) {
                cout << ia.what();
            }
            cout << '\n';
        }
        cout << "---\n";
    }
    catch (overflow_error const& oe) {
        cout << oe.what() << '\n';
    }
    catch (invalid_argument const& ia) {
        cout << ia.what() << '\n';
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


    while (resuelveCaso());



    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}