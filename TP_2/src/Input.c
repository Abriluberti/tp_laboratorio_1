/*
 * Input.c
 *
 *  Created on: 12 may. 2022
 *      Author: Abril Uberti Div E
 */


#include <stdio.h>
#include <string.h>
#include "Input.h"
#include <string.h>

void rellenarInt(int* variableRecibida, char textoMostrar[])
{
	printf(textoMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);
}
void rellenarFloat(float* variableRecibida, char textoMostrar[])
{
	printf(textoMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);
}
void rellenarArray(char arrayRecibido[], char textoMostrar[])
{
	printf(textoMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}

void ordenarArray()
{


}
