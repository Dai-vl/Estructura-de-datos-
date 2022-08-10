// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

template<class profesor, class alumno>
class autoescuela {
private:
    unordered_map<alumno, pair<int, profesor>> mA;
    unordered_map<profesor, unordered_set<alumno>> mP;
public:
    autoescuela() {}
    
    void alta(const alumno& a, const profesor& p) {
        auto it = mA.find(a);
        if (it != mA.end()){
            string prof = it->second.second;
            mP[prof].erase(a);
            it->second.second = p;
            mP[p].insert(a);
        }
        else {
            mA[a].first = 0;
            mA[a].second = p;
            mP[p].insert(a);
        }
    }

    bool es_alumno(const alumno& a, const profesor& p) const{
        return (mA.find(a)->second.second == p);
    }

    int puntuacion(const alumno& a) const {
        auto it = mA.find(a);
        if (it == mA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
        return it->second.first;
    }

    void actualizar(const alumno& a, const int& p) {
        auto it = mA.find(a);
        if (it == mA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
        it->second.first += p;
    }

    set<alumno> examen(const profesor& p, const int& n) const{
        set<alumno> s;
        auto it = mP.find(p);
        if (it != mP.end()) {
            for (auto ipa : it->second) {
                if (mA.at(ipa).first >= n)
                    s.insert(ipa);
            }
        }
        return s;
    }

    void aprobar(const alumno& a) {
        auto it = mA.find(a);
        if(it == mA.end()) throw domain_error("El alumno " + a + " no esta matriculado");
        string prof = it->second.second;
        mP[prof].erase(a);
        mA.erase(a);
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string op, alumno, profesor;
    int punt;
    cin >> op;

    if (!std::cin)
        return false;

    autoescuela<string, string> a;

    while (op != "FIN") {
        try {
            if (op == "alta") {
                cin >> alumno >> profesor;
                a.alta(alumno, profesor);
            }
            else if (op == "es_alumno") {
                cin >> alumno >> profesor;
                bool es = a.es_alumno(alumno, profesor);
                string aux;
                es ? aux = " es alumno de " : aux = " no es alumno de ";
                cout << alumno << aux << profesor;
                cout << '\n';
            }
            else if (op == "puntuacion") {
                cin >> alumno;
                int p = a.puntuacion(alumno);
                cout << "Puntuacion de " << alumno << ": " << p;
                cout << '\n';
            }
            else if (op == "actualizar") {
                cin >> alumno >> punt;
                a.actualizar(alumno, punt);
            }
            else if (op == "examen"){
                cin >> profesor >> punt;
                set<string > s = a.examen(profesor, punt);
                cout << "Alumnos de " << profesor << " a examen:\n";
                for (auto i : s)
                    cout << i << '\n';
            }
            else if (op == "aprobar") {
                cin >> alumno;
                a.aprobar(alumno);
            }

        }
        catch (domain_error& e) {
            cout << "ERROR\n";
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