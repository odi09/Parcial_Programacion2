/*
 * informe.h
 *
 *  Created on: 19 oct. 2021
 *      Author: ojose
 */

#ifndef INFORME_H_
#define INFORME_H_
typedef struct
{
char juego[63];
int isEmpty; // // 1 OCUPADO O Dado de alta. 0 dado de baja o Disponible
}eJuego;

int iniJuego(eJuego juego[], int largo);
int juego_estaJuegoLista(eJuego juego[], int largo, char juegoRec []);
int generarListaJuegos(eArcade juego[], int largoJuego, eJuego listaJuego[], int largoListaJuego);
int listarSalonesConMasArcade(eArcade juegos[], int largoJuegos, eSalon salas[], int largoSalas);
int listarArcadeConMasJugadores(eArcade juegos[], int largoJuegos, eSalon salas[], int largoSalas);

#endif /* INFORME_H_ */
