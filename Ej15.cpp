// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include<stack>
#include<string>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    stack<char> pila;
    string entrada;
    getline(cin, entrada);


    if (!std::cin)
        return false;

    int par = 0, cor = 0, llav= 0;
    bool equilibrado = true;

    for (int i = 0; i < (int) entrada.length() && equilibrado; i++) {
        if (entrada[i] == '(' ) {
            pila.push(entrada[i]);
            par++;
        }
        else if (entrada[i] == '[') {
            pila.push(entrada[i]);
            cor++;
        }
        else if (entrada[i] == '{') {
            pila.push(entrada[i]);
            llav++;
        }
        else if (entrada[i] == ')' ){
            if (pila.empty() || pila.top() != '(')
                equilibrado = false;
            else {
                pila.pop();
                par--;
            }
        }
        else if (entrada[i] == ']') {
            if (pila.empty() || pila.top() != '[')
                equilibrado = false;
            else {
                pila.pop();
                cor--;
            }
        }
        else if (entrada[i] == '}') {
            if (pila.empty() || pila.top() != '{')
                equilibrado = false;
            else {
                pila.pop();
                llav--;
            }
        }
    }

    if (equilibrado && par == 0 && cor == 0 && llav == 0) cout << "SI\n";
    else cout << "NO\n";

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