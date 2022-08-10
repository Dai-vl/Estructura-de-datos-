// IMPORTANTE
// Nombre del alumno: Daniela Vidal
// Usuario del juez: A75

// Las torres del desierto

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <unordered_map>
#include <map>

using namespace std;

enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {
private:
    unordered_map<string, pair<int, int>> torres;
    unordered_map<int, map<int, string>> coordenadasX; //x y nombre
    unordered_map<int, map<int, string>> coordenadasY; //y x nombre
public:

    void anyadir_torre(const string& nombre, int x, int y) { //coste logaritmico en funcion de las torres que haya en el mapa ordenado dentro de cada mapa de coordenadas 
        if (torres.count(nombre) != 0) throw domain_error("Torre ya existente");
        else if (coordenadasX.count(x) && coordenadasX.at(x).count(y)) {
                throw domain_error("Posicion ocupada");
        }
        else {
            torres[nombre] = { x, y };
            coordenadasX[x].insert( { y, nombre });
            coordenadasY[y].insert({ x, nombre });
        }
    }

    void eliminar_torre(const string& nombre) { //coste logaritmico en funcion de las torres que esten en el mapa ordenado dentro del mapa de coordenadas (acceder a un unordered_map es casi constante)
        if (torres.count(nombre) == 0) throw domain_error("Torre no existente");
        else {
            pair<int, int> coord = torres[nombre];
            coordenadasX.at(coord.first).erase(coord.second);
         /*   if (coordenadasX.at(coord.first).empty()) {
                coordenadasX.erase(coord.first);
            }*/
            coordenadasY.at(coord.second).erase(coord.first);
            torres.erase(nombre);
        }
    }

    pair<int, int> posicion(const string& nombre) const { //coste constante ya que es buscar en un unordered_map (al estar bien diseñado es constante)
        if(torres.count(nombre) == 0) throw domain_error("Torre no existente");
        else {
            return torres.at(nombre);
        }
    }

    pair<bool, string> torre_en_posicion(int x, int y) const { //coste logaritmico en el numero de torres dentro del mapa ordenado, ya que es buscar en un map ordenado en un unordered_map 
        if (coordenadasX.count(x) != 0 && coordenadasX.at(x).count(y) != 0) {
            return{ true, coordenadasX.at(x).at(y) };
        }
        else {
            return{ false, "" };
        }
    }

    string torre_mas_cercana(const string& nombre, const Direccion& dir) const { //coste logaritmico respecto al numero de torres en una x o una y, ya que buscar en un unordered map es constante y luego hay que buscar en el mapa ordenado
        if (torres.count(nombre) == 0) throw domain_error("Torre no existente");
        else {
            pair<int, int> coord = torres.at(nombre);
            if (dir == Norte) {
                auto it = coordenadasX.at(coord.first).find(coord.second);
                if (it != coordenadasX.at(coord.first).end()) {
                    ++it;
                }
                if (it != coordenadasX.at(coord.first).end())
                    return{ it->second };
                else
                    throw domain_error("No hay torres en esa direccion");
            }
            else if (dir == Sur) {
                auto it = coordenadasX.at(coord.first).find(coord.second);
                if (it != coordenadasX.at(coord.first).begin()) {
                    --it;
                    return{ it->second };
                }
                else
                    throw domain_error("No hay torres en esa direccion");
            }
            else if (dir == Este) {
                auto it = coordenadasY.at(coord.second).find(coord.first);
                if (it != coordenadasY.at(coord.second).end()) {
                    ++it;
                }
                if (it != coordenadasY.at(coord.second).end())
                    return{ it->second };
                else
                    throw domain_error("No hay torres en esa direccion");
            }
            else{
                auto it = coordenadasY.at(coord.second).find(coord.first);
                if (it != coordenadasY.at(coord.second).begin()) {
                    --it;
                    return{ it->second };
                }
                else
                    throw domain_error("No hay torres en esa direccion");
            }
        }
    }



};

// Transforma un string en el tipo enumerado Direccion
// Para la llamada a la función torre_mas_cercana
Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
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

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


