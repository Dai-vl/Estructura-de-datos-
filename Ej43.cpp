// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
using namespace std;

using tabla = std::map < std::string, int >;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    tabla t;
    string nombre, nota;
    int sum;
    for (int i = 0; i < n; ++i) {
        getline(cin, nombre); //para comerse el final de linea
        getline(cin, nombre);
        cin >> nota;
        nota == "INCORRECTO" ? sum = -1 : sum = 1;
        t[nombre] += sum;
    }

    for (auto i : t) {
        if( i.second != 0)
            cout << i.first << ", " << i.second << '\n';
    }

    cout << "---\n";
    // escribir sol

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
