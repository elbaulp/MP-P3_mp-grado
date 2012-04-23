/*
 * imagen3.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: hkr
 */

#include "../include/imagen3.h"
#include "../include/imagenES.h"

void Imagen::crear(int f, int c){
	filas 	= f;
	columnas= c;
	buffer 	= new unsigned char* [filas];

	buffer[0] = new unsigned char[filas * columnas];

	for(int i = 1; i < filas ; i++){
		buffer[i] = buffer[columnas*i]; //m[i-1]+ncol
	}
}
