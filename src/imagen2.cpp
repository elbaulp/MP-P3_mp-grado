/*
 * imagen2.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */

#include "../include/imagen2.h"
#include "../include/imagenES.h"

#include <string.h>

void Imagen::crear(int f, int c) {
	if (f < 0 && c < 0) {
		filas 	 = 0;
		columnas = 0;
		buffer 	 = 0;
	}else{
		filas 	 = f;
		columnas = c;
		buffer 	 = new unsigned char*[filas];

		for (int i = 0; i < filas; i++)
			buffer[i] = new unsigned char[columnas];
	}
}

//-------------------------

bool Imagen::leer_imagen(const char file[]) {
	int f;
	int c;
	bool resul = false;
	unsigned char* auxBuffer;

	TipoImagen tipo = LeerTipoImagen(file, f, c);
	auxBuffer = new unsigned char[f * c];

	if (tipo == IMG_PGM) {
		destruir();
		crear(f, c);
		if (LeerImagenPGM(file, filas, columnas, auxBuffer)) {
			//Pasamos el buffer la estructura de imagen2
			for (int i = 0; i < filas; i++)
				for (int j = 0; j < columnas; j++)
					buffer[i][j] = auxBuffer[i * columnas + j];
			delete[] auxBuffer;
			resul = true;
		}

	}
	return resul;
}

void Imagen::set_buffer(int i, int j, unsigned char v) {
	buffer[i][j] = v;
}

//-------------------------

unsigned char Imagen::get_buffer(int i, int j) const {
	return buffer[i][j];
}

//-------------------------

void Imagen::destruir() {
	for (int i = 0; i < filas; i++)
		delete[] buffer[i];
	delete[] buffer;

	filas = 0;
	columnas = 0;
}

//-------------------------

bool Imagen::escribir_imagen(const char file[]){
	//Pasamos de la estructura de buffer2 a la simple
	unsigned char* auxBuffer = new unsigned char[filas * columnas];

	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			auxBuffer[i*columnas + j] = buffer[i][j]; //2d Array to 1D

	if (EscribirImagenPGM(file, auxBuffer, filas, columnas)){
		delete[] auxBuffer; //TODO Fuera
		return true;
	}
	return false;
}
