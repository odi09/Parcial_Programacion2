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
#include "informe.h"
#define LARGO_ARRAY_SALON 100
#define LARGO_ARRAY_ARCADE 1000


int main(void) {
	setbuf(stdout, NULL);

eSalon arraySalon[LARGO_ARRAY_SALON];
eArcade arrayAcarde[LARGO_ARRAY_ARCADE];
eJuego juegoLista[LARGO_ARRAY_ARCADE];
int opcion;
int opcionArcadea;
int subMenu;
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
int idSala;
//int prueba;

    initSalon(arraySalon, LARGO_ARRAY_SALON);

    alta_forzada(&arraySalon[0], "FLORESTA","NAZCA 1000", 2);
    alta_forzada(&arraySalon[1], "ALMAGRO","CORRIENTE 1100", 1);
    alta_forzada(&arraySalon[2], "PALERMO"," HONDURA 2000", 2);
    alta_forzada(&arraySalon[3], "FLORES","RIVADAVIA 2100", 1);
    alta_forzada(&arraySalon[4], "SAN CRISTOBAL","SAN JUAN 3000", 2);
    alta_forzada(&arraySalon[5], "CONSTITUCION","SAN JUAN 3100", 1);

    alta_FONZADA_Arcade(&arrayAcarde[0], "EEUU", 1, "MARIO", 10, 100, 3);
    alta_FONZADA_Arcade(&arrayAcarde[1], "MEXICO", 1, "TACO", 1, 100, 2);
    alta_FONZADA_Arcade(&arrayAcarde[2], "ARGENTINA", 2, "PIBE", 2, 100, 2);
    alta_FONZADA_Arcade(&arrayAcarde[3], "CHILE", 1, "CHELA", 3, 100, 3);
    alta_FONZADA_Arcade(&arrayAcarde[4], "CANADA", 1, "MARIO", 10, 100, 3);
    alta_FONZADA_Arcade(&arrayAcarde[5], "URUGUAY", 1, "PIBE", 1, 100, 3);
    alta_FONZADA_Arcade(&arrayAcarde[6], "COLOMBIA", 1, "MARIO", 10, 100, 3);
	alta_FONZADA_Arcade(&arrayAcarde[7], "PANAMA", 1, "TACO", 4, 100, 2);
	alta_FONZADA_Arcade(&arrayAcarde[8], "VENEZUELA", 2, "PIBE", 2, 100, 2);
	alta_FONZADA_Arcade(&arrayAcarde[9], "IRLANDA", 1, "CHELA", 3, 100, 3);
	alta_FONZADA_Arcade(&arrayAcarde[10], "CANADA", 1, "MARIO", 10, 100, 2);
	alta_FONZADA_Arcade(&arrayAcarde[11], "URUGUAY", 1, "PIBE", 2, 100, 2);


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
				baja(arraySalon, LARGO_ARRAY_SALON, id, "**Id de la Sala esta dato dado de Baja.**\n\n");
				bajaArcade(arrayAcarde, LARGO_ARRAY_ARCADE, id,"**Id de la Arcade esta dato dado de Baja.**\n\n");
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
				imprimirTodaslasSalas(arraySalon, LARGO_ARRAY_SALON);
				pedirEntero(&idSala, 0, 100, 3, "Ingrese Id de la sala: ", "ERROR ingrese Id valida del 0 - 100");
				posicionLibreArcade(arrayAcarde, LARGO_ARRAY_ARCADE, &posicionArcade);
				altaArcade(&arrayAcarde[posicionArcade], naciJuego, sonidoArcade, nombreJuego, cantidadJug, cantidadMaxFichas, idSala);
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
				generarListaJuegos(arrayAcarde, LARGO_ARRAY_ARCADE,juegoLista , LARGO_ARRAY_ARCADE);
				break;
			case 9:
				pedirEntero(&subMenu, 1, 7, 3, "Selecciones un Informe.\n1.Listar los salones con más de 4 arcades.\n"
						                       "2.Listar los arcades para más de 2 jugadores.\n3.Listar toda la información de un salón en específico ingresando su ID.\n"
						                       "4.Listar todos los arcades de un salón determinado ingresando su ID.\n5.Imprimir el salón con más cantidad de arcades.\n"
						                       "6.Ingresar el ID de un salón, y el valor en pesos de una ficha.\n"
						                       "7.Ingresar el nombre de un juego.\n", "ERROR ingrese una opcion valida\n");
				switch(subMenu)
				{
				case 1:
					listarSalonesConMasArcade(arrayAcarde, LARGO_ARRAY_ARCADE, arraySalon, LARGO_ARRAY_SALON);
					break;
				case 2:
					listarArcadeConMasJugadores(arrayAcarde, LARGO_ARRAY_ARCADE, arraySalon, LARGO_ARRAY_SALON);
					break;
				}
				break;
			}

	}while(opcion != 0);


 	return EXIT_SUCCESS;
}
