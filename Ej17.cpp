// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;

// función que resuelve el problema
void resolver() {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n, salta;
    cin >> n >> salta;

    if (n == 0 && salta == 0)
        return false;

    queue<int> cola;

    for (int i = 1; i <= n; i++) {
        cola.push(i);
    }

    int c = 0;

    while (cola.size() != 1) {
        if (c == salta) {
            c = 0;
        }
        else {
            c++;
            cola.push(cola.front());
        }
        cola.pop();
    }
    // escribir sol

    cout << cola.front() << '\n';

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
