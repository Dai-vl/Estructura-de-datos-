// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

bool es_toeplitz(const list<list<int>>& matriz) {
    bool es = false;
    auto it = matriz.begin();
    list<int> fila1 = *it;
    ++it;
    if (it == matriz.end())
        return true;

    list<int> fila2 = (*it);

    auto elem = fila1.begin();
    auto elem2 = ++fila2.begin();

    while (it != matriz.end()) {
        if (elem2 != fila2.end() && (*elem) != (*elem2)) {
            return false;
        }
        else if (elem2 == fila2.end()) {
            if (it != --matriz.end()) {
                fila1 = *it;
                fila2 = (*++it);
                elem = fila1.begin();
                elem2 = ++fila2.begin();
            }
            else
                return es;
        }
        else {
            ++elem; ++elem2;
            es = true;
        }
    }

    return es;
}

bool resuelveCaso() {
    int n;
    cin >> n;

    if (n == 0)
        return false;

    list<list<int>> lista;

    while (n != 0){
        list<int> aux;
        while (n != 0) {
            aux.push_back(n);
            cin >> n;
        }
        lista.push_back(aux);
        cin >> n;
    }

    if (es_toeplitz(lista))
        cout << "SI\n";
    else cout << "NO\n";

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
