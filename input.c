/*
 * input.c
 *
 *  Created on: 23 may. 2022
 *      Author: Abril Uberti, div e
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myGets(char *cadena, int longitud) {
	int retorno = -1;
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int getInt(int *pResultado, char textoAMostrar[]) {

	printf(textoAMostrar);
	scanf("%d", pResultado);
	fflush(stdin);
	return 0;
}

int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt, " \n Ingrese un numero:") == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

//FUNCIONES PARA LOS FLOATS

int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo) {
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0) {
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

//funciones para las cadenas
int isValidTexto(char *stringRecibido) {
	int retorno = 0; // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	for (i = 0; stringRecibido[i] != '\0'; i++) {
		if (stringRecibido[i] < ' ' || stringRecibido[i] > 'z'
				|| stringRecibido[i] == 'ñ') {
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int utn_getTexto(char *pCadena, char *mensaje, char *mensajeError) {
	int retorno = 0;

	if (mensaje != NULL && mensajeError != NULL && pCadena != NULL) {

		printf(mensaje);
		fflush(stdin);
		gets(pCadena);

		if (isValidTexto(pCadena) == -1) {
			retorno = 1;
			printf(mensajeError);
		}

	}

	return retorno;
}
