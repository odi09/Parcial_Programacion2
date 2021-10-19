/*
 * salon.h
 *
 *  Created on: 17 oct. 2021
 *      Author: ojose
 */

#ifndef SALON_H_
#define SALON_H_
typedef struct
{
	char nombre[128];
	char direccion[128];
	int tipo;
	int id;
	int isEmpty; // // 1 Dando de alta, 0 dado de baja o Disponible
}eSalon;

int initSalon(eSalon salon[], int largo);
int alta(eSalon salon[], char nombre[], char direccion[], int tipo);
int posicionLibre(eSalon salon[], int largo, int* auxPosicion);
int baja(eSalon salon[], int largo, int id, char* pMensaje);
int buscarId(eSalon salon[], int largo, int id);
int imprimirUnSalon(eSalon salon[]);
int imprimirTodaslasSalas(eSalon salon[], int largo);
#endif /* SALON_H_ */
