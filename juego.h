#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <string>

void juegoUnJugador();
void juegoDosJugadores();
void mostrarPuntuacionMasAlta();
void tirarDados(int dados[]);
int calcularPuntaje(int dados[]);
bool escalera(int dados[]);
void imprimirResultados(int dados[], int puntaje, const std::string& nombre);

#endif // JUEGO_H_INCLUDED
