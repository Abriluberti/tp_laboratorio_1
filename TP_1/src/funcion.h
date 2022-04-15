/*
 * funcion.h
 *
 *  Created on: 8 abr. 2022
 *      Author: Abril Uberti(div e)
 */

#ifndef FUNCION_H_
#define FUNCION_H_
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"


///@fn descontar(float)
///@brief ejerce calculos para poder hacer un descuento
///
///@param decuentoLatam, descuentoAerolineas
/// @return el precio ingresado con descuento
float descontar(float);
///@fn aumentar(float)
///@brief ejerce calculos para poder hacer un aumento
///
///@param aumentoLatam, aumentoLatam
/// @return el precio ingresado con aumento
float aumentar(float);
///@fn valorBitcoin(float)
///@brief refleja el precio pagar en bitcoin
///
///@param bitcoinAerolineas,bitcoinLatam
/// @return el precio con bitcion
float valorBitcoin(float);
///@fn precioPorKm(float,float)
///@brief para calcular el precio unitario por km
///
///@param unitarioAerolineas, unitarioLatam
/// @return el precio es multiplicado por km
float precioPorKm(float precio, float km);
///@fn diferenciaDePrecios(float,float)
///@brief hace la diferencia entre precio
///
///@param diferencias
/// @return se hace la diferencia entre latam y aerolineas
float diferenciaDePrecios(float latam, float aerolineas);


#endif /* FUNCION_H_ */
