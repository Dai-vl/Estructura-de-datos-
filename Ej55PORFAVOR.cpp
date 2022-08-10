// Nombre del alumno Daniela Vidal
// Usuario del Juez A75


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;


class iPud {
private:
    struct infoCancion {
        int duracion;
        pair<bool, list<string>::iterator> itLista;
        pair<bool, list<string>::iterator> itRepr;
        infoCancion() : duracion(0), itLista({ false, list<string>::iterator() }), itRepr({ false, list<string>::iterator() }) {};
    };

    unordered_map<string, infoCancion> mapaCanc;
    list<string> playlist;
    list<string> reprod;
    int tiempoLista = 0;

public:
    void addSong(const string& cancion, int duracion) {
        if (mapaCanc.count(cancion))
            throw domain_error("addSong");
        mapaCanc[cancion].duracion = duracion;
    }

    void addToPlaylist(const string& cancion) {
        if (!mapaCanc.count(cancion)) 
            throw domain_error("addToPlaylist");
        auto it = mapaCanc.find(cancion);
        if (!it->second.itLista.first) {
            playlist.push_back(cancion);
            it->second.itLista = { true, --playlist.end() };
            tiempoLista += it->second.duracion;
        }
    }

    string current() const{
        if (playlist.size() == 0)
            throw domain_error("current");
        return playlist.front();
    }

    string play() {
        string s = " vacio ";

        if (playlist.size() > 0) {
            s = playlist.front();
            playlist.pop_front();

            auto it = mapaCanc.find(s);

            it->second.itLista = { false, list<string>::iterator() };

            if (it->second.itRepr.first) {
                reprod.erase(it->second.itRepr.second);
            }
            reprod.push_front(s);
            it->second.itRepr = { true, reprod.begin() };

            tiempoLista -= it->second.duracion;
        }

        return s;
    }

    int totalTime()  {
        return tiempoLista;
    }

    vector<string> recent(int n) {
        vector<string> vector;

        auto it = reprod.begin();
        for (auto it = reprod.begin(); vector.size() < n && it != reprod.end(); ++it) {
            vector.push_back(*it);
        }

        return vector;
    }

    void deleteSong(const string& cancion) {
        if (mapaCanc.count(cancion)) {
            auto it = mapaCanc.find(cancion);
            if (it->second.itLista.first) {
                playlist.erase(it->second.itLista.second);
                tiempoLista -= it->second.duracion;
            }
            if (it->second.itRepr.first){
                reprod.erase(it->second.itRepr.second);
            }
            mapaCanc.erase(cancion);
        }
    }

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string op, cancion, aux;
    int arg;
    cin >> op;
    if (!std::cin)
        return false;

    iPud iPud;

    while (op != "FIN") {
        try {
            if (op == "play") {
                cancion = iPud.play();
                if (cancion == " vacio ")
                    cout << "No hay canciones en la lista\n";
                else
                    cout << "Sonando " << cancion << '\n';
            }
            else if (op == "totalTime") {
                arg = iPud.totalTime();
                cout << "Tiempo total " << arg << '\n';
            }
            else if (op == "recent") {
                cin >> arg;
                vector<string> sol = iPud.recent(arg);
                arg = sol.size();
                if (arg == 0)
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << arg << " mas recientes\n";
                    for (string& c : sol) {
                        cout << "    " << c << '\n';
                    }
                }
            }
            else  if (op == "addSong") {
                cin >> cancion >> aux >> arg;
                iPud.addSong(cancion, arg);
            }
            else if (op == "addToPlaylist") {
                cin >> cancion;
                iPud.addToPlaylist(cancion);
            }
            else if (op == "current") {
                cancion = iPud.current();
            }
            else if (op == "deleteSong") {
                cin >> cancion;
                iPud.deleteSong(cancion);
            }
        }
        catch (domain_error& e) {
            cout << "ERROR " << e.what() << '\n';
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