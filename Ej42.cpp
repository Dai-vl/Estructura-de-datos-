// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

// función que resuelve el problema
template <class T>
void mostrar(const set<T> &s) {
    auto i = s.begin();
    if (i != s.end()) {
        cout << *i;
        ++i;
    }
    while (i != s.end()) {
        cout << ' ' << *i;
        ++i;
    }
    cout << endl;

}

template <class T>
void resolver(set<T>& s, T fin, int k) {
    T aux;
    cin >> aux;

    while (aux != fin) {
        s.insert(aux);
        cin >> aux;
        if (s.size() == k + 1) {
            auto it = s.begin();
            s.erase(*it);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    std::cin >> tipo;

    if (!std::cin)
        return false;
    int k;
    cin >> k;

    if (tipo == 'N') {
        set<int> s;
        resolver(s, -1, k);
        mostrar(s);
    }
    else if (tipo == 'P') {
        set<string> s;
        string fin = "FIN";
        resolver(s, fin, k);
        mostrar(s);
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}