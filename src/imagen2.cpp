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
 bool Imagen::leer_imagen(const char file[]){
	 //Antes de esto leerTIpoImagen para tenr las filas y columnas de la imagen
	 //unsigned char* buffer[fil*col]; //Para ponerlo de la primera forma para que al leer la imagen pasemos el parametro correctamente
	 //Le pasalo a leerImganPGM con este biffer
	 //Despues pasamos el buffer a nuestra forma de buffer de doble puntero con un doble for
	 //delete[] el buffer aux
 }
