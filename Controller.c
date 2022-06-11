/*
 * Controller.c
 *
 *
 *Author: Abril uberti, div d
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "string.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int valParser = 0;

	pFile = fopen(path, "r");
	if (pFile == ((void*) 0)) {
		return 0;
	}

	valParser = parser_PassengerFromText(pFile, pArrayListPassenger);
	fclose(pFile);

	return valParser;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int valParser = 0;

	pFile = fopen(path, "rb");
	if (pFile == ((void*) 0)) {
		printf("\nNo se abre el archivo!!!\n");
	} else {
		valParser = parser_PassengerFromBinary(pFile, pArrayListPassenger);
	}
	fclose(pFile);
	return valParser;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int idEntero;
	char idAux[10];
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char pasajeroChar[40];
	char codigoVueloAux[15];
	char estadoDeVueloAux[20];
	char precio[40];
	int retorno = 0;
	int validar;

	Passenger *pasajeroNuevo;

	idEntero = passengerIdLibre(pArrayListPassenger);
	itoa(idEntero, idAux, 10);

	validar = utn_getTexto(nombreAux, "\n*ingrese el nombre:", "ERROR");
	while (validar == -1) {
		validar = utn_getTexto(nombreAux, "\n*ingrese el nombre:", "ERROR");

	}

	validar = utn_getTexto(apellidoAux, "\n*ingrese el apellido:", "ERROR");
	while (validar == -1) {

		validar = utn_getTexto(apellidoAux, "\n*ingrese el apellido:", "ERROR");
	}

	validar = utn_getTexto(estadoDeVueloAux, "\n*ingrese el estado de vuelo:",
			"ERROR");
	while (validar == -1) {
		validar = utn_getTexto(estadoDeVueloAux,
				"\n*ingrese el estado de vuelo:", "ERROR");

	}

	validar = utn_getFloat(&precioAux, "\n*ingrese precio: \n", "Error", 1,
			1000000000000000000);
	while (validar == -1) {
		validar = utn_getFloat(&precioAux, "\n*ingrese precio: \n", "Error", 1,
				1000000000000000000);

	}

	itoa(precioAux, precio, 40);

	validar = utn_getInt(&tipoPasajeroAux,
			"\n *ingrese el tipo de pasajero 1, 2 o 3: \n ", " Error", 1, 3, 3);
	if (validar == -1) {
		validar = utn_getInt(&tipoPasajeroAux,
				"\n *ingrese el tipo de pasajero 1, 2, 3: \n ", " Error", 1, 3,
				3);

	}
	switch (tipoPasajeroAux) {
	case 1:
		strcpy(pasajeroChar, "Primera clase.");
		break;
	case 2:
		strcpy(pasajeroChar, "Clase business.");
		break;
	case 3:
		strcpy(pasajeroChar, "Clase turista.");
		break;
	}

	validar = utn_getTexto(codigoVueloAux, "\n *ingrese el codigo de vuelo \n",
			"Error");
	if (validar == -1) {
		validar = utn_getTexto(codigoVueloAux,
				"\n *ingrese el codigo de vuelo \n", "Error");

	}

	pasajeroNuevo = Passenger_newParametros(idAux, nombreAux, apellidoAux,
			pasajeroChar, precio, codigoVueloAux, estadoDeVueloAux);
	if (pasajeroNuevo != ((void*) 0)) {
		printf("\nSe cargo correctamente.\n El id que corresponde es %d\n,",
				pasajeroNuevo->id);
		retorno = 1;
		ll_add(pArrayListPassenger, pasajeroNuevo);
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_editPassenger(LinkedList *pArrayListPassenger) {

	int idAbuscar;
	int respuestaMenu2daOpcion;
	int validar;

	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	int tipoPasajeroAux;
	char codigoVueloAux[15];
	char estadoDeVueloAux[20];
	int indexx;

	Passenger *pasajeroModificado;

	utn_getInt(&idAbuscar, "ingrese el id a modificar", "id NO EXISTENTE", 1,
			ll_len(pArrayListPassenger), 5);
	pasajeroModificado = buscaDeld(pArrayListPassenger, idAbuscar);
	indexx = ll_indexOf(pArrayListPassenger, pasajeroModificado);
	pasajeroModificado = ll_get(pArrayListPassenger, indexx);
	do {
		printf("1- Modificar nombre.\n"
				"2- Modificar apellido.\n"
				"3- Modificar el precio\n"
				"4- Modificar el tipo de pasajero\n"
				"5- Modificar el codigo de vuelo \n"
				"6- Modificar el estado de vuelo.\n"
				"7- Salir.\n"
				"\nIngrese la opcion deseada.\n");

		scanf("%d", &respuestaMenu2daOpcion);
		fflush(stdin);

		switch (respuestaMenu2daOpcion) {

		case 1:
			validar = utn_getTexto(nombreAux, "Ingrese el nombre: ", "error");
			if (validar == -1) {
				printf("regresando al menu  \n");
				break;
			}
			Passenger_setNombre(pasajeroModificado, nombreAux);
			break;

		case 2:
			validar = utn_getTexto(apellidoAux, "Ingrese el apellido: ",
					"error");
			if (validar == -1) {
				printf("regresando al menu \n");
				break;
			}
			Passenger_setApellido(pasajeroModificado, apellidoAux);
			break;
		case 3:
			validar = utn_getFloat(&precioAux, "Ingrese el precio:\n:", "error",
					1, 10000000);
			if (validar == -1) {
				printf("regresando al menu  \n");
				break;
			}
			Passenger_setPrecio(pasajeroModificado, precioAux);
			break;
		case 4:
			validar = utn_getInt(&tipoPasajeroAux,
					"Ingrese el tipo de pasajero:\n:", "error", 1, 4, 3);
			if (validar == -1) {
				printf("regresando al menu  \n");
				break;
			}
			Passenger_setTipoPasajero(pasajeroModificado, tipoPasajeroAux);
			break;
		case 5:
			validar = utn_getTexto(codigoVueloAux,
					"Ingrese el codigo de vuelo: ", "error");
			if (validar == -1) {
				printf("regresando al menu  \n");
				break;
			}
			Passenger_setCodigoVuelo(pasajeroModificado, codigoVueloAux);
			break;
		case 6:
			validar = utn_getTexto(estadoDeVueloAux,
					"Ingrese el estado de vuelo: ", "error");

			if (validar == -1) {
				printf("regresando al menu  \n");
				break;
			}
			Passenger_setEstadoDeVuelo(pasajeroModificado, estadoDeVueloAux);
			break;

		case 7:

			printf("\nSaliendo al menu\n.");
			break;
		default:
			printf("opcion no valida");
		}
	} while (respuestaMenu2daOpcion != 7);

	return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {

	Passenger *pasajeroBorrado;
	int idABorrar;
	int borrarPosicion;
	int indexx;


	utn_getInt(&idABorrar, "\nIngrese la ID que se va a BORRAR\n",
			"ese id NO EXISTE", 1, ll_len(pArrayListPassenger), 3);

	pasajeroBorrado = buscaDeld(pArrayListPassenger, idABorrar);
	indexx = ll_indexOf(pArrayListPassenger, pasajeroBorrado);
	pasajeroBorrado = ll_get(pArrayListPassenger, indexx);
	utn_getInt(&borrarPosicion, "Deseas ELIMINAR ese id?\n1-SI\n, 2-NO\n",
			"¡¿SI O NO?!", 1, 2, 3);
	printf("se borro correctamente");
	ll_remove(pArrayListPassenger, indexx);
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	listaEnteraDePassenger(pArrayListPassenger);

	return 0;

}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;

	Node *pasajero = pArrayListPassenger->pFirstNode;
	Node *segundoPasajero;

	Passenger *comprobacion;
	Passenger *comprobacionSegunda;

	int indexxPrimera;
	int indexxSegunda;

	for (comprobacion = pasajero->pElement; pasajero != NULL; pasajero =
			pasajero->pNextNode) {

		comprobacion = pasajero->pElement;
		if (pasajero->pNextNode != ((void*) 0)) {
			segundoPasajero = pasajero->pNextNode;
			for (comprobacionSegunda = segundoPasajero->pElement;
					segundoPasajero != ((void*) 0); segundoPasajero =
							segundoPasajero->pNextNode) {
				comprobacionSegunda = segundoPasajero->pElement;
				if (comprobacion->id > comprobacionSegunda->id) {
					indexxPrimera = ll_indexOf(pArrayListPassenger,
							comprobacion);
					indexxSegunda = ll_indexOf(pArrayListPassenger,
							comprobacionSegunda);
					ll_set(pArrayListPassenger, indexxPrimera,
							comprobacionSegunda);
					ll_set(pArrayListPassenger, indexxSegunda, comprobacion);
					retorno = 1;
				}

			}
		}
	}

	return retorno;
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;

	int retorno = 1;
	pFile = fopen(path, "w");
	if (pFile == NULL) {
		retorno = 0;
	}

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigovuelo[15];
	char tipoPasajeroAux[27];
	int tipoPasajero;
	char estadoVuelo[15];

	Node *idBuscada = pArrayListPassenger->pFirstNode;
	fprintf(pFile, "%s,%s,%s,%s,%s,%s,%s\n", "id", "nombre", "apellido",
			"precio", "codigo de vuelo", "tipo de pasajero", "estado de vuelo");

	for (; idBuscada != NULL; idBuscada = idBuscada->pNextNode) {

		Passenger_getId(idBuscada->pElement, &id);
		Passenger_getNombre(idBuscada->pElement, nombre);
		Passenger_getApellido(idBuscada->pElement, apellido);
		Passenger_getPrecio(idBuscada->pElement, &precio);
		Passenger_getCodigoVuelo(idBuscada->pElement, codigovuelo);
		Passenger_getTipoPasajero(idBuscada->pElement, &tipoPasajero);
		Passenger_getEstadoDeVuelo(idBuscada->pElement, estadoVuelo);

		switch (tipoPasajero) {
		case -1:
			strcpy(tipoPasajeroAux, "Primera clase.");
			break;
		case 0:
			strcpy(tipoPasajeroAux, "Clase business.");
			break;
		case 1:
			strcpy(tipoPasajeroAux, "Clase turista.");
			break;
		}

		fprintf(pFile, "%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio,
				codigovuelo, tipoPasajeroAux, estadoVuelo);

	}

	fclose(pFile);

	return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	FILE *pFile;
	int retorno = 1;
	pFile = fopen(path, "wb");
	if (pFile == NULL) {

		retorno = 0;
	}

	Node *idBuscada = pArrayListPassenger->pFirstNode;

	for (; idBuscada != NULL; idBuscada = idBuscada->pNextNode) {
		fwrite(idBuscada->pElement, sizeof(Passenger), 1, pFile);
	}
	fclose(pFile);

	return retorno;

}

