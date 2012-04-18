/*
 * imagen1.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */
#include "../include/imagen1.h"
#include "../include/imagenES.h"

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

}

//-------------------------

bool Imagen::leer_imagen(const char file[]){
	bool s = LeerImagenPGM("./imagenes/hombro.pgm", this->filas, this->columnas, this->buffer);
	return s;
}

//-------------------------

bool Imagen::escribir_imagen(const char buffer[]) const{
	return true;
}

