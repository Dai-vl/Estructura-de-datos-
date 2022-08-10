// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class persona {
private:
    int edad;
    string nombre;
public:
    persona(int e, string n) : edad(e), nombre(n) {};
    persona() {};
    int getEdad() const {
        return edad;
    }

    string getNombre() const {
        return nombre;
    }
};

class filtro_edad {
private: int edadMin, edadMax;
public: 
    filtro_edad(int em, int ex) : edadMin(em), edadMax(ex) {};

    int operator()(persona p) {
        return p.getEdad() < edadMin || p.getEdad() > edadMax;
    }
};


template <class T, class Predicate>
void remove_if (list <T > &lista, Predicate pred) {
    auto it = lista.begin();

    while (it != lista.end()) {
        if (pred(*it)) {
            it = lista.erase(it);
        }
        else {
            ++it;
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, edadMin, edadMax;
    cin >> n >> edadMin >> edadMax;

    if (n == 0 && edadMin == 0 && edadMax == 0)
        return false;

    list<persona> l;

    for (int i = 0; i < n; i++) {
        string n;
        int e;
        cin >> e;
        cin.get();
        getline(cin, n);
        l.push_back(persona(e, n));
    }

    remove_if(l, filtro_edad(edadMin, edadMax));
    // escribir sol


    auto it = l.begin();
    persona p;

    while (it != l.end()) {
        p = *it;
        cout << p.getNombre() << '\n';
        ++it;
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
