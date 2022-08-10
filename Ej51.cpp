// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

using namespace std;

class carnetPorPuntos {
private:
    const int MAX = 15;
    unordered_map<string, int> carnet;
    int array[16];

public:
    void nuevo(const string& dni) {
        if (carnet.count(dni) != 0) throw domain_error("Conductor duplicado");
        carnet[dni] = 15;
        ++array[15];
    }

    void quitar(const string& dni, const int& puntos) {
        if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
        int antP = carnet[dni];
        antP - puntos >= 0 ? carnet[dni] -= puntos : carnet[dni] = 0;
        --array[antP];
        ++array[carnet[dni]];
    }

    int consultar(const string& dni) const{
        if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
        return carnet.at(dni);
    }

    int cuantos_con_puntos(const int& puntos) const{
        if(puntos < 0 || puntos > MAX) throw domain_error("Puntos no validos");
        return array[puntos];
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string op, dni;
    int arg;
    cin >> op;
    if (!std::cin)
        return false;

    carnetPorPuntos c = carnetPorPuntos();

    while (op != "FIN") {
        try {
            if (op == "nuevo") {
                cin >> dni;
                c.nuevo(dni);
            }
            else if (op == "cuantos_con_puntos") {
                cin >> arg;
                int a = c.cuantos_con_puntos(arg);
                cout << "Con " << arg << " puntos hay " << a << '\n';

            }
            else if (op == "quitar") {
                cin >> dni >> arg;
                c.quitar(dni, arg);
            }
            else if (op == "consultar") {
                cin >> dni;
                int a = c.consultar(dni);
                cout << "Puntos de " << dni << ": " << a << '\n';
            }
        }
        catch (domain_error &e) {
            cout << "ERROR: " << e.what() << '\n';
        }
        cin >> op;
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