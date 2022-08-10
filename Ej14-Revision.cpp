// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed.h"
using namespace std;

template<class T>
class double_linked_list_plus : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
    void particion(int piv) {
        Nodo* ult = this->fantasma->ant; //desde el ultimo
        Nodo* aMover;
        while (ult != this->fantasma && ult->elem > piv) {
            ult = ult->ant;
        }

        Nodo* act = this->fantasma->sig; 
        Nodo* stop = ult;
        while (act != this->fantasma && act != stop) {
            if (act->elem > piv) {
                aMover = act;
                act = act->sig;

                aMover->ant->sig = act;
                act->ant = aMover->ant;

                aMover->sig = ult->sig;
                aMover->ant = ult;
                ult->sig = aMover;
                aMover->sig->ant= aMover;

                ult = aMover;

            }
            else {
                act = act->sig;
            }
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



// función que resuelve el problema
void resolver() {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;

    cin >> n;

    if (!std::cin)
        return false;

    int piv; cin >> piv;

    double_linked_list_plus<int> lista;
    int aux;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        lista.push_back(aux);
    }

    lista.particion(piv);
    lista.print();

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