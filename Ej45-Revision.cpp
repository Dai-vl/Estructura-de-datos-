// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <set>
using namespace std;


void resuelveCaso() {

    unordered_map<string, int> dicc;

    string clave; int valor;


    string d1, d2;

    getline(std::cin, d1);
    getline(std::cin, d2);
    stringstream ss1(d1), ss2(d2);

    set<string> nuevos;
    set<string> elim;
    set<string> camb;

    while (ss1 >> clave) {
        ss1 >> valor;
        dicc[clave] = valor;
        elim.insert(clave);
    }

 
    while (ss2 >> clave) {
        ss2 >>  valor;
        if (!dicc.count(clave))
            nuevos.insert(clave);
        else if (dicc.count(clave) && dicc.at(clave) != valor)
            camb.insert(clave);
        elim.erase(clave);
    }

    if (nuevos.size() == 0 && camb.size() == 0 && elim.size() == 0)
        cout << "Sin cambios\n";
        
    else {
        if (nuevos.size() != 0) {
            cout << "+";
            for (auto& a : nuevos) {
                cout << ' ' << a;
            }
            cout << '\n';
        }
        if (elim.size() != 0) {
            cout << "-";
            for (auto& a : elim) {
                cout << ' ' << a;
            }
            cout << '\n';
        }
        if (camb.size() != 0) {
            cout << "*";
            for (auto& a : camb) {
                cout << ' ' << a;
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
    cin.get();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}