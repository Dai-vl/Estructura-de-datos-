// Ej6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "linked_list_ed_plus.h"
using namespace std;

bool resuelveCaso() {

    char letra;
    cin >> letra;

    if (!cin)
        return false;

    linked_list_ed_plus<std::string> lista;
    std::string str;
    getline(std::cin, str); // para saltar el final de linea
    getline(std::cin, str); // lee la linea del caso
    std::stringstream ss(str); // construye el objeto ss de tipo stringstream
    while (ss) {
        std::string aux;
        ss >> aux;
        lista.push_back(aux);
    }
    lista.mostrarPropiedad([letra](string palabra) {return palabra[0] == letra; });

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