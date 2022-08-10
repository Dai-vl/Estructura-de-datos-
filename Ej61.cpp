// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <list>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

template<typename paciente>
class urgencias {
private:
    unordered_map<paciente, pair<int, typename list<paciente>::iterator>> personas;
    list<paciente> listGravedad[3]; // 1, 2, 3 gravedad -1
    set<paciente> recuperadosSet;
    const int MIN_GRAV = 1, MAX_GRAV = 3;
    
public:
    void nuevo_paciente(const paciente &p, int g) {
        if (personas.count(p)) throw domain_error("Paciente repetido");
        if (g > MAX_GRAV || g < MIN_GRAV) throw domain_error("Gravedad incorrecta");
        else {
            listGravedad[g -1].push_back(p);
            personas[p] = { g, --listGravedad[g-1].end()};
        }
    }

    int gravedad_actual(const paciente &p) const {
        if (!personas.count(p)) throw domain_error("Paciente inexistente");
        else {
            return personas.at(p).first;
        }
    }

    paciente siguiente() {
        if (listGravedad[0].size() == 0 && listGravedad[1].size() == 0 && listGravedad[2].size() == 0)
            throw domain_error("No hay pacientes");
        else {
            for (int i = 2; i >= 0; --i) {
                if (listGravedad[i].size() != 0) {
                    string p = listGravedad[i].front();
                    listGravedad[i].pop_front();
                    personas.erase(p);
                    return p;
                }
            }
        }
    }

    void mejora(const paciente& p) {
        if (!personas.count(p)) throw domain_error("Paciente inexistente");
        else {
            //se coloca al principio de la nueva gravedad
            auto itP = personas.find(p);
            int antGrav = itP->second.first;
            int nuevGrav = antGrav - 1;
            //borro al paciente de la sala de espera
            listGravedad[antGrav-1].erase(itP->second.second);
            //lo meto en la nueva sala de espera
            if (nuevGrav > 0) {
                listGravedad[nuevGrav - 1].push_front(p);
                personas.at(p) = { nuevGrav, listGravedad[nuevGrav - 1].begin() };
            }
            else {
                recuperadosSet.insert(p);
                personas.erase(p);
            }
        }
    }

    vector<paciente> recuperados() const{
        vector<paciente> v;
        for (paciente p : recuperadosSet)
            v.push_back(p);
        return v;
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string op;
    cin >> op;
    if (!std::cin)
        return false;

    string p;
    int g;
    urgencias<string> u;

    while (op != "FIN") {
        try {
            if (op == "nuevo_paciente") {
                cin >> p >> g;
                u.nuevo_paciente(p, g);
            }
            else if (op == "gravedad_actual") {
                cin >> p;
                g = u.gravedad_actual(p);
                cout << "La gravedad de " << p << " es " << g << '\n';
            }
            else if (op == "siguiente") {
               p =  u.siguiente();
               cout << "Siguiente paciente: " << p << '\n';
            }
            else if (op == "mejora") {
                cin >> p;
                u.mejora(p);

            }
            else if (op == "recuperados") {
                vector<string> v = u.recuperados();
                cout << "Lista de recuperados:";
                for (string s : v)
                    cout << ' ' << s;
                cout << '\n';
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