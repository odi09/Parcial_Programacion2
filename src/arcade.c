/*
 * arcade.c
 *
 *  Created on: 18 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "arcade.h"
#define LEN_ARRAY_ARCADE 1000
static int generarId(void);

/**\brief Inicializa todas las posiciones colocando un 0 de ocupado.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int initArcade(eArcade arcade[], int largo)
{
	int retorno = 0;
	int i;
	if(arcade != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			arcade[i].isEmpty = 0;
		}
		retorno = 1;
	}

	return retorno;
}
/**\brief Busca un espacio libre.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param auxEspacio. La direccion de memoria de un espacio disponible.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int posicionLibreArcade(eArcade arcade[], int largo, int* auxPosicion)
{
	int retorno = 0;
	int i;
	if( arcade != NULL && auxPosicion != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			if(arcade[i].isEmpty == 0)
			{
				*auxPosicion = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
/**\brief Modifica los datos del un empleados.
 * param arcade[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param nacionalidad[]. La direccion de memoria de un array.
 * param tipoDeSonido[]. La direccion de memoria de un array.
 * param nombreDelJuego[]. La direccion de memoria de un array.
 * param cantJugadores. Recibe la cantidad de jugadores.
 * param cantFichas. Recibe la cantidad maxima de fichas.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int altaArcade(eArcade arcade[], char nacionalidad[], int tipoDeSonido, char nombreDelJuego[], int cantJugadores, int cantFichas, int idSala)
{
	int retorno = 0;

	if(arcade != NULL && nacionalidad != NULL && tipoDeSonido > 0 && nombreDelJuego != NULL && cantJugadores > 0 && cantFichas > 0 && idSala > 0)
	{
		strncpy(arcade->nacionadidad, nacionalidad, LEN_ARRAY_ARCADE);
		arcade->tipoSonido = tipoDeSonido;
		strncpy(arcade->nombreJuego, nombreDelJuego, LEN_ARRAY_ARCADE);
		arcade->id = generarId();
		arcade->idSala = idSala;
		arcade->isEmpty = 1;
		arcade->cantiJugadores = cantJugadores;
		arcade->cantiMaxFichas = cantFichas;
		retorno = 1;
	}
	return retorno;
}
/**\brief Modifica los datos del un arcade.
 * param arcade[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param nombreDelJuego[]. La direccion de memoria de un array.
 * param cantJugadores. Recibe la cantidad de jugadores.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int modifcarArcade(eArcade arcade[], int largo, int idArcade, char nombreDelJuego[], int cantJugadores, int opcion)
 {
	int retorno = 0;
	int posicionArcade;
	int i;

//	if (arcade != NULL && nombreDelJuego != NULL && cantJugadores > 0)
	{
		posicionArcade = buscarIdArcade(arcade, largo, idArcade);
		if(posicionArcade >= 0)
		{
			switch(opcion)
			{
			case 1:
				strncpy(arcade[posicionArcade].nombreJuego,nombreDelJuego,sizeof(arcade[posicionArcade].nombreJuego));
                for(i = 0; i < largo; i++)
                {
                	if(arcade[i].isEmpty == 1)
                	{
                		printf("- Nombre del Juego: %s -\n", arcade[i].nombreJuego);
                	}
                }
				break;
			case 2:
				arcade[posicionArcade].cantiJugadores = cantJugadores;
				break;
			}
			retorno = 1;
		}
	}
	return retorno;
 }
/**\brief Da de baja a un Arcade.
 * param arcade[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id es el id del empleado que se desea dar de baja.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int bajaArcade(eArcade arcade[], int largo, int id, char* pMensaje)
{
	int retorno = 0;
	int i;
	if(arcade != NULL && largo > 0 && id > 0 && buscarIdArcade(arcade, largo, id)>= 0 )
	{
		for(i = 0; i < largo; i++)
		{
			if(arcade[i].id == id && arcade[i].isEmpty == 1)
			{
				arcade[i].isEmpty = 0;
				printf("%s", pMensaje);
				retorno = 1;
				break;
			}
		}
	}
	else
	{
		printf("ID no encontrado.\n");
	}
	return 	retorno;
}
/**\brief Busca un id.
 * param arcade[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id. Es el id que desea buscar el usuario.
 * param Retorna la posicion del del id que se busca.
 */
int buscarIdArcade(eArcade arcade[], int largo, int id)
{
	int retorno = 0;
	int i;
	if(arcade != NULL && largo > 0 && id > 0)
	{
		for(i = 0; i < largo; i++)
		{
			if(arcade[i].isEmpty == 1 && arcade[i].id == id)
			{
				retorno = i;
				break;
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
/**\brief Muestra solo un Arcade dado de alta.
 * param arcade[]. La direccion de memoria de una posicion del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirUnArcade(eArcade arcade[])
{
	int retorno = 0;

	if (arcade != NULL)
	{
		printf("-Id Sala: %d - Nacionalidad del Arade: %s - Tipo de Sonido: %d - Nombre del Juego: %s - Cantidad de Jugadores: %d - Cantidad Maxima de Fichas: %d - Id: %d-\n\n"
				,arcade->idSala,arcade->nacionadidad, arcade->tipoSonido, arcade->nombreJuego, arcade->cantiJugadores, arcade->cantiMaxFichas, arcade->id);
		retorno = 1;
	}
	return retorno;
}
/**\brief Muestra todas los Arcade dados de alta.
 * param arcade[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirTodaslosArcade(eArcade arcade[], int largo)
{
	int retorno;
	int contador = 0;
	int i;
	if(arcade != NULL && largo > 0)
	{
		for(i=0;i<largo;i++)
		{
			contador++;
			if(arcade[i].isEmpty == 1)
			{
				printf("%d_Nacionalidad del Arade: %s - Tipo de Sonido: %d - Nombre del Juego: %s - Cantidad de Jugadores: %d - Cantidad Maxima de Fichas: %d - Id: %d\n\n"
						,contador, arcade[i].nacionadidad, arcade[i].tipoSonido, arcade[i].nombreJuego, arcade[i].cantiJugadores, arcade[i].cantiMaxFichas, arcade[i].id);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int alta_FONZADA_Arcade(eArcade arcade[], char nacionalidad[], int tipoDeSonido, char nombreDelJuego[], int cantJugadores, int cantFichas, int idSala)
{
	int retorno = 0;

	if(arcade != NULL && nacionalidad != NULL && tipoDeSonido > 0 && nombreDelJuego != NULL && cantJugadores > 0 && cantFichas > 0 && idSala > 0)
	{
		strncpy(arcade->nacionadidad, nacionalidad, LEN_ARRAY_ARCADE);
		arcade->tipoSonido = tipoDeSonido;
		strncpy(arcade->nombreJuego, nombreDelJuego, LEN_ARRAY_ARCADE);
		arcade->id = generarId();
		arcade->idSala = idSala;
		arcade->isEmpty = 1;
		arcade->cantiJugadores = cantJugadores;
		arcade->cantiMaxFichas = cantFichas;
		retorno = 1;
	}
	return retorno;
}

static int generarId(void)
{
	static int contador = 0001;
	return contador++;
}

