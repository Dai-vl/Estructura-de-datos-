// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

class academia_chino {
private:
    unordered_map<string, pair<int, list<string>::iterator>> maP;
    list<string> lista[7]; // uno menos q el nivel
public:
    void nuevo_estudiante(const string& dni, const int& grupo) {
        if (maP.count(dni) != 0) throw domain_error("Estudiante existente");
        if (grupo < 1 || grupo > 6)
            throw domain_error("Grupo incorrecto");
        lista[grupo-1].push_front(dni);
        maP[dni] = {grupo, lista[grupo-1].begin()};
    }

    void promocionar(const string& dni) {
        if (maP.count(dni) == 0) throw domain_error("Estudiante no existente");
        if (maP.at(dni).first > 6) throw domain_error("Estudiante ya graduado");
        int grupo = maP[dni].first;
        lista[grupo - 1].erase(maP[dni].second);
        ++grupo;
        lista[grupo - 1].push_front(dni);
        maP[dni].first = grupo;
        maP.at(dni).second = lista[grupo - 1].begin();
    }

    int grupo_estudiante(const string& dni) const{
        if (maP.count(dni) == 0) throw domain_error("Estudiante no existente");
        if (maP.at(dni).first > 6) throw domain_error("Estudiante ya graduado");
        return maP.at(dni).first;
    }

    vector<string> graduados() const{
        vector<string> a;
        for (auto &it : lista[6]) {
            a.push_back(it);
        }
        sort(a.begin(), a.end());
        return a;
    }

    string novato(const int& grupo) const{
        if (grupo < 1 || grupo > 6) throw domain_error("Grupo incorrecto");
        if (lista[grupo - 1].empty()) throw domain_error("Grupo vacio");
        return *lista[grupo - 1].begin();
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entradaç
    string op;
    cin >> op;
    if (!std::cin)
        return false;

    string es;
    int g;

    academia_chino ac;
    while (op != "FIN") {
        try {
            if (op == "nuevo_estudiante") {
                cin >> es >> g;
                ac.nuevo_estudiante(es, g);
            }
            else if (op == "promocionar") {
                cin >> es;
                ac.promocionar(es);
            }
            else if (op == "novato") {
                cin >> g;
                string s = ac.novato(g);
                cout << "Novato de " << g << ": " << s << '\n';
            }
            else if (op == "graduados") {
                vector<string> s = ac.graduados();
                cout << "Lista de graduados:";
                for (string t : s) {
                    cout << ' ' << t;
                }
                cout << '\n';
            }
            else if (op == "grupo_estudiante") {
                cin >> es;
                int s = ac.grupo_estudiante(es);
                cout << es << " esta en el grupo " << s << endl;
            }

        }
        catch (domain_error& e) {
            cout << "ERROR: " << e.what() << '\n';
        }
        cin >> op;
    }
    cout << "---\n";
    // escribir sol


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