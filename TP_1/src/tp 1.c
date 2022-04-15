/*
 ============================================================================
 Name        : tp 1.c
 Author      : abril uberti (Div E)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.  El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
 a) Tarjeta de débito (descuento 10%)
 b) Tarjeta de crédito (interés 25%)
 c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
 d) Mostrar precio por km (precio unitario)
 e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 Aerolíneas:
 a) Precio con tarjeta de débito: r
 b) Precio con tarjeta de crédito: r
 c) Precio pagando con bitcoin : r
 d) Precio unitario: r
 La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	float km=0;
	float descuentoAerolineas;
	float aumentoAerolineas;
	float precioAerolineas=0;
	float bitcoinAerolineas;
	float unitarioAerolineas;
	float descuentoLatam;
	float precioLatam=0;
	float aumentoLatam;
	float bitcoinLatam;
	float unitarioLatam;
	float diferencias;
	int flagA=0;
	int flagB=0;
	int flagC=0;

  do
  {
	  printf( "\n1- Ingresar Kilómetros(km= %.2f).\n"
			"2-Ingresar Precio de los Vuelos(aerolineas= %.2f , latam=%.2f) \n"
			"3- Calcular todos los costos. \n"
			"4- Informar Resultados. \n"
			"5- Carga forzada de datos. \n"
			"6- Salir. \n"
			 "\n ingrese la opcion deseada:", km , precioAerolineas, precioLatam);
	  fflush(stdin);
	  scanf("%d", &opcion);

	switch(opcion)
	{
		case 1:
			printf("\nIngreso del km");
			scanf("%f", &km);
			while(km<1)
			{
				printf("Error, ingrese el kilomentraje valido");
				fflush(stdin);
				scanf("%f", &km);
			}
			flagA=1;
			break;
		case 2:
			 printf("Ingresar precio de vuelo Aerolineas\n");
			 scanf("%f", &precioAerolineas);
			 while(precioAerolineas<1)
			 {
				 printf("Error, ingrese correctamente");
				 fflush(stdin);
				 scanf("%f",&precioAerolineas);
			 }
			 printf("Ingresar precio de vuelo Latam\n");
		     scanf("%f", &precioLatam);
		     while(precioLatam<1)
			 {
				 printf("Error, ingrese correctamente");
				 fflush(stdin);
				 scanf("%f",&precioLatam);
			 }
		     flagB=1;
		     break;
		case 3:

			if(flagA && flagB)
			{
				printf("Calcular todos los costos\n");
				descuentoAerolineas=descontar(precioAerolineas);
				 aumentoAerolineas=aumentar(precioAerolineas);
				 bitcoinAerolineas = valorBitcoin(precioAerolineas);
				 unitarioAerolineas= precioPorKm(precioAerolineas, km);

				 descuentoLatam=descontar(precioLatam);
				 aumentoLatam=aumentar(precioLatam);
				 bitcoinLatam= valorBitcoin(precioLatam);
                 unitarioLatam=precioPorKm(precioLatam, km);

				diferencias= diferenciaDePrecios (precioLatam, precioAerolineas);
				flagC=1;
			}
			else
			{
				printf("Error falta ingresar datos en el 1 y 2\n");
			}
			break;
		case 4:
			if (flagC==1)
			{
				printf("KMs Ingresados: %.2f km\n\n",km );
				printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
				printf("a) Precio con tarjeta de debito: $ %.2f \n",descuentoAerolineas );
				printf("b) Precio con tarjeta de credito: $  %.2f \n", aumentoAerolineas);
				printf("c) Precio pagando con bitcoin: %.2f BTC\n", bitcoinAerolineas);
				printf("d) Mostrar precio unitario:  $ %.2f \n\n", unitarioAerolineas);
				printf("Precio Latam: $%.2f\n", precioLatam );
				printf("a) Precio con tarjeta de debito: $ %.2f \n", descuentoLatam);
				printf("b) Precio con tarjeta de credito: $ %.2f \n",aumentoLatam );
				printf("c) Precio pagando con bitcoin: %.2f BTC\n",bitcoinLatam);
				printf("d) Mostrar precio unitario: $ %.2f \n\n", unitarioLatam);

				printf("La diferencia de precio es de: $ %.2f \n ", diferencias);
			}
			else
			{
				printf("Error, debe pasar por el 3 antes de seguir\n");
			}
			break;
		case 5:
			precioLatam=159339;
			precioAerolineas=162965;
			km=7090;


			descuentoAerolineas=descontar(precioAerolineas);
			aumentoAerolineas=aumentar(precioAerolineas);
			bitcoinAerolineas = valorBitcoin(precioAerolineas);
			unitarioAerolineas= precioPorKm(precioAerolineas, km);

			descuentoLatam=descontar(precioLatam);
			aumentoLatam=aumentar(precioLatam);
			bitcoinLatam= valorBitcoin(precioLatam);
			unitarioLatam= precioPorKm(precioLatam, km);

			diferencias=diferenciaDePrecios( precioLatam , precioAerolineas);


			printf("KMs Ingresados: %.2f km\n\n",km );
			printf("Precio Aerolineas: $%.2f\n",precioAerolineas);
			printf("a) Precio con tarjeta de debito: $ %.2f \n",descuentoAerolineas );
			printf("b) Precio con tarjeta de credito: $  %.2f \n", aumentoAerolineas);
			printf("c) Precio pagando con bitcoin: %.2f BTC\n", bitcoinAerolineas);
			printf("d) Mostrar precio unitario:  $ %.2f \n\n", unitarioAerolineas);
			printf("Precio Latam: $%.2f\n", precioLatam );
			printf("a) Precio con tarjeta de debito: $ %.2f \n", descuentoLatam);
			printf("b) Precio con tarjeta de credito: $ %.2f \n",aumentoLatam );
			printf("c) Precio pagando con bitcoin: %.2f BTC\n",bitcoinLatam);
			printf("d) Mostrar precio unitario: $ %.2f \n\n", unitarioLatam);
			printf("La diferencia de precio es de: $ %.2f \n ", diferencias);
			break;
	case 6:
		printf("\n Gracias por su visita, vuelva pronto");
			break;
			default:
		printf("ERROR, el numero que ingreso es menor que 1 o mayor que 6 o es un caracter \n");
	}
  }
while (opcion !=6);
return 0;
}
