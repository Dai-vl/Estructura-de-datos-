// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class carnetPorPuntos {
private:
    const int MAX = 15;
    unordered_map<string, pair<int, list<string>::iterator>> carnet; //dni puntos que tiene posicion en la lista de puntos
    list<string> v[16];

public:
    void nuevo(const string& dni) {
        if (carnet.count(dni) != 0) throw domain_error("Conductor duplicado");
        v[15].push_front(dni);
        carnet[dni] = { 15, v[15].begin() };
    }

    void quitar(const string& dni, const int& puntos) {
        if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
        int antP = carnet[dni].first;
        if (antP != 0) {
            antP - puntos >= 0 ? carnet[dni].first -= puntos : carnet[dni].first = 0;
            int nuevP = carnet[dni].first;

            //lo cambio en la lista
            v[antP].erase(carnet.at(dni).second);
            v[nuevP].push_front(dni);
            carnet[dni].second = v[nuevP].begin();
        }
    }

    void recuperar(const string& dni, const int& puntos) {
        if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
        int antP = carnet[dni].first;
        if (antP != MAX) {
            antP + puntos <= MAX ? carnet[dni].first += puntos : carnet[dni].first = 15;
            int nuevP = carnet[dni].first;

            //lo cambio en la lista
            v[antP].erase(carnet.at(dni).second);
            v[nuevP].push_front(dni);
            carnet[dni].second = v[nuevP].begin();
        }
    }

    int consultar(const string& dni) const {
        if (carnet.count(dni) == 0) throw domain_error("Conductor inexistente");
        return carnet.at(dni).first;
    }

    int cuantos_con_puntos(const int& puntos) const {
        if (puntos < 0 || puntos > MAX) throw domain_error("Puntos no validos");
        return (int)v[puntos].size();
    }

    list<string> lista_por_puntos(const int &puntos) const{
        if (puntos < 0 || puntos > MAX) throw domain_error("Puntos no validos");
        return v[puntos];
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
            else if (op == "recuperar") {
                cin >> dni >> arg;
                c.recuperar(dni, arg);
            }
            else if (op == "consultar") {
                cin >> dni;
                int a = c.consultar(dni);
                cout << "Puntos de " << dni << ": " << a << '\n';
            }
            else if (op == "lista_por_puntos") {
                cin >> arg;
                list<string> l = c.lista_por_puntos(arg);
                cout << "Tienen " << arg << " puntos:";
                for (string s : l) {
                    cout << ' ' << s;
                }
                cout << '\n';
            }
        }
        catch (domain_error& e) {
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