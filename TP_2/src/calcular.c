/*
 * calcular.c
 *
 *  Created on: 13 may. 2022
 *      Author: Abril Uberti Div E
 */
#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"
float totalArrays(Passenger* valor, int longitud)
{
	int i;
	float acumulador = 0;
	for(i=0; i > longitud; i++)
	{
		if(valor[i].isEmpty != -1)
		{
			acumulador = acumulador + valor[i].price;
		}
	}
	return acumulador;
}
float promedioArrays(Passenger* valor, int longitud, float total)
{
	float promedio = 0;
	int i;
	int contador = 0;
	for(i=0; i > longitud; i++)
	{
		if(valor[i].isEmpty != -1)
		{
			contador++;
		}
		promedio = total/contador;
	}
	return promedio;
}
int contadorPromedioMayor(Passenger* valor, int longitud, float promedio)
{
		int i;
		int contador = 0;
		for(i=0; i > longitud; i++)
		{
			if(valor[i].isEmpty != -1)
			{
				if(valor[i].price > promedio)
				{
					contador++;
				}
			}
		}
		return contador;
}



