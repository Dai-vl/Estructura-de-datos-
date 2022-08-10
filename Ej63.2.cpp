#include <iostream>
#include <iomanip>
#include <fstream>
#include "gestor_futbolistas.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string instruccion;
    cin >> instruccion;
    if (!std::cin)
        return false;

    gestor_futbolistas gest;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "fichar") {
                string jugador;  cin >> jugador;
                string equipo;  cin >> equipo;
                gest.fichar(jugador, equipo);
            }
            else if (instruccion == "ultimos_fichajes") {
                string equipo; cin >> equipo;
                int n; cin >> n;
                vector<string> sol = gest.ultimos_fichajes(equipo, n);
                cout << "Ultimos fichajes de " << equipo << ":";
                for (string& s : sol)
                    cout << " " << s;
                cout << endl;
            }
            else if (instruccion == "cuantos_equipos") {
                string jugador; cin >> jugador;
                int sol = gest.cuantos_equipos(jugador);
                cout << "Equipos que han fichado a " << jugador << ": " << sol << endl;
            }
            else if (instruccion == "fichados") {
                string equipo; cin >> equipo;
                int sol = gest.fichados(equipo);
                cout << "Jugadores fichados por " << equipo << ": " << sol << endl;
            }
            else if (instruccion == "equipo_actual") {
                string jugador; cin >> jugador;
                string equipo = gest.equipo_actual(jugador);
                cout << "El equipo de " << jugador << " es " << equipo << endl;
            }
        }
        catch (domain_error& de) {
            cout << "ERROR: " << de.what() << endl;
        }
        cin >> instruccion;
    }

    cout << "---" << endl;
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
