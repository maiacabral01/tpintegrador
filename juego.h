#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <string> // Incluye la biblioteca de la clase string

// Declaraciones de las funciones
void juegoUnJugador(int& puntuacionMasAlta, std::string& nombrePuntuacionMasAlta);
void juegoDosJugadores(int& puntuacionMasAlta, std::string& nombrePuntuacionMasAlta);
void mostrarPuntuacionMasAlta(int puntuacionMasAlta, const std::string& nombrePuntuacionMasAlta);
void tirarDados(int dados[]);
int calcularPuntaje(int dados[]);
bool escalera(int dados[]);
void imprimirResultados(int dados[], int puntaje, const std::string& nombre);

#endif // JUEGO_H_INCLUDED
