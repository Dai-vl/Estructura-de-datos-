// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include "bintree_eda.h"
using namespace std;


template <class T>
class bintree_plus : public bintree<T> {
    using Link = typename bintree<T>::Link;
public:

    pair <bool,pair<int,int>> level(T elem) {
        bool encontrado = false;
        int repeticiones = 0;
        T nodo{}; int nivel = 0;
        if (this->empty())
            return { false , {1, 0} };

        queue<pair <int, Link>> cola;

        cola.push({ 1 , this->raiz});
        pair<int, int> sol = { 0,1 };

        // en la cola solamente guardamos arboles no vacios
        while (!cola.empty() && !encontrado) {
            auto const& par = cola.front();
            auto const& a = par.second;
            nivel = par.first;
            if (nivel != sol.first) {
                sol.first = nivel;
                sol.second = 0;
            }
            if (a->elem == elem) {
                sol.second++;
            }
            if (sol.second > 1) encontrado = true;
            else {
                if(a->left != nullptr)
                    cola.push({ par.first + 1 , a->left });
                if (a->right != nullptr)
                    cola.push({ par.first + 1 , a->right });
            }
            cola.pop();
        }
        return { encontrado , sol };
    }

    bintree_plus() {
        bintree<T>();
    }

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



void resuelveCaso() {
    char tipo;
    cin >> tipo;
    if (tipo == 'N') {
        int num;
        cin >> num;
        bintree_plus<int> arbolito = leerArbolPlus(-1);
        pair<bool, pair<int, int>> sol = arbolito.level(num);
        if (sol.first)
            cout << sol.second.first << '\n';
        else
            cout << "NO EXISTE\n";
    }
    else if (tipo == 'C') {
        char letra;
        cin >> letra;
        bintree_plus<char> arbolito = leerArbolPlus('.');
        pair<bool, pair<int, int>> sol = arbolito.level(letra);
        if (sol.first)
            cout << sol.second.first << '\n';
        else
            cout << "NO EXISTE\n";
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