/*
 * main.C
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	int option = 0;
	int banderaCargaV = 0;
	int banderaGuardar = 0;
	int comprobacion;

	LinkedList *clonacionDeArray;
	LinkedList *listaPasajeros = ll_newLinkedList();
	setbuf(stdout, NULL);
	do {
		printf(
				"\n----------------------------------------|MENU DE OPCIONES|----------------------------------------"
						"\n1-Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
						"\n2-Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
						"\n3-Alta de pasajero"
						"\n4-Modificar datos de pasajero "
						"\n5-Baja de pasajero "
						"\n6-Listar pasajeros"
						"\n7. Copia de seguridad"
						"\n8- Cargar copia de seguridad"
						"\n9-Ordenar pasajeros"
						"\n10-Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
						"\n11-Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
						"\n12-Salir"
						"\n----------------------------------------------------------------------------------------------------\n\n");
		scanf("%d", &option);
		fflush(stdin);
		switch (option) {
		case 1:
			controller_loadFromText("data.csv", listaPasajeros);
			banderaCargaV = 1;
			break;
		case 2:
			banderaCargaV = 1;
			controller_loadFromBinary("data.bin", listaPasajeros);
			break;
		case 3:
			banderaCargaV = 1;
			controller_addPassenger(listaPasajeros);
			break;
		case 4:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");
				break;
			} else {
				controller_editPassenger(listaPasajeros);
			}
			break;
		case 5:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");
				break;
			} else {
				controller_removePassenger(listaPasajeros);
			}
			break;
		case 6:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");

			} else {
				controller_ListPassenger(listaPasajeros);
			}
			break;
		case 7:
			if (ll_isEmpty(listaPasajeros)) {
				comprobacion = controller_loadFromText("backup.csv", listaPasajeros);

				if (comprobacion == 1) {
					printf("Bien! se han cargado correctamente. \n");
					ll_sort(listaPasajeros, Passenger_comparacionPorNombre, 1);
					system("pause");
				} else {
					printf("No! no se cargaron correctamente. \n");
					system("pause");
				}
			} else {
				printf("Bien! se han cargado correctamente.\n");
				system("pause");
			}
			banderaGuardar = 1;
			break;
		case 8:
			clonacionDeArray = ll_clone(listaPasajeros);

			comprobacion = controller_saveAsText("copiadesegurida.csv", clonacionDeArray);

			if (ll_contains(listaPasajeros, clonacionDeArray)) {

			}
			if (comprobacion == 1) {
				printf("Perfecto! se realizo la copia de seguirdad.\n");
				system("pause");
			} else {
				printf("No! no se pudo realizar la copia de segurida. \n");
				system("pause");
			}
            break;

		case 9:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");

			} else {
				controller_sortPassenger(listaPasajeros);
			}
			break;
		case 10:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");
				break;
			} else {

				controller_saveAsText("dataGuardado.csv", listaPasajeros);
				banderaGuardar = 1;
			}
			break;
		case 11:
			if (banderaCargaV == 0) {
				printf("\n Debe cargar al menos un pasajero");
				break;
			} else {

				controller_saveAsBinary("data.bin", listaPasajeros);
				banderaGuardar = 1;
			}
			break;

		case 12:
			if (banderaGuardar == 1) {
				printf("que tenga un buen dia, vuelva pronto!\n");

			} else {
				printf("se recomienda GUARDAR datos, CUIDADO!");
			}
			break;
		default:
			printf("NO! solo hay 12 opciones");
			break;
		}

	} while (option != 12);
	return 0;
}

