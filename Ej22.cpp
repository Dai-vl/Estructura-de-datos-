// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

template < class T >
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
    auto it1 = ini1;
    auto it2 = ini2;
    while (it1 != fin1 && it2 != fin2) {
        if (*it1 == *ini2) { //sigue buscando
            auto aux = it1;
            it2 = ini2;
            while (aux != fin1 && it2 != fin2 && *aux == *it2) {
                ++aux;
                ++it2;
            }
            if (it2 != fin2) {
                ++it1;
            }
        }
        else {
            ++it1;
        }
    }

    return it1;

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2;
    cin >> n1 >> n2;

    if (n1 == 0 && n2 == 0)
        return false;

    list<int> l1;
    list<int> l2;
    int aux;
    for (int i = 0; i < n1; i++) {
        cin >> aux;
        l1.push_back(aux);
    }
    for (int i = 0; i < n2; i++) {
        cin >> aux;
        l2.push_back(aux);
    }

    auto borrar = l1.begin();
    while (borrar != l1.end()) {
        borrar = Mysearch(borrar, l1.end(), l2.begin(), l2.end());
        if (borrar != l1.end()) {
            for (int i = 0; i < n2; i++) {
               borrar = l1.erase(borrar);
            }
        }
    }


    //muestra la sol
    auto it = l1.begin();
    if (it != l1.end()) {
        cout << *it;
        ++it;
        while (it != l1.end()) {
            cout << ' ' << *it;
            ++it;
        }
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
