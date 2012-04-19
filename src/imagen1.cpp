/*
 * imagen1.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */
#include "../include/imagen1.h"
#include "../include/imagenES.h"
#include <iostream>
#include <assert.h>

using namespace std;

void Imagen::crear(int f, int c) {
	//assert(f > 0 && c > 0);

	if (f > 0 && c > 0) {
		filas = f;
		columnas = c;
		buffer = new unsigned char[filas * columnas];
	} else {
		filas = 0;
		columnas = 0;
		buffer = 0;
	}
}

void Imagen::set_buffer(int i, int j, unsigned char v) {
	buffer[i*columnas+j] = v;
}

//-------------------------

unsigned char Imagen::get_buffer(int i, int j) const {
	return buffer[i*columnas+j];
}

//-------------------------

void Imagen::destruir() {
	filas = 0;
	columnas = 0;
	delete[] buffer;
}

//-------------------------

bool Imagen::leer_imagen(const char file[]) {
	int f;
	int c;
	TipoImagen tipo = LeerTipoImagen(file, f, c);

	if (tipo == IMG_PGM) {
		destruir();
		crear(f, c);
		//cout << filas << columnas << endl;
		if (LeerImagenPGM(file, filas, columnas, buffer))
			return true;
		return false;
	}
	return false;
}

//-------------------------

bool Imagen::escribir_imagen(const char file[]) const {
	if (EscribirImagenPGM(file, buffer, filas, columnas))
		return true;
	return false;
}
