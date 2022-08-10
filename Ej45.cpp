// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

using table = map<string, int>;

//bool compare(pair<char, string> p1, pair<char, string> p2) {
//    if (p1.first == '+') {
//        if (p2.first == '+')  return p1.second < p2.second;
//        return true;
//    }
//    else if (p1.first == '-') {
//        if (p2.first == '+' ) return false;
//        if(p2.first == '-') return p1.second < p2.second;
//        return true;
//    }
//    else {
//        if (p2.first == '+' || p2.first == '-') return false;
//        else return p1.second < p2.second;
//    }
//}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    table t;
    string dicc;


    getline(cin, dicc);
    stringstream s(dicc);

    string p;
    int n;
    while (s >> p) {
        s >> n;
        t[p] = n;
    }

    getline(cin, dicc);
    stringstream ss(dicc);
    vector< string> nuevos, elim, camb;
    int valor;

    while (ss >> p) {
        ss >> n;
        int num = t.count(p);

        if (num == 0) { //no existia
            nuevos.push_back( p );
        }
        else { // si ya existia
            valor = t[p];
            if (valor != n) { //se ha modificado
                camb.push_back(p );
            }
            t.erase(p);
        }
    }

    if (t.size() > 0) { //los que se han eliminado
        for (auto a : t) {
            elim.push_back(a.first );
        }
    }

    sort(nuevos.begin(), nuevos.end());
    sort(elim.begin(), elim.end());
    sort(camb.begin(), camb.end());

    
    if (nuevos.size() == 0 && elim.size() == 0 && camb.size() == 0) {
        cout << "Sin cambios\n";
    }
    else {
        if (nuevos.size() > 0) {
            cout << "+";
            for (string n : nuevos) {
                cout << " " << n;
            }
            cout << '\n';
        }
        if (elim.size() > 0) {
            cout << "-";
            for (string n : elim) {
                cout << " " << n;
            }
            cout << '\n';
        }
        if (camb.size() > 0) {
            cout << "*";
            for (string n : camb) {
                cout << " " << n;
            }
            cout << '\n';
        }
    }


    cout << "---\n";


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
    char aux;
    cin.get(aux);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}