// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:
    void eliminarRep() {
        Nodo* aux = this->prim;
        Nodo* duplicado;
        while (aux != nullptr && aux->sig != nullptr) {
            if (aux->elem == aux->sig->elem) {
                duplicado = aux->sig;
                aux->sig = duplicado->sig;
                delete duplicado;
            }
            else
            {
                aux = aux->sig;
            }
        }
    }

    void mostrar() {
        Nodo* aux = this->prim;
        if (aux != nullptr) {
            cout << aux->elem;
            aux = aux->sig;
        }
        while (aux != nullptr) {
            cout << ' ' << aux->elem;
            aux = aux->sig;
        }
        cout << '\n';
    }
};


bool resuelveCaso() {
    
    int n;
    cin >> n;

    if (n == -1)
        return false;

    linked_list_ed_plus<char> lista;

    char aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        lista.push_back(aux);
    }

    lista.eliminarRep();
    lista.mostrar();
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
