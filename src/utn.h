/*
 * utn.h
 *
 *  Created on: 25 sep. 2021
 *      Author: ojose
 */

#ifndef UTN_H_
#define UTN_H_

char pedirDireccion(char Char[], int tamano, int reintento, char *pTexto,char *pTextoError);
char pedirCuit(char Char[], int tamano, int reintento, char *pTexto,char *pTextoError);
char pedirCadenaDeSoloLetras(char Char[], int tamano, int reintento,char *pTexto, char *pTextoError);
int pedirEntero(int *pInt, int min, int max, int reintento, char *pTexto,char *pTextoError);
float pedirFlotante(float *pFloat, int min, int max, int reintento,char *pTexto, char *pTextoError);

#endif /* UTN_H_ */
