/**
 * @file ocultar.cpp
 * @brief Fichero principal encargado de ocultar el mensaje
 *
 *	Created on: Mar 15, 2012
 *		@author: Alejandro Alcalde
 */
#include "../include/imagenES.h"
#include "../include/imagen.h"
#include "../include/transformar.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	Imagen img;
	if (argc < 3) {
		cerr << "Uso: " << "negativo imagenEntrada.pgm imagenSalida.pgm\n";
		return -1;
	}
	img.crear(3, 3); //todo, 0,0 y combprobar
	if (!img.leer_imagen(argv[1])) { //PAsamos el archivo a leer
		cerr << "No se puede leer la imagen " << endl;
		return -2;
	}
	negativo(img);
	if (!img.escribir_imagen(argv[2])) {
		cerr << "No se puede escribir la imagen " << endl;
		return -3;
	}
	img.destruir();

	return 0;
}

