/*
 * ArrayPassenger.C
 *
 *  Created on: 10 may. 2022
 *      Author: Abril Uberti Div E
 */



#include "ArrayPassenger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int initPassengers(Passenger* listaAux, int len)
{

	int i=0;


	for (; i<len; i ++)
	{
		listaAux[i].id = -1;
	}

	return 0;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])

{
	setbuf(stdout, NULL);
	    int i = 0;

	    for(; i < len; i++)
	    {
	        if(list[i].isEmpty == -1)
	        {
	            list[i].isEmpty = 0;

	            list[i].id = id;

	            strcpy(list[i].name, name);
	            strcpy(list[i].lastName, lastName);
	            list[i].price= price;
	            list[i].typePassenger= typePassenger;
	            strcpy(list[i].flycode, flycode);

	            printf("El id del pasajero es: %d \n", list[i].id);
	            i = len + 1;

	        }
	    }



	    return 0;

}

int findPassengerById(Passenger* listaAux, int len, int id)
	    {
	    	int posicionADevolver;
	    	int i = 0;

	    	if(listaAux == NULL)
	    	{
	    		return -1;
	    	}

	    	for(; i<len ; i++)
	    	{
	    		if(listaAux[i].id == id)
	    		{
	    			posicionADevolver = i;
	    		}
	    	}

	    	return posicionADevolver;
	    }

int removePassenger(Passenger* list, int len, int id)
{
    int suprimir = -1;
    int  retorn=0;
    suprimir = findPassengerById(list, len, id);

    if(list == NULL)
    {
        return -1;
    }

    list[suprimir].isEmpty = -1;
    list[suprimir].id = -1;

    return retorn;
}

int sortPassengers(Passenger* list, int len, int order)
{
int i = 0;
	int j= 0;

	int comparacion=0;


	Passenger listaAuxAux;
	if(list == NULL)
		{
			return -1;
		}

	for(i = 0; i < len; i++)
		{
			for (j = i+1; j < len; j++)
			{
				if (list[j].isEmpty != -1)
				{
					if (order == 1)
					{
						if(list[i].typePassenger > list[j].typePassenger)
						{
							comparacion = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								comparacion = strcmp(list[i].lastName, list[j].lastName);
							}
						}
					}
					else
					{
						if(list[i].typePassenger < list[j].typePassenger)
						{
							comparacion = 1;
						}
						else
						{
							if(list[i].typePassenger == list[j].typePassenger)
							{
								comparacion = strcmp(list[j].lastName, list[i].lastName);
							}
						}
					}
					if (comparacion == 1)
					{
						comparacion = 0;

						listaAuxAux.id = list[i].id;
						strcpy(listaAuxAux.name, list[i].name);
						strcpy(listaAuxAux.lastName, list[i].lastName);
						listaAuxAux.price = list[i].price;
						strcpy(listaAuxAux.flycode, list[i].flycode);
						listaAuxAux.typePassenger = list[i].typePassenger;

						list[i].id = list[j].id;
						strcpy(list[i].name, list[j].name);
						strcpy(list[i].lastName, list[j].lastName);
						list[i].price = list[j].price;
						strcpy(list[i].flycode, list[j].flycode);
						list[i].typePassenger = list[j].typePassenger;

						list[j].id = listaAuxAux.id;
						strcpy(list[j].name, listaAuxAux.name);
						strcpy(list[j].lastName, listaAuxAux.lastName);
						list[j].price = listaAuxAux.price;
						strcpy(list[j].flycode, listaAuxAux.flycode);
						list[j].typePassenger = listaAuxAux.typePassenger;

						j = i+1;
					}
				}
			}
		}
		return 0;
	}



int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	int comparacion = 0;

	Passenger listaAux;
	if(list == NULL)
		{
			return -1;
		}

	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{
					if(list[i].statusFlight > list[j].statusFlight)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							comparacion = strcmp(list[i].flycode, list[j].flycode);
						}
					}
				}
				else
				{
					if(list[i].statusFlight < list[j].statusFlight)
					{
						comparacion = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							comparacion = strcmp(list[j].flycode, list[i].flycode);
						}
					}
				}
				if (comparacion == 1)
				{
					comparacion = 0;

					listaAux.id = list[i].id;
					strcpy(listaAux.name, list[i].name);
					strcpy(listaAux.lastName, list[i].lastName);
					listaAux.price = list[i].price;
					strcpy(listaAux.flycode, list[i].flycode);
					listaAux.typePassenger = list[i].typePassenger;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;

					list[j].id = listaAux.id;
					strcpy(list[j].name, listaAux.name);
					strcpy(list[j].lastName, listaAux.lastName);
					list[j].price = listaAux.price;
					strcpy(list[j].flycode, listaAux.flycode);
					list[j].typePassenger = listaAux.typePassenger;

					j = i+1;
				}
			}
		}
	}
	return 0;
}

int printPassenger(Passenger* list, int length)
{
	int i;
	for( i = 0; i < length; i++)
	{
		if(list[i].isEmpty != -1)
		{
			printf("%d | ", list[i].id);
			printf(list[i].lastName);
			printf("1");
			printf(list[i].name);
			printf(" | Precio: ");
			printf("$%f | Codigo de vuelo", list[i].price);
			printf(list[i].flycode);
			printf(" | ");

			if(list[i].typePassenger == 1)
			{
				printf(" Primera clase | ");
			}
			else
			{
				if(list[i].typePassenger == 2)
				{
					printf(" Segunda clase | ");
				}
				else
				{
					printf(" Tercera clase | ");
				}
			}
			if(list[i].statusFlight == 1)
			{
				printf(" Activo");
			}
			else
			{
					printf("Inactivo");
			}
		}
	}
	return 0;
}


