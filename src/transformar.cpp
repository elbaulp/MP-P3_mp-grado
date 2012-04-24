/*
 * transformar.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */
#include "../include/transformar.h"
#include "../include/imagen.h"

void negativo(Imagen& img){
	int filas 		= img.get_filas();
	int columnas 	= img.get_columnas();

	for (int i = 0; i < filas ; i++)
		for (int j = 0; j < columnas; j++)
			//Invierto los bits del pixel
			img.set_buffer(i,j,~img.get_buffer(i,j));
}

void desplazar(Imagen& img, int m){
	int filas 		= img.get_filas();
	int columnas 	= img.get_columnas();

	for (int i = 0; i < filas ; i++)
		for (int j = 0; j < columnas; j++)
			//Desplazar
			img.set_buffer(i,j,img.get_buffer(i,j)<<m);
}
