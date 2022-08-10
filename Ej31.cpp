// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "bintree_eda.h"
using namespace std;

template <class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;
private:

    T menorElem(Link raiz) {
        auto minimo = raiz->elem;
        if (raiz->left != nullptr) {
            minimo = min(minimo, menorElem(raiz->left));
        }
        if (raiz->right != nullptr) {
            minimo = min(minimo, menorElem(raiz->right));
        }
        return minimo;
    }
public:

    bintree_plus() {
        bintree<T>();
    }

    bintree_plus(T const& e) :
        bintree<T>(e) {}

    // árbol con dos hijos
    bintree_plus(bintree_plus<T> const& l, T const& e, bintree_plus<T> const& r) :
        bintree<T>(l, e, r) {}

    T getMin() {
        return menorElem( this->raiz);
    }
};

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

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char tipo;
    cin >> tipo;
    if (!std::cin)
        return false;

    if (tipo == 'N') {
        bintree_plus<int> arbolito = leerArbolPlus(-1);
        int min = INT_MIN;
        cout << arbolito.getMin();
    }
    else if (tipo == 'P'){
        string vacio = "#";
        bintree_plus<string> arbolito = leerArbolPlus(vacio);
        string min = arbolito.root();
        cout << arbolito.getMin();
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
