// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
using namespace std;

template<class T>
void mostrar(set<T> set) {
    auto it = set.begin();
    cout << *it;
    ++it;
    while (it != set.end()) {
        cout << ' ' << *it;
        ++it;
    }
    cout << '\n';
}

bool resuelveCaso() {
    char modo; cin >> modo;
    if (!std::cin)
        return false;
    int k; cin >> k;

    if (modo == 'N') {
        set<int> set;
        int n; cin >> n;

        while (n != -1) {
            set.insert(n);
            if (set.size() == k +1)
                set.erase(set.begin());
            cin >> n;
        }
        mostrar(set);
    }
    else if (modo == 'P') {
        set<string> set;
        string n; cin >> n;

        while (n != "FIN") {
            set.insert(n);
            if (set.size() == k +1)
                set.erase(set.begin());
            cin >> n;
        }
        mostrar(set);
       
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