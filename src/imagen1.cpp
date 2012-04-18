/*
 * imagen1.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */
#include <iostream>

#include "../include/imagen1.h"
#include "../include/imagenES.h"

using namespace std;

Imagen::Imagen(int f, int c){
	buffer 	= new unsigned char[f*c];
	filas 	= f;
	columnas= c;
}

void Imagen::set_buffer(int i, int j, unsigned char v){

}

//-------------------------

unsigned char Imagen::get_buffer(int i, int j) const{
	return 'c';
}

//-------------------------

void Imagen::destruir(){
	filas = NULL;
	columnas = NULL;
	delete buffer;
}

//-------------------------

bool Imagen::leer_imagen(const char file[]){
	return LeerImagenPGM(file, filas, columnas, buffer);
}

//-------------------------

bool Imagen::escribir_imagen(const char buffer[]) const{
	return true;
}
