/*
 * informe.c
 *
 *  Created on: 19 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "salon.h"
#include "arcade.h"
#include "informe.h"
/*
int listarArcadeMaxJuag(eSalon sala[], int largoSala , eArcade arcade[], int largoArcade)
{
	int retorno = 0;
	int indexSala;
	int cotadorArcade = 0;
	int i;

	for(i = 0; i < largoSala; i++)
	{
		printf("uno\n");
		if(sala[i].isEmpty == 1)
		{
			printf("dos\n");
			indexSala = sala[i].id;
			for(i = 0; i < largoArcade; i++)
			{
				if(arcade[i].idSala == indexSala)
				{
					printf("cuatro\n");
					cotadorArcade++;
				}
			}
		}
	}
	retorno = cotadorArcade;

	return retorno;
}*/
/**\brief Inicializa todas las posiciones colocando un 0 de ocupado.
 * param juego[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int iniJuego(eJuego juego[], int largo)
{
	int retorno = 0;
	int i;
	if(juego != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			juego[i].isEmpty = 0;
		}
		retorno = 1;
	}
	return retorno;
}
/**\brief Recibe una cadena y valida que exita, si la encuentra devuelve un 1.
 * param juego[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param juegoRec[]. recibe una cadena de caracteres.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int juego_estaJuegoLista(eJuego juego[], int largo, char juegoRec [])
{
	int retorno = 0;
	int i;

	if (juego != NULL && juegoRec != NULL && largo > 0)
	{
		for (i = 0; i < largo; i++)
		{
			if (juego[i].isEmpty == 1 && strcmp(juego[i].juego, juegoRec) == 0)
			{

				retorno = 1;
				break;
			}

		}
	}

	return retorno;
}
/**\brief Recibe una cadena y valida que exita, si la encuentra devuelve un 1.
 * param juego[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param juegoRec[]. recibe una cadena de caracteres.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int generarListaJuegos(eArcade juego[], int largoJuego, eJuego listaJuego[], int largoListaJuego)
{
	int i;
	int indiceListaJuegos = 0;
	int retorno = 0;

	//iniJuego(listaJuego, largoListaJuego);

		if (juego != NULL && largoJuego > 0 &&  listaJuego != NULL && largoListaJuego >0 )
			{
				for (i = 0; i < largoJuego; i++)
				{
					if(listaJuego[i].isEmpty == 0)
					{
						if(juego_estaJuegoLista(listaJuego, largoListaJuego, juego[i].nombreJuego) == 0)
						{
							strncpy(listaJuego[indiceListaJuegos].juego, juego[i].nombreJuego, 63);
							printf("Imprimir %s\n", listaJuego[indiceListaJuegos].juego);
							listaJuego[i].isEmpty = 1;
							indiceListaJuegos++;
							retorno = 1;
						}
					}
				}
			}
	return retorno;
}
/**\brief Recibe una cadena y valida que exita, si la encuentra devuelve un 1.
 * param juego[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param juegoRec[]. recibe una cadena de caracteres.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int listarSalonesConMasArcade(eArcade juegos[], int largoJuegos, eSalon salas[], int largoSalas)
{
	int retorno;
	int contador = 0;
	int i;
	int j;

	if(juegos != NULL && largoJuegos > 0 && salas != NULL && largoSalas > 0)
	{
		for(i = 0; i < largoSalas; i++)
		{
			if(salas[i].isEmpty == 1)
			{
				for(j = 0; j < largoJuegos; j++)
				{
					if(salas[i].id == juegos[j].idSala)
					{
						contador++;
						if (contador > 4)
						{
							imprimirUnSalon(&salas[i]);
							contador = 0;
							retorno = 1;
							break;
						}
					}
				}
			}
		}
	}
	return retorno;
}
int listarArcadeConMasJugadores(eArcade juegos[], int largoJuegos, eSalon salas[], int largoSalas)
{
	int retorno = 0;
	int i;
	int j;

	if(juegos != NULL && largoJuegos > 0 && salas != NULL && largoSalas > 0)
	{
		for(i = 0; i < largoJuegos; i++)
		{
			if(juegos[i].isEmpty == 1 && juegos[i].cantiJugadores > 2)
			{
				imprimirUnArcade(&juegos[i]);
				for(j = 0; j < largoSalas; j++)
				{
					if(salas[j].id == juegos[i].idSala)
					{
						printf("Nombre de la Sala: %s\n", salas[j].nombre);
						retorno = 1;
						break;
					}
				}
			}
		}
	}

	return retorno;
}
