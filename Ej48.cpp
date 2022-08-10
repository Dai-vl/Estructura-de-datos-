// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;


bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    
    int num;
    unordered_map<int, int> numeros; //numero y las veces que aparece
    vector<int> orden;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (!numeros[num])
            orden.push_back(num);
        ++numeros[num];
    }

    for (int& i : orden)
        cout << i << ' ' << numeros[i] << '\n';

    cout << "---\n";

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