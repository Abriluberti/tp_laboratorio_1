/*
 * Passenger.c
 *
 *
 *Author: Abril uberti, div d
 */
#include "LinkedList.h"
#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/// @brief va a setear el id
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger *this, int id) {
	this->id = id;
	if (this->id != id) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener el id
///
/// @pre
/// @post
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger *this, int *id) {
	*id = this->id;
	if (*id != this->id) {
		return 1;
	}
	return 0;
}
/// @brief va a setear nombre
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger *this, char *nombre) {
	if (nombre != ((void*) 0) && this != ((void*) 0)) {
		strcpy(this->nombre, nombre);
		return 0;
	}

	return 1;

}
/// @brief va a obtener nombre
///
/// @pre
/// @post
/// @param this
/// @param nombre
/// @return
int Passenger_getNombre(Passenger *this, char *nombre) {
	strcpy(nombre, this->nombre);
	if (!(strcmp(nombre, this->nombre))) {

		return 1;
	}
	return 0;
}
/// @brief va a setear el apellido
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return
int Passenger_setApellido(Passenger *this, char *apellido) {
	if (this != ((void*) 0) && apellido != ((void*) 0)) {
		strcpy(this->apellido, apellido);
		return 0;
	}

	return 1;
}
/// @brief va a obtener el apellido
///
/// @pre
/// @post
/// @param this
/// @param apellido
/// @return
int Passenger_getApellido(Passenger *this, char *apellido) {
	strcpy(apellido, this->apellido);
	if (!(strcmp(apellido, this->apellido))) {
		return 1;
	}
	return 0;
}
/// @brief va a setear el codigo de vuelo
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	if (this != ((void*) 0) && codigoVuelo != ((void*) 0)) {
		strcpy(this->codigoVuelo, codigoVuelo);
		return 0;
	}

	return 1;
}
/// @brief va a obtener el codigo de vuelo
///
/// @pre
/// @post
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	strcpy(codigoVuelo, this->codigoVuelo);
	if (!(strcmp(codigoVuelo, this->codigoVuelo))) {
		return 1;
	}
	return 0;
}
/// @brief va a setear tipo de pasajero
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {
	this->tipoPasajero = tipoPasajero;
	if (this->tipoPasajero != tipoPasajero) {

		return 1;
	}

	return 0;
}
/// @brief va a obtener el tipo de pasajero
///
/// @pre
/// @post
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {
	*tipoPasajero = this->tipoPasajero;
	if (*tipoPasajero != this->tipoPasajero) {
		return 1;
	}
	return 0;
}
/// @brief va a setear el precio
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return
int Passenger_setPrecio(Passenger *this, float precio) {
	this->precio = precio;
	if (this->precio != precio) {

		return 1;
	}
	return 0;
}
/// @brief va a obtener el precio
///
/// @pre
/// @post
/// @param this
/// @param precio
/// @return
int Passenger_getPrecio(Passenger *this, float *precio) {
	*precio = this->precio;
	if (*precio != this->precio) {
		return 1;
	}
	return 0;
}
/// @brief va a obtener el estado de vuelo
///
/// @pre
/// @post
/// @param this
/// @param estadoDeVuelo
/// @return
int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo) {
	strcpy(estadoDeVuelo, this->estadoDeVuelo);
	if (!(strcmp(estadoDeVuelo, this->estadoDeVuelo))) {
		return 1;
	}
	return 0;
}
/// @brief va a setear el estado de vuelo
///
/// @pre
/// @post
/// @param this
/// @param estadoDeVuelo
/// @return
int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo) {

	if (this != ((void*) 0) && estadoDeVuelo != ((void*) 0)) {
		strcpy(this->estadoDeVuelo, estadoDeVuelo);
		return 0;
	}

	return 1;
}
/// @brief va a vaciar los datos de la lista abriendo la memoria dinamica
///
/// @pre
/// @post
/// @return retorna nuevo pasajero
Passenger* Passenger_new() {
	Passenger *nuevoPasajero = ((void*) 0);
	nuevoPasajero = (Passenger*) malloc(sizeof(Passenger));

	if (nuevoPasajero != ((void*) 0)) {
		nuevoPasajero->id = 0;
		strcpy(nuevoPasajero->nombre, " ");
		strcpy(nuevoPasajero->apellido, " ");
		nuevoPasajero->tipoPasajero = 0;
		nuevoPasajero->precio = 0;
		strcpy(nuevoPasajero->codigoVuelo, " ");
	}

	return nuevoPasajero;

}
/// @brief va a llenar los datos del pasajero nuevo
///
/// @pre
/// @post
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param tipoPasajeroStr
/// @param precioStr
/// @param flycodeStr
/// @param estadoDeVuelo
/// @return va a retornar nuevo pasajero
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *tipoPasajeroStr, char *precioStr,
		char *flycodeStr, char *estadoDeVuelo) {
	Passenger *nuevoPasajero = Passenger_new();
	int idAux;
	int tipoAux;
	float precioAux;

	idAux = atoi(idStr);
	tipoAux = strcmp(tipoPasajeroStr, "ExecutiveClass");

	precioAux = atof(precioStr);

	int validacion = 0;

	if (nuevoPasajero != ((void*) 0)) {

		if (Passenger_setId(nuevoPasajero, idAux) == 0) {
			validacion++;
			if (Passenger_setNombre(nuevoPasajero, nombreStr) == 0) {
				validacion++;
				if (Passenger_setApellido(nuevoPasajero, apellidoStr) == 0) {
					validacion++;
					if (Passenger_setTipoPasajero(nuevoPasajero, tipoAux)
							== 0) {

						validacion++;
						if (Passenger_setPrecio(nuevoPasajero, precioAux)
								== 0) {
							validacion++;
							if (Passenger_setCodigoVuelo(nuevoPasajero,
									flycodeStr) == 0) {
								validacion++;
								if (Passenger_setEstadoDeVuelo(nuevoPasajero,
										estadoDeVuelo) == 0) {
									validacion++;
								}
							}
						}
					}
				}
			}

			if (validacion != 7) {
				free(nuevoPasajero);
				nuevoPasajero = ((void*) 0);
			}
		}

	}
	return nuevoPasajero;
}
/// @brief va a mostrar la lista entera
///
/// @pre
/// @post
/// @param pArrayListPassenger
/// @return
int listaEnteraDePassenger(LinkedList *pArrayListPassenger) {
	Node *posicion = pArrayListPassenger->pFirstNode;
	Passenger *lectura;

	printf(
			"\n°ID:   °Nombre:   °Precio:  °Tipo De Pasajero:   °Codigo De Vuelo: \n");
	for (; posicion != ((void*) 0); posicion = posicion->pNextNode) {
		lectura = posicion->pElement;
		passangerListarUnica(lectura);

	}

	return 1;
}
/// @brief va a buscar el id libre
///
/// @pre
/// @post
/// @param pArrayListPassenger
/// @return va a retornar devolver
int passengerIdLibre(LinkedList *pArrayListPassenger) {
	Node *posicion = pArrayListPassenger->pFirstNode;
	Passenger *ultimo;
	int devolver = 0;

	if (ll_len(pArrayListPassenger) == 0) {
		devolver = 1;
	} else {
		for (; posicion != ((void*) 0); posicion = posicion->pNextNode) {
			ultimo = posicion->pElement;
		}
		devolver = ultimo->id + 1;
	}

	return devolver;
}
/// @brief va a buscar el id
///
/// @pre
/// @post
/// @param pArrayListPassenger
/// @param idABuscar
void* buscaDeld(LinkedList *pArrayListPassenger, int idABuscar) {
	Node *posicion = pArrayListPassenger->pFirstNode;

	Passenger *idBuscada;

	for (idBuscada = posicion->pElement;
			idBuscada->id != idABuscar && idBuscada != ((void*) 0); posicion =
					posicion->pNextNode) {
		idBuscada = posicion->pElement;
	}
	if (idBuscada->id != idABuscar) {
		idBuscada = ((void*) 0);
		printf("NO FUE POSIBLE!!!");
	}
	return idBuscada;
}
/// @brief muestra los datos de pasajeros
///
/// @pre
/// @post
/// @param lecturaDeDato
void passangerListarUnica(Passenger *lecturaDeDato) {
	char tipoPasajeroAux[27];
	if (lecturaDeDato != ((void*) 0)) {
		switch (lecturaDeDato->tipoPasajero) {
		case 1:
			strcpy(tipoPasajeroAux, "Primera clase");
			break;
		case 0:
			strcpy(tipoPasajeroAux, "Clase business");
			break;
		case -1:
			strcpy(tipoPasajeroAux, "Clase turista");
			break;
		}

		printf("%d  [  ", lecturaDeDato->id);
		printf(lecturaDeDato->nombre);
		printf(" ");
		printf(lecturaDeDato->apellido);
		printf("  ]  ");
		printf("%.2f", lecturaDeDato->precio);
		printf("  [  ");
		printf(tipoPasajeroAux);
		printf("  ]  ");
		printf(lecturaDeDato->codigoVuelo);
		printf("  [  ");
		printf(lecturaDeDato->estadoDeVuelo);
		printf("  ]  ");
		printf("\n");
	}

}
