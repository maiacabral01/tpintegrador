#ifndef JUEGO_CPP_INCLUDED
#define JUEGO_CPP_INCLUDED

#include "juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

static int puntuacionMasAlta = 0;
static string nombrePuntuacionMasAlta;

void tirarDados(int dados[]) {
    for (int i = 0; i < 6; i++) {
        dados[i] = rand() % 6 + 1;
    }
}
    // Contar los dados del 1 al 6
int calcularPuntaje(int dados[]) {
    int conteo[7] = {0};
    for (int i = 0; i < 6; i++) {
        conteo[dados[i]]++;
    }

    // Verificar si es escalera
    if (escalera(dados)) {
        return 1000; // Un puntaje alto que indique que gan— con una escalera
    }

    // Verificar si hay un sexteto de 6
    if (conteo[6] == 6) {
        return -1; // Indica que el puntaje se debe resetear a 0
    }

    // Verificar si hay un sexteto de otro nœmero
    for (int i = 1; i <= 5; i++) {
        if (conteo[i] == 6) {
            return i * 10;
        }
    }

    // Sumar todos los dados si no se cumple ninguna condici—n especial
    int puntaje = 0;
    for (int i = 1; i <= 6; i++) {
        puntaje += conteo[i] * i;
    }

    return puntaje;
}

bool escalera(int dados[]) {
    sort(dados, dados + 6);
    for (int i = 0; i < 6; i++) {
        if (dados[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void imprimirResultados(int dados[], int puntaje, const string& nombre) {
    cout << "Dados: ";
    for (int i = 0; i < 6; i++) {
        cout << dados[i] << " ";
    }
    cout << endl<< endl;
    cout << "Combinaci—n: ";
    if (escalera(dados)) {
        cout << "Escalera" << endl;
    } else if (puntaje == -1) {
        cout << "Sexteto de 6 - Puntaje reseteado" << endl;
    } else {
        cout << "Suma de dados" << endl;
    }
    cout << "Puntaje: " << puntaje << endl<<endl;
}

void juegoUnJugador() {
    string nombre;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;

    int puntajeTotal = 0;
    int ronda = 1;
    int dados[6];
    srand(time(0)); // Inicializar la semilla para la funci—n rand

    while (puntajeTotal < 100) {

        system("pause");
        system("CLS");
        cout << "--------RONDA " << ronda<<"--------"<<endl<<endl;
        cout << "Puntaje actual: " << puntajeTotal << endl;
        int maxPuntajeRonda = 0;

        for (int i = 0; i < 3; i++) {
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) {
                cout << "ÁEscalera! " << nombre << " ha ganado la partida." << endl;
                return;
            }

            if (puntaje == -1) {
                puntajeTotal = 0;
                maxPuntajeRonda = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda) {
                maxPuntajeRonda = puntaje;
            }

            cout<<endl;
            imprimirResultados(dados, puntaje, nombre);
        }

        puntajeTotal += maxPuntajeRonda;
        ronda++;
    }

    system("pause");
    system("CLS");
    cout << "ÁFelicidades, " << nombre << "! Has ganado con un puntaje de " << puntajeTotal << endl;


    if (puntajeTotal > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal;
        nombrePuntuacionMasAlta = nombre;
    }
}

void juegoDosJugadores() {
    string nombre1, nombre2;
    cout << "Ingrese el nombre del primer jugador: ";
    cin >> nombre1;
    cout << "Ingrese el nombre del segundo jugador: ";
    cin >> nombre2;

    system("pause");
    system("CLS");

    int puntajeTotal1 = 0, puntajeTotal2 = 0;
    int ronda = 1;
    int dados[6];
    srand(time(0)); // Inicializar la semilla para la funci—n rand

    while (puntajeTotal1 < 100 && puntajeTotal2 < 100) {
        // Turno del primer jugador

        cout <<"TURNO DE "<<nombre1<<"   | RONDA " << ronda<<"   | PUNTAJE TOTAL: "<<puntajeTotal1<<endl;
        cout <<"--------------------------------------------------------"<<endl;

        int maxPuntajeRonda1 = 0;

        for (int i = 0; i < 3; i++) {
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) {
                cout << "Escalera! " << nombre1 << " ha ganado la partida." << endl;
                return;
            }

            if (puntaje == -1) {
                puntajeTotal1 = 0;
                maxPuntajeRonda1 = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda1) {
                maxPuntajeRonda1 = puntaje;
            }

            imprimirResultados(dados, puntaje, nombre1);
        }
        system("pause");
        system("CLS");

        puntajeTotal1 += maxPuntajeRonda1;

        // Turno del segundo jugador
        cout <<"TURNO DE "<<nombre2<<"   | RONDA " << ronda<<"   | PUNTAJE TOTAL: "<<puntajeTotal2<<endl;
        cout <<"--------------------------------------------------------"<<endl;

        int maxPuntajeRonda2 = 0;

        for (int i = 0; i < 3; i++) {
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) {
                cout << "ÁEscalera! " << nombre2 << " ha ganado la partida." << endl;
                return;
            }

            if (puntaje == -1) {
                puntajeTotal2 = 0;
                maxPuntajeRonda2 = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda2) {
                maxPuntajeRonda2 = puntaje;
            }

            imprimirResultados(dados, puntaje, nombre2);
        }
        system("pause");
        system("CLS");

        puntajeTotal2 += maxPuntajeRonda2;
        ronda++;
    }

        if (puntajeTotal1 >= 100 && puntajeTotal2 >= 100) {
        if (puntajeTotal1 == puntajeTotal2) {
            cout << "ÁEmpate entre " << nombre1 << " y " << nombre2 << " con " << puntajeTotal1 << " puntos!" << endl;
        } else if (puntajeTotal1 > puntajeTotal2) {
            cout << "Á" << nombre1 << " ha ganado la partida con " << puntajeTotal1 << " puntos!" << endl;
        } else {
            cout << "Á" << nombre2 << " ha ganado la partida con " << puntajeTotal2 << " puntos!" << endl;
        }
    } else if (puntajeTotal1 >= 100) {
        cout << "Á" << nombre1 << " ha ganado la partida con " << puntajeTotal1 << " puntos!" << endl;
    } else {
        cout << "Á" << nombre2 << " ha ganado la partida con " << puntajeTotal2 << " puntos!" << endl;
    }

    if (puntajeTotal1 > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal1;
        nombrePuntuacionMasAlta = nombre1;
    }
    if (puntajeTotal2 > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal2;
        nombrePuntuacionMasAlta = nombre2;
    }
}

void mostrarPuntuacionMasAlta() {
    cout << "La puntuaci—n m‡s alta es de " << nombrePuntuacionMasAlta << " con " << puntuacionMasAlta << " puntos." << endl;
}



#endif // JUEGO_CPP_INCLUDED
