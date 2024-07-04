#include "juego.h" // Incluye la cabecera del archivo de juego
#include <iostream> // Incluye la biblioteca de entrada y salida estándar
#include <cstdlib> // Incluye la biblioteca de funciones generales de propósito
#include <ctime> // Incluye la biblioteca de funciones relacionadas con el tiempo
#include <algorithm> // Incluye la biblioteca de algoritmos

using namespace std; // Permite el uso del espacio de nombres estándar

// Función que simula tirar los dados
void tirarDados(int dados[]) {
    for (int i = 0; i < 6; i++) {
        dados[i] = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6 para cada dado
    }
}

// Función que calcula el puntaje basado en los resultados de los dados
int calcularPuntaje(int dados[]) {
    int conteo[7] = {0}; // Array para contar la frecuencia de cada valor de dado (1-6)
    for (int i = 0; i < 6; i++) {
        conteo[dados[i]]++; // Incrementa el contador correspondiente al valor del dado
    }

    // Verifica si hay una escalera (1, 2, 3, 4, 5, 6)
    if (escalera(dados)) {
        return 1000; // Un puntaje alto que indica que el jugador ganó con una escalera
    }

    // Verifica si hay un sexteto de 6
    if (conteo[6] == 6) {
        return -1; // Indica que el puntaje se debe resetear a 0
    }

    // Verifica si hay un sexteto de otro número
    for (int i = 1; i <= 5; i++) {
        if (conteo[i] == 6) {
            return i * 10; // Calcula el puntaje basado en el número del sexteto
        }
    }

    // Suma todos los dados si no se cumple ninguna condición especial
    int puntaje = 0;
    for (int i = 1; i <= 6; i++) {
        puntaje += conteo[i] * i;
    }

    return puntaje; // Devuelve el puntaje calculado
}

