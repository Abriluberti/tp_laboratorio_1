/*
 * funcion.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Abril Uberti(Div E)
 */

float descontar(float precio)
{
	float descuento;
	descuento=precio - ( precio *0.10);
	return descuento;
}

float aumentar(float precio)
{
	float aumento;
	aumento=precio + (precio*0.25);
	return aumento;
}

float valorBitcoin(float precio)
{
	float valor;
	valor=precio/4606954.55;
	return valor;
}

float precioPorKm(float precio, float km)

{
		float precioUnitario;
	precioUnitario=precio/km;
	return precioUnitario;
}

float diferenciaDePrecios(float latam, float aerolineas)
{
	float diferencias;
	if(latam>aerolineas)
	{
		diferencias=latam-aerolineas;
	}

	else
			{
				diferencias = aerolineas;
			}

	return diferencias;

}



