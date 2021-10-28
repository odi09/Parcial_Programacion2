/*
 * arcade.h
 *
 *  Created on: 18 oct. 2021
 *      Author: ojose
 */

#ifndef ARCADE_H_
#define ARCADE_H_
typedef struct
{
	char nacionadidad[128];
	int tipoSonido;
	char nombreJuego[63];
	int cantiJugadores;
	int cantiMaxFichas;
	int id;
	int idSala;
	int isEmpty; // // 1 Dando de alta, 0 dado de baja o Disponible
}eArcade;

int initArcade(eArcade arcade[], int largo);
int altaArcade(eArcade arcade[], char nacionalidad[], int tipoDeSonido, char nombreDelJuego[], int cantJugadores, int cantFichas, int idSala);
int modifcarArcade(eArcade arcade[], int largo, int idArcade, char nombreDelJuego[], int cantJugadores, int opcion);
int posicionLibreArcade(eArcade arcade[], int largo, int* auxPosicion);
int bajaArcade(eArcade arcade[], int largo, int id, char* pMensaje);
int buscarIdArcade(eArcade arcade[], int largo, int id);
int imprimirUnArcade(eArcade arcade[]);
int imprimirTodaslosArcade(eArcade arcade[], int largo);

int alta_FONZADA_Arcade(eArcade arcade[], char nacionalidad[], int tipoDeSonido, char nombreDelJuego[], int cantJugadores, int cantFichas, int idSala);

#endif /* ARCADE_H_ */
