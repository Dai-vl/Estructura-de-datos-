// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {
private:
    unordered_map<string, pair<int, int>> mapaTorres;
    unordered_map<int, map<int, string>> mapaX;
    unordered_map<int, map<int, string>> mapaY;

public:
    void anyadir_torre(const string& nombre, int x, int y) {
        if (mapaTorres.count(nombre)) throw domain_error("Torre ya existente");
        if (mapaX.count(x) && mapaX.at(x).count(y)) throw domain_error("Posicion ocupada");
        mapaTorres[nombre] = { x, y };
        mapaX[x][y] = nombre;
        mapaY[y][x] = nombre;
    }

    void eliminar_torre(const string& nombre) {
        if (!mapaTorres.count(nombre)) throw domain_error("Torre no existente");
        auto it = mapaTorres.find(nombre);
        mapaX[it->second.first].erase(it->second.second);
        if (mapaX[it->second.first].empty())
            mapaX.erase(it->second.first);
        mapaY[it->second.second].erase(it->second.first);
        if (mapaY[it->second.second].empty())
            mapaY.erase(it->second.second);
        mapaTorres.erase(nombre);
    }

    pair <int, int> posicion(const string& nombre) const {
        if (!mapaTorres.count(nombre)) throw domain_error("Torre no existente");
        return mapaTorres.at(nombre);
    }

    pair<bool, string> torre_en_posicion(int x, int y) const {
        if (!mapaX.count(x) || !mapaX.at(x).count(y)) return {false, string()};
        return { true, mapaX.at(x).at(y) };
    }

    string torre_mas_cercana(const string& nombre, const Direccion& dir) const {
        if (!mapaTorres.count(nombre)) throw domain_error("Torre no existente");
        pair<int, int> pos = mapaTorres.at(nombre);
        if (dir == Sur) {
            auto itX = mapaX.find(pos.first);
            if (itX == mapaX.end()) throw domain_error("No hay torres en esa direccion");
            auto itY = itX->second.find(pos.second);
            
            if (itY == itX->second.begin())
                throw domain_error("No hay torres en esa direccion");

            --itY;
            return itY->second;
        }
        else if (dir == Norte) {
            auto itX = mapaX.find(pos.first);
            if (itX == mapaX.end()) throw domain_error("No hay torres en esa direccion");
            auto itY = itX->second.find(pos.second);

            ++itY;
            if (itY != itX->second.end())
                return itY->second;
            else
                throw domain_error("No hay torres en esa direccion");
        }
        else if (dir == Este) {
            auto itY = mapaY.find(pos.second);
            if (itY == mapaY.end()) throw domain_error("No hay torres en esa direccion");
            auto itX = itY->second.find(pos.first);

            ++itX;
            if (itX != itY->second.end())
                return itX->second;
            else
                throw domain_error("No hay torres en esa direccion");

        }
        else if (dir == Oeste) {
            auto itY = mapaY.find(pos.second);
            if (itY == mapaY.end()) throw domain_error("No hay torres en esa direccion");
            auto itX = itY->second.find(pos.first);

            if (itX == itY->second.begin())
                throw domain_error("No hay torres en esa direccion");

            --itX;
            return itX->second;
        }
    }

};

Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Desierto d;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "anyadir_torre") {
                std::string nombre; int x, y;
                std::cin >> nombre >> x >> y;
                d.anyadir_torre(nombre, x, y);
            }
            else if (op == "eliminar_torre") {
                std::string nombre;
                std::cin >> nombre;
                d.eliminar_torre(nombre);
            }
            else if (op == "posicion") {
                std::string nombre;
                std::cin >> nombre;
                std::pair<int, int> sol = d.posicion(nombre);
                std::cout << sol.first << ' ' << sol.second << '\n';
            }
            else if (op == "torre_en_posicion") {
                int x, y; std::cin >> x >> y;
                std::pair<bool, std::string> sol = d.torre_en_posicion(x, y);
                if (sol.first)
                    std::cout << "SI " << sol.second << '\n';
                else std::cout << "NO\n";
            }
            else {
                std::string nombre; std::string dir;
                std::cin >> nombre >> dir;
                std::string sol = d.torre_mas_cercana(nombre, calculaDir(dir));
                std::cout << sol << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
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