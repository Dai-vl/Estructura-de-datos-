// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"
using namespace std;

template<class T>
class deque_plus : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:

    void entremezclar(deque_plus<T>& d) {
        Nodo* act = this->fantasma->sig;
        Nodo* aMov = d.fantasma->sig;

        while (aMov != d.fantasma && act != this->fantasma) {
            aMov->ant->sig = aMov->sig;
            aMov->sig->ant = aMov->ant;
            aMov->sig = act->sig;
            act->sig->ant = aMov;

            aMov = aMov->ant->sig;

            act->sig = act->sig->ant;
            act->sig->ant = act;

            act = act->sig->sig;
        }

        while (aMov != d.fantasma) {
            act->ant->sig = aMov;

            aMov->ant->sig = aMov->sig;
            aMov->sig->ant = aMov->ant;

            aMov = aMov->sig;
            act->ant->sig->sig = act;
            act->ant->sig->ant = act->ant;
            act->ant = act->ant->sig;
        }
    }

    void print() {
        Nodo* act = this->fantasma->sig;
        if (act != this->fantasma) 
            cout << act->elem;
        act = act->sig;
        while (act != this->fantasma) {
            cout << ' ' << act->elem;
            act = act->sig;
        }
        cout << '\n';
    }
};


void resuelveCaso() {
    int n, aux;
    cin >> n;

    deque_plus<int> lista1;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        lista1.push_back(aux);
    }

    cin >> n;
    deque_plus<int> lista2;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        lista2.push_back(aux);
    }

    lista1.entremezclar(lista2);

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