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

        system("CLS");

        switch (opcion) {

            case 1:
                juegoUnJugador(puntuacionMasAlta, nombrePuntuacionMasAlta);
                system("pause");
                system("CLS");
                break;

            case 2:
                juegoDosJugadores(puntuacionMasAlta, nombrePuntuacionMasAlta);
                system("pause");
                system("CLS");
                break;

            case 3:
                mostrarPuntuacionMasAlta(puntuacionMasAlta, nombrePuntuacionMasAlta);
                system("pause");
                system("CLS");
                break;

            case 4:
                cout << "Saliendo del juego..." << endl;
                break;

            default:
                system("CLS");

                cout << "Opcion no valida. Intente de nuevo." << endl;

                system("pause");


        }
    } while (opcion != 4);

    return 0;
}
