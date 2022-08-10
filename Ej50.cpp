// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct tEquipo {
    int tiempT = 0;
    int probRes = 0;
    unordered_map<string, pair<int, string>> mapaProb; //intentos fallidos, veredicto
};

struct sol {
    string nombre;
    int tiempo;
    int resueltos;

    bool operator<(const sol& s) const {
        return(resueltos > s.resueltos) || 
            (resueltos == s.resueltos && tiempo < s.tiempo) || 
            (resueltos == s.resueltos && tiempo == s.tiempo && nombre < s.nombre);
    }
};


bool resuelveCaso() {
    string equipo;
    cin >> equipo;
    if (!std::cin)
        return false;

    unordered_map<string, tEquipo> mapaEquipos;

    string prob, ver;
    int tiempo;

    while (equipo != "FIN") {
        cin >> prob >> tiempo >> ver;

        if (mapaEquipos[equipo].mapaProb[prob].second != "AC") {
            auto it = mapaEquipos.at(equipo).mapaProb.find(prob);

            if (ver != "AC") 
                it->second.first++;
            else {
                auto itE = mapaEquipos.find(equipo);
                itE->second.probRes++;
                itE->second.tiempT += tiempo + 20 * it->second.first;
            }
            it->second.second = ver;
        }
        cin >> equipo;
    }

    vector<sol> solucion;

    for (auto e : mapaEquipos)
        solucion.push_back({ e.first, e.second.tiempT, e.second.probRes });

    sort(solucion.begin(), solucion.end());

    for (sol s : solucion) {
        cout << s.nombre << ' ' << s.resueltos << ' ' << s.tiempo << '\n';
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