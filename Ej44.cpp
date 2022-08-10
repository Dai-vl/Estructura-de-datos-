// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

using tabla = map<string, vector<int>>;

string toLower(string& p) {
    for (char& c : p) {
        c = tolower(c);
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
    char aux = ' ';

    string linea, p;

    tabla t;
    
    for (int i = 1; i <= n; ++i) {
        aux = ' ';
        while (aux != '\n') {
            cin >> p;
            if (!p.empty() && p.length() > 2) {
                //comprobar q este en otra linea
                p = toLower(p);
                if (t[p].empty() || t[p].back() != i) {
                    t[p].push_back(i);
                }
            }
            cin.get(aux);
        }
    }

    for (auto a : t) {
        cout << a.first;
        for (int i : a.second)
            cout << ' ' << i;
        cout << '\n';
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
