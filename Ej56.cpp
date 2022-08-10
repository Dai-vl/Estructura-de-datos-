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

struct info_estado {
    int compromisarios;
    string maxPartido;
    int maxVotos;
};

class ConteoVotos {
private:
    unordered_map<string, info_estado> estados;
    map<string, pair<int, unordered_map<string, int>>> partidos; //partido compromisarios estado votos
public:

    void nuevo_estado(const string& nombre, int num_compromisarios) { 
        //coste constante ya que es un unordered_map y sus operaciones tienen coste constante
        if (estados.count(nombre) != 0) throw domain_error("Estado ya existente");
        estados[nombre].compromisarios = num_compromisarios;
        estados[nombre].maxVotos = 0;
    }
    void sumar_votos(const string& estado, const string& partido, int num_votos) { 
        //coste logaritmo en el numero de partidos ya que 
        //se busca , se inserta y se borra en un mapa ordenado, implementado con un arbol de busqueda binaria cuyo coste es 
        //logaritmico en el numero de elementos
        if (estados.count(estado) == 0)
            throw domain_error("Estado no encontrado");
        int aux;
        if (partidos.count(partido) != 0 && partidos.at(partido).second.count(estado) != 0)
            aux = partidos[partido].second.at(estado) + num_votos;
        else
            aux = num_votos;

        partidos[partido].second.insert({estado, aux});

        if (aux > estados.at(estado).maxVotos) {
            estados.at(estado).maxVotos = aux;
            string antMax = estados.at(estado).maxPartido;
            estados.at(estado).maxPartido = partido;

            //le sumo los compromisarios del partido al nuevo
            partidos.at(partido).first += estados.at(estado).compromisarios;
            //le quito al antiguo
            if(antMax != "")
                partidos.at(antMax).first -= estados.at(estado).compromisarios;
        }
    }
    string ganador_en(const string& estado) const { 
        //coste constante ya que es un unordered_map y sus operaciones tienen coste constante
        if(estados.count(estado) == 0)
            throw domain_error("Estado no encontrado");
        return estados.at(estado).maxPartido;
    }
    vector<pair<string, int>> resultados() const { 
        // coste lineal en el numero de partidos
        vector<pair<string, int>> v;
        //max de cada estado y sumas los compromisarios q tenga ese estado
        for (auto& it : partidos) {
            if (it.second.first > 0)
                v.push_back({ it.first, it.second.first });
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


