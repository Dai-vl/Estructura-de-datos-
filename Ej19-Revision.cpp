// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

bool esVocal(const char& c) {
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
        return true;
    return false;
}

string vocales(const string& codigo) {
    string codigoDev;
    stack<char> aux;

    for (char c : codigo) {
        if (!esVocal(c)) {
            aux.push(c);
        }
        else {
            while (!aux.empty()) {
                codigoDev.push_back(aux.top());
                aux.pop();
            }
            codigoDev.push_back(c);
        }
    }

    while (!aux.empty()) {
        codigoDev.push_back(aux.top());
        aux.pop();
    }

    return codigoDev;
}


string delanteDetras(const string &codigo) {
    queue<char> delante;
    stack<char> detras;

    for (int i = 0; i < codigo.length(); ++i) {
        if ((i % 2) == 0)
            delante.push(codigo[i]);
        else
            detras.push(codigo[i]);
    }

    string codigoDev;

    int tam = delante.size();
    for (int i = 0; i < tam; ++i) {
        codigoDev.push_back(delante.front());
        delante.pop();
    }

    tam = detras.size();
    for (int i = 0; i < tam; ++i) {
        codigoDev.push_back(detras.top());
        detras.pop();
    }

    return codigoDev;
}

bool resuelveCaso() {
    string codigo2;

    getline(cin, codigo2);

    if (!std::cin)
        return false;

    string codigo1 = delanteDetras(codigo2);
    string codigo0 = vocales(codigo1);

    cout << codigo0 << '\n';

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