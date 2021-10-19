/*
 * salon.c
 *
 *  Created on: 17 oct. 2021
 *      Author: ojose
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "salon.h"
static int generarId(void);

/**\brief Inicializa todas las posiciones colocando un 0 de ocupado.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int initSalon(eSalon salon[], int largo)
{
	int retorno = 0;
	int i;
	if(salon != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			salon[i].isEmpty = 0;
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
int posicionLibre(eSalon salon[], int largo, int* auxPosicion)
{
	int retorno = 0;
	int i;
	if( salon != NULL && auxPosicion != NULL && largo > 0)
	{
		for(i = 0; i < largo; i++)
		{
			if(salon[i].isEmpty == 0)
			{
				*auxPosicion = i;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
/**\brief Pide al usuario cargar los datos.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param auxNombre[]. La direccion de memoria de un array.
 * param auxDireccion[]. La direccion de memoria de un array.
 * param auxTipo. Recibe el tipo de sala.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int alta(eSalon salon[], char nombre[], char direccion[], int tipo)
{
	int retorno = 0;

	if(salon != NULL && nombre != NULL && direccion != NULL && tipo > 0 )
	{
		salon->id = generarId();
		salon->isEmpty = 1;
		salon->tipo = tipo;
		strncpy(salon->nombre, nombre, sizeof(salon->nombre));
		strncpy(salon->direccion, direccion, sizeof(salon->direccion));
		retorno = 1;
	}
	return retorno;
}
/**\brief Da de baja a una sala.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id es el id del empleado que se desea dar de baja.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int baja(eSalon salon[], int largo, int id, char* pMensaje)
{
	int retorno = 0;
	int i;
	if(salon != NULL && largo > 0 && id > 0 && buscarId(salon, largo, id)>= 0 )
	{
		for(i = 0; i < largo; i++)
		{
			if(salon[i].id == id && salon[i].isEmpty == 1)
			{
				salon[i].isEmpty = 0;
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
 * param salon[]. La direccion de memoria de un array.
 * param largo. Largo del array.
 * param id. Es el id que desea buscar el usuario.
 * param Retorna la posicion del del id que se busca.
 */
int buscarId(eSalon salon[], int largo, int id)
{
	int retorno = 0;
	int i;
	if(salon != NULL && largo > 0 && id > 0)
	{
		for(i = 0; i < largo; i++)
		{
			if(salon[i].isEmpty == 1 && salon[i].id == id)
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
/**\brief Muestra solo una sala dado de alta.
 * param salon[]. La direccion de memoria de una posicion del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirUnSalon(eSalon salon[])
{
	int retorno = 0;

	if (salon != NULL)
	{
		printf("-Nombre: %s - Direccion: %s - Tipo de Sala: %d - Id: %d\n\n",
				salon->nombre, salon->direccion, salon->tipo, salon->id);
		retorno = 1;
	}
	return retorno;
}
/**\brief Muestra todas las sala dado de alta.
 * param salon[]. La direccion de memoria de un array.
 * param largo. Tamaño del array.
 * param Retorna 1 si sale todo bien o 0 si no.
 */
int imprimirTodaslasSalas(eSalon salon[], int largo)
{
	int retorno;
	int contador = 0;
	int i;
	if(salon != NULL && largo > 0)
	{
		for(i=0;i<largo;i++)
		{
			contador++;
			if(salon[i].isEmpty == 1)
			{
				printf("%d_Nombre de la Sala: %s - Direccion: %s - Tipo de Sala: %d - Id: %d\n"
						,contador, salon[i].nombre, salon[i].direccion, salon[i].tipo, salon[i].id);
				retorno = 1;
			}
		}
	}
	return retorno;
}

static int generarId(void)
{
	static int contador = 1;
	return contador++;
}
