// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

struct fecha {
    int anyo, mes, dia; 

  /*  bool operator>(fecha f1) {
        return ((anyo > f1.anyo) || (anyo == f1.anyo && mes > f1.mes) || (anyo == f1.anyo && mes == f1.mes && dia > f1.dia));
    }*/
};

// función que resuelve el problema
void resolver() {


}

bool resuelveCaso() {
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    stack<pair<fecha, int>> cola;

    for (int i = 0; i < n; ++i) {
        fecha f;
        int acc;
        char aux;
        cin >> f.dia >> aux >> f.mes >> aux >> f.anyo >> acc; 

        while (!cola.empty() && acc >= cola.top().second) {
            cola.pop();
        }
        if (!cola.empty())
            cout <<setw(2) <<setfill('0') << cola.top().first.dia << '/' << setw(2) <<cola.top().first.mes << '/' << cola.top().first.anyo << '\n';
        else if(cola.empty())
            cout << "NO HAY\n";
        cola.push({ f, acc });
    }

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