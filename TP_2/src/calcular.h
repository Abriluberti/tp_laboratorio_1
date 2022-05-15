/*
 * calcular.h
 *
 *  Created on: 13 may. 2022
 *      Author: Abril Uberti Div E
 */

#ifndef CALCULAR_H_
#define CALCULAR_H_
#include "ArrayPassenger.h"

float totalArrays(Passenger* valor, int longitud);
float promedioArrays(Passenger* valor, int longitud, float total);
int contadorPromedioMayor(Passenger* valor, int longitud, float promedio);

#endif /* CALCULAR_H_ */
