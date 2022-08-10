// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "set_eda.h"
using namespace std;

template <class T, class Comparator = std::less<T>>
class set_plus : public set<T, Comparator> {
    using Link = typename set<T, Comparator>::Link;
private:
    //encuentra el primer elemento mayor que e
    pair<bool, T> min(T const& e, Link a) const {
        if (a == nullptr) 
            return{ false, 0 };
        else {
            if (e == a->elem)
                return { true, a->elem };
            else if (e > a->elem) 
                return min(e, a->dr);
            else {
                pair<bool, T> iz = min(e, a->iz);
                if (iz.first)
                    return { true, iz.second};
                else
                    return{ true, a->elem };
            }
               
        }
    }

public:
    pair<bool, T> lower_bound(T const& e) const {
        return min(e, this->raiz);
    }

};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    cin >> n;

    if (n == 0)
        return false;

    set_plus<int> a;
    int e;

    for (int i = 0; i < n; i++) {
        cin >> e;
        a.insert(e);
    }

    int m;
    cin >> m;
    int aux;
    pair<bool, int> sol;

    for (int i = 0; i < m; i++) {
        cin >> aux;
        sol = a.lower_bound(aux);
        sol.first ? cout << sol.second : cout << "NO HAY";
        cout << '\n';
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
