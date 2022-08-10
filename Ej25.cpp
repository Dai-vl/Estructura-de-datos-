// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string n;
    getline(cin, n);
    if (!std::cin)
        return false;

    list<char> l;
    auto it = l.begin();

    for (int i = 0; i < (int)n.length(); i++) {
        if (n[i] == '-')
            it = l.begin();
        else if (n[i] == '+')
            it = l.end();
        else if (n[i] == '*') {
            if(it != l.end())
                ++it;
        }
        else if (n[i] == '3') {
            if (it != l.end()) {
                it = l.erase(it);
            }
        }
        else
            l.insert(it, n[i]);
    }

    // escribir sol
    auto c = l.begin();
    for (int i = 0; i < (int)l.size(); i++) {
        cout << (*c);
        ++c;
    }
    cout << '\n';

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