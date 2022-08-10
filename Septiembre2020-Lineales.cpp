// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
using namespace std;

template<typename T>
class deque_plus : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:

    void interseccion(deque_plus<T>& d) {

        Nodo* act = this->fantasma->sig;
        Nodo* aMov = d.fantasma->sig;
        Nodo* aBorr;

        while (act != this->fantasma && aMov != d.fantasma) {

            if (act->elem < aMov->elem) {
                aBorr = act;
                act = act->sig;

                aBorr->ant->sig = act;
                act->ant = aBorr->ant;
                delete aBorr;
            }
            else if (act->elem > aMov->elem) {
                aMov = aMov->sig;
            }
            else {
                act = act->sig;
                aMov = aMov->sig;
            }
        }

        while (act != this->fantasma) {
            aBorr = act;
            act = act->sig;

            aBorr->ant->sig = act;
            act->ant = aBorr->ant;
            delete aBorr;
        }
    }

    void print() {
        Nodo* act = this->fantasma->sig;

        if (act != this->fantasma) {
            cout << act->elem;
            act = act->sig;
        }

        while (act != this->fantasma) {
            cout << ' ' << act->elem;
            act = act->sig;
        }
        cout << '\n';
    }
};


void resuelveCaso() {

    deque_plus<int> lista1, lista2;

    int n;
    cin >> n;
    while (n != 0) {
        lista1.push_back(n);
        cin >> n;
    }

    cin >> n;
    while (n != 0) {
        lista2.push_back(n);
        cin >> n;
    }

    lista1.interseccion(lista2);
    lista1.print();
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}