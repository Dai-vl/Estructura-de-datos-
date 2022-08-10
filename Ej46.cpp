// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
using namespace std;

using table = unordered_map<int, int>;

void resuelveCaso() {

    table mapa;
    int n, a;
    cin >> n;
    int longAct = 0, longMax = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (mapa.count(a) == 1 && mapa[a] >= i - longAct) {
            longAct = i - mapa[a];
        }
        else {
            longAct++;
        }
        mapa[a] = i;
        if (longMax < longAct)
            longMax = longAct;

      /*  if (mapa.count(a) == 0) {
            mapa[a] = i;
            longAct++;
            if (longMax < longAct)
                longMax = longAct;
        }
        else if(mapa[a] >= i - longAct) {
            longAct = i - mapa[a];
            mapa[a] = i;
        }*/
    }

    cout << longMax << "\n";

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