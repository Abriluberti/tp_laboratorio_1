/*
 ============================================================================
 Name        : TP_laboratorio_2_.c
 Author      : Abril Uberti Div E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include <string.h>
#include "ArrayPassenger.h"
#include "calcular.h"

int main(void)
{
	setbuf(stdout,NULL);
	int contador;
	float promedio;
	float total;
	int idAux;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;
	int respuesta;
	int respuestaMenu2daOpcion;
	int buscarPosicion;
	int largo=2000;
	int tipoBusqueda;
	int ordenCriterio;
	int valAgregarPasajero;
	int valRetirarPasajero;
	int valSortPasajero;
	int bandera=0;

	Passenger pasajeros[largo];

	initPassengers(pasajeros, largo);

	do {
	printf(                "\n1- Ingresar pasajero. \n"
								"2- Modificar pasajero. \n"
								"3- Eliminar pasajero. \n"
								"4- Informar pasajeros. \n"
								"5- Ingreso forzado de pasajeros. \n"
								"6- Salir. \n"
								"\n Ingrese la opcion deseada.");
		   scanf("%d", &respuesta);
		   fflush(stdin);

		   switch(respuesta)
		   {
			   case 1:
			   {
				   idAux ++;

					rellenarArray( nombre, "Ingrese el nombre del pasajero");

					rellenarArray(apellido, "Ingrese el apellido del pasajero.");

					rellenarFloat(&precio, "Ingrese el precio del vuelo.");

					rellenarArray(codigoDeVuelo, "Ingrese el codigo de vuelo");

					rellenarInt(&tipoDePasajero, "Ingrese el tipo de pasajero.");

					valAgregarPasajero =addPassenger(pasajeros, largo,idAux, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo);
					if(valAgregarPasajero == -1)
					{
						printf("Error, ingrese de nuevo");
					}
					bandera=1;
					break;
			   }
			   case 2:
			   {
				   if(bandera ==1)
				   {
				   rellenarInt(&idAux, "\nIngrese el ID del pasajero a modificar.");

					buscarPosicion = findPassengerById(pasajeros, largo, idAux);

					do{
						printf(	"\n1- Modificar nombre.\n"
								"2- Modificar apellido.\n"
								"3- Modificar precio.\n"
								"4- Modificar codigo de vuelo.\n"
								"5- Modificar tipo de pasajero.\n"
								"6- Salir.\n"
								"\nIngrese la opcion deseada.\n");

								scanf("%d", &respuestaMenu2daOpcion);
								fflush(stdin);

			switch(respuestaMenu2daOpcion)
			{
				case 1:

					rellenarArray(pasajeros[buscarPosicion].name, "Ingrese el nombre");
					break;
				case 2:

					rellenarArray(pasajeros[buscarPosicion].lastName, "Ingrese el apellido.");
					break;

				case 3:

					rellenarFloat(&pasajeros[buscarPosicion].price,"Ingrese el precio.");
					break;

				case 4:

					rellenarArray(pasajeros[buscarPosicion].flycode,"Ingrese el codigo de vuelo.");

					break;

				case 5:

					rellenarInt(&pasajeros[buscarPosicion].typePassenger, "Ingrese el tipo de pasajero.");
					bander
					break;

				case 6:

					printf("\nSaliendo al menu\n.");
					break;

				default:
				{
					printf("\nOpcion incorrecta.\n");
					break;
				}
			}
			}while(respuestaMenu2daOpcion != 6);
		       }
			    break;
				}
			case 3:
				if(bandera==1)
				{
				rellenarInt(&idAux, "\nIngrese el ID del pasajero a eliminar.");

				buscarPosicion = findPassengerById(pasajeros, largo, idAux);

				pasajeros[buscarPosicion].isEmpty = -1;
				valRetirarPasajero = removePassenger(pasajeros, largo, buscarPosicion);
				if (valRetirarPasajero == -1)
				{
					printf("Error, intente otra vez");
				}
				}
				break;
		   case 4:
			   if(bandera==1)
			   	{
			  rellenarInt(&tipoBusqueda, "\n1-Ordenar por apellido y pasajero. \n2-Ordenar por codigo de vuelo.\n");
			  rellenarInt(&ordenCriterio, "\n1-Ordenar de forma ascedente. \n2-Ordenar de forma descendente.");
			  total=totalArrays(pasajeros, largo);
			  promedio=promedioArrays(pasajeros, largo, total);
			  contador=contadorPromedioMayor(pasajeros, largo, promedio);
			  if(tipoBusqueda == 1)
			  {
				  valSortPasajero=sortPassengers(pasajeros, largo, ordenCriterio);
			  }
			  else
			  {
				  valSortPasajero= sortPassengersByCode(pasajeros, largo, ordenCriterio);
			  }
			  if(valSortPasajero== -1)
			  {
				  printf("Error, intente otra vez");
			  }
			  printPassenger(pasajeros,largo);
			  printf("La suma de todos los precios da %f y el promedio es %f, %d pasajeros superan ese promedio", total, promedio, contador);
			   }
			  break;
		   case 5:
			   strcpy(nombre, "Emma");
			   strcpy(apellido, "Uberti");
			   precio = largo;
			   tipoDePasajero = 1;
			   strcpy(codigoDeVuelo, "BRILA-07");
			   addPassenger(pasajeros, largo, idAux, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo);
			   idAux++;
			   strcpy(nombre, "Roma");
			   strcpy(apellido, "Marambio");
			   precio = largo;
			   tipoDePasajero = 1;
			   strcpy(codigoDeVuelo, "AEP");
			   addPassenger(pasajeros, largo, idAux, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo);
			   idAux++;
			   strcpy(nombre, "Giovanni");
			   strcpy(apellido, "Marambio");
			   precio = largo;
			   tipoDePasajero = 1;
			   strcpy(codigoDeVuelo, "EZE");
			   addPassenger(pasajeros, largo, idAux, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo);
			   idAux++;
			   strcpy(nombre, "Benjamin");
			   strcpy(apellido, "Damico");
			   precio = largo;
			   tipoDePasajero = 1;
			   strcpy(codigoDeVuelo, "remoño");
			   addPassenger(pasajeros, largo, idAux, nombre, apellido, precio, tipoDePasajero, codigoDeVuelo);
			   bandera = 1;
			   break;
			   case 6:
				   printf("\n Que tenga un buen vuelo!");
				   break;
			   default:
			   {
				  printf("\n Opcion no valida. \n");
			   }

		   }
	}while(respuesta !=6);
		return 0;
}

