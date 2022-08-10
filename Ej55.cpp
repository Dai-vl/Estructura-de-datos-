// IMPORTANTE
// Nombre del alumno: Daniela Vidal
// Usuario del juez: A75


// Elecciones presidenciales

#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <fstream>

using namespace std;

struct info_playlist {
    bool estaP;
    bool estaR;
    list<string>::iterator itPlaylist;
    list<string>::iterator itRepr;
    info_playlist() : estaP(false), estaR(false){};
};

class iPud {
private:
    unordered_map<string, pair<string, int>> mapCancion;
    unordered_map<string, info_playlist> mapPlaylist; 
    list<string> reproducidas;
    list<string> playlist;
    int tPlaylist = 0;
public:

    void addSong(const string & c, const string & a, const int& d) {
        if (mapCancion.count(c) != 0) throw domain_error("addSong");
        else {
            mapCancion[c] = { a, d };
        }
    }

    void addToPlaylist(const string& c) {
        if (mapCancion.count(c) == 0) throw domain_error("addToPlaylist");
        else {
            if (!mapPlaylist[c].estaP) { //se añade si no esta ya en la playlist
                playlist.push_back(c);
                tPlaylist += mapCancion.at(c).second;
                mapPlaylist[c].estaP = true;
                mapPlaylist[c].itPlaylist = --playlist.end();;
            }
        }
    }

    string current() const{
        if (playlist.size() == 0) throw domain_error("current");
        else {
            return playlist.front();
        }
    }

    string play() {
        if(playlist.size() == 0)  throw length_error("No hay canciones en la lista");
        else{
            string primera = playlist.front();
            playlist.pop_front();
            if (mapPlaylist.at(primera).estaR) //esta en reproducidas
                reproducidas.erase(mapPlaylist.at(primera).itRepr);

            reproducidas.push_front(primera);
            tPlaylist -= mapCancion.at(primera).second;
            mapPlaylist[primera].estaP = false;
            mapPlaylist[primera].estaR = true;
            mapPlaylist[primera].itRepr = reproducidas.begin();

            return primera;
        }

    }

    int totalTime() const{
        if (playlist.empty()) return 0;
        else return tPlaylist;
    }

    vector<string> recent(const int &n) const {
        if (reproducidas.size() == 0)
            throw std::length_error("No hay canciones recientes");
        vector<string> v;
        int i = 0;
        for (auto it = reproducidas.begin(); i < n && it != reproducidas.end(); ++i) {
            v.push_back(*it);
            ++it;
        }
        return v;
    }

    void deleteSong(const string& c) {
        if (mapCancion.count(c)) {
            if (mapPlaylist.count(c)) {
                if (mapPlaylist.at(c).estaP) {
                    playlist.erase(mapPlaylist.at(c).itPlaylist);
                    tPlaylist -= mapCancion.at(c).second;
                }
                if(mapPlaylist.at(c).estaR) {
                    reproducidas.erase(mapPlaylist.at(c).itRepr);
                }
                mapCancion.erase(c);
                mapPlaylist.erase(c);
            }
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    
    string c, a;
    int d;
    iPud ip;

    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "addSong") {
                cin >> c >> a >> d;
                ip.addSong(c, a, d);
            }
            else if (op == "addToPlaylist") {
                cin >> c;  ip.addToPlaylist(c);
            }
            else if (op == "current") {
                c = ip.current();
            }
            else if (op == "play") {
                string a = ip.play();
                cout << "Sonando " << a << endl;
            }
            else if (op == "totalTime") {
                d = ip.totalTime();
                cout <<  "Tiempo total "  << d << '\n';
            }
            else if (op == "recent") {
                int n; cin >> n;
                vector<string> sol = ip.recent(n);
                cout << "Las " << sol.size() << " mas recientes\n";
                for (string &s : sol)
                    std::cout << "    " << s << '\n';
            }
            else if (op == "deleteSong") {
                cin >> c;
                ip.deleteSong(c);
            }
        }
        catch (std::domain_error const& e) {
            std::cout << "ERROR " << e.what() << '\n';
        }
        catch (std::length_error const& e) {
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


