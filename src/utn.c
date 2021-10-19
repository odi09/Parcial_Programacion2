/*
 * char.c
 *
 *  Created on: 7 sep. 2021
 *      Author: ojose
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
//#include "calculadora.h"

static int getInt(int *pResultado);
static int esNumero(char cadena[]);
static float getFloat(float *pResultado);
static float esNumeroConComa(char cadena[]);
static char getChar(char Resultado[], int tamano);
static char getSoloChar(char Resultado[], int tamano);
static char getEsCaracterNumerico(char Resultado[], int tamano);
static char esCaracter(char cadena[]);
static char esSoloCaracter(char cadena[]);
static char esCaracterNumerico(char cadena[]);
static int myGets(char cadena[], int longitud);

/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1
 *
 */
static int myGets(char cadena[], int longitud) {
	int retorno = -1;
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumero(buffer) == 0) {
			retorno = 0;
			*pResultado = atoi(buffer);

		}
	}
	return retorno;
}
/**
 *\brief  Valida que la cadena que recibe sea un numero entero.
 *\param  char cadena[] la variable que se recibe para analizar
 *\return 0 si salio todo BIEN, si no devuelve un 1.
 *
 */
static int esNumero(char cadena[]) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		if (cadena[0] == '-') {
			i = 1;
		}
		for (; cadena[i] != '\0'; i++) {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1
 *
 */
static float getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esNumeroConComa(buffer) == 0) {
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;
}
/**
 *\brief Valida que la cadena que recibe sea un numero decimal.
 *\param char cadena[] la variable que se recibe para analizar
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static float esNumeroConComa(char cadena[]) {
	int i = 0;
	int retorno = -1;
	int punto = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		if (cadena[0] == '-') {
			i = 1;
		}
		for (; cadena[i] != '\0'; i++) {

			if (punto == 0 && cadena[i] == '.') {
				punto = 1;
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 1;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static char getChar(char Resultado[], int tamano) {
	int retorno = -1;
	char buffer[100];

	if (Resultado != NULL && tamano > 0) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esCaracter(buffer) == 0) {
			retorno = 0;
			strncpy(Resultado, buffer, tamano);
		}
	}
	return retorno;
}
/**
 *\brief Valida que la cadena que recibe sea un String.
 *\param char cadena[] la variable que se recibe para analizar.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static char esCaracter(char cadena[]) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		for (i = 0;/*strlen(cadena) > i &&*/cadena[i] != '\0'; i++) {
			if ((cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] != ' ') && (cadena[i] != '-')
					&& (cadena[i] < '0' || cadena[i] > '9')) {
				retorno = 1;
				break;
			}
			i++;
		}

	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static char getEsCaracterNumerico(char Resultado[], int tamano) {
	int retorno = -1;
	char buffer[100];

	if (Resultado != NULL && tamano > 0) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esCaracterNumerico(buffer) == 0) {
			retorno = 0;
			strncpy(Resultado, buffer, tamano);
		}
	}
	return retorno;
}
/**
 *\brief Valida que la cadena que recibe sea un String.
 *\param char cadena[] la variable que se recibe para analizar.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static char esCaracterNumerico(char cadena[]) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		for (i = 0;/*strlen(cadena) > i &&*/cadena[i] != '\0'; i++) {
			if ((cadena[i] != ' ') && (cadena[i] != '-')
					&& (cadena[i] < '0' || cadena[i] > '9')) {
				retorno = 1;
				break;
			}
			i++;
		}

	}
	return retorno;
}
/**
 *\brief
 *\param
 *\return 0 si salio todo BIEN, si no devuelve un -1.
 *
 */
static char getSoloChar(char Resultado[], int tamano) {
	int retorno = -1;
	char buffer[100];

	if (Resultado != NULL && tamano > 0) {
		if (myGets(buffer, sizeof(buffer)) == 0
				&& esSoloCaracter(buffer) == 0) {
			retorno = 0;
			strncpy(Resultado, buffer, tamano);
		}
	}
	return retorno;
}

/**
 *\brief Valida que la cadena que recibe sea un String.
 *\param char cadena[] la variable que se recibe para analizar.
 *\return Un 0 si salio todo bien, si no devuelve un 1.
 *
 */
