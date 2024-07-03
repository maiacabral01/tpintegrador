#include <iostream>
#include "juego.h"

using namespace std;

int main() {
    int opcion;
    int puntuacionMasAlta = 0;
    string nombrePuntuacionMasAlta;

    do {
        cout << "--------Menu Principal--------" << endl<<endl;
        cout << "1. Juego nuevo para un jugador" << endl;
        cout << "2. Juego nuevo para dos jugadores" << endl;
        cout << "3. Mostrar puntuacion mas alta" << endl;
        cout << "4. Salir del juego" << endl<<endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                juegoUnJugador(puntuacionMasAlta, nombrePuntuacionMasAlta);
                break;
            case 2:
                juegoDosJugadores(puntuacionMasAlta, nombrePuntuacionMasAlta);
                break;
            case 3:
                mostrarPuntuacionMasAlta(puntuacionMasAlta, nombrePuntuacionMasAlta);
                break;
            case 4:
                cout << "Saliendo del juego..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;

        }
    } while (opcion != 4);

    return 0;
}