// Función que verifica si los dados forman una escalera
bool escalera(int dados[]) {
    for (int x=0;x<6;x++){ //damos 6 vueltas para garantizar el orden definitivo.
        for (int i=0;i<5;i++){// 5 vueltas para comparar elementos entre si...
            if (dados[i]>dados[i+1]){//...y ordenamos de forma creciente
                int aux=dados[i+1]; //usamos una variable auxiliar para preservar dados[i+1]
                dados[i+1]=dados[i];
                dados[i]=aux;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        if (dados[i] != i + 1) {
            return false;// Si algún dado no coincide con el valor esperado, no es una escalera
        }
    }
    return true;// Si todos los valores coinciden, es una escalera
}


// Función que imprime los resultados de los dados y el puntaje
void imprimirResultados(int dados[], int puntaje, const string& nombre) {
    cout << "Dados: ";
    for (int i = 0; i < 6; i++) {
        cout << dados[i] << " "; // Imprime los valores de los dados
    }
    cout << endl << endl;
    cout << "Combinacion: ";
    if (escalera(dados)) {
        cout << "Escalera" << endl; // Indica que se obtuvo una escalera
    } else if (puntaje == -1) {
        cout << "Sexteto de 6 - Puntaje reseteado" << endl; // Indica que se obtuvo un sexteto de 6
    } else {
        cout << "Suma de dados" << endl; // Indica que el puntaje se basa en la suma de los dados
    }
    cout << "Puntaje: " << puntaje << endl << endl; // Imprime el puntaje obtenido
}

// Función para el juego de un jugador
void juegoUnJugador(int& puntuacionMasAlta, string& nombrePuntuacionMasAlta) {
    string nombre; // Variable para el nombre del jugador
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre; // Lee el nombre del jugador

    int puntajeTotal = 0; // Puntaje total del jugador
    int ronda = 1; // Número de ronda
    int dados[6]; // Array para almacenar los valores de los dados
    srand(time(0)); // Inicializa la semilla para la función rand

    while (puntajeTotal < 100) { // Continua jugando hasta que el puntaje total sea al menos 100
        cout << "--------RONDA " << ronda << "--------" << endl << endl;
        cout << "Puntaje actual: " << puntajeTotal << endl;
        int maxPuntajeRonda = 0; // Puntaje máximo de la ronda

        for (int i = 0; i < 3; i++) { // El jugador tira los dados 3 veces en cada ronda
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) { // Si se obtiene una escalera
                cout << "Escalera! " << nombre << " ha ganado la partida." << endl;
                return; // Termina el juego
            }

            if (puntaje == -1) { // Si se obtiene un sexteto de 6
                puntajeTotal = 0; // Resetea el puntaje total
                maxPuntajeRonda = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda) {
                maxPuntajeRonda = puntaje; // Actualiza el puntaje máximo de la ronda
            }

            cout << endl;
            imprimirResultados(dados, puntaje, nombre); // Imprime los resultados de los dados
        }

        puntajeTotal += maxPuntajeRonda; // Actualiza el puntaje total del jugador
        ronda++; // Incrementa el número de ronda
    }

    cout << "Felicidades, " << nombre << "! Has ganado con un puntaje de " << puntajeTotal << endl;

    // Actualiza la puntuación más alta si el jugador ha obtenido una puntuación mayor
    if (puntajeTotal > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal;
        nombrePuntuacionMasAlta = nombre;
    }
}

// Función para el juego de dos jugadores
void juegoDosJugadores(int& puntuacionMasAlta, string& nombrePuntuacionMasAlta) {
    string nombre1, nombre2; // Variables para los nombres de los jugadores
    cout << "Ingrese el nombre del primer jugador: ";
    cin >> nombre1;
    cout << "Ingrese el nombre del segundo jugador: ";
    cin >> nombre2;

    int puntajeTotal1 = 0, puntajeTotal2 = 0; // Puntajes totales de los jugadores
    int ronda = 1; // Número de ronda
    int dados[6]; // Array para almacenar los valores de los dados
    srand(time(0)); // Inicializa la semilla para la función rand

    while (puntajeTotal1 < 100 && puntajeTotal2 < 100) { // Continua jugando hasta que uno de los jugadores obtenga al menos 100 puntos
        // Turno del primer jugador
        cout << "TURNO DE " << nombre1 << " | RONDA " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal1 << endl;
        cout << "--------------------------------------------------------" << endl;
        int maxPuntajeRonda1 = 0; // Puntaje máximo de la ronda para el primer jugador

        for (int i = 0; i < 3; i++) { // El jugador tira los dados 3 veces en cada ronda
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) { // Si se obtiene una escalera
                cout << "Escalera! " << nombre1 << " ha ganado la partida." << endl;
                return; // Termina el juego
            }

            if (puntaje == -1) { // Si se obtiene un sexteto de 6
                puntajeTotal1 = 0; // Resetea el puntaje total del primer jugador
                maxPuntajeRonda1 = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda1) {
                maxPuntajeRonda1 = puntaje; // Actualiza el puntaje máximo de la ronda
            }

            imprimirResultados(dados, puntaje, nombre1); // Imprime los resultados de los dados
        }

        cout << "--------------------------------------------------------" << endl;
        cout << "Maximo Puntaje de la Ronda: " << maxPuntajeRonda1 << endl;

        puntajeTotal1 += maxPuntajeRonda1; // Actualiza el puntaje total del primer jugador

        // Turno del segundo jugador
        cout << "TURNO DE " << nombre2 << " | RONDA " << ronda << " | PUNTAJE TOTAL: " << puntajeTotal2 << endl;
        cout << "--------------------------------------------------------" << endl;
        int maxPuntajeRonda2 = 0; // Puntaje máximo de la ronda para el segundo jugador

        for (int i = 0; i < 3; i++) { // El jugador tira los dados 3 veces en cada ronda
            tirarDados(dados);
            int puntaje = calcularPuntaje(dados);

            if (puntaje == 1000) { // Si se obtiene una escalera
                cout << "Escalera! " << nombre2 << " ha ganado la partida." << endl;
                return; // Termina el juego
            }

            if (puntaje == -1) { // Si se obtiene un sexteto de 6
                puntajeTotal2 = 0; // Resetea el puntaje total del segundo jugador
                maxPuntajeRonda2 = 0;
                cout << "Sexteto de 6 - Puntaje reseteado a 0" << endl;
                break;
            }

            if (puntaje > maxPuntajeRonda2) {
                maxPuntajeRonda2 = puntaje; // Actualiza el puntaje máximo de la ronda
            }

            imprimirResultados(dados, puntaje, nombre2); // Imprime los resultados de los dados
        }

        cout << "--------------------------------------------------------" << endl;
        cout << "Maximo Puntaje de la Ronda: " << maxPuntajeRonda2 << endl;

        puntajeTotal2 += maxPuntajeRonda2; // Actualiza el puntaje total del segundo jugador
        ronda++; // Incrementa el número de ronda
    }

    // Determina el ganador del juego
    if (puntajeTotal1 >= 100 && puntajeTotal2 >= 100) {
        if (puntajeTotal1 == puntajeTotal2) {
            cout << "Empate entre " << nombre1 << " y " << nombre2 << " con " << puntajeTotal1 << " puntos!" << endl;
        } else if (puntajeTotal1 > puntajeTotal2) {
            cout << nombre1 << " ha ganado la partida con " << puntajeTotal1 << " puntos!" << endl;
        } else {
            cout << nombre2 << " ha ganado la partida con " << puntajeTotal2 << " puntos!" << endl;
        }
    } else if (puntajeTotal1 >= 100) {
        cout << nombre1 << " ha ganado la partida con " << puntajeTotal1 << " puntos!" << endl;
    } else {
        cout << nombre2 << " ha ganado la partida con " << puntajeTotal2 << " puntos!" << endl;
    }

    // Actualiza la puntuación más alta si alguno de los jugadores ha obtenido una puntuación mayor
    if (puntajeTotal1 > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal1;
        nombrePuntuacionMasAlta = nombre1;
    }
    if (puntajeTotal2 > puntuacionMasAlta) {
        puntuacionMasAlta = puntajeTotal2;
        nombrePuntuacionMasAlta = nombre2;
    }
}

// Función que muestra la puntuación más alta
void mostrarPuntuacionMasAlta(int puntuacionMasAlta, const string& nombrePuntuacionMasAlta) {
    cout << "La puntuacion mas alta es de " << nombrePuntuacionMasAlta << " con " << puntuacionMasAlta << " puntos." << endl;
}

