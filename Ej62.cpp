// Enlace al video de la explicacion: https://youtu.be/GiHcAXkBDf8

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


class oficinaDeEmpleo {
private:
    unordered_map<string, unordered_map<string, list<string>::iterator>> maP;
    unordered_map<string, list<string>> maE; //front sera la mas antigua
public:

    void altaOficina(string p, string e) { //coste constante ya que un mapa sin orden
        if (!maP.count(p) || (maP.count(p) && !maP.at(p).count(e))) {
            maE[e].push_back(p);
            list<string>::iterator it = maE.at(e).end();
            --it;
            maP[p].insert({ e, it });
        }
    }

    string ofertaEmpleo(string e) { //coste lineal en el numero de empleos que tiene la persona
        if(!maE.count(e)) throw domain_error("No existen personas apuntadas a este empleo");
        else {
            string p = maE[e].front();
            for (auto& it : maP.at(p)) {
                string empleo = it.first;
                auto posE = it.second;
                maE.at(empleo).erase(posE);
                if (maE.at(empleo).empty())
                    maE.erase(empleo);
            }
            maP.erase(p);
            return p;
        }
    }

    vector<string> listadoEmpleos(string p) { //coste n*log(n) en el numero de empleos por el sort
        if(!maP.count(p)) throw domain_error("Persona inexistente");
        else {
            vector<string> v;
            for (auto& it : maP.at(p)) {
                v.push_back(it.first);
            }
            sort(v.begin(), v.end());
            return v;
        }
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string op;
    cin >> op;

    if (!std::cin)
        return false;

    string p, e;
    oficinaDeEmpleo o = oficinaDeEmpleo();

    while (op != "FIN") {
        try {
            if (op == "altaOficina") {
                cin >> p >> e;
                o.altaOficina(p, e);
            }
            else if (op == "ofertaEmpleo") {
                cin >> e;
                p = o.ofertaEmpleo(e);
                cout << e << ": " << p << '\n';
            }
            else if (op == "listadoEmpleos") {
                cin >> p;
                vector<string> s = o.listadoEmpleos(p);
                cout << p << ':';
                for (string e : s)
                    cout << ' ' << e;
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