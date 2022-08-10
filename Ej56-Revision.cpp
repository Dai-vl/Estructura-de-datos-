// IMPORTANTE
// Nombre del alumno: Daniela Vidal
// Usuario del juez: A75


// Elecciones presidenciales

#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;



class ConteoVotos {
private:
    struct info_estado {
        int compr;
        string ganador;
        unordered_map<string, int> mapaPE; //partido estado
    };

    unordered_map<string, info_estado> mapaEstados;
    map<string, int> mapaPartidos;

public:

    void nuevo_estado(const string& nombre, int num_compromisarios) {
        if (mapaEstados.count(nombre)) throw domain_error("Estado ya existente");
        mapaEstados[nombre].compr = num_compromisarios;
    }

    void sumar_votos(const string& estado, const string& partido, int num_votos) {
        if (!mapaEstados.count(estado)) throw domain_error("Estado no encontrado");

        auto it = mapaEstados.find(estado);
        it->second.mapaPE[partido] += num_votos;

        if (!it->second.ganador.empty() && it->second.mapaPE[partido] > it->second.mapaPE[it->second.ganador]) {
            mapaPartidos.at(it->second.ganador) -= it->second.compr;
            if (mapaPartidos.at(it->second.ganador) == 0)
                mapaPartidos.erase(it->second.ganador);
            it->second.ganador = partido;
            mapaPartidos[partido] += it->second.compr;
        }
        else if(it->second.ganador.empty()){
            it->second.ganador = partido;
            mapaPartidos[partido] += it->second.compr;
        }

    }

    string ganador_en(const string& estado) const {
        if (!mapaEstados.count(estado)) throw domain_error("Estado no encontrado");

        return mapaEstados.at(estado).ganador;
    }

    vector<pair<string, int>> resultados() const {
        vector<pair<string, int>> v;

        auto it = mapaPartidos.begin();
        while (it != mapaPartidos.end()) {
            v.push_back({ it->first, it->second });
            ++it;
        }
        return v;
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    ConteoVotos cv;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_estado") {
                std::string nombre; int num_compromisarios;
                std::cin >> nombre >> num_compromisarios;
                cv.nuevo_estado(nombre, num_compromisarios);
            }
            else if (op == "sumar_votos") {
                std::string estado, partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                cv.sumar_votos(estado, partido, num_votos);
            }
            else if (op == "ganador_en") {
                std::string estado;
                std::cin >> estado;
                std::string sol = cv.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << sol << '\n';
            }
            else if (op == "resultados") {
                std::vector<std::pair<std::string, int>> sol = cv.resultados();
                for (std::pair<std::string, int> const& s : sol)
                    std::cout << s.first << ' ' << s.second << '\n';
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
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


