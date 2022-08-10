// IMPORTANTE
//
// Nombre y apellidos del alumno
// Daniela Vidal León
// Usuario del juez de clase
//A67

#include <iostream>
#include <string> 
#include <sstream> 
#include <fstream>

#include "linked_list_ed.h"
using namespace std;

template <class T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:

    //
    // Aqui el método implementado por el alumno
    //
    void eliminarRepetidos() { //el primero nunca lo voy a eliminar asi que lo dejo como esta
        Nodo* aux = this->prim;
        Nodo* aux2;
        while (aux != nullptr && aux->sig != nullptr) {
            if (aux->sig->elem == aux->elem) {
                aux2 = aux->sig;
                aux->sig = aux2->sig;
                if (aux2 == this->ult)
                    this->ult = aux;
                delete aux2;
            }
            else {
                aux = aux->sig;
            }
        }

    };

    void print(std::ostream& o) const {
        Nodo* aux = this->prim;
        if (aux != nullptr) {
            o << aux->elem;
            aux = aux->sig;
        }
        while (aux != nullptr) {
            o << ' ' << aux->elem;
            aux = aux->sig;
        }
        o << '\n';
    }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& o, linked_list_ed_plus<T> const& l) {
    l.print(o);
    return o;
}

bool resuelveCaso() {
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    linked_list_ed_plus<char> lista;
    for (int i = 0; i < numElem; ++i) {
        char c; std::cin >> c;
        lista.push_back(c);
    }
    lista.eliminarRepetidos();

    std::cout << lista;

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

}