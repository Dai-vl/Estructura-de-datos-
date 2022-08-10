// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

pair<int, int> resolver(const vector<int>& v) {

    stack<int> pila; //en el top guardo 
    int interMax = 0, pos = (int)v.size();

    for (int i = (int)v.size() - 1; i >= 0; i--) {
        if (pila.empty() && interMax < (int)v.size() - i) {
            pila.push(i);
        }
        else if (!pila.empty() && interMax < pila.top() - i) {

        }
    }


    return{ interMax, pos };
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    vector<int> v(n);
    for (int& x : v) cin >> x;


    // escribir sol
    pair<int, int> sol = resolver(v);

    cout << sol.first << ' ' << sol.second << '\n';
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