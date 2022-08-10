// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
using namespace std;

template <typename T>
class list_eda_plus : public list<T> {
    using Nodo = typename list<T>::Nodo;
    
private:
    template <class Apuntado>
    class reverse_iterator {
        // puntero al nodo actual del recorrido
        Nodo* act;
        // puntero al nodo fantasma (para saber cuándo estamos fuera)
        Nodo* fan;
    public:

        reverse_iterator() : act(nullptr), fan(nullptr) {}

        // para acceder al elemento apuntado
        Apuntado& operator*() const {
            if (act == fan) throw std::out_of_range("fuera de la lista");
            return act->elem;
        }

        // para acceder a un método del elemento apuntado
        // it->metodo() en vez de (*it).metodo()
        Apuntado* operator->() const {
            return &(operator*());
        }

        reverse_iterator& operator++() { 
            if (act == fan->sig) throw std::out_of_range("fuera de la lista");
            act = act->ant;
            return *this;
        }

        reverse_iterator operator++(int) { // ++ postfijo
            reverse_iterator ret(*this);
            operator++();
            return ret;
        }

        bool operator==(reverse_iterator const& that) const {
            return act == that.act && fan == that.fan;
        }

        bool operator!=(reverse_iterator const& that) const {
            return !(*this == that);
        }

    private:
        // para que list pueda construir objetos del tipo iterador
        friend class list_eda_plus;

        // constructora privada
        reverse_iterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };

public:
    using r_iterator = reverse_iterator<T>;

    r_iterator rbegin() {
        return r_iterator(this->fantasma, this->fantasma);
    }

    r_iterator rend() {
        return r_iterator(this->fantasma->sig, this->fantasma);
    }
};




void resuelveCaso() {

    list_eda_plus<int> lista;
    int n;

    cin >> n;
    while (n != 0) {
        lista.push_back(n);
        cin >> n;
    }

    auto it = lista.rbegin();
    if (it != lista.rend()) {
        ++it;
        cout << (*it);
    }

    while (it != lista.rend()) {
        ++it;
        cout << ' ' << (*it);
    }

    cout << '\n';
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