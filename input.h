/*
 * input.h
 *
 *
 *      Author: Abril uberti, div d
 */

#ifndef INPUT_H_
#define INPUT_H_
/// @brief ingreso un array de tipo de char
///
/// @pre
/// @post
/// @param cadena
/// @param longitud
/// @return
int myGets(char *cadena, int longitud);
/// @brief ingreso un array de tipo int
///
/// @pre
/// @post
/// @param pResultado
/// @param textoAMostrar
/// @return
int getInt(int *pResultado, char textoAMostrar[]);
/// @brief validacion del array char
///
/// @pre
/// @post
/// @param cadena
/// @return
int esNumerica(char *cadena);
/// @brief ingreso un numero de tipo int con validacion
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);
/// @brief  ingreso un numero de tipo float con validacion
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo);
/// @brief ingreso un numero de tipo float
///
/// @pre
/// @post
/// @param pResultado
/// @return
int getFloat(float *pResultado);
/// @brief valida el array recibido
///
/// @pre
/// @post
/// @param stringRecibido
/// @return
int isValidTexto(char *stringRecibido);
/// @brief ingreso de un array y validacion
///
/// @pre
/// @post
/// @param pCadena
/// @param mensaje
/// @param mensajeError
/// @return
int utn_getTexto(char *pCadena, char *mensaje, char *mensajeError);

#endif /* INPUT_H_*/
