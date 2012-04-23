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
	if (argc < 4) {
		cout << "Uso: " << "desplazar NumDesplazamientos ImagenEntrada ImagenSalida\n";
		return -1;
	}
	img.crear(0, 0);
	if (!img.leer_imagen(argv[2])) { //PAsamos el archivo a leer
		cout << "No se puede leer la imagen " << endl;
		return -2;
	}
	desplazar(img, (int)*argv[1]);
	if (!img.escribir_imagen(argv[3])) {
		cout << "No se puede escribir la imagen " << endl;
		return -3;
	}
	img.destruir();

	return 0;
}

