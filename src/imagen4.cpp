/*
 * imagen4.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: hkr
 */

#include "../include/imagen4.h"
#include "../include/imagenES.h"

void Imagen::crear(int f, int c) {

	if (f > 0) {
		columnas = c;
//		Celdas primeraCelda;
//		primeraCelda.fila = new unsigned char[columnas];
//		pt->nextRow = primeraCelda;
//		Celdas ultima;
//		ultima.fila = new unsigned char[columnas];
//		pt->nextRow = primera;
		Celdas* aux =0;
		for (int i = 1; i < filas; i++) {
			pt = new Celdas;
			pt->nextRow = aux;
			aux = pt;
		}
	}
}
