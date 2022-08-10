// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include<algorithm>
#include <vector>
using namespace std;

bool comparator(pair<string, int> const &p1, pair<string, int> const &p2) {
    return(p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first));
}


bool resuelveCaso() {
    string deporte, nombre;
    cin >> deporte;

    if (!cin)
        return false;

    unordered_map<string, string> mapa;
    unordered_map<string, unordered_set<string>> deportes;

    deportes.insert({ deporte, {} });
    cin >> nombre;
    while (nombre != string("_FIN_")) {
        if (!isupper(nombre[0])) {
            if (mapa.count(nombre) == 0) {
                mapa[nombre] = deporte;
                deportes[deporte].insert(nombre);
            }
            else {
                if (mapa[nombre] != deporte) { //si es un deporte distinto no cuenta
                    deportes[mapa[nombre]].erase(nombre);
                }
            }
        }
        else {
            deporte = nombre;
            deportes[deporte].insert({});
        }
        cin >> nombre;
    }

    vector<pair<string, int>> sol;

    for (auto const&a : deportes) {
        sol.push_back({ a.first, a.second.size() });
    }
    
    sort(sol.begin(), sol.end(), comparator);

    for (auto &a : sol)
        cout << a.first << ' ' << a.second << '\n';

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
