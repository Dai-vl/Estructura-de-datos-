// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

bool resuelveCaso() {
    int n; cin >> n;

    if (!std::cin)
        return false;
    int k;
    cin >> k;

    int a;
    queue<int> cola;
    deque<pair<int, int>> posMaximos;
    vector<int> maximos;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        cola.push(a);
        if (!posMaximos.empty() && (i - posMaximos.front().second == k))
            posMaximos.pop_front();
        while ((!posMaximos.empty() && a > posMaximos.back().first)) {
            posMaximos.pop_back();
        }
        posMaximos.push_back({a, i});
        if (cola.size() == k) {
            maximos.push_back(posMaximos.front().first);
            cola.pop();
        }
    }

    cout << maximos[0];

    for (int i = 1; i < maximos.size(); ++i)
        cout << ' ' << maximos[i];
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