/*
 ============================================================================
 Name        : Parcial.c
 Author      : Odi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "utn.h"
#include "salon.h"
#include "arcade.h"
#define LARGO_ARRAY_SALON 100
#define LARGO_ARRAY_ARCADE 1000

int main(void) {
	setbuf(stdout, NULL);

eSalon arraySalon[LARGO_ARRAY_SALON];
eArcade arrayAcarde[LARGO_ARRAY_ARCADE];
int opcion;
int opcionArcadea;
char nombreSala[128];
char direccionSala[128];
char naciJuego[128];
int sonidoArcade;
char nombreJuego[128];
int cantidadJug;
int cantidadMaxFichas;
int tipoSala;
int posicionSalon;
int posicionArcade;
int id;

    initSalon(arraySalon, LARGO_ARRAY_SALON);
	do
	{
		pedirEntero(&opcion, 0, 9, 3,"Ingrese una opcion:\n1.Dar el alta de una Sala.\n2.Dar de baja una Sala.\n3.Imprimir las Salas dadas de Alta."
				                     "\n4.Dar el alta de un Arcade.\n5.Modificar Arcade.\n6.Eliminar Arcade.\n7.Imprimir Arcade.\n8.Imprimir Juegos.\n9.Informes.\n"
				                     "0.Salir","ERROR ingrese una opcion validad.");
		switch (opcion)
			{
			case 1:
				pedirCadenaDeSoloLetras(nombreSala, sizeof(nombreSala), 3, "Ingrese nombre de la Sala: ", "ERROR ingrese un nombre validad.");
				pedirDireccion(direccionSala, sizeof(direccionSala), 3, "Ingrese Direccion: ", "ERROR ingrese una direccion validad.");
				pedirEntero(&tipoSala, 1, 2, 3, "Ingrese tipo de Sala.\n1.SHOPPING\n2.LOCAL: \n", "ERROR ingrese un tipo validad.");
				posicionLibre(arraySalon, LARGO_ARRAY_SALON, &posicionSalon);
				alta(&arraySalon[posicionSalon], nombreSala, direccionSala, tipoSala);
				imprimirUnSalon(&arraySalon[posicionSalon]);
				break;
			case 2:
				imprimirTodaslasSalas(arraySalon, LARGO_ARRAY_SALON);
				pedirEntero(&id, 0, 100, 3, "Ingrese Id a dar de baja: \n", "ERROR ingrese un Id valido");
				baja(arraySalon, LARGO_ARRAY_SALON, id, "Id de la Sala esta dato dado de Baja.\n\n");
				break;
			case 3:
				imprimirTodaslasSalas(arraySalon, LARGO_ARRAY_SALON);
				break;
			case 4:
				pedirCadenaDeSoloLetras(naciJuego, sizeof(naciJuego), 3, "Ingrese Nacionalidad del Arcade: ", "ERROR ingrese nacionalidda valida");
				pedirEntero(&sonidoArcade,1,2, 3, "Ingrese tipo de Sonido.\n1.MONO\n2.ESTEREO.\n", "ERROR ingrese tipo de sonido valida");
				pedirDireccion(nombreJuego, sizeof(nombreJuego), 3, "Ingrese Nombre del Juego: ", "ERROR ingrese nombre valida");
				pedirEntero(&cantidadJug, 0, 10, 3, "Ingrese Cantidad de jugadores: ", "ERROR ingrese cantidad valida del 0 - 10");
				pedirEntero(&cantidadMaxFichas, 0, 100, 3, "Ingrese Cantidad Maxima de fichas: ", "ERROR ingrese cantida valida del 0 - 100");
				posicionLibreArcade(arrayAcarde, LARGO_ARRAY_ARCADE, &posicionArcade);
				altaArcade(&arrayAcarde[posicionArcade], naciJuego, sonidoArcade, nombreJuego, cantidadJug, cantidadMaxFichas);
				imprimirUnArcade(&arrayAcarde[posicionArcade]);
				break;
			case 5:
				imprimirTodaslosArcade(arrayAcarde, LARGO_ARRAY_ARCADE);
				pedirEntero(&id, 0, 1000, 3, "Ingrese Id a modificar: ", "ERROR ingrese un valor valido.");
				pedirEntero(&opcionArcadea, 1, 2, 3, "1.Modificar Nombre del Juego.\n2.Modificar Cantidad de jugadores.\n", "ERROR ingrese un valor valido.");
				if(opcionArcadea == 1)
				{
					pedirDireccion(nombreJuego, sizeof(nombreJuego), 3, "Ingrese Nombre del Juego: ", "ERROR ingrese nombre valida");
				}
				else if(opcionArcadea == 2)
	        	{
					pedirEntero(&cantidadJug, 0, 10, 3, "Ingrese Cantidad de jugadores: ", "ERROR ingrese cantidad valida del 0 - 10");
		        }
				modifcarArcade(arrayAcarde, LARGO_ARRAY_ARCADE, id, nombreJuego, cantidadJug, opcionArcadea);
				break;
			case 6:
				pedirEntero(&opcion, 1,2, 3, "¿Esta seguro de Dar la Baja?\n1.Si.\n2.No.\n ", "ERROR ingrese una opcion valida");
				if(opcion == 1)
				{
					pedirEntero(&id, 0, 1000, 3, "Ingrese Id a Dar de Baja: ", "ERROR ingrese un valor valido.");
					bajaArcade(arrayAcarde, LARGO_ARRAY_ARCADE, id,"**Id de la Sala esta dato dado de Baja.**\n\n");
				}
				break;
			case 7:
				imprimirTodaslosArcade(arrayAcarde, LARGO_ARRAY_ARCADE);
				break;
			case 8:
				break;
			case 9:
				break;
			}

	}while(opcion != 0);


 	return EXIT_SUCCESS;
}
