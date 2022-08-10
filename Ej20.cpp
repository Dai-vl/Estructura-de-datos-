// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;

bool resolver(const vector<int>& v) {
    int med = -1;
    stack<int> pila;

    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] < med)
            return true;
        while (!pila.empty() && v[i] > pila.top()) {
            if (med < pila.top())
                med = pila.top();
            pila.pop();
        }
        pila.push(v[i]);

    }
    return false;
}


bool resuelveCaso() {
    int n;
    cin >> n;
    if (!std::cin)
        return false;

    vector<int> v(n);

    for (int& i : v)
        cin >> i;

    if (resolver(v))
        cout << "ELEGIR OTRA";
    else
        cout << "SIEMPRE PREMIO";
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