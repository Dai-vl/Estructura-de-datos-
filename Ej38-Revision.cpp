// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "bintree_eda.h"
using namespace std;

template<class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;

public:

    bintree_plus() : bintree<T>() {}

    // árbol hoja
    bintree_plus(T const& e) :
        bintree<T>(e) {}

    // árbol con dos hijos
    bintree_plus(bintree_plus<T> const& l, T const& e, bintree_plus<T> const& r) :
        bintree<T>(l, e, r) {}

    // consultar el hijo izquierdo
    bintree_plus<T> left() const {
        if (this->empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
        else return bintree_plus<T>(this->raiz->left);
    }

    // consultar el hijo derecho
    bintree_plus<T> right() const {
        if (this->empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
        else return bintree_plus(this->raiz->right);
    }


    pair<bool, int> level(int valor) {
       int level = 0, cont = 0;

       if (this->empty())
           return { false, 0 };
       else if (this->raiz->left == nullptr && this->raiz->right == nullptr)
           return{ false, 0 };

       else {
           queue<pair <int, Link>> pendientes; //nivel y link al arbol
           pendientes.push({ 1, this->raiz });

           while (!pendientes.empty()) {
               pair<int, Link> const &par = pendientes.front();
               Link const& arbol = par.second;

               if (par.first != level) {
                   level = par.first;
                   cont = 0;
               }
               if (arbol->elem == valor)
                   cont++;

               if (cont == 2)
                   return{ true, level };
               else {
                   if (arbol->left != nullptr)
                       pendientes.push({ par.first + 1, arbol->left });
                   if (arbol->right != nullptr)
                       pendientes.push({ par.first + 1, arbol->right });
               }
               pendientes.pop();
           }
           return{ false, 0 };
       }
    }

};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree_plus<T> leerArbolPlus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbolPlus(vacio);
        auto dr = leerArbolPlus(vacio);
        return { iz, raiz, dr };
    }
}


void resuelveCaso() {

    char modo;
    cin >> modo;

    if (modo == 'N') {
        int valor; cin >> valor;
        bintree_plus<int> tree = leerArbolPlus(-1);
        auto sol = tree.level(valor);
        if (sol.first)
            cout << sol.second << '\n';
        else cout << "NO EXISTE\n";
    }
    else if (modo == 'C') {
        char valor; cin >> valor;
        char stop = '.';
        bintree_plus<char> tree = leerArbolPlus(stop);
        auto sol = tree.level(valor);
        if (sol.first)
            cout << sol.second << '\n';
        else cout << "NO EXISTE\n";
    }



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