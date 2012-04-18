/*
 * imagen2.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */

#include "../include/imagen2.h"
#include "../include/imagenES.h"

Imagen::Imagen(int f, int c){
	filas 	= f;
	columnas= c;
	buffer 	= new unsigned char* [filas];

	for(int i=0; i < columnas; i++)
		buffer[i] = new unsigned char[columnas];
}
