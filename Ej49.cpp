// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool resuelveCaso() {
    // leer los datos de la entrada
    int p;
    cin >> p;

    if (p == 0)
        return false;

    unordered_map <string, pair<int, vector<pair<string, int>>>> mapaP; // Es un mapa con clave pelicula y valor veces que aparece en total dicha pelicula y un vector que guarda el nombre y tiempo de aparicion de cada actor
    unordered_map<string, int> mapaA; // Mapa con clave actor y tiempo total que aparece en pantalla

    string pelicula, actor;
    int nActores, minutos;

    for (int i = 0; i < p; ++i) {
        cin >> pelicula >> nActores;
        vector<pair < string, int>> aux;
        for (int j = 0; j < nActores; ++j) {
            cin >> actor >> minutos;
            aux.push_back({ actor, minutos });
        }
        mapaP[pelicula] = { 0, aux};
    }

    int e;
    pair<string, int> maxP;
    cin >> e;
    for (int i = 0; i < e; ++i) {
        cin >> pelicula;
        ++mapaP[pelicula].first;
        if (maxP.second <= mapaP[pelicula].first) {
            maxP.second = mapaP[pelicula].first;
            maxP.first = pelicula;
        }
    }

    int maxValue = 0;
    set<string> maxActores;
    for (auto& p : mapaP) {  //recorre las peliculas
        for (auto& a : p.second.second) { //recorre los actores de cada pelicula
            mapaA[a.first] += a.second * p.second.first;
            if (maxValue < mapaA[a.first]) {
                maxValue = mapaA[a.first];
                maxActores.clear();
                maxActores.insert(a.first);
            }
            else if (maxValue == mapaA[a.first]) {
                maxActores.insert(a.first);
            }
        }
    }

    cout << maxP.second << ' ' << maxP.first << '\n';
    cout << maxValue; 
    for (auto x : maxActores)
        cout << ' ' << x;
    cout << '\n';

    //unordered_map<string, vector<pair<string, int>>> infoMap;
    //string pelicula, actor;
    //int actores, minutos;
    //for (int i = 0; i < p; ++i) {
    //    cin >> pelicula >> actores;
    //    for (int j = 0; j < actores; ++j) {
    //        cin >> actor >> minutos;
    //        infoMap[pelicula].push_back({ actor, minutos });
    //    }
    //}
    //int e;
    //cin >> e;
    //unordered_map<string, int> programacion;
    //pair<string, int> max;
    //for (int i = 0; i < e; ++i) {
    //    cin >> pelicula;
    //    ++programacion[pelicula];
    //    if (programacion[pelicula] >= max.second) {
    //        max.first = pelicula;
    //        max.second = programacion[pelicula];
    //    }
    //}
    //int maxValue = 0;
    //for (auto &a : infoMap) {
    //    if (programacion[a.first] != 1) {
    //        for (auto& par : a.second) {
    //            par.second = par.second * programacion[a.first];
    //            if (par.second > maxValue) {
    //                maxValue = par.second;
    //            }
    //        }
    //    }
    //}
    //vector<pair<string, int>> maxActores;

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
