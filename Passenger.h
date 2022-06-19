/*
 * Passenger.h
 *
 *
 *Author: Abril uberti, div d
 */
#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct {
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[15];
	char estadoDeVuelo[20];

} Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *tipoPasajeroStr, char *precioStr,
		char *flycodeStr, char *estadoDeVuelo);

void Passenger_delete();

int Passenger_setId(Passenger *this, int id);
int Passenger_getId(Passenger *this, int *id);

int Passenger_setNombre(Passenger *this, char *nombre);
int Passenger_getNombre(Passenger *this, char *nombre);

int Passenger_setApellido(Passenger *this, char *apellido);
int Passenger_getApellido(Passenger *this, char *apellido);

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo);
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo);

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);
int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo);

int listaEnteraDePassenger(LinkedList *pArrayListPassenger);
int passengerIdLibre(LinkedList *pArrayListPassenger);
void* buscaDeld(LinkedList *pArrayListPassenger, int idABuscar);
void passangerListarUnica(Passenger *lecturaDeDato);
int Passenger_comparacionPorNombre(void* primerNombre, void* segundoNombre);

#endif /* PASSENGER_H_ */
