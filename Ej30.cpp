// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

template <class T>
class bintree_plus : public bintree<T>{
    using Link = typename bintree<T>::Link;
private:
    int calcularNodos(Link raiz) const{
        if (raiz == nullptr) {
            return 0;
        }
        else {
            int iz = calcularNodos(raiz->left);
            int dc = calcularNodos(raiz->right);
            return iz + dc + 1;
        }
    }

    int calcularHojas(Link raiz) const {
        if (raiz == nullptr) {
            return 0;
        }
        else {
            int iz = calcularHojas(raiz->left);
            int dc = calcularHojas(raiz->right);
            return iz + dc + (raiz->left == nullptr && raiz->right == nullptr);
        }
    }

    int calcularAltura(Link raiz) const {
        if (raiz == nullptr) {
            return 0;
        }
        else {
            int iz = calcularAltura(raiz->left);
            int dc = calcularAltura(raiz->right);
            return max(iz, dc) + 1;
        }
    }

public:

    bintree_plus() {
        bintree<T>();
    }

    bintree_plus(T const& e) :
        bintree<T>(e){}

    // árbol con dos hijos
    bintree_plus(bintree_plus<T> const& l, T const& e, bintree_plus<T> const& r) :
        bintree<T>(l, e, r){}


    int getNodos() const{
        return calcularNodos(this->raiz);
    }

    int getHojas() const {
        return calcularHojas(this->raiz);
    }

    int getAltura() const{
        return calcularAltura(this->raiz);
    }

};

template <typename T>  //COPYRIGHT
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
void resuelveCaso() {
    bintree_plus<char> arbolito = leerArbolPlus('.');

    cout << arbolito.getNodos() << ' ' << arbolito.getHojas() << ' ' << arbolito.getAltura() << '\n';
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