static char esSoloCaracter(char cadena[]) {
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0) {
		retorno = 0;
		for (i = 0;/*strlen(cadena) > i &&*/cadena[i] != '\0'; i++) {
			if ((cadena[i] < 'a' || cadena[i] > 'z')
					&& (cadena[i] < 'A' || cadena[i] > 'Z')
					&& (cadena[i] != ' ')) {
				retorno = 1;
				//printf("INGRESE AL ERROR DE esCaracter\n");
				break;
			}
			i++;
			//printf("INGRESO AL FOR DE ESCARACTER\n");
		}

	}
	return retorno;
}
/**
 *\brief Recibe una cadena y valida que sea una Direccion y lo devuelve.
 *\param Char[] recibe la direccion de memoria de un array de caracteres.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 */
char pedirDireccion(char Char[], int tamano, int reintento, char *pTexto, char *pTextoError)
{
	int auxRetorno = -1;
	int retorno;
	char auxChar[100];

	if (Char != NULL && reintento >= 0 && pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getChar(auxChar, sizeof(auxChar)) == 0)
			{
				strncpy(Char, auxChar, tamano);
				auxRetorno = 1;
				break;
			}
			else
			{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
			}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe la direccion de memoria de una array de caracteres y valida que tenga solo caracteres Numericos y lo devuelve.
 *\param Char[] recibe la direccion de memoria de un array de caracteres.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 */
char pedirCuit(char Char[], int tamano, int reintento,char *pTexto, char *pTextoError)
{
	int auxRetorno = -1;
	int retorno;
	char auxChar[100];

	if (Char != NULL && reintento >= 0 && pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getEsCaracterNumerico(auxChar, sizeof(auxChar)) == 0)
			{
				strncpy(Char, auxChar, tamano);
				auxRetorno = 1;
				break;
			}
			else
			{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
			}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe la direccion de memoria de una array de caracteres y valida que tenga solo Letras y lo devuelve.
 *\param Char[] recibe la direccion de memoria de un array de caracteres.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 */
char pedirCadenaDeSoloLetras(char Char[], int tamano, int reintento,char *pTexto, char *pTextoError)
{
	int auxRetorno = -1;
	int retorno;
	char auxChar[100];

	if (Char != NULL && reintento >= 0 && pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getSoloChar(auxChar, sizeof(auxChar)) == 0)
			{
				strncpy(Char, auxChar, tamano);
				auxRetorno = 1;
				break;
			}
			else
			{
				printf("%s\n", pTextoError);
				reintento--;
				auxRetorno = 0;
			}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe un numero y valida que sea Entero y lo devuelve.
 *\param pInt recibe el puntero de un entero.
 *\param min numero minimo que puede recibir la funcion.
 *\param max numero maximo que puede recibir la fucion.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 *
 */
int pedirEntero(int *pInt, int min, int max, int reintento, char *pTexto,char *pTextoError)
{
	int auxRetorno;
	int retorno;
	int auxInt;

	if (pInt != NULL && min	< max&& reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);
			fflush(stdin);
			if (getInt(&auxInt) == 0)
			{
				if (auxInt >= min && auxInt <= max)
				{
					*pInt = auxInt;
					auxRetorno = 1;
					break;
				}
				else
				{
					printf("%s\n", pTextoError);
					reintento--;
					auxRetorno = 0;
				}
				fflush(stdin);
			}

			fflush(stdin);
		}
	}

	retorno = auxRetorno;
	return retorno;
}
/**
 *\brief Recibe un numero y valida que sea Decimal y lo devuelve.
 *\param pFloat recibe el puntero de un decimal.
 *\param min numero minimo que puede recibir la funcion.
 *\param max numero maximo que puede recibir la fucion.
 *\param reintento recibe la cantidad de veces que se puede reintentar.
 *\param pTexto recibe la direccion de memoria de un mensaje.
 *\param pTextoError recibe la direccion de memoria del mensaje de error.
 *\return 1 si salio todo BIEN, si no devuelve 0.
 *
 */
float pedirFlotante(float *pFloat, int min, int max, int reintento,char *pTexto, char *pTextoError)
{
	int auxRetorno;
	int retorno;
	float auxFloat;

	if (pFloat != NULL && min < max&& reintento>=0 && pTexto != NULL && pTextoError != NULL)
	{
		for (int i = 0; i < reintento; i++)
		{
			printf("%s", pTexto);

			if (getFloat(&auxFloat) == 0)
			{
				if (auxFloat >= min && auxFloat <= max)
				{
					*pFloat = auxFloat;
					auxRetorno = 1;
					break;
				}
				else
				{
					printf("%s\n", pTextoError);
					reintento--;
					auxRetorno = 0;
				}
			}
			fflush(stdin);
		}

	}
	retorno = auxRetorno;
	return retorno;
}
